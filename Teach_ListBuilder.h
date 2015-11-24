//
//  Teach_ListBuilder.h
//  
//
//  Created by Colin Costello on 2015-11-21.
//
//

#ifndef ____Teach_ListBuilder__
#define ____Teach_ListBuilder__

#include <stdio.h>
#include "Teach_rowObject.h"
#include <map>

#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "listclass.h"
#endif


struct tmember{
    string name;
    int year;
    int PME_hrs;
    int PME_sd;
    int UME_hrs;
    int UME_sd;
    int CME_hrs;
    int CME_sd;
    int OTH_hrs;
    int OTH_sd;
};

class Teach_ListBuilder {

public:

    Teach_ListBuilder(int startyear,int endyear,multimap<string,Teach_rowObject> *data);
    void scanMap();
    void printList(ListClass);

    ListClass pme;
    ListClass cme;
    ListClass ume;
    ListClass other;

private:
    int year_s;
    int year_e;
    multimap<string,Teach_rowObject>* data;
    tmember tally(string,int);
    void addMember(tmember);
};

#endif /* defined(____Teach_ListBuilder__) */
