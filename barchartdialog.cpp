#include "barchartdialog.h"
#include <iterator>
#include <QPen>
#include <qpainter.h>
#include <qradiobutton.h>

//QWidget * test;
#include <iostream>
using namespace std;

int xEnd;
/*Contructor*/
barchartdialog::barchartdialog(QWidget *parent) : QWidget(parent)
{
    //set the title and size of the dialog//
    setWindowTitle("Bar Chart");
    setFixedSize(1000,800);

    cout << "Constructor is called" << endl;
    xOrigin=50;
    temp=0;

    xEnd = -1;

    //Print Button
    printButton = new QPushButton("Print", this);
    printButton->setGeometry(QRect(QPoint(20, 700),QSize(120,20)));
    connect(printButton, SIGNAL(pressed()),this,SLOT(printButtonPushed()));

    //set up the position of buttons and connect buttons with the slot method//
    barButton1 = new QRadioButton("",this);
    barButton2 = new QRadioButton("",this);
    barButton1->setGeometry(QRect(QPoint(150,30),QSize(120,20)));
    barButton2->setGeometry(QRect(QPoint(150,60),QSize(120,20)));
    barGroup=new QButtonGroup(this);
    barGroup->addButton(barButton1);
    barGroup->addButton(barButton2);
    connect(barGroup,SIGNAL(buttonClicked(int)),this,SLOT(switchBarValue()));

    //set up scroll bar and connect it with the scroll to methods//
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

/*
 * Get data from a GraphClass object using iterator.
 * Decides types of this object and creates three qvectors that stores the title,
 * value and colors, which will be used to paint the bars.
 * Paint the bar chart dialog
 */
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
    //set up the text on buttons and colors that are used to display the bars//
    if(barTitle.at(0)=="Grant - PR"){
        barButton1->setText("Total Number");
        barButton2->setText("Total Amount");
        this->barValue=value1;
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
        typeNum=4;
    }
    else if(barTitle.at(0)=="Teaching - PME"){
        barButton1->setText("Number of Student");
        barButton2->setText("Number of Teaching Hours");
        this->barValue=value1;
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
        typeNum=4;
    }
    else if(barTitle.at(0)=="Pres - Lectures"){
        barButton1->hide();
        barButton2->hide();
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
        typeNum=4;
    }
    else{
        barButton1->hide();
        barButton2->hide();
        for(int i=0;i<21;i++){
            color.push_back(QColor(qrand()%256,qrand()%256,qrand()%256,255));
        }
        typeNum=21;
    }

    this->barColor=color;
    update();
}

/*
 * SwitchBarValue method is used when either two buttons is clicked
 * and switches the value
 */
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

/*
 * This method is used to set up the page step of the scroll bar.
 * The length of the page step is between 10 and 1000.
 * If x-cordinate(the end point) is smaller than the width of
 * the screen,which is 1000, set the page step to be the width.
 * If the x-cordinate is bigger than 1990, set the page step to be
 * 10.Otherwise, the page step will vary depending on x-cordinate.
 * When the page step has been set up, repaint the dialog
 */
void barchartdialog::scrollTo()
{
    if (xEnd < 0) xEnd = xCordinate;

    cout<< "XEND " << xEnd << "xCOOR " << xCordinate <<endl;
    horizontalBar->setMinimum(0);
    if(xEnd<=1000){
        horizontalBar->setMaximum(1);
        horizontalBar->setPageStep(1000);
    }
    else if(xEnd>=1990){
        horizontalBar->setMaximum(xEnd-990);
        horizontalBar->setPageStep(10);
    }
    else{
        horizontalBar->setMaximum(xEnd-1000);
        horizontalBar->setPageStep(2000-xEnd);
    }

    xOrigin=xOrigin-horizontalBar->value()+temp;
    temp=horizontalBar->value();

    update();
}
/*
 * The bar graph method takes the data from its private attributes,which have already been set up
 * in the setData method, and generates the bar chart by drawing the x-axis,y-axis, bars and the
 * index rectangle.
 * The numbers on the y-axis is set up depending on the biggest number in the qVector object that stores
 * all value.
 */
void barchartdialog::paintEvent(QPaintEvent *parent)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,1));

    int count = barValue.size();
    int space = 20;//space between bars//
    int barWidth = 40;
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
    for(int i = 0;i<typeNum;i++){
        QRect indexRect(760,100+i*20-12,20,20);
        painter.setBrush(barColor[i]);
        painter.drawRect(indexRect);
        painter.drawText(790,100+i*20,QString::fromStdString(barTitle[i]));
    }

    //draw the x,y-axis, the year on x-axis and the bar//


    int i = 0;
    int start=startYear;
    painter.drawLine(xCordinate,yOrigin,xCordinate+space,yOrigin);
    xCordinate +=space;

    while(i<count)
    {
        int previousX = xCordinate;
        int sum=0;
        for(int p=0;p<typeNum;p++)
        {
            if(barValue[i]!=0)
            {
                percent = barValue[i]/yMaxScale;
                barHeight = percent*500;
                QRect barRect(xCordinate,yOrigin-barHeight,barWidth,barHeight);
                painter.setBrush(barColor[i%typeNum]);
                painter.drawRect(barRect);
                painter.drawText(QPoint(xCordinate+10,yOrigin-barHeight-10),QString::number(barValue[i]));
                xCordinate+=barWidth;
                sum+=barValue[i];
            }
                i++;
        }
        if(sum!=0){
            painter.drawText(QPoint((xCordinate-previousX)/2+previousX-28,yOrigin+40),QString::number(start)+"-");
            painter.drawText(QPoint((xCordinate-previousX)/2+previousX,yOrigin+40),QString::number(start+1));
            painter.drawLine(xCordinate,yOrigin,xCordinate+space,yOrigin);
            xCordinate+=space;
        }
        start++;
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





