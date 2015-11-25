#include "barchartdialog.h"
#include <iterator>
#include <QPen>
#include <qpainter.h>
#include <qradiobutton.h>

//QWidget * test;
#include <iostream>
using namespace std;
barchartdialog::barchartdialog(QWidget *parent) : QWidget(parent)
{
    //set the title and size of the dialog//
    setWindowTitle("Bar Chart");
    setFixedSize(1000,800);

    xOrigin=50;
    temp=0;

    //Print Button
    printButton = new QPushButton("Print", this);
    printButton->setGeometry(QRect(QPoint(20, 700),QSize(120,20)));
    connect(printButton, SIGNAL(pressed()),this,SLOT(printButtonPushed()));

    //set up the default buttons//
    barButton1 = new QRadioButton("",this);
    barButton2 = new QRadioButton("",this);
    barButton1->setGeometry(QRect(QPoint(150,30),QSize(120,20)));
    barButton2->setGeometry(QRect(QPoint(150,60),QSize(120,20)));
    barGroup=new QButtonGroup(this);
    barGroup->addButton(barButton1);
    barGroup->addButton(barButton2);
    connect(barGroup,SIGNAL(buttonClicked(int)),this,SLOT(switchBarValue()));

    //set up scroll bar//
    layout = new QVBoxLayout(this);
    horizontalBar = new QScrollBar(Qt::Horizontal);
    layout->addStretch();
    layout->addWidget(horizontalBar);
    connect(horizontalBar,&QScrollBar::valueChanged,this,&barchartdialog::scrollTo);

}

void barchartdialog::printButtonPushed()
{
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Document"));

    if (dialog->exec() != QDialog::Accepted)
        return;

    QPixmap pixmap = QPixmap::grabWidget(this, 0, 0, -1, -1);
    QPainter painter;
    painter.begin(&printer);
    painter.drawImage(0, 0, pixmap.toImage());
    painter.end();
}

/*Use the graphclass object, which contains the data*/
void barchartdialog::setData(GraphClass *graph,int start,int end)
{
    this->startYear=start;
    this->endYear=end;
    QVector<int> value1;
    QVector<int> value2;
    QVector<string> title;
    QVector<QColor> color;

    //get the data from a GraphClass object//
    list<list<BarValue> > * readyForGraph = graph->getRange();
    list<list<BarValue> >::iterator i1 = readyForGraph->begin();

    while (i1 != readyForGraph->end()) {
        list<BarValue>::iterator i2 = i1->begin();
        while (i2 != i1->end()) {
            title.push_back(i2->title);
            value1.push_back(i2->yValue1);
            value2.push_back(i2->yValue2);
            ++ i2;
        }
        ++ i1;
    }

    this->barValue1=value1;
    this->barValue2=value2;
    this->barTitle=title;
    this->startYear=start;
    this->endYear=end;
    barValue=barValue1;

    cout << "Bar title : " << barTitle.at(0) << endl;
    //set up the text on buttons and colors that are used to display the bars//
    if(barTitle.at(0)=="Grant - PR"){
        barButton1->setText("Total Number");
        barButton2->setText("Total Amount");
        this->barValue=value1;
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
    }
    else if(barTitle.at(0)=="Teaching - PME"){
        barButton1->setText("Total Number of Student");
        barButton2->setText("Total Number of Teaching Hours");
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
    }
    else if(barTitle.at(0)=="Pres - Lectures"){
        barButton1->setText("Total Number");
        barButton2->hide();
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
    }
    else{
        barButton1->setText("Total Number of Publication");
        barButton2->hide();
        for(int i=0;i<21;i++){
            color.push_back(QColor(qrand()%256,qrand()%256,qrand()%256,255));
        }
    }

    this->barColor=color;

    repaint();
}

void barchartdialog::switchBarValue()
{
    if(barButton1->isChecked()){
        barValue=barValue1;
    }
    else{
        barValue=barValue2;
    }
    repaint();
}

/*This method is used to set up the page step of the scroll bar*/
void barchartdialog::scrollTo()
{
    printf("Scroll Test");
    int range=xCordinate-xOrigin;
        if(range>800){
            horizontalBar->setPageStep(1600-xCordinate);
        }
        else if(range>1590){
            horizontalBar->setPageStep(10);
        }

        else{
          horizontalBar->setPageStep(800);
        }

        horizontalBar->setMinimum(0);
        horizontalBar->setMaximum(801-horizontalBar->pageStep());

        xOrigin=xOrigin-horizontalBar->value()+temp;
        temp=horizontalBar->value();

        repaint();
}
/*Draw the bar graph*/
void barchartdialog::paintEvent(QPaintEvent *parent)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,2));

    int count = barValue.size();


    int space = 50;//space between bars//
    int barWidth = 20;
    int barHeight = 0;
    int yOrigin = 600;
    int yAxisLength = yOrigin - 100;
    xCordinate=xOrigin;
    double percent;


    //find the maximum value along the y-axis//
    double max = 0.00;

    for(int i = 0;i<count;i++){
        if(max<barValue[i]){
            max = barValue[i];
        }
    }
    int temp;
    int n = 0;
    temp=max;
    while(temp%10!=temp){
        temp/=10;
        n++;
    }
    double yMaxScale;
    yMaxScale=temp+1;

    for(int i = 0;i<n;i++){
        yMaxScale*=10;
    }
    int yScaleNum=(yMaxScale<10)? yMaxScale : 10;



    //draw the rectangle that represents the index and draw the years on the x-axis//
    for(int i = 0;i<4;i++){
        QRect indexRect(870,100+i*20,20,20);
        painter.setBrush(barColor[i]);
        painter.drawRect(indexRect);
        painter.drawText(900,100+i*26,QString::fromStdString(barTitle[i]));
    }

    //draw the x,y-axis, the year on x-axis and the bar//
    int i = 0;
    int start=startYear;

    if(barValue1.size()%21==0){
        typeNum=21;
    }
    else{
        typeNum=4;
    }

    while(i<count)
    {
        if(i%typeNum==0){
            painter.drawLine(xCordinate,yOrigin,xCordinate+space,yOrigin);
            painter.drawText(QPoint(xCordinate+space+15,yOrigin+40),QString::number(start)+"-");
            painter.drawText(QPoint(xCordinate+space+45,yOrigin+40),QString::number(start+1));
            start++;
            xCordinate += space;
        }

        percent = barValue[i]/yMaxScale;
        barHeight = percent*500;
        painter.drawLine(xCordinate,yOrigin,xCordinate+barWidth,yOrigin);//draw x-axis//
        QRect barRect(xCordinate,yOrigin-barHeight,barWidth,barHeight);
        painter.setBrush(barColor[i%typeNum]);
        painter.drawRect(barRect);

        if(barValue[i]!=0)
        {
            painter.drawText(QPoint(xCordinate,yOrigin-barHeight-10),QString::number(barValue[i]));
        }

        xCordinate += barWidth;

        i++;
    }


    //draw y-axis//
    painter.drawLine(xOrigin,yOrigin,xOrigin,100);//draw y-axis//
    int temp1 = yMaxScale/yScaleNum;
    for(int i = 0;i<yScaleNum;i++)
    {
        painter.drawText(QPoint(xOrigin-30,yOrigin-yAxisLength/yScaleNum*i),QString::number(temp1*i));

    }
    painter.drawText(QPoint(xOrigin-30,100),QString::number(yMaxScale));
}



