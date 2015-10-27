#include "graphclass.h"


#include <iterator>
#include <stdlib.h>
#include <iostream>

using namespace std;

GraphClass::GraphClass(int startYear, int endYear, string name, multimap<string, Grant_rowObject> * data)
{
    list<string> * barTitles = new list<string>();
    barTitles->push_back("Grant - PR");
    barTitles->push_back("Grant - IS");
    barTitles->push_back("Clinic - PR");
    barTitles->push_back("Clinic - IS");

    range = new list<list<BarValue> >;
    cout << "--------------------------" << endl;
    cout << "Start " << startYear << " EndYear " << endYear << endl;
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
            //cout << "Found match!" << endl;
            int pos = i->second.sDate - startYear;
            if (pos < 0 || i->second.sDate >= endYear) {
                //cout << "MIssed" << endl;
                ++ i;
                continue;
            }
            //cout << "Position: " << pos << endl;
            list<list<BarValue> >::iterator outer = range->begin();
            //cout << "Position: " << pos << endl;
            advance(outer, pos);

            list<BarValue>::iterator inner = outer->begin();

            if (i->second.fundType == "Grants" && i->second.peerReviewed){
                //No advance needed
                //cout << "Type: Grants and Peer Review" << endl;
            }
            else if (i->second.fundType == "Grants" && i->second.indGrant){
                //cout << "in" << endl;
                advance(inner, 1);
                //cout << "out" << endl;
                //cout << "Type: Grants and InsSpons" << endl;
            }
            else if (i->second.fundType == "Clinical Trials" && i->second.peerReviewed){
                //cout << "in2" << endl;
                advance(inner, 2);
                //cout << "out2" << endl;
                //cout << "Type: Clinicla and Peer Review" << endl;
            }
            else if (i->second.fundType == "Clinical Trials" && i->second.indGrant){
                //cout << "in3" << endl;
                advance(inner, 3);
                //cout << "out3" << endl;

                //cout << "Type: Clinical and InsSpons" << endl;
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
