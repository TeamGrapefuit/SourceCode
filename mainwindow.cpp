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
#include "Pub_ListBuilder.h"
#include "Pres_ListBuilder.h"
#include "Teach_ListBuilder.h"
#include "barchartdialog.h"
#include "piechartdialog.h"
#include "QFileDialog"

#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H
#include "graphclass.h"
#endif

//Method declaration
using namespace std;
void on_pushButton_clicked();
void on_spinBox_valueChanged(int arg1);

//The int value from date scroll box 1 and 2
int date1 = 2010;
int date2 = 2015;
GraphClass * test;
//The string value from the name box
string nameFirst = "temp";
string nameLast = "temp";
string nameFull = "temp";

multimap<string, Grant_rowObject>* databaseGrant;
multimap<string, Teach_rowObject>* databaseTeach;
multimap<string, Pub_rowObject>* databasePub;
multimap<string, Pres_rowObject>* databasePres;
QString filename;
int databaseTest = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Grape Fruit Project");

//    QWidget *widget1 = new QWidget();

//    widget1->setFixedHeight(5);

//    QHBoxLayout * top = new QHBoxLayout();
//    test = NULL;
//    //Director
////    multimap<string, Grant_rowObject> * database = new multimap<string, Grant_rowObject>();
////   Grant_rowObject * a = new Grant_rowObject("A", "Domain", 2011, 2012, "Grants", "Received", true, false, "Role", "Title", "apInvestigator", "acpInvestigator",  1);
////   Grant_rowObject * b = new Grant_rowObject("B", "Domain", 2011, 2012, "Clinical Trials", "Received", false, true, "Role", "Title", "apInvestigator", "acpInvestigator",  2);
////   Grant_rowObject * c = new Grant_rowObject("C", "Domain", 2012, 2013, "Grants", "Received", false, true, "Role", "Title", "apInvestigator", "acpInvestigator",  3);
////   Grant_rowObject * d = new Grant_rowObject("D", "Domain", 2012, 2013, "Clinical Trials", "Received", true, false, "Role", "Title", "apInvestigator", "acpInvestigator",  4);
////   Grant_rowObject * e = new Grant_rowObject("E", "Domain", 2013, 2014, "Grants", "Received", true, false, "Role", "Title", "apInvestigator", "acpInvestigator",  5);

////   database->insert(pair<string, Grant_rowObject>(a->name, *a));
////   database->insert(pair<string, Grant_rowObject>(b->name, *b));
////   database->insert(pair<string, Grant_rowObject>(c->name, *c));
////   database->insert(pair<string, Grant_rowObject>(d->name, *d));
////   database->insert(pair<string, Grant_rowObject>(e->name, *e));
//    //database = BuildGrants("Grants_changed.csv");
//    std::string stringFilename = filename.toUtf8().constData();

//    database = BuildGrants(stringFilename);
//    multimap<string, Grant_rowObject>::iterator i = database->begin();

//    ListBuilder * lb = new ListBuilder(2000, 2025, database);
//    lb->scanMap();
//    //lb->printList(lb->peerreviewed_grants);
//    ListClass * grants = new ListClass("Grants", lb->grants.param1, lb->grants.param2, true);
//    grants->addChild(&lb->peerreviewed_grants);
//    grants->addChild(&lb->industrygrant_grants);

//    ListClass * clinfund = new ListClass("Clinical Funding", lb->clinicalfunding.param1, lb->clinicalfunding.param2, true);
//    clinfund->addChild(&lb->peerreviewed_cf);
//    clinfund->addChild(&lb->industrygrant_cf);

//    //lb->printList(lb->industrygrant_cf);
//    //Column Names
//    list<string> * test = new list<string>();
//    test->push_back("");
//    test->push_back("");
//    test->push_back("");
//    test->push_back("Total #");
//    test->push_back("Total $");

////    ListClass * c1r1 = new ListClass("C1 R1", 5, -1, true);
////    ListClass * c1r2 = new ListClass("C1 R2", 5, -1, true);
////    ListClass * c2r1 = new ListClass("C2 R1", 2, -1, false);
////    ListClass * c2r2 = new ListClass("C2 R2", 2, -1, false);

