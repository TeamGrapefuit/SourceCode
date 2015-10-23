#include "graphclass.h"
#include <iterator>

GraphClass::GraphClass(int startYear, int endYear, string name, multimap<string, Grant_rowObject> * data)
{
    list<string> * barTitles = new list<string>();
    barTitles->push_back("Grant - PR");
    barTitles->push_back("Grant - IS");
    barTitles->push_back("Clinic - PR");
    barTitles->push_back("Clinic - IS");

    range = new list<list<BarValue> >;
    for (int i = startYear; i < endYear; i ++){
        list<BarValue> temp;
        range->push_back(temp);
    }

    list<list<BarValue> >::iterator yearBarValues = range->begin();
    while (yearBarValues != range->end()){
        list<string>::iterator titles = barTitles->begin();
        while (titles != barTitles->end()){
            BarValue val;
            val.title = *titles;
            val.yValue1 = 0;    //Refers to Total #
            val.yValue2 = 0;    //Refers to Total $ amount
            yearBarValues->push_back(val);
            
            ++ titles;
        }
        
        ++ yearBarValues;
    }

    multimap<string, Grant_rowObject>::iterator i = data->begin();
    while (i != data->end()){
        if (i->first == name){
            int pos = i->second.sDate - startYear;
            if (pos < 0) {
                cout << "GraphClass.cpp - Date Mismatch Error" << endl;
                exit(EXIT_FAILURE);
            }
            list<list<BarValue> >::iterator outer = range->begin();
            advance(outer, pos);
            
            list<BarValue>::iterator inner = outer->begin();
            
            if (i->second.fundType == "Grants" && i->second.peerReviewed){
                //No advance needed
            }
            if (i->second.fundType == "Grants" && i->second.indGrant){
                advance(inner, 1);
            }
            if (i->second.fundType == "Clinical Trials" && i->second.peerReviewed){
                advance(inner, 2);
            }
            if (i->second.fundType == "Clinical Trials" && i->second.indGrant){
                advance(inner, 3);
            }
            
            inner->yValue1 += 1;
            inner->yValue2 += i->second.totalAmount;
        }
        
        ++ i;
    }
    
}

GraphClass::~GraphClass()
{
    list<list<BarValue> >::iterator level1 = range->begin();
    while (level1 != range->end()){
       level1->clear();
        ++ level1;
    }

    range->clear();
}

list<list<BarValue> > * GraphClass::getRange()
{
    return this->range;
}

