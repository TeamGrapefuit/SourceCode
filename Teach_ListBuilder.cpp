//
//  Teach_ListBuilder.cpp
//  
//
//  Created by Colin Costello on 2015-11-21.
//
//

#include "Teach_ListBuilder.h"
#include <string>
#include <stdio.h>

Teach_ListBuilder::Teach_ListBuilder(int s_year,int e_year,multimap<string,Teach_rowObject>*somedata){
    this->year_s = s_year;
    this->year_e = e_year;
    this->data = somedata;
    
    ListClass* c = new ListClass("CME",0,0,true);
    ListClass* p = new ListClass("PME",0,0,true);
    ListClass* u = new ListClass("UME",0,0,true);
    ListClass* o = new ListClass("OTH",0,0,true);
    
    this->cme = *c;
    this->pme = *p;
    this->ume = *u;
    this->other = *o;
    int years = year_e-year_s;
    int i;
    for (i=0;i<years;i++){
        this->cme.addChild(to_string(year_s+i), 0, 0, true);
        this->pme.addChild(to_string(year_s+i), 0, 0, true);
        this->ume.addChild(to_string(year_s+i), 0, 0, true);
        this->other.addChild(to_string(year_s+i), 0, 0, true);
    }
}
tmember Teach_ListBuilder::tally(string aname,int year){
    
    tmember crow;
    crow.name = aname;
    crow.year = year;
    crow.PME_hrs=0;
    crow.PME_sd=0;
    crow.CME_hrs=0;
    crow.CME_sd=0;
    crow.UME_hrs=0;
    crow.UME_sd=0;
    crow.OTH_hrs=0;
    crow.OTH_sd=0;
    
    std::multimap<string,Teach_rowObject>::iterator iter;
    
    iter = data->begin();
    
    for (iter = data->equal_range(crow.name).first; iter!=data->equal_range(crow.name).second;iter++){
        
        if (year==(*iter).second.sDate){
            
            if (((strcmp((*iter).second.program.c_str(),"Postgraduate Medical Education"))==0)&&(year==(*iter).second.sDate)){
                crow.PME_hrs = crow.PME_hrs+(*iter).second.tHours;
                crow.PME_sd = crow.PME_sd+(*iter).second.totalStudents;
                
            }
            else if (((*iter).second.program=="Continuing Medical Education")&&(year==(*iter).second.sDate)){
                crow.CME_hrs = crow.CME_hrs+(*iter).second.tHours;
                crow.CME_sd = crow.CME_sd+(*iter).second.totalStudents;
                
            }
            else if (((*iter).second.program=="Undergraduate Medical Education")&&(year==(*iter).second.sDate)){
                crow.UME_hrs = crow.UME_hrs+(*iter).second.tHours;
                crow.UME_sd = crow.UME_sd+(*iter).second.totalStudents;
                
            }
            else {
                crow.OTH_hrs = crow.OTH_hrs+(*iter).second.tHours;
                crow.OTH_sd = crow.OTH_sd+(*iter).second.totalStudents;
    
            }

        }
    }
    return crow;
}
void Teach_ListBuilder::addMember(tmember tmember){
    
    if (tmember.PME_hrs > 0){
        list<ListClass *> * temp = this->pme.getChildren(); // find the year
        if (temp!=NULL){
           list<ListClass *>::iterator i = temp->begin();
           while (i != temp->end()){
               int yr = stoi((*i)->getName());
               if (tmember.year==yr){                                   // when we have the year
                   list<ListClass *> * temp_j = (*i)->getChildren();    // find the name
                   if (temp_j!=NULL){
                       list<ListClass *>::iterator j = temp_j->begin();
                       int found=0;
                       while (j != temp_j->end()){
                           string mn = (*j)->getName();
                           if (strcmp(tmember.name.c_str(),mn.c_str())==0){         // if we find the name
                               found = 1;
                                (*j)->param1 = (*j)->getParam1() + tmember.PME_hrs; // update year hrs
                                (*j)->param2 = (*j)->getParam2() + tmember.PME_sd;  // update year students
                               
                                this->pme.param1 = this->pme.param1 + tmember.PME_hrs; // update pme totals
                                this->pme.param2 = this->pme.param2 + tmember.PME_sd;  //
                                break;
                           }
                           j++;
                       }
                       if(found!=1){                                 // else we dont find the name
                           ListClass *m = new ListClass(tmember.name.c_str(),tmember.PME_hrs,tmember.PME_sd,false);
                           (*i)->addChild(m);                                  // so add it
                           (*i)->param1 = (*i)->getParam1() + tmember.PME_hrs; // update year hrs
                           (*i)->param2 = (*i)->getParam2() + tmember.PME_sd;  // update year students
                           
                           this->pme.param1 = this->pme.param1 + tmember.PME_hrs; // update pme totals
                           this->pme.param2 = this->pme.param2 + tmember.PME_sd;  //
                           break;
                       }
                   }
               }
               i++;
           }
        }
    }
    if (tmember.CME_hrs > 0){
        list<ListClass *> * temp = this->cme.getChildren();           // find the year
        if (temp!=NULL){
            list<ListClass *>::iterator i = temp->begin();
            while (i != temp->end()){
                int yr = stoi((*i)->getName());
                if (tmember.year==yr){                                // when we have the year
                    list<ListClass *> * temp_j = (*i)->getChildren(); // find the name
                    if (temp_j!=NULL){
                        list<ListClass *>::iterator j = temp_j->begin();
                        int found=0;
                        while (j != temp_j->end()){
                            string mn = (*j)->getName();
                            if (strcmp(tmember.name.c_str(),mn.c_str())==0){ // if we find the name
                                found = 1;
                                (*j)->param1 = (*j)->getParam1() + tmember.CME_hrs; // update year hrs
                                (*j)->param2 = (*j)->getParam2() + tmember.CME_sd; // update year students
                                
                                this->cme.param1 = this->cme.param1 + tmember.CME_hrs; // update pme totals
                                this->cme.param2 = this->cme.param2 + tmember.CME_sd;  //
                                break;
                            }
                            j++;
                        }
                        if(found!=1){                                 // else we dont find the name so add it
                            ListClass *m = new ListClass(tmember.name.c_str(),tmember.CME_hrs,tmember.CME_sd,false);
                            (*i)->addChild(m);
                            (*i)->param1 = (*i)->getParam1() + tmember.CME_hrs; // update year hrs
                            (*i)->param2 = (*i)->getParam2() + tmember.CME_sd;  // update year students
                            
                            this->cme.param1 = this->cme.param1 + tmember.CME_hrs; // update pme totals
                            this->cme.param2 = this->cme.param2 + tmember.CME_sd;  //
                            break;
                        }
                    }
                }
                i++;
            }
        }
    }
    if (tmember.UME_hrs > 0){
        list<ListClass *> * temp = this->ume.getChildren();           // find the year
        if (temp!=NULL){
            list<ListClass *>::iterator i = temp->begin();
            while (i != temp->end()){
                int yr = stoi((*i)->getName());
                if (tmember.year==yr){                                // when we have the year
                    list<ListClass *> * temp_j = (*i)->getChildren(); // find the name
                    if (temp_j!=NULL){
                        list<ListClass *>::iterator j = temp_j->begin();
                        int found=0;
                        while (j != temp_j->end()){
                            string mn = (*j)->getName();
                            if (strcmp(tmember.name.c_str(),mn.c_str())==0){ // if we find the name
                                found = 1;
                                (*j)->param1 = (*j)->getParam1() + tmember.UME_hrs; // update year hrs
                                (*j)->param2 = (*j)->getParam2() + tmember.UME_sd; // update year students
                                
                                this->ume.param1 = this->ume.param1 + tmember.UME_hrs; // update pme totals
                                this->ume.param2 = this->ume.param2 + tmember.UME_sd;  //
                                break;
                            }
                            j++;
                        }
                        if(found!=1){                                // else we dont find the name so add it
                            ListClass *m = new ListClass(tmember.name.c_str(),tmember.UME_hrs,tmember.UME_sd,false);
                            (*i)->addChild(m);
                            (*i)->param1 = (*i)->getParam1() + tmember.UME_hrs; // update year hrs
                            (*i)->param2 = (*i)->getParam2() + tmember.UME_sd;  // update year students
                            
                            this->ume.param1 = this->ume.param1 + tmember.UME_hrs; // update pme totals
                            this->ume.param2 = this->ume.param2 + tmember.UME_sd;  //
                            break;
                        }
                    }
                }
                i++;
            }
        }
    }
    if (tmember.OTH_hrs > 0){
        list<ListClass *> * temp = this->other.getChildren();         // find the year
        if (temp!=NULL){
            list<ListClass *>::iterator i = temp->begin();
            while (i != temp->end()){
                int yr = stoi((*i)->getName());
                if (tmember.year==yr){                                // when we have the year
                    list<ListClass *> * temp_j = (*i)->getChildren(); // find the name
                    if (temp_j!=NULL){
                        list<ListClass *>::iterator j = temp_j->begin();
                        int found=0;
                        while (j != temp_j->end()){
                            string mn = (*j)->getName();
                            if (strcmp(tmember.name.c_str(),mn.c_str())==0){ // if we find the name
                                found = 1;
                                (*j)->param1 = (*j)->getParam1() + tmember.OTH_hrs; // update year hrs
                                (*j)->param2 = (*j)->getParam2() + tmember.OTH_sd; // update year students
                                
                                this->other.param1 = this->other.param1 + tmember.OTH_hrs; // update pme totals
                                this->other.param2 = this->other.param2 + tmember.OTH_sd;  //
                                break;
                            }
                            j++;
                        }
                        if(found!=1){                                   // else we dont find the name so add it
                            ListClass *m = new ListClass(tmember.name.c_str(),tmember.OTH_hrs,tmember.OTH_sd,false);
                            (*i)->addChild(m);
                            (*i)->param1 = (*i)->getParam1() + tmember.OTH_hrs; // update year hrs
                            (*i)->param2 = (*i)->getParam2() + tmember.OTH_sd;  // update year students
                            
                            this->other.param1 = this->other.param1 + tmember.OTH_hrs; // update pme totals
                            this->other.param2 = this->other.param2 + tmember.OTH_sd;  //
                            break;
                        }
                    }
                }
                i++;
            }
        }
    }
}

void Teach_ListBuilder::scanMap(){
    
    int i;
    
    map<string, bool> visited; // create a map to keep track of visited row objects
        
    std::multimap<string, Teach_rowObject>::iterator cur = data->begin(); // get row iterator
    
    while (cur != data->end()){                         // while there are more rows do
            
        map<string, bool>::iterator j = visited.find(cur->second.name); // check if visited
        
        if (j == visited.end()){                        // if not visited
        
            for(i = year_s;i<year_e;i++){               // for each year in range
                tmember crow;                           // get members info
                crow = this->tally(cur->second.name,i); // add member to list
                this->addMember(crow);
                visited.emplace(crow.name,true);
            }
        }
    cur++;

    }
}

void Teach_ListBuilder::printList(ListClass alist){
    
    printf("%s", alist.getName().c_str()); // print the list
    printf("  %d", alist.getParam1());
    printf("  %d\n", alist.getParam2());
    
    list<ListClass *> * temp = alist.getChildren(); // print its children
    if (temp!=NULL){
        list<ListClass *>::iterator i = temp->begin();
        while (i != temp->end()){
            printList(*(*i));
            ++ i;
        }
    }
}
