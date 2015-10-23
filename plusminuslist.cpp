#include "plusminuslist.h"
#include <iterator>
#include <QString>
#include <QStringList>
#include <iostream>
using namespace std;

PlusMinusList::PlusMinusList(int columns, list<string> * colNames)
{
    rootTree = new QTreeWidget(0);
    rootTree->setColumnCount(columns);
    columnNum = columns;

    list<string>::iterator iterate = colNames->begin();
    QStringList headerlabels;

    while (iterate != colNames->end()){
        QString colTitle = QString::fromUtf8(iterate->c_str());
        headerlabels.push_back(colTitle);
        ++ iterate;
    }

    rootTree->setHeaderLabels(headerlabels);


}

PlusMinusList::~PlusMinusList()
{
    delete rootTree;
}

QTreeWidget * PlusMinusList::getTree()
{
    return rootTree;
}


void PlusMinusList::AddFirstLevelFilter(ListClass * node)
{
    QTreeWidgetItem * treeItem = new QTreeWidgetItem();
    QString name = QString::fromUtf8(node->getName().c_str());
    treeItem->setText(0, name);

    if (node->getParam2() != -1){
        QString num = QString::number(node->getParam2());
        treeItem->setText(columnNum - 1, num);
    }
    if (node->getParam1() != -1){
        QString num = QString::number(node->getParam1());
        if (node->getParam2() != -1){
            treeItem->setText(columnNum - 2, num);
        } else {
            treeItem->setText(columnNum - 1, num);
        }
    }

    rootTree->addTopLevelItem(treeItem);

    if (node->getChildren() != NULL){
        AddSubFilters(treeItem, node->getChildren(), 1);
    }
}

void PlusMinusList::AddSubFilters(QTreeWidgetItem * parent, list<ListClass *> * children, int depth){
    list<ListClass *>::iterator iterate = children->begin();

    while (iterate != children->end()){

        //cout << (*iterate)->getName() << endl;
        QTreeWidgetItem * treeItem = new QTreeWidgetItem(parent);
        QString name = QString::fromUtf8((*iterate)->getName().c_str());

        treeItem->setText(depth, name);

        if ((*iterate)->getParam2() != -1){
            QString num = QString::number((*iterate)->getParam2());
            treeItem->setText(columnNum - 1, num);
        }
        if ((*iterate)->getParam1() != -1){
            QString num = QString::number((*iterate)->getParam1());
            if ((*iterate)->getParam2() != -1){
                treeItem->setText(columnNum - 2, num);
            } else {
                treeItem->setText(columnNum - 1, num);
            }
        }

        if ((*iterate)->getChildren() != NULL){
            AddSubFilters(treeItem, (*iterate)->getChildren(), depth + 1);
        }

        ++iterate;
    }
}
