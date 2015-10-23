#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plusminuslist.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <list>
#include <string>
#include <QMenuBar>
#include "graphdialog.h"
#include <QApplication>
#include <iostream>
#include <iterator>
#include "Director.h"
#include "ListBuilder.h"
//#include "graph.h"

using namespace std;
void on_pushButton_clicked();
void on_spinBox_valueChanged(int arg1);

//The int value from date scroll box 1 and 2
int date1, date2;
//The string value from the name box
string name;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Grape Fruit Project");

    QWidget *widget1 = new QWidget();

    widget1->setFixedHeight(5);

    QHBoxLayout * top = new QHBoxLayout();

    //Director
    multimap<string, Grant_rowObject>* database = BuildGrants("Grants_changed.csv");
    multimap<string, Grant_rowObject>::iterator i = database->begin();

    ListBuilder * lb = new ListBuilder(2005, 2016, database);
    lb->scanMap();
    lb->printList(lb->peerreviewed_grants);
    ListClass * grants = new ListClass("Grants", lb->grants.param1, lb->grants.param2, true);
    grants->addChild(&lb->peerreviewed_grants);
    grants->addChild(&lb->industrygrant_grants);

    ListClass * clinfund = new ListClass("Clinical Funding", lb->clinicalfunding.param1, lb->clinicalfunding.param2, true);
    clinfund->addChild(&lb->peerreviewed_cf);
    clinfund->addChild(&lb->industrygrant_cf);

    lb->printList(lb->grants);
    //Column Names
    list<string> * test = new list<string>();
    test->push_back("");
    test->push_back("");
    test->push_back("Total #");
    test->push_back("Total $");

//    ListClass * c1r1 = new ListClass("C1 R1", 5, -1, true);
//    ListClass * c1r2 = new ListClass("C1 R2", 5, -1, true);
//    ListClass * c2r1 = new ListClass("C2 R1", 2, -1, false);
//    ListClass * c2r2 = new ListClass("C2 R2", 2, -1, false);

//    c1r1->addChild(c2r1);
//    c1r1->addChild(c2r2);
//    c1r2->addChild(c2r1);

    PlusMinusList * plusminus = new PlusMinusList(test->size(), test);
    plusminus->AddFirstLevelFilter(grants);
    plusminus->AddFirstLevelFilter(clinfund);
    top->addWidget(plusminus->getTree());

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(top);


    this->centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Graph button action. Pressing graph button makes this happen
void MainWindow::on_pushButton_clicked()
{
    GraphDialog *newDialog = new GraphDialog();

    if(date1 < date2)
    {
        newDialog->show();
        newDialog->raise();
        newDialog->activateWindow();

    }
    else
    {
        cout << "Your dates are not correct" << endl;
    }
}
//This takes value in first date box and sets it to global variable
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    date1 = arg1;
}

//This takes value in second date box and sets it to global variable
void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    date2 = arg1;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    name = arg1.toStdString();
}
