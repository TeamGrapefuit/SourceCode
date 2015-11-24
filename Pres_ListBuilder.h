//
//  Pres_ListBuilder.h
//  
//
//  Created by Colin Costello on 2015-11-22.
//
//

#ifndef ____Pres_ListBuilder__
#define ____Pres_ListBuilder__

#include <stdio.h>
#include "Pres_rowObject.h"
#include <map>

#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "listclass.h"
#endif
struct presmember{
    string name;
    int Poster_Presentation;
    int Invited_Lectures;
    int Abstract_Presented;
    int Conference_Presentation;
    int Student_Presentation;
    int Symposia;
    int Workshop;
    int visiting_prof;
    int work;
    int other;
};

class Pres_ListBuilder{
    
public:
Pres_ListBuilder(int syear,int eyear,multimap<string,Pres_rowObject>*data);
    
    void scanMap();
    void printList(ListClass);
    
    ListClass* a_p;
    ListClass* c_p;
    ListClass* i_l;
    ListClass* p_p;
    ListClass* s_p;
    ListClass* s_y;
    ListClass* v_p;
    ListClass* w_s;
    ListClass* o_t;
private:
    int year_s;
    int year_e;
    multimap<string,Pres_rowObject>* data;
    
    presmember tally(string);
    void addMember(presmember);
};

#endif /* defined(____Pres_ListBuilder__) */
