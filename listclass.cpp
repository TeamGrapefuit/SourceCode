#include "listclass.h"


ListClass::ListClass(string name, int param1, int param2, bool hasList)
{
    this->name = name;
    this->param1 = param1;
    this->param2 = param2;
    if (hasList) this->children = new list<ListClass *>();
    else this->children = NULL;
}
ListClass::ListClass()
{
    this->name = "";
    this->param1 = 0;
    this->param2 = 0.00;
    this->children = NULL;
}

ListClass::~ListClass()
{
    if (this->children !=NULL)
        this->children->clear();
}

void ListClass::addChild(string name, int param1, int param2, bool hasList)
{
    this->children->push_back(new ListClass(name, param1, param2, hasList));
}

void ListClass::addChild(ListClass * child)
{
    this->children->push_back(child);
}

string ListClass::getName()
{
    return this->name;
}

int ListClass::getParam1()
{
    return this->param1;
}

int ListClass::getParam2()
{
    return this->param2;
}

list<ListClass *> * ListClass::getChildren()
{
    return this->children;
}
