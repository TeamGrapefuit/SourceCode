#include "Pub_ListBuilder.h"
#include <iterator>
#include <list>
#include <iostream>

using namespace std;

Pub_ListBuilder::Pub_ListBuilder(int s_year,int e_year,multimap<string,Pub_rowObject>*somedata){
	
	ListClass *publications = new ListClass("Publications", 0, 0, true);

	ListClass *pub_abs = new ListClass("Published Abstracts", 0, 0, true);
	ListClass *books = new ListClass("Books",0,0,true);
	ListClass *books_edited = new ListClass("Books Edited",0,0,true);
	ListClass *book_chap = new ListClass("Book Chapters",0,0,true);
	ListClass *case_rep = new ListClass("Case Reports",0,0,true);

	ListClass *clinical = new ListClass("Clinical Care guidelines",0,0,true);
	ListClass *journal = new ListClass("Journal Articles",0,0,true);
	ListClass *commentaries = new ListClass("Commentaries",0,0,true);
	ListClass *conf_pro = new ListClass("Conference Proceedings",0,0,true);
	ListClass *editorials = new ListClass("Editorials",0,0,true);

	ListClass *invited_art = new ListClass("Invited Articles",0,0,true);
	ListClass *let_ed = new ListClass("Letters to Editor",0,0,true);
	ListClass *mag_ent = new ListClass("Magazine Entries",0,0,true);		
	ListClass *manuals = new ListClass("Manuals",0,0,true);
	ListClass *mono = new ListClass("Monographs",0,0,true);

	ListClass *multi = new ListClass("Multimedia",0,0,true);
	ListClass *newsletter = new ListClass("Mewsletter Articles",0,0,true);
	ListClass *news_art = new ListClass("Newspaper Articles",0,0,true);
	ListClass *student = new ListClass("Supervised Student Publications",0,0,true);
	ListClass *web = new ListClass("Websites/Videos",0,0,true);
	ListClass *work_papers = new ListClass("Working Papers",0,0,true);

	Pubs = *publications;

 	Book_Chapters = *book_chap;
	Books = *books;
	Book_Edited = *books_edited;
	Case_Reports = *case_rep;
	Clinical_Care_Guidelines = *clinical;
	Commentaries = *commentaries;
	Conference_Proceedings = *conf_pro;
	Editorials = *editorials;
	Invited_Articles = *invited_art;
	Journal_Article = *journal;
	Letters_to_Editor = *let_ed;
	Magazine_Entries = *mag_ent;
	Manuals = *manuals;
	Monographs= *mono;
	Multimedia = *multi;
	Newsletter_Articles = *newsletter;
	Newspaper_Articles = *news_art;
	Published_Abstract = *pub_abs;
	Supervised_Student_Publications = *student;
	Websites_Videos = *web;
	Working_Papers = *work_papers;

	year_s = s_year;
	year_e = e_year;
	data = somedata;

	Pubs.addChild(&Book_Chapters);
	Pubs.addChild(&Books);
	Pubs.addChild(&Book_Edited);
	Pubs.addChild(&Case_Reports);
	Pubs.addChild(&Clinical_Care_Guidelines);
	Pubs.addChild(&Commentaries);
	Pubs.addChild(&Conference_Proceedings);
	Pubs.addChild(&Editorials);
	Pubs.addChild(&Invited_Articles);
	Pubs.addChild(&Journal_Article);
	Pubs.addChild(&Letters_to_Editor);
	Pubs.addChild(&Magazine_Entries);
	Pubs.addChild(&Manuals);
	Pubs.addChild(&Monographs);
	Pubs.addChild(&Multimedia);
	Pubs.addChild(&Newsletter_Articles);
	Pubs.addChild(&Newspaper_Articles);
	Pubs.addChild(&Published_Abstract);
	Pubs.addChild(&Supervised_Student_Publications);
	Pubs.addChild(&Websites_Videos);
	Pubs.addChild(&Working_Papers);


}
pubmember Pub_ListBuilder::tally(string name){
 
    int numelements = 0;
    numelements =(int) data->count(name);
    std::multimap<string,Pub_rowObject>::iterator iter;
    iter = data->begin();

    //int pt = 0;
    pubmember current;
    current.name = name;
    for (iter = data->equal_range(name).first; iter!=data->equal_range(name).second;iter++){
        cout << (*iter).second.statDate << endl;
        if ((this->year_s<=(*iter).second.statDate)&&(this->year_e>=(*iter).second.statDate)){
		 if ((*iter).second.type=="Book Chapters"){
			current.book_chapters++;
		}
		 if ((*iter).second.type=="Books"){
			current.books++;                                        
                }
		 if ((*iter).second.type=="Book Edited"){
			current.book_edit++;                                        
                }
		 if ((*iter).second.type=="Case Reports"){
			current.case_rep++;                                        
                }
		 if ((*iter).second.type=="Clinical Care Guidelines"){
			current.clinical++;
		}                                        
                 if ((*iter).second.type=="Commentaries"){                                        
                	current.comments++;
		}
		 if ((*iter).second.type=="Conference Proceedings"){
			current.confer++;                                        
                }
		 if ((*iter).second.type=="Editorials"){                                        
                	current.editorials++;
		}
		 if ((*iter).second.type=="Invited Articles"){
			current.inv_art++;                                        
                }	
		 if ((*iter).second.type=="Journal Article"){
			current.journals++;                                        
                }
		 if ((*iter).second.type=="Letters to Editor"){
			current.letter_to_ed++;                                        
                }
		 if ((*iter).second.type=="Magazine Entries"){
			current.mag++;                                        
                }
		 if ((*iter).second.type=="Manuals"){
			current.man++;                                        
                }
		 if ((*iter).second.type=="Monographs"){
			current.mono++;                                        
                }
		 if ((*iter).second.type=="Multimedia"){
			current.multi++;                                        
                }
		 if ((*iter).second.type=="Newsletter Articles"){
			current.newsletter++;                                        
                }
		 if ((*iter).second.type=="Newspaper Articles"){
			current.newspaper++;                                        
                }
	 	 if ((*iter).second.type=="Published Abstract"){
			current.pub_ab++;                                        
                }
		 if ((*iter).second.type=="Supervised Student Publications"){
                        current.student_pub++;
                }
		 if ((*iter).second.type=="Websites / Videos"){
                        current.websites++;
                }
		 if ((*iter).second.type=="Working Papers"){ 
                        current.working_papers++; 
                }
	} 
    }
    return current;	
}

