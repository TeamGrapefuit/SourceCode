//
//  Pres_ListBuilder.cpp
//  
//
//  Created by Colin Costello on 2015-11-22.
//
//

#include "Pres_ListBuilder.h"

#include <iostream>

using namespace std;

Pres_ListBuilder::Pres_ListBuilder(int s_year ,int e_year, multimap<string,Pres_rowObject>*somedata){
    
    this->year_s = s_year;
    this->year_e = e_year;
    this->data = somedata;
    
    this->a_p = new ListClass("Abstract Presented",0,-1,true);
    this->c_p = new ListClass("Conference Presentation",0,-1,true);
    this->i_l = new ListClass("Invited Lectures",0,-1,true);
    this->p_p = new ListClass("Poster Presentation",0,-1,true);
    this->s_p = new ListClass("Student Presentation",0,-1,true);
    this->s_y = new ListClass("Symposia",0,-1,true);
    this->v_p = new ListClass("Visiting Professorship",0,-1,true);
    this->w_s = new ListClass("Workshop",0,-1,true);
    this->o_t = new ListClass("Other",0,-1,true);

}
presmember Pres_ListBuilder::tally(string aname){
    
    presmember prow;
    prow.name = aname;
    prow.Poster_Presentation=0;
    prow.Invited_Lectures=0;
    prow.Abstract_Presented=0;
    prow.Conference_Presentation=0;
    prow.Student_Presentation=0;
    prow.Symposia=0;
    prow.Workshop=0;
    prow.visiting_prof=0;
    prow.other=0;

    std::multimap<string,Pres_rowObject>::iterator iter;
    
    iter = data->begin();
    
    for (iter = data->equal_range(prow.name).first; iter!=data->equal_range(prow.name).second;iter++){
        
        if ((this->year_s<=(*iter).second.date)&&(this->year_e>=(*iter).second.date)){
            
            if (strcmp((*iter).second.type.c_str(),"Abstract Presented")==0){
                prow.Abstract_Presented++;
            }
            else if (strcmp((*iter).second.type.c_str(),"Conference Presentation")==0){
                prow.Conference_Presentation++;
                
            }
            else if (strcmp((*iter).second.type.c_str(),"Invited Lectures")==0){
                prow.Invited_Lectures++;
            }
            
            else if (strcmp((*iter).second.type.c_str(),"Poster Presentation")==0){
                prow.Poster_Presentation++;
            }
            else if (strcmp((*iter).second.type.c_str(),"Student Presentation")==0){
                prow.Student_Presentation++;
            }
            else if (strcmp((*iter).second.type.c_str(),"Symposia")==0){
                prow.Symposia++;
            }
            
            else if (strcmp((*iter).second.type.c_str(),"Visiting Professorship")==0){
                prow.visiting_prof++;
            }
            else if (strcmp((*iter).second.type.c_str(),"Workshop")==0){
                prow.Workshop++;
            }
            else {
                prow.other++;
            }
        }
    }
    return prow;
}
void Pres_ListBuilder::addMember(presmember pmember){
        if (pmember.Abstract_Presented > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Abstract_Presented,-1,false);
            this->a_p->addChild(ap);
            this->a_p->param1 = this->a_p->param1 + pmember.Abstract_Presented;
        }
        if (pmember.Invited_Lectures > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Invited_Lectures,-1,false);
            this->i_l->addChild(ap);
            this->i_l->param1 = this->i_l->param1 + pmember.Invited_Lectures;
        }
        if (pmember.Conference_Presentation > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Conference_Presentation,-1,false);
            this->c_p->addChild(ap);
            this->c_p->param1 = this->c_p->param1 + pmember.Conference_Presentation;
        }
        if (pmember.Poster_Presentation > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Poster_Presentation,-1,false);
            this->p_p->addChild(ap);
            this->p_p->param1 = this->p_p->param1 + pmember.Poster_Presentation;
        }
        if (pmember.Student_Presentation > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Student_Presentation,-1,false);
            this->s_p->addChild(ap);
            this->s_p->param1 = this->s_p->param1 + pmember.Student_Presentation;
        }
        if (pmember.Symposia > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Symposia,-1,false);
            this->s_y->addChild(ap);
            this->s_y->param1 = this->s_y->param1 + pmember.Symposia;
        }
        if (pmember.visiting_prof > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.visiting_prof,-1,false);
            this->v_p->addChild(ap);
            this->v_p->param1 = this->v_p->param1 + pmember.visiting_prof;
        }
        if (pmember.Workshop > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.Workshop,-1,false);
            this->w_s->addChild(ap);
            this->w_s->param1 = this->w_s->param1 + pmember.Workshop;
        }
        if (pmember.other > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),pmember.other,-1,false);
            this->o_t->addChild(ap);
            this->o_t->param1 = this->o_t->param1 + pmember.other;
        }
}

void Pres_ListBuilder::scanMap(){


    map<string, bool> visited;                       // create a map to keep track of visited row objects

    std::multimap<string, Pres_rowObject>::iterator cur = data->begin(); // get row iterator
    while (cur != data->end()){                      // while there are more rows do
    
        map<string, bool>::iterator j = visited.find(cur->second.name); // check if visited
        if (j == visited.end()){                     // if not visited
            presmember prow;                         // get members info
            cout << cur->second.name << endl;
            prow = this->tally(cur->second.name);    // add member to list
            this->addMember(prow);
            visited.emplace(prow.name,true);
        }
    
    cur++;
    }
}
void Pres_ListBuilder::printList(ListClass alist){
    
    printf("%s", alist.getName().c_str()); // print the list
    //printf("  %d", alist.getParam1());
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

