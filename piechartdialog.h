#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <grant_rowobject.h>
#include <graphclass.h>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

using namespace std;

class piechart : public QWidget
{
    Q_OBJECT

private:
    QVector<int> graphValue1;
    QVector<int> graphValue2;
    QVector<string> graphTitle;
    QVector<QColor> graphColor;
    QVector<int> graphValue;

    int startDate, endDate;

    QRadioButton *value1Button;
    QRadioButton *value2Button;
    QButtonGroup *buttonGroup;



public:

    explicit piechart(QWidget *parent = 0);
    void setData(GraphClass *graph, int start, int end);
    void paintEvent(QPaintEvent * event);



signals:

private slots:
    void switchValue();

public slots:
};

#endif // PIECHART_H
