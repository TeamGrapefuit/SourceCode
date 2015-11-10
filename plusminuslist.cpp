/*
    Team Grapefruit
    Oct 26th/2015
    This file contains the implementation of a class
    which builds a tree to display data from any of the
    4 files.
*/
#include "plusminuslist.h"
#include <iterator>
#include <QString>
#include <QStringList>
#include <iostream>
using namespace std;

//PlusMinusList
//Constructor
//Input: Number of columns in the tree, list of the colummn titles
//Output: (Empty tree is created)
PlusMinusList::PlusMinusList(int columns, list<string> * colNames)
{
    //Initialize the tree
    rootTree = new QTreeWidget(0);
    rootTree->setColumnCount(columns);
    columnNum = columns;

    //Populate the tree headings with the column titles
    list<string>::iterator iterate = colNames->begin();
    QStringList headerlabels;

    while (iterate != colNames->end()){
        QString colTitle = QString::fromUtf8(iterate->c_str());
        headerlabels.push_back(colTitle);
        ++ iterate;
    }

    rootTree->setHeaderLabels(headerlabels);
}

//PlusMinusList
//Destructor
//Input: None
//Output: (Tree is deleted)
PlusMinusList::~PlusMinusList()
{
    delete rootTree;
}

//getTree
//Returns the created tree
//Input: Number of columns in the tree, list of the colummn titles
//Output: (Empty tree is created)
QTreeWidget * PlusMinusList::getTree()
{
    return rootTree;
}

//AddFirstLevelFilter
//Adds a Listclas object as a highlevel item to the tree
//Input: ListClass object to display
//Output: (Listclass object is added to the tree)
void PlusMinusList::AddFirstLevelFilter(ListClass * node)
{
    //Create a tree item
    QTreeWidgetItem * treeItem = new QTreeWidgetItem();
    QString name = QString::fromUtf8(node->getName().c_str());
    treeItem->setText(0, name);

    //Determine which parameters are to be displayed
    if (node->getParam2() != -1){
        //Display parameter 2
        QString num = QString::number(node->getParam2());
        treeItem->setText(columnNum - 1, num);
    }
    if (node->getParam1() != -1){
        //Display parameter 1
        QString num = QString::number(node->getParam1());
        if (node->getParam2() != -1){
            treeItem->setText(columnNum - 2, num);
        } else {
            treeItem->setText(columnNum - 1, num);
        }
    }

    //Add the item to the tree
    rootTree->addTopLevelItem(treeItem);

    //If the item has children, add its children to the tree
    if (node->getChildren() != NULL){
        AddSubFilters(treeItem, node->getChildren(), 1);
    }
}

//AddSubFilters
//Adds a Listclas object as a highlevel item to the tree
//Input: ListClass object to display
//Output: (Listclass object is added to the tree)
void PlusMinusList::AddSubFilters(QTreeWidgetItem * parent, list<ListClass *> * children, int depth){
    list<ListClass *>::iterator iterate = children->begin();

    //Iterate through all the children
    while (iterate != children->end()){

        //cout << (*iterate)->getName() << endl;
        QTreeWidgetItem * treeItem = new QTreeWidgetItem(parent);
        QString name = QString::fromUtf8((*iterate)->getName().c_str());
        treeItem->setText(depth, name);

        //Determine which parameters are to be displayed
        if ((*iterate)->getParam2() != -1){
            //Display parameter 2
            QString num = QString::number((*iterate)->getParam2());
            treeItem->setText(columnNum - 1, num);
        }
        if ((*iterate)->getParam1() != -1){
            QString num = QString::number((*iterate)->getParam1());
            //Display parameter 1
            if ((*iterate)->getParam2() != -1){
                treeItem->setText(columnNum - 2, num);
            } else {
                treeItem->setText(columnNum - 1, num);
            }
        }

        //If this object has children, add the children on the tier below
        if ((*iterate)->getChildren() != NULL){
            AddSubFilters(treeItem, (*iterate)->getChildren(), depth + 1);
        }

        ++iterate;
    }
}
