#include "barchartdialog.h"
#include <iterator>
#include <QPen>
#include <qpainter.h>
#include <qradiobutton.h>

/*
 * Constructor
 * Set up the title, window size, postions of two buttons
 * and positions of layout
 */

barchartdialog::barchartdialog(QWidget *parent) : QWidget(parent)
{
    //set the title and size of the dialog//
    setWindowTitle("Bar Chart");
    setFixedSize(1000,800);
    //set up the cordinate of the origin on x-axis to be 50 and the previous scroll bar value to be 0//
    xOrigin=50;
    temp=0;

    //set up the postions of two buttons and add them into a button group//
    barButton1 = new QRadioButton("",this);
    barButton2 = new QRadioButton("",this);
    barButton1->setGeometry(QRect(QPoint(150,30),QSize(120,20)));
    barButton2->setGeometry(QRect(QPoint(150,60),QSize(120,20)));
    barGroup=new QButtonGroup(this);
    barGroup->addButton(barButton1);
    barGroup->addButton(barButton2);
    connect(barGroup,SIGNAL(buttonClicked(int)),this,SLOT(switchBarValue()));

    //set up the default scroll bar//
    layout = new QVBoxLayout(this);
    horizontalBar = new QScrollBar(Qt::Horizontal);
    layout->addStretch();
    layout->addWidget(horizontalBar);
    connect(horizontalBar,&QScrollBar::valueChanged,this,&barchartdialog::scrollTo);

}

/*
 * SetData method is used to get the data from a graphclass object and
 * Get data from a graphclass object which contains a row object
 * Determine the type of the row object
 * Set up the buttons and creates a QVector that stores the colors which is used to display bars
 * Repaint the bar chart
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
        barButton1->setText("Total Number of Student");
        barButton2->setText("Total Number of Teaching Hours");
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
        typeNum=4;
    }
    else if(barTitle.at(0)=="Pres - Lectures"){
        barButton1->setText("Total Number");
        barButton2->hide();
        for(int i=0;i<21;i++){
            color.push_back(QColor(qrand()%256,qrand()%256,qrand()%256,255));
        }
        typeNum=4;
    }
    else{
        barButton1->setText("Total Number of Publication");
        barButton2->hide();
        color.push_back(QColor(Qt::red));
        color.push_back(QColor(Qt::yellow));
        color.push_back(QColor(Qt::green));
        color.push_back(QColor(Qt::blue));
        typeNum=21;
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

/*
 * ScrollTo method is used to set up scroll bar when users move it
 * If the range of the scroll baris longer than 800, which is the width of the dialog,
 * set the page step to be 1600 minus the cordinate of the last bar, so
 */
void barchartdialog::scrollTo(){
    int range=xCordinate-xOrigin;

    cout<<"123"<<endl;
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

    //draw the index rectangle//
    for(int i = 0;i<4;i++){
        QRect indexRect(870,100+i*20,20,20);
        painter.setBrush(barColor[i]);
        painter.drawRect(indexRect);
        painter.drawText(900,100+i*26,QString::fromStdString(barTitle[i]));
    }

    //draw the x-axis,the year on x-axis and the bar//
    int i = 0;
    int start=startYear;

    while(i<count)
    {
        painter.drawLine(xCordinate,yOrigin,xCordinate+space,yOrigin);
        xCordinate += space;

        int sum =0;

        for(int p=0;p<typeNum;p++){
            percent = barValue[i]/yMaxScale;
            barHeight = percent*500;
            painter.drawLine(xCordinate,yOrigin,xCordinate+barWidth,yOrigin);
            QRect barRect(xCordinate,yOrigin-barHeight,barWidth,barHeight);
            painter.setBrush(barColor[i%typeNum]);
            painter.drawRect(barRect);
            sum+=barValue[i];
            if(barValue[i]!=0)
            {
                painter.drawText(QPoint(xCordinate+5,yOrigin-barHeight-10),QString::number(barValue[i]));
            }
            xCordinate+=barWidth;
            i++;
        }
        if(sum==0){
            xCordinate = xCordinate-space-barWidth*typeNum;
        }
        else{
            painter.drawText(QPoint(xCordinate-typeNum*barWidth/4*3,yOrigin+40),QString::number(start)+"-");
            painter.drawText(QPoint(xCordinate-typeNum*barWidth/4*3+30,yOrigin+40),QString::number(start+1));
        }
        start++;
    }

    //draw y-axis and the numbers on y-axis//
    painter.drawLine(xOrigin,yOrigin,xOrigin,100);
    int temp1 = yMaxScale/yScaleNum;
    for(int i = 0;i<yScaleNum;i++)
    {
        painter.drawText(QPoint(xOrigin-30,yOrigin-yAxisLength/yScaleNum*i),QString::number(temp1*i));

    }
    painter.drawText(QPoint(xOrigin-30,100),QString::number(yMaxScale));
}



