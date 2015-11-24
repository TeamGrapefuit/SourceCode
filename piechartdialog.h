#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <grant_rowobject.h>
#include <graphclass.h>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QScrollBar>

#include <QPushButton>
#include <QPrinter>
#include <QPrintDialog>

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

    QPushButton *printButton;//Button to print

    int startDate, endDate;

    int yOrigin;
    int yCordinate;
    int temp;
    int typeNum;

    QRadioButton *value1Button;
    QRadioButton *value2Button;
    QButtonGroup *buttonGroup;

    QScrollBar *verticalBar;
    QHBoxLayout *layout;



public:

    explicit piechart(QWidget *parent = 0);
    void setData(GraphClass *graph, int start, int end);
    void paintEvent(QPaintEvent * event);

    void scrollTo();



signals:

private slots:
    void switchValue();

    void printButtonPushed();

public slots:
};

#endif // PIECHART_H
