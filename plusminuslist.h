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
    int columnNum;
    QTreeWidget * rootTree;

public:
    explicit PlusMinusList(int columns, list<string> * colNames);
    ~PlusMinusList();
    void AddFirstLevelFilter(ListClass * node);
    void AddSubFilters(QTreeWidgetItem * parent, list<ListClass *> * children, int depth);
    QTreeWidget * getTree();

signals:

public slots:
};

#endif // PLUSMINUSLIST_H
