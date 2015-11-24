//
//  Pres_ListBuilder.cpp
//  
//
//  Created by Colin Costello on 2015-11-22.
//
//

#include "Pres_ListBuilder.h"

Pres_ListBuilder::Pres_ListBuilder(int s_year ,int e_year, multimap<string,Pres_rowObject>*somedata){
    
    this->year_s = s_year;
    this->year_e = e_year;
    this->data = somedata;
    
    this->a_p = new ListClass("Abstract Presented",0,0,true);
    this->c_p = new ListClass("Conference Presentation",0,0,true);
    this->i_l = new ListClass("Invited Lectures",0,0,true);
    this->p_p = new ListClass("Poster Presentation",0,0,true);
    this->s_p = new ListClass("Student Presentation",0,0,true);
    this->s_y = new ListClass("Symposia",0,0,true);
    this->v_p = new ListClass("Visiting Professorship",0,0,true);
    this->w_s = new ListClass("Workshop",0,0,true);
    this->o_t = new ListClass("Other",0,0,true);

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
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Abstract_Presented,false);
            this->a_p->addChild(ap);
            this->a_p->param2 = this->a_p->param2 + pmember.Abstract_Presented;
        }
        if (pmember.Invited_Lectures > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Invited_Lectures,false);
            this->i_l->addChild(ap);
            this->i_l->param2 = this->i_l->param2 + pmember.Invited_Lectures;
        }
        if (pmember.Conference_Presentation > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Conference_Presentation,false);
            this->c_p->addChild(ap);
            this->c_p->param2 = this->c_p->param2 + pmember.Conference_Presentation;
        }
        if (pmember.Poster_Presentation > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Poster_Presentation,false);
            this->p_p->addChild(ap);
            this->p_p->param2 = this->p_p->param2 + pmember.Poster_Presentation;
        }
        if (pmember.Student_Presentation > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Student_Presentation,false);
            this->s_p->addChild(ap);
            this->s_p->param2 = this->s_p->param2 + pmember.Student_Presentation;
        }
        if (pmember.Symposia > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Symposia,false);
            this->s_y->addChild(ap);
            this->s_y->param2 = this->s_y->param2 + pmember.Symposia;
        }
        if (pmember.visiting_prof > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.visiting_prof,false);
            this->v_p->addChild(ap);
            this->v_p->param2 = this->v_p->param2 + pmember.visiting_prof;
        }
        if (pmember.Workshop > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.Workshop,false);
            this->w_s->addChild(ap);
            this->w_s->param2 = this->w_s->param2 + pmember.Workshop;
        }
        if (pmember.other > 0){
            ListClass *ap = new ListClass(pmember.name.c_str(),0,pmember.other,false);
            this->o_t->addChild(ap);
            this->o_t->param2 = this->o_t->param2 + pmember.other;
        }
}

void Pres_ListBuilder::scanMap(){

    
    map<string, bool> visited;                       // create a map to keep track of visited row objects

    std::multimap<string, Pres_rowObject>::iterator cur = data->begin(); // get row iterator
    while (cur != data->end()){                      // while there are more rows do
    
        map<string, bool>::iterator j = visited.find(cur->second.name); // check if visited
        if (j == visited.end()){                     // if not visited
            presmember prow;                         // get members info
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

