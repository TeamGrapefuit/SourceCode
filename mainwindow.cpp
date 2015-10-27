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
#include "barchartdialog.h"
#include "piechartdialog.h"

#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H
#include "graphclass.h"
#endif

//#include "graph.h"

using namespace std;
void on_pushButton_clicked();
void on_spinBox_valueChanged(int arg1);

//The int value from date scroll box 1 and 2
int date1 = 2010;
int date2 = 2015;
GraphClass * test;
//The string value from the name box
string name;
multimap<string, Grant_rowObject>* database;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Grape Fruit Project");

    QWidget *widget1 = new QWidget();

    widget1->setFixedHeight(5);

    QHBoxLayout * top = new QHBoxLayout();
    test = NULL;
    //Director
//    multimap<string, Grant_rowObject> * database = new multimap<string, Grant_rowObject>();
//   Grant_rowObject * a = new Grant_rowObject("A", "Domain", 2011, 2012, "Grants", "Received", true, false, "Role", "Title", "apInvestigator", "acpInvestigator",  1);
//   Grant_rowObject * b = new Grant_rowObject("B", "Domain", 2011, 2012, "Clinical Trials", "Received", false, true, "Role", "Title", "apInvestigator", "acpInvestigator",  2);
//   Grant_rowObject * c = new Grant_rowObject("C", "Domain", 2012, 2013, "Grants", "Received", false, true, "Role", "Title", "apInvestigator", "acpInvestigator",  3);
//   Grant_rowObject * d = new Grant_rowObject("D", "Domain", 2012, 2013, "Clinical Trials", "Received", true, false, "Role", "Title", "apInvestigator", "acpInvestigator",  4);
//   Grant_rowObject * e = new Grant_rowObject("E", "Domain", 2013, 2014, "Grants", "Received", true, false, "Role", "Title", "apInvestigator", "acpInvestigator",  5);

//   database->insert(pair<string, Grant_rowObject>(a->name, *a));
//   database->insert(pair<string, Grant_rowObject>(b->name, *b));
//   database->insert(pair<string, Grant_rowObject>(c->name, *c));
//   database->insert(pair<string, Grant_rowObject>(d->name, *d));
//   database->insert(pair<string, Grant_rowObject>(e->name, *e));
    database = BuildGrants("Grants_changed.csv");
    multimap<string, Grant_rowObject>::iterator i = database->begin();

    ListBuilder * lb = new ListBuilder(2000, 2025, database);
    lb->scanMap();
    //lb->printList(lb->peerreviewed_grants);
    ListClass * grants = new ListClass("Grants", lb->grants.param1, lb->grants.param2, true);
    grants->addChild(&lb->peerreviewed_grants);
    grants->addChild(&lb->industrygrant_grants);

    ListClass * clinfund = new ListClass("Clinical Funding", lb->clinicalfunding.param1, lb->clinicalfunding.param2, true);
    clinfund->addChild(&lb->peerreviewed_cf);
    clinfund->addChild(&lb->industrygrant_cf);

    //lb->printList(lb->industrygrant_cf);
    //Column Names
    list<string> * test = new list<string>();
    test->push_back("");
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
    GraphClass * test = new GraphClass(date1, date2, "Strangelove, Dr.", database);
    barchartdialog *chart = new barchartdialog();
    chart->setData(test,date1,date2);
    chart->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    GraphClass * test = new GraphClass(date1, date2, "Strangelove, Dr.", database);
    piechart *chart = new piechart();
    chart->setData(test,date1,date2);
    chart->show();
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
