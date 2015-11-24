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


class barchartdialog : public QWidget
{
    Q_OBJECT

private:
    int startYear,endYear;
    QVector<int> barValue1;//vector that stores the number of people//
    QVector<int> barValue2;//vector that stores the amount
    QVector<int> barValue;//vector that stores the current value which will be showed on the dialog//
    QVector<string> barTitle;//title//
    QVector<QColor> barColor;//color of the bars//

    QPushButton *printButton;//Button to print

    QRadioButton *barButton1;//button that switch to total number//
    QRadioButton *barButton2;//button that switch to total amount//
    QButtonGroup *barGroup;//button group that contains button 1 and 2//

    QScrollBar *horizontalBar;//horizontal bar//
    QVBoxLayout *layout;

    int xOrigin;
    int xCordinate;
    int temp;//previous scroll bar value//
    int typeNum;//number of types

public:
    explicit barchartdialog(QWidget *parent = 0);

    void setData(GraphClass *graph, int start, int end);

    void paintEvent(QPaintEvent *parent);

signals:

private slots:
    void switchBarValue();

    void printButtonPushed();

    void scrollTo();

public slots:
};

#endif // BARCHARTDIALOG_H