////    c1r1->addChild(c2r1);
////    c1r1->addChild(c2r2);
////    c1r2->addChild(c2r1);

//    PlusMinusList * plusminus = new PlusMinusList(test->size(), test);
//    plusminus->AddFirstLevelFilter(grants);
//    plusminus->AddFirstLevelFilter(clinfund);
//    top->addWidget(plusminus->getTree());

//    QVBoxLayout * mainLayout = new QVBoxLayout(this);
//    mainLayout->addSpacing(20);
//    mainLayout->addLayout(top);


//    this->centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * input:
 * output: void
 * This creates the barchart dialog when button is pressed on main window
 */
void MainWindow::on_pushButton_clicked()
{    
    if(nameFirst == "temp")
    {
        statusBar()->showMessage("No First Name", 2000);
    }
    else if(nameLast == "temp")
    {
        statusBar()->showMessage("No Last Name", 2000);
    }
    else if(databaseTest == 1)
    {
        nameFull = nameLast + ", " + nameFirst;
        cout << nameFull << endl;
        //GraphClass * test = new GraphClass(date1, date2, "Strangelove, Dr.", database);
        GraphClass * test = new GraphClass(date1, date2, nameFull, databaseGrant);
        barchartdialog *chart = new barchartdialog();
        chart->setData(test,date1,date2);
        chart->show();
    }
    else if(databaseTest == 2)
    {
        nameFull = nameLast + ", " + nameFirst;
        cout << nameFull << endl;
        //GraphClass * test = new GraphClass(date1, date2, "Strangelove, Dr.", database);
        GraphClass * test = new GraphClass(date1, date2, nameFull, databaseTeach);
        barchartdialog *chart = new barchartdialog();
        chart->setData(test,date1,date2);
        chart->show();
    }
    else if(databaseTest == 3)
    {
        nameFull = nameLast + ", " + nameFirst;
        cout << nameFull << endl;
        //GraphClass * test = new GraphClass(date1, date2, "Strangelove, Dr.", database);
        GraphClass * test = new GraphClass(date1, date2, nameFull, databasePres);
        barchartdialog *chart = new barchartdialog();
        chart->setData(test,date1,date2);
        chart->show();
    }
    else if(databaseTest == 4)
    {
        nameFull = nameLast + ", " + nameFirst;
        cout << nameFull << endl;
        //GraphClass * test = new GraphClass(date1, date2, "Strangelove, Dr.", database);
        GraphClass * test = new GraphClass(date1, date2, nameFull, databasePub);
        barchartdialog *chart = new barchartdialog();
        chart->setData(test,date1,date2);
        chart->show();
    }
}

/**
 * input:
 * output: void
 * This creates the piechart dialog when button pressed on main window
 */
void MainWindow::on_pushButton_2_clicked()
{
    cout << databaseTest << endl;

    if(nameFirst == "temp")
    {
        statusBar()->showMessage("No First Name", 2000);
    }
    else if(nameLast == "temp")
    {
        statusBar()->showMessage("No Last Name", 2000);
    }
    else if(databaseTest == 1)
    {
        nameFull = nameLast + ", " + nameFirst;
        GraphClass * test = new GraphClass(date1, date2, nameFull, databaseGrant);
        piechart *chart = new piechart();
        chart->setData(test,date1,date2);
        chart->show();
    }
    else if(databaseTest == 2)
    {
        nameFull = nameLast + ", " + nameFirst;
        GraphClass * test = new GraphClass(date1, date2, nameFull, databaseTeach);
        piechart *chart = new piechart();
        chart->setData(test,date1,date2);
        chart->show();
    }
    else if(databaseTest == 3)
    {
        cout << "pietest" << endl;
        nameFull = nameLast + ", " + nameFirst;
        GraphClass * test = new GraphClass(date1, date2, nameFull, databasePres);
        piechart *chart = new piechart();
        chart->setData(test,date1,date2);
        chart->show();
    }
    else if(databaseTest == 4)
    {
        nameFull = nameLast + ", " + nameFirst;
        GraphClass * test = new GraphClass(date1, date2, nameFull, databasePub);
        piechart *chart = new piechart();
        chart->setData(test,date1,date2);
        chart->show();
    }
}

