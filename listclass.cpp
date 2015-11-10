/*
    Team Grapefruit
    Oct 26th/2015
    This file contains the implementation of a class
    which stores data to be displayed in the plus/minus list.
    It works with each of the 4 files.
*/
#include "listclass.h"

//ListClass
//Constructor
//Input: Name, and two integer parameters
//Output: (List Class Object is created)
ListClass::ListClass(string name, int param1, int param2, bool hasList)
{
    this->name = name;
    this->param1 = param1;
    this->param2 = param2;
    if (hasList) this->children = new list<ListClass *>();
    else this->children = NULL;
}

//ListClass
//Constructor
//Input: None
//Output: (List Class Object is created)
ListClass::ListClass()
{
    this->name = "";
    this->param1 = 0;
    this->param2 = 0.00;
    this->children = NULL;
}

//ListClass
//Destructor
//Input: None
//Output: (List Class Object's children are deallocated)
ListClass::~ListClass()
{
    if (this->children !=NULL)
        this->children->clear();
}

//addChild
//Adds a child to children
//Input: Name, and two integer parameters, boolean describing whether the ListClass will have children
//Output: (List Class Object is added to children)
void ListClass::addChild(string name, int param1, int param2, bool hasList)
{
    this->children->push_back(new ListClass(name, param1, param2, hasList));
}

//addChild
//Adds a child to children
//Input: List Class object
//Output: (List Class Object is added to children)
void ListClass::addChild(ListClass * child)
{
    this->children->push_back(child);
}

//getName
//Returns the name of the ListClass object
//Input: None
//Output: Name
string ListClass::getName()
{
    return this->name;
}

//getParam1
//Returns an integer parameter of the ListClass object
//Input: None
//Output: Param1
int ListClass::getParam1()
{
    return this->param1;
}

//getParam2
//Returns an integer parameter of the ListClass object
//Input: None
//Output: Param1
int ListClass::getParam2()
{
    return this->param2;
}


//getChildren
//Returns the children of the ListClass object
//Input: None
//Output: Children
list<ListClass *> * ListClass::getChildren()
{
    return this->children;
}