void Pub_ListBuilder::scanMap(){
     // create a map to keep track of visited row objects
     map<string, bool> visited;

     unsigned long mapsize;
     mapsize = data->size();

     std::multimap<string, Pub_rowObject>::iterator cur = data->begin();
     while (cur != data->end()){
	pubmember c_mem;
	if ( cur == data->begin()) {
            c_mem = this->tally(cur->second.name);
            this->addMember(c_mem);
            visited.insert(pair<string, bool>(cur->second.name, true));
        }
	else
        {
            map<string, bool>::iterator j = visited.find(cur->second.name);

            if (j == visited.end() || j->first != cur->second.name){
                c_mem = this->tally(cur->second.name);
                this->addMember(c_mem);
                visited.insert(pair<string, bool>(cur->second.name, true));
            }
        }
	++ cur;
     }
}

void Pub_ListBuilder::addMember(pubmember amember){
	
	if (amember.books > 0){
	    ListClass *books = new ListClass(amember.name,0,amember.books,false);
	    this->Books.addChild(books);
	    this->Books.param2 = this->Books.param2 + amember.books;
	    this->Pubs.param2 = this->Pubs.param2 + amember.books;    
	}
	if (amember.book_chapters > 0){
            ListClass *bookchap = new ListClass(amember.name,0,amember.book_chapters,false);
            this->Book_Chapters.addChild(bookchap);
            this->Book_Chapters.param2 = this->Book_Chapters.param2 + amember.book_chapters;
            this->Pubs.param2 = this->Pubs.param2 + amember.book_chapters;
	}
	if (amember.book_edit > 0){
            ListClass *booksedit = new ListClass(amember.name,0,amember.book_edit,false);
	    this->Book_Edited.addChild(booksedit);
            this->Book_Edited.param2 = this->Book_Edited.param2 + amember.book_edit;
	    this->Pubs.param2 = this->Pubs.param2 + amember.book_edit;
        }
	if (amember.journals > 0){
            ListClass *jour = new ListClass(amember.name,0,amember.journals,false);
	    this->Journal_Article.addChild(jour);
            this->Journal_Article.param2 = this->Journal_Article.param2 + amember.journals;
	    this->Pubs.param2 = this->Pubs.param2 + amember.journals;
        }
	if (amember.pub_ab > 0){
           ListClass *pubab = new ListClass(amember.name,0,amember.pub_ab,false);
	   this->Published_Abstract.addChild(pubab);
           this->Published_Abstract.param2 = this->Published_Abstract.param2 + amember.pub_ab;
	   this->Pubs.param2 = this->Pubs.param2 + amember.pub_ab;
        }
	if (amember.letter_to_ed > 0){
	   ListClass *lte = new ListClass(amember.name,0,amember.letter_to_ed,false);
           this->Letters_to_Editor.addChild(lte);
	   this->Letters_to_Editor.param2 = this->Letters_to_Editor.param2 + amember.letter_to_ed;
           this->Pubs.param2 = this->Pubs.param2 + amember.letter_to_ed;
	}
	if (amember.case_rep > 0){
           ListClass *crep = new ListClass(amember.name,0,amember.case_rep,false);
           this->Case_Reports.addChild(crep);
	   this->Case_Reports.param2 = this->Case_Reports.param2 + amember.case_rep;
           this->Pubs.param2 = this->Pubs.param2 + amember.case_rep;
	}
	if (amember.clinical > 0){
           ListClass *clinic = new ListClass(amember.name,0,amember.clinical,false);
           this->Clinical_Care_Guidelines.addChild(clinic);
           this->Clinical_Care_Guidelines.param2 = this->Clinical_Care_Guidelines.param2 + amember.clinical;
	   this->Pubs.param2 = this->Pubs.param2 + amember.clinical;
	}
	if (amember.comments > 0){
           ListClass *comme = new ListClass(amember.name,0,amember.comments,false);
           this->Commentaries.addChild(comme);
	   this->Commentaries.param2 = this->Commentaries.param2 + amember.comments;
           this->Pubs.param2 = this->Pubs.param2 + amember.comments;
	}
	if (amember.confer > 0){
           ListClass *conf = new ListClass(amember.name,0,amember.confer,false);
           this->Conference_Proceedings.addChild(conf);
           this->Conference_Proceedings.param2 = this->Conference_Proceedings.param2 + amember.confer;
	   this->Pubs.param2 = this->Pubs.param2 + amember.confer;
	}
	if (amember.editorials > 0){
           ListClass *eds = new ListClass(amember.name,0,amember.editorials,false);
           this->Editorials.addChild(eds);
           this->Editorials.param2 = this->Editorials.param2 + amember.editorials;
           this->Pubs.param2 = this->Pubs.param2 + amember.editorials;
	}
	if (amember.inv_art > 0){
           ListClass *ia = new ListClass(amember.name,0,amember.inv_art,false);
           this->Invited_Articles.addChild(ia);
	   this->Invited_Articles.param2 = this->Invited_Articles.param2 + amember.inv_art;
           this->Pubs.param2 = this->Pubs.param2 + amember.inv_art;
	}
	if (amember.mag > 0){
           ListClass *maga = new ListClass(amember.name,0,amember.mag,false);
           this->Magazine_Entries.addChild(maga);
           this->Magazine_Entries.param2 = this->Magazine_Entries.param2 + amember.mag;
	   this->Pubs.param2 = this->Pubs.param2 + amember.mag;
	}
	if (amember.man > 0){
           ListClass *mans = new ListClass(amember.name,0,amember.man,false);
           this->Manuals.addChild(mans);
           this->Manuals.param2 = this->Manuals.param2 + amember.man;
           this->Pubs.param2 = this->Pubs.param2 + amember.man;
	}
	if (amember.mono > 0){
           ListClass *monog = new ListClass(amember.name,0,amember.mono,false);
           this->Monographs.addChild(monog);
           this->Monographs.param2 = this->Monographs.param2 + amember.mono;
	   this->Pubs.param2 = this->Pubs.param2 + amember.mono;
	}
	if (amember.multi > 0){
           ListClass *media = new ListClass(amember.name,0,amember.multi,false);
           this->Multimedia.addChild(media);
           this->Multimedia.param2 = this->Multimedia.param2 + amember.multi;
	   this->Pubs.param2 = this->Pubs.param2 + amember.multi;
	}
	if (amember.newsletter > 0){
           ListClass *nl = new ListClass(amember.name,0,amember.newsletter,false);
           this->Newsletter_Articles.addChild(nl);
	   this->Newsletter_Articles.param2 = this->Newsletter_Articles.param2 + amember.newsletter;
           this->Pubs.param2 = this->Pubs.param2 + amember.newsletter;
	}
	if (amember.newspaper > 0){
           ListClass *nw = new ListClass(amember.name,0,amember.newspaper,false);
           this->Newspaper_Articles.addChild(nw);
	   this->Newspaper_Articles.param2 = this->Newspaper_Articles.param2 + amember.newspaper;
           this->Pubs.param2 = this->Pubs.param2 + amember.newspaper;
	}
	if (amember.student_pub > 0){
           ListClass *stpub = new ListClass(amember.name,0,amember.student_pub,false);
           this->Supervised_Student_Publications.addChild(stpub);
	   this->Supervised_Student_Publications.param2 = this->Supervised_Student_Publications.param2 + amember.student_pub;
           this->Pubs.param2 = this->Pubs.param2 + amember.student_pub;
	}
	if (amember.websites > 0){
           ListClass *web = new ListClass(amember.name,0,amember.websites,false);
           this->Websites_Videos.addChild(web);
	   this->Websites_Videos.param2 = this->Websites_Videos.param2 + amember.websites;
           this->Pubs.param2 = this->Pubs.param2 + amember.websites;
	}
	if (amember.working_papers > 0){
           ListClass *wp = new ListClass(amember.name,0,amember.working_papers,false);	
           this->Working_Papers.addChild(wp);
	   this->Working_Papers.param2 = this->Working_Papers.param2 + amember.working_papers;
           this->Pubs.param2 = this->Pubs.param2 + amember.working_papers;
	}

}
void Pub_ListBuilder::printList(ListClass alist){
    list<ListClass *> * temp = alist.getChildren();
    list<ListClass *>::iterator i = temp->begin();
    while (i != temp->end()){
        printf("Name: %s\n", (*i)->getName().c_str());
        printf("Param1: %d\n", (*i)->getParam1());
        printf("Param2: %0.2d\n", (*i)->getParam2());
        ++ i;
    }
}

