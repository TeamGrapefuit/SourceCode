#ifndef BARCHARTDIALOG_H
#define BARCHARTDIALOG_H

#include <QWidget>
#include <grant_rowobject.h>

#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H
#include "graphclass.h"
#endif

#include <QPainter>
#include <QRadioButton>
#include <QButtonGroup>


class barchartdialog : public QWidget
{
    Q_OBJECT

private:
    int startYear,endYear;
    QVector<int> barValue1;
    QVector<int> barValue2;
    QVector<int> barValue;
    QVector<string> barTitle;
    QVector<QColor> barColor;

    QRadioButton *barButton1;
    QRadioButton *barButton2;
    QButtonGroup *barGroup;



public:
    explicit barchartdialog(QWidget *parent = 0);
    void setData(GraphClass *graph, int start, int end);
    void paintEvent(QPaintEvent *parent);

signals:

private slots:
    void switchBarValue();

public slots:
};

#endif // BARCHARTDIALOG_H
