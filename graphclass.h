#pragma once
#include <string>
#include <list>
#include <map>
#include <iostream>
#include "Grant_rowObject.h"
#include "Pres_rowObject.h"
#include "Pub_rowObject.h"
#include "Teach_rowObject.h"

using namespace std;

struct BarValue {
    string title;
    int yValue1;
    int yValue2;
};

class GraphClass
{
    list<list<BarValue> > * range;

public:
    GraphClass(int startYear, int endYear, string name, multimap<string, Grant_rowObject> * data);
    GraphClass(int startYear, int endYear, string name, multimap<string, Pres_rowObject> * data);
    GraphClass(int startYear, int endYear, string name, multimap<string, Pub_rowObject> * data);
    GraphClass(int startYear, int endYear, string name, multimap<string, Teach_rowObject> * data);

    ~GraphClass();

    list<list<BarValue> > * getRange();

};
