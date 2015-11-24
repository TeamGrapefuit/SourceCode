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

 yOrigin=10;
 temp=0;

 //Print Button
 printButton = new QPushButton("Print", this);
 printButton->setGeometry(QRect(QPoint(20,550),QSize(120,20)));
 connect(printButton, SIGNAL(pressed()),this,SLOT(printButtonPushed()));

 value1Button = new QRadioButton("",this);
 value2Button = new QRadioButton("",this);
 value1Button->setGeometry(QRect(QPoint(50,400),QSize(120,60)));
 value2Button->setGeometry(QRect(QPoint(180,400),QSize(120,60)));
 buttonGroup=new QButtonGroup(this);
 buttonGroup->addButton(value1Button);
 buttonGroup->addButton(value2Button);
 connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(switchValue()));

 layout = new QHBoxLayout(this);
 verticalBar = new QScrollBar(Qt::Vertical);
 layout->addWidget(verticalBar);

 connect(verticalBar,&QScrollBar::valueChanged,this,&piechart::scrollTo);
 printf("Pie Test");
}

void piechart::printButtonPushed()
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

void piechart::setData(GraphClass *graph,int start,int end)
{
    QVector<int> value1;
    QVector<int> value2;
    QVector<string> title;
    QVector<QColor> color;
    list<list<BarValue> > * readyForGraph = graph->getRange();
    list<list<BarValue> >::iterator i1 = readyForGraph->begin();

    //printf("Pie Test");
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

    if(graphTitle.at(0)=="Grant - PR"){
        value1Button->setText("Total Number");
        value2Button->setText("Total Amount");
        typeNum=4;
    }
    else if(graphTitle.at(0)=="Teaching - PME"){
        value1Button->setText("Total Number of Student");
        value2Button->setText("Total Number of Teaching Hours");
        typeNum=4;
    }
    else if(graphTitle.at(0)=="Pres - Lectures"){
        value1Button->setText("Total Number");
        value2Button->hide();
        typeNum=4;
    }
    else{
        value1Button->setText("Total Number of Publication");
        value2Button->hide();
        typeNum=21;
    }
    repaint();
}

void piechart::scrollTo(){
    printf("Test Pie Scroll");
    int range=yCordinate;
    if(range>600){
        verticalBar->setPageStep(1200-yCordinate);
    }
    else if(range>1190){
        verticalBar->setPageStep(10);
    }

    else{
      verticalBar->setPageStep(600);
    }

    verticalBar->setMinimum(0);
    verticalBar->setMaximum(601-verticalBar->pageStep());

    yOrigin=yOrigin-verticalBar->value()+temp;
    temp=verticalBar->value();

    update();
}


void piechart::switchValue(){
    if(value1Button->isChecked()){
        graphValue=graphValue1;
    }
    else{
        graphValue=graphValue2;
    }

    repaint();
}

void piechart::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QRect size(10,10,280,280);

    int count = graphValue.size();
    double sum = 0,startAng = 0;
    double percent,angle,endAng;

    //draw a white eclipse when there is nothing
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

        //draw the index rectangles

        yCordinate = yOrigin;
        for(int i = 0;i<count;i++){
            if(i%typeNum==0&&i!=0){
                start++;
            }
            if(graphValue[i]!=0){
            painter.setBrush(graphColor[i]);
            painter.drawRect(320,yCordinate,30,20);
            painter.drawText(QPoint(360,yCordinate+12),QString::number(start)+"-");
            painter.drawText(QPoint(390,yCordinate+12),QString::number(start+1));
            painter.drawText(QPoint(430,yCordinate+12),QString::fromStdString(graphTitle[i]));
            yCordinate+=30;
            }
            else{
                continue;
            }
        }

        //draw the pie slices and add the number or amount on the specific slices
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

