#include <QtGui>
#include <iterator>
#include <stdlib.h>
#include <qradiobutton.h>
#include "piechartdialog.h"
#include <iostream>
#include <math.h>

piechart::piechart(QWidget *parent) : QWidget(parent)
{
 setWindowTitle("Pie Chart");
 setFixedSize(600,600);

 value1Button = new QRadioButton("Total Number",this);
 value2Button = new QRadioButton("Total Amount",this);
 value1Button->setGeometry(QRect(QPoint(50,400),QSize(120,60)));
 value2Button->setGeometry(QRect(QPoint(180,400),QSize(120,60)));
 buttonGroup=new QButtonGroup(this);
 buttonGroup->addButton(value1Button);
 buttonGroup->addButton(value2Button);
 connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(switchValue()));
}

void piechart::setData(GraphClass *graph,int start,int end)
{
    QVector<int> value1;
    QVector<int> value2;
    QVector<string> title;
    QVector<QColor> color;
    list<list<BarValue> > * readyForGraph = graph->getRange();
    list<list<BarValue> >::iterator i1 = readyForGraph->begin();

    while (i1 != readyForGraph->end()) {
        list<BarValue>::iterator i2 = i1->begin();
        while (i2 != i1->end()) {
            title.push_back(i2->title);
            value1.push_back(i2->yValue1);
            value2.push_back(i2->yValue2);
            color.push_back(QColor(qrand()%256,qrand()%256,qrand()%256,255));
            ++ i2;
        }
        ++ i1;
    }

    this->startDate = start;
    this->endDate = end;
    this->graphValue1=value1;
    this->graphValue2=value2;
    this->graphTitle=title;
    this->graphColor=color;
    graphValue=graphValue1;
    update();
    repaint();
}

void piechart::switchValue(){
    if(value1Button->isChecked()){
        graphValue=graphValue1;
    }
    else{
        graphValue=graphValue2;
    }
    update();
    repaint();
}

void piechart::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QRect size(10,10,280,280);

    int y = 10;
    int count = graphValue.size();
    double sum = 0,startAng = 0;
    double percent,angle,endAng;

    if(count==0){
        painter.setBrush(Qt::white);
        painter.drawPie(size,360,5760);
    }

    else{
        for(int i = 0; i<count;i++){
        sum+=graphValue[i];
        }

        painter.setPen(QPen(Qt::black,1));

        int start = startDate;
        for(int i = 0;i<count;i++){
            if(i%4==0&&i!=0){
                start++;
            }
            painter.setBrush(graphColor[i]);
            painter.drawRect(320,y,30,20);
            painter.drawText(QPoint(360,y+12),QString::number(start)+"-");
            painter.drawText(QPoint(390,y+12),QString::number(start+1));
            painter.drawText(QPoint(430,y+12),QString::fromStdString(graphTitle[i]));
            y+=30;

        }

        for(int i = 0;i<count;i++)
        {
            if(graphValue[i]!=0)
            {
            percent = graphValue[i]/sum;
            angle = 360*percent;
            endAng = startAng + angle;
            painter.setBrush(graphColor[i]);
            painter.drawPie(size,startAng*16,angle*16);
            painter.drawText(QPoint(150+cos((startAng+angle/2)*3.14/180)*70,150-sin((startAng+angle/2)*3.14/180)*70),QString::number(percent*100)+"%");
            startAng = endAng;
            }
        }
    }
}