/**
  input: integer value of starting date
  output: void
  This takes value in starting date box and sets it to global variable date1
**/
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    date1 = arg1;
}

/**
  input: integer value of ending date
  output: void
  This takes value in ending date box and sets it to global variable date2
**/
void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    date2 = arg1;
}
//input: QString from name box on screen
//Output: Void
//This takes the string inside the name box on the main window and assigns it to the name variable
int i;
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    nameFirst = arg1.toStdString();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    nameLast = arg1.toStdString();
}

void MainWindow::on_actionOpen_File_triggered()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("CSV Files (*.csv)")); // Opens dialog box allowing user to find csv file
    statusBar()->showMessage("File Loaded", 2000);

    csvBuild();

//    MainWindow object;
//    object.update();
}

void MainWindow::showGrants()
{
    databaseGrant = getGrants();
    multimap<string, Grant_rowObject>::iterator i = databaseGrant->begin();

    QWidget *widget1 = new QWidget();

    widget1->setFixedHeight(5);

    QHBoxLayout * top = new QHBoxLayout();
    test = NULL;

    /*
     * THIS IS WHERE THE IF STATEMENTS WERE
     *
     *
     *
    */
    ListBuilder * lb = new ListBuilder(2000, 2025, databaseGrant);
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
    test->push_back("Names");
    test->push_back("Total #");
    test->push_back("Total $");

    PlusMinusList * plusminus = new PlusMinusList(test->size(), test);
    plusminus->AddFirstLevelFilter(grants);
    plusminus->AddFirstLevelFilter(clinfund);
    top->addWidget(plusminus->getTree());

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(top);


    this->centralWidget()->setLayout(mainLayout);
}

void MainWindow::showTeach()
{
    databaseTeach = getTeachings();
    multimap<string, Teach_rowObject>::iterator i = databaseTeach->begin();
//    while (i != databasePres->end()){
//        cout << i->second.name << endl;
//        ++ i;
//    }
    QWidget *widget1 = new QWidget();

    widget1->setFixedHeight(5);

    QHBoxLayout * top = new QHBoxLayout();
    test = NULL;

    /*
     * THIS IS WHERE THE IF STATEMENTS WERE
     *
     *
     *
    */
    Teach_ListBuilder  lb = Teach_ListBuilder(2000, 2025, databaseTeach);
    lb.scanMap();

    //lb->printList(lb->peerreviewed_grants);
//    ListClass * i_l = new ListClass("Invited Lectures", lb->i_l->param1, lb->i_l->param2, true);
//    i_l->addChild(lb->i_l);
//    ListClass * a_p = new ListClass("Abtracts Presented", lb->a_p->param1, lb->a_p->param2, true);
   // ListClass * c_p = new ListClass("Conference Presentations", lb->)

    //Column Names
    list<string> * test = new list<string>();
    test->push_back("");
    test->push_back("Academic Year");
    test->push_back("Faculty");
    test->push_back("Hours");
    test->push_back("Students");

    //lb.printList(*lb.cme);

    PlusMinusList * plusminus = new PlusMinusList(test->size(), test);
    plusminus->AddFirstLevelFilter(&lb.cme);
    plusminus->AddFirstLevelFilter(&lb.pme);
    plusminus->AddFirstLevelFilter(&lb.ume);
    plusminus->AddFirstLevelFilter(&lb.other);
    top->addWidget(plusminus->getTree());

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(top);


    this->centralWidget()->setLayout(mainLayout);

}

