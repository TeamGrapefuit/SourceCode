#pragma once
#include <stdio.h>
#include <string>

#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "listclass.h"
#endif
#include "Grant_rowObject.h"
#include <map>
#include <functional>

struct Member{
    ListClass grant_pr;
    ListClass grant_cf;
    ListClass indspr_g;
    ListClass indspr_cf;
    int totalGrants;
    int num_pr_g;
    int num_is_g;
    double g_pr_amount;
    double g_is_amount;
    int totalcf;
    int num_pr_cf;
    int num_is_cf;
    double cf_pr_amount;
    double cf_is_amount;
    
};
class ListBuilder {
    
    list<ListClass *> * toplevel;
    
public:
    ListBuilder(int startyear,int endyear,multimap<string,Grant_rowObject> *data);
    
    void scanMap();
    Member tally(string);
    void addMember(Member);
    void printList(ListClass);
    
    ListClass grants;
    ListClass clinicalfunding;
    ListClass peerreviewed_grants;
    ListClass industrygrant_grants;
    ListClass peerreviewed_cf;
    ListClass industrygrant_cf;
private:   
    int year_s;
    int year_e;
    multimap<string,Grant_rowObject>* data;
   
};
    
    



