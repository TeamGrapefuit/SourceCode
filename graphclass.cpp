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

GraphClass::GraphClass(int startYear, int endYear, string name, map<string, Teach_rowObject> * data)
{
    list<string> * barTitles = new list<string>();
    barTitles->push_back("Teaching - PME");
    barTitles->push_back("Teaching - UME");
    barTitles->push_back("Teaching - CME");
    barTitles->push_back("Teaching - Other");

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
            val.yValue1 = 0;    //Refers to Total # students
            val.yValue2 = 0;    //Refers to Total # teching hours
            yearBarValues->push_back(val);

            ++ titles;
        }

        ++ yearBarValues;
    }

    multimap<string, Teach_rowObject>::iterator i = data->begin();
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

            if (i->second.fundType == "PME" ){
                //No advance needed
            }
            if (i->second.fundType == "UME" ){
                advance(inner, 1);
            }
            if (i->second.fundType == "CME" ){
                advance(inner, 2);
            }
            if (i->second.fundType == "Other"){
                advance(inner, 3);
            }

            inner->yValue1 += i->second.hpTeach;
            inner->yValue2 += i->second.tHours ;/
        }

        ++ i;
    }
}

GraphClass::GraphClass(int startYear, int endYear, string name, map<string, Pres_rowObject> * data)
{
    list<string> * barTitles = new list<string>();
    barTitles->push_back("Pres - Lectures");
    barTitles->push_back("Pres - Presented");
    barTitles->push_back("Pres - Type");
    barTitles->push_back("Pres - Other");

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

            if (i->second.fundType == "Lectures"){
                //No advance needed
            }
            if (i->second.fundType == "Presented"){
                advance(inner, 1);
            }
            if (i->second.fundType == "Type"){
                advance(inner, 2);
            }
            if (i->second.fundType == "Other"){
                advance(inner, 3);
            }

            inner->yValue1 += i->second.numPresent ;//total number of presentation
        }

        ++ i;
    }

}

GraphClass::GraphClass(int startYear, int endYear, string name, map<string, Pub_rowObject> * data)
{
    list<string> * barTitles = new list<string>();
    barTitles->push_back("Publications - Book Chapters");
    barTitles->push_back("Publications - Books");
    barTitles->push_back("Publications - Books Edited");
    barTitles->push_back("Publications - Case Reports");
    barTitles->push_back("Publications - Clinical Care Guidelines");
    barTitles->push_back("Publications - Commentaries");
    barTitles->push_back("Publications - Conference Proceedings");
    barTitles->push_back("Publications - Editorials");
    barTitles->push_back("Publications - Invited Articles");
    barTitles->push_back("Publications - Journal Article");
    barTitles->push_back("Publications - Letters to Editor");
    barTitles->push_back("Publications - Magazine Entries");
    barTitles->push_back("Publications - Manuals");
    barTitles->push_back("Publications - Monographs");
    barTitles->push_back("Publications - Multimedia");
    barTitles->push_back("Publications - Newsletter Articles");
    barTitles->push_back("Publications - Newspaper Articles");
    barTitles->push_back("Publications - Published Abstract");
    barTitles->push_back("Publications - Supervised Student Publications");
    barTitles->push_back("Publications - Websites / Videos");
    barTitles->push_back("Publications - Working Papers");

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
            val.yValue1 = 0;    //Refers to Total # Publications
            yearBarValues->push_back(val);

            ++ titles;
        }

        ++ yearBarValues;
    }

    multimap<string, Pub_rowObject>::iterator i = data->begin();
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

            if (i->second.fundType == "Book Chapters"){
                //No advance needed
            }
            if (i->second.fundType == "Books" ){
                advance(inner, 1);
            }
            if (i->second.fundType == "Books Edited"){
                advance(inner, 2);
            }
            if (i->second.fundType == "Case Reports"){
                advance(inner, 3);
            }
            if (i->second.Type == "Clinical Care Guidelines"){
                advance(inner, 4);
            }
            if (i->second.Type == "Commentaries"){
                advance(inner, 5);
            }
            if (i->second.Type == "Conference Proceedings"){
                advance(inner, 6);
            }
            if (i->second.Type == "Editorials"){
                advance(inner, 7);
            }
            if (i->second.Type == "Invited Articles"){
                advance(inner, 8);
            }
            if (i->second.Type == "Journal Article"){
                advance(inner, 9);
            }
            if (i->second.Type == "Letters to Editor"){
                advance(inner, 10);
            }
            if (i->second.Type == "Magazine Entries"){
                advance(inner, 11);
            }
            if (i->second.Type == "Manuals"){
                advance(inner, 12);
            }
            if (i->second.Type == "Monographs"){
                advance(inner, 13);
            }
            if (i->second.Type == "Multimedia"){
                advance(inner, 14);
            }
            if (i->second.Type == "Newsletter Articles"){
                advance(inner, 15);
            }
            if (i->second.Type == "Newspaper Articles"){
                advance(inner, 16);
            }
            if (i->second.Type == "Published Abstract"){
                advance(inner, 17);
            }
            if (i->second.Type == "Supervised Student Publications"){
                advance(inner, 18);
            }
            if (i->second.Type == "Websites / Videos"){
                advance(inner, 19);
            }
            if (i->second.Type == "Working Papers"){
                advance(inner, 20);
            }

            inner->yValue1 += i->second.totalPub;//total number of Publications
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
