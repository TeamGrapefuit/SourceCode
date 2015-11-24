#ifndef BARCHARTDIALOG_H
#define BARCHARTDIALOG_H

#include <QWidget>
#include <grant_rowobject.h>
#include <graphclass.h>
#include <QPainter>
#include <QRadioButton>
#include <QButtonGroup>
#include <QScrollBar>
#include <QVBoxLayout>

#include <QPushButton>
#include <QPrinter>
#include <QPrintDialog>

/*
 * barchartdialog is used to get data from a graphclass object
 * and paint a bar chart based on the data
 */

class barchartdialog : public QWidget
{
    Q_OBJECT

private:
    int startYear,endYear;
    QVector<int> barValue1;//qvector that stores the number of people//
    QVector<int> barValue2;//qvector that stores the amount
    QVector<int> barValue;//qvector that stores the value which will be showed on the dialog//
    QVector<string> barTitle;//title//
    QVector<QColor> barColor;//color of the bars//

    QRadioButton *barButton1;//button that switch to total number//
    QRadioButton *barButton2;//button that switch to total amount//
    QButtonGroup *barGroup;//button group that contains button 1 and 2//

    QPushButton *printButton;//Button to print

    QScrollBar *horizontalBar;//horizontal bar//
    QVBoxLayout *layout;//layout that contains the scroll bar//

    int xOrigin;//the cordinate of the origin//
    int xCordinate;//used to store the cordinate when each bar is painted//
    int temp;//previous scroll bar value//
    int typeNum;//number of types

public:
    explicit barchartdialog(QWidget *parent = 0);

    void setData(GraphClass *graph, int start, int end);

    void paintEvent(QPaintEvent *parent);

signals:

private slots:
    void printButtonPushed();
    void switchBarValue();

    void scrollTo();

public slots:
};

#endif // BARCHARTDIALOG_H
