#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H
#include "graphclass.h"
#endif

#include <QMainWindow>
#include "graphdialog.h"
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
#include "QMessageBox"
#include <queue>

#define DATABASEGRANT 1
#define DATABASETEACH 2
#define DATABASEPRES 3
#define DATABASEPUB 4

using namespace std;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    int date1 = 2013;
    int date2 = 2015;
    int databaseTest = 0;

    GraphClass * test;

    string nameFirst = "";
    string nameLast = "";
    string nameFull = "";

    multimap<string, Grant_rowObject>* databaseGrant;
    multimap<string, Teach_rowObject>* databaseTeach;
    multimap<string, Pub_rowObject>* databasePub;
    multimap<string, Pres_rowObject>* databasePres;
    QString filename;

    queue<pair<int, Grant_rowObject> > granterror;

    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_actionOpen_File_triggered();

    void csvBuild();

    void showGrants();

    void showTeach();

    void showPres();

    void showPub();

    void on_actionPrint_triggered();

    void on_actionExit_2_triggered();

    void on_actionPie_Graph_triggered();

    void on_actionBar_Graph_triggered();

    void on_actionView_Errors_triggered();

private:
    Ui::MainWindow *ui;

    GraphDialog *newDialog;
};

#endif // MAINWINDOW_H