void MainWindow::showPres()
{
    //cout << "Test showPres" << endl;

    databasePres = getPresentations();
    multimap<string, Pres_rowObject>::iterator i = databasePres->begin();
    while (i != databasePres->end()){
        cout << i->second.name << endl;
        ++ i;
    }
    QWidget *widget1 = new QWidget();

    widget1->setFixedHeight(5);

    QHBoxLayout * top = new QHBoxLayout();
    test = NULL;

    /*
     * THIS IS WHERE THE IF STATEMENTS WERE
     *
     *
     *
    */
    Pres_ListBuilder  lb = Pres_ListBuilder(2000, 2025, databasePres);
    lb.scanMap();

    //lb->printList(lb->peerreviewed_grants);
//    ListClass * i_l = new ListClass("Invited Lectures", lb->i_l->param1, lb->i_l->param2, true);
//    i_l->addChild(lb->i_l);
//    ListClass * a_p = new ListClass("Abtracts Presented", lb->a_p->param1, lb->a_p->param2, true);
   // ListClass * c_p = new ListClass("Conference Presentations", lb->)

    //Column Names
    list<string> * test = new list<string>();
    test->push_back("");
    test->push_back("Faculty Name");
    test->push_back("# of Presentations");

    lb.printList(*lb.a_p);

    PlusMinusList * plusminus = new PlusMinusList(test->size(), test);
    plusminus->AddFirstLevelFilter(lb.i_l);
    plusminus->AddFirstLevelFilter(lb.a_p);
    plusminus->AddFirstLevelFilter(lb.c_p);
    top->addWidget(plusminus->getTree());

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(top);


    this->centralWidget()->setLayout(mainLayout);
}

void MainWindow::showPub()
{
    //cout << "Test showPub" << endl;

    //cout << "Test showPres" << endl;

    databasePub = getPublications();
//    multimap<string, Pub_rowObject>::iterator i = databasePub->begin();
//    while (i != databasePub->end()){
//        cout << i->second.name << endl;
//        ++ i;
//    }
    QWidget *widget1 = new QWidget();

    widget1->setFixedHeight(5);

    QHBoxLayout * top = new QHBoxLayout();
    test = NULL;

    /*
     * THIS IS WHERE THE IF STATEMENTS WERE
     *
     *
     *
    */
    cout << databasePub->size() << endl;
    Pub_ListBuilder  lb = Pub_ListBuilder(2000, 2025, databasePub);
    lb.scanMap();

    //lb->printList(lb->peerreviewed_grants);
//    ListClass * i_l = new ListClass("Invited Lectures", lb->i_l->param1, lb->i_l->param2, true);
//    i_l->addChild(lb->i_l);
//    ListClass * a_p = new ListClass("Abtracts Presented", lb->a_p->param1, lb->a_p->param2, true);
   // ListClass * c_p = new ListClass("Conference Presentations", lb->)

    //Column Names
    list<string> * test = new list<string>();
    test->push_back("");
    test->push_back("");
    test->push_back("Faculty Name");
    test->push_back("Total");

//    lb.printList(*lb.Pubs);

    PlusMinusList * plusminus = new PlusMinusList(test->size(), test);
    plusminus->AddFirstLevelFilter(&lb.Pubs);
    top->addWidget(plusminus->getTree());
    lb.printList(lb.Pubs);
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(top);


    this->centralWidget()->setLayout(mainLayout);
}

/**
 * input:
 * output: void
 * This creates the grants plus minus list using the file the user points to in his/her computer by the file>newfile button
 */
void MainWindow::csvBuild()
{
    std::string stringFilename = filename.toUtf8().constData();

    //database = BuildGrants(stringFilename);

    int testBuild = Build(stringFilename);

//    date1 = getDatesGrants().first;
//    date2 = getDatesGrants().second;

//    if (date1 == -666)
//    {
//        date1 = 1900;
//    }

//    cout << date1 << endl;
//    cout << date2 << endl;

    if (testBuild == 0)
    {
        cout << "Incorrect file type" << endl;
        databaseTest = 0;
    }
    else if (testBuild == 1)
    {
        showGrants();
        databaseTest = 1;
    }
    else if (testBuild == 2)
    {
       showTeach();
       databaseTest = 2;
    }
    else if (testBuild == 3)
    {
        showPres();
        databaseTest = 3;
    }
    else if (testBuild == 4)
    {
        showPub();
        databaseTest = 4;
    }
}
