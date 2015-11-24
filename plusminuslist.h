/*
    Team Grapefruit
    Oct 26th/2015
    This file contains the implementation of a class
    which builds a tree to display data from any of the
    4 files.
*/
#ifndef PLUSMINUSLIST_H
#define PLUSMINUSLIST_H
#pragma once
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <list>
#include <QTreeWidget>

#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "listclass.h"
#endif

class PlusMinusList
{
    int columnNum;				//Number of columns to be used in the tree
    QTreeWidget * rootTree;		//Tree that is created

public:
    explicit PlusMinusList(int columns, list<string> * colNames);							//Constructor
    ~PlusMinusList();																		//Destructor
    void AddFirstLevelFilter(ListClass * node);												//Adds a highlevel tier to the tree
    void AddSubFilters(QTreeWidgetItem * parent, list<ListClass *> * children, int depth);	//Adss a sublevel to a given high level
    QTreeWidget * getTree();																//Returns the created tree

signals:

public slots:
};

#endif // PLUSMINUSLIST_H
