#include "Pub_ListBuilder.h"
#include <iterator>
#include <list>
#include <iostream>

using namespace std;

Pub_ListBuilder::Pub_ListBuilder(int s_year,int e_year,multimap<string,Pub_rowObject>*somedata){
	
    // create list headers for each type of publication
    
    ListClass *publications = new ListClass("Publications", -1, -1, true);
    ListClass *pub_abs = new ListClass("Published Abstracts", -1, -1, true);
    ListClass *books = new ListClass("Books",-1,-1,true);
    ListClass *books_edited = new ListClass("Books Edited",-1,-1,true);
    ListClass *book_chap = new ListClass("Book Chapters",-1,-1,true);
    ListClass *case_rep = new ListClass("Case Reports",-1,-1,true);
    ListClass *clinical = new ListClass("Clinical Care guidelines",-1,-1,true);
    ListClass *journal = new ListClass("Journal Articles",-1,-1,true);
    ListClass *commentaries = new ListClass("Commentaries",-1,-1,true);
    ListClass *conf_pro = new ListClass("Conference Proceedings",-1,-1,true);
    ListClass *editorials = new ListClass("Editorials",-1,-1,true);
    ListClass *invited_art = new ListClass("Invited Articles",-1,-1,true);
    ListClass *let_ed = new ListClass("Letters to Editor",-1,-1,true);
    ListClass *mag_ent = new ListClass("Magazine Entries",-1,-1,true);
    ListClass *manuals = new ListClass("Manuals",-1,-1,true);
    ListClass *mono = new ListClass("Monographs",-1,-1,true);
    ListClass *multi = new ListClass("Multimedia",-1,-1,true);
    ListClass *newsletter = new ListClass("Mewsletter Articles",-1,-1,true);
    ListClass *news_art = new ListClass("Newspaper Articles",-1,-1,true);
    ListClass *student = new ListClass("Supervised Student Publications",-1,-1,true);
    ListClass *web = new ListClass("Websites/Videos",-1,-1,true);
    ListClass *work_papers = new ListClass("Working Papers",-1,-1,true);

	this->Pubs = *publications;

 	this->Book_Chapters = *book_chap;
	this->Books = *books;
	this->Book_Edited = *books_edited;
	this->Case_Reports = *case_rep;
	this->Clinical_Care_Guidelines = *clinical;
	this->Commentaries = *commentaries;
	this->Conference_Proceedings = *conf_pro;
	this->Editorials = *editorials;
	this->Invited_Articles = *invited_art;
	this->Journal_Article = *journal;
	this->Letters_to_Editor = *let_ed;
	this->Magazine_Entries = *mag_ent;
	this->Manuals = *manuals;
	this->Monographs= *mono;
	this->Multimedia = *multi;
	this->Newsletter_Articles = *newsletter;
	this->Newspaper_Articles = *news_art;
	this->Published_Abstract = *pub_abs;
	this->Supervised_Student_Publications = *student;
	this->Websites_Videos = *web;
	this->Working_Papers = *work_papers;

	this->year_s = s_year;
	this->year_e = e_year;
	this->data = somedata;

	this->Pubs.addChild(&Book_Chapters);
	this->Pubs.addChild(&Books);
	this->Pubs.addChild(&Book_Edited);
	this->Pubs.addChild(&Case_Reports);
	this->Pubs.addChild(&Clinical_Care_Guidelines);
	this->Pubs.addChild(&Commentaries);
	this->Pubs.addChild(&Conference_Proceedings);
	this->Pubs.addChild(&Editorials);
	this->Pubs.addChild(&Invited_Articles);
	this->Pubs.addChild(&Journal_Article);
	this->Pubs.addChild(&Letters_to_Editor);
	this->Pubs.addChild(&Magazine_Entries);
	this->Pubs.addChild(&Manuals);
    this->Pubs.addChild(&Monographs);
	this->Pubs.addChild(&Multimedia);
	this->Pubs.addChild(&Newsletter_Articles);
	this->Pubs.addChild(&Newspaper_Articles);
	this->Pubs.addChild(&Published_Abstract);
	this->Pubs.addChild(&Supervised_Student_Publications);
	this->Pubs.addChild(&Websites_Videos);
	this->Pubs.addChild(&Working_Papers);


}
pubmember Pub_ListBuilder::tally(string name){
 
    int numelements = 0;
    numelements =(int) data->count(name);
    std::multimap<string,Pub_rowObject>::iterator iter;
    iter = data->begin();

    pubmember current;
    // initialize struct
    current.name = name;
    current.book_chapters = 0;
    current.book_edit = 0;
    current.books = 0;
    current.case_rep = 0;
    current.clinical = 0;
    current.comments = 0;
    current.confer = 0;
    current.editorials = 0;
    current.inv_art = 0;
    current.journals = 0;
    current.letter_to_ed = 0;
    current.mag = 0;
    current.man = 0;
    current.mono = 0;
    current.newsletter = 0;
    current.newspaper = 0;
    current.pub_ab= 0;
    current.student_pub = 0;
    current.websites = 0;
    current.working_papers = 0;
    current.multi = 0;
    
    for (iter = data->equal_range(name).first; iter!=data->equal_range(name).second;iter++){
        //cout << (*iter).second.statDate << endl;
        cout << iter->second.type << endl;
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
         map<string, bool>::iterator j = visited.find(cur->second.name);
         if (j == visited.end()){
             pubmember mem;
             mem = this->tally(cur->second.name);
             this->addMember(mem);
             visited.insert(pair<string, bool>(cur->second.name, true));
         }
         ++ cur;
     }
}

void Pub_ListBuilder::addMember(pubmember amember){
    printf("amember name:%s\n",amember.name.c_str());
	if (amember.books > 0){
        ListClass *books = new ListClass(amember.name.c_str(),amember.books,-1,false);
	    this->Books.addChild(books);
	    this->Books.param2 = this->Books.param2 + amember.books;
	    this->Pubs.param2 = this->Pubs.param2 + amember.books;    
	}
	if (amember.book_chapters > 0){
            ListClass *bookchap = new ListClass(amember.name,amember.book_chapters,-1,false);
            this->Book_Chapters.addChild(bookchap);
            this->Book_Chapters.param2 = this->Book_Chapters.param2 + amember.book_chapters;
            this->Pubs.param2 = this->Pubs.param2 + amember.book_chapters;
	}
	if (amember.book_edit > 0){
            ListClass *booksedit = new ListClass(amember.name,amember.book_edit,-1,false);
	    this->Book_Edited.addChild(booksedit);
            this->Book_Edited.param2 = this->Book_Edited.param2 + amember.book_edit;
	    this->Pubs.param2 = this->Pubs.param2 + amember.book_edit;
        }
	if (amember.journals > 0){
            ListClass *jour = new ListClass(amember.name,amember.journals,-1,false);
	    this->Journal_Article.addChild(jour);
            this->Journal_Article.param2 = this->Journal_Article.param2 + amember.journals;
	    this->Pubs.param2 = this->Pubs.param2 + amember.journals;
        }
	if (amember.pub_ab > 0){
           ListClass *pubab = new ListClass(amember.name,amember.pub_ab,-1,false);
	   this->Published_Abstract.addChild(pubab);
           this->Published_Abstract.param2 = this->Published_Abstract.param2 + amember.pub_ab;
	   this->Pubs.param2 = this->Pubs.param2 + amember.pub_ab;
        }
	if (amember.letter_to_ed > 0){
       ListClass *lte = new ListClass(amember.name,amember.letter_to_ed,-1,false);
           this->Letters_to_Editor.addChild(lte);
	   this->Letters_to_Editor.param2 = this->Letters_to_Editor.param2 + amember.letter_to_ed;
           this->Pubs.param2 = this->Pubs.param2 + amember.letter_to_ed;
	}
	if (amember.case_rep > 0){
           ListClass *crep = new ListClass(amember.name,amember.case_rep,-1,false);
           this->Case_Reports.addChild(crep);
	   this->Case_Reports.param2 = this->Case_Reports.param2 + amember.case_rep;
           this->Pubs.param2 = this->Pubs.param2 + amember.case_rep;
	}
	if (amember.clinical > 0){
           ListClass *clinic = new ListClass(amember.name,amember.clinical,-1,false);
           this->Clinical_Care_Guidelines.addChild(clinic);
           this->Clinical_Care_Guidelines.param2 = this->Clinical_Care_Guidelines.param2 + amember.clinical;
	   this->Pubs.param2 = this->Pubs.param2 + amember.clinical;
	}
	if (amember.comments > 0){
           ListClass *comme = new ListClass(amember.name,amember.comments,-1,false);
           this->Commentaries.addChild(comme);
	   this->Commentaries.param2 = this->Commentaries.param2 + amember.comments;
           this->Pubs.param2 = this->Pubs.param2 + amember.comments;
	}
	if (amember.confer > 0){
           ListClass *conf = new ListClass(amember.name,amember.confer,-1,false);
           this->Conference_Proceedings.addChild(conf);
           this->Conference_Proceedings.param2 = this->Conference_Proceedings.param2 + amember.confer;
	   this->Pubs.param2 = this->Pubs.param2 + amember.confer;
	}
	if (amember.editorials > 0){
           ListClass *eds = new ListClass(amember.name,amember.editorials,-1,false);
           this->Editorials.addChild(eds);
           this->Editorials.param2 = this->Editorials.param2 + amember.editorials;
           this->Pubs.param2 = this->Pubs.param2 + amember.editorials;
	}
	if (amember.inv_art > 0){
           ListClass *ia = new ListClass(amember.name,amember.inv_art,-1,false);
           this->Invited_Articles.addChild(ia);
	   this->Invited_Articles.param2 = this->Invited_Articles.param2 + amember.inv_art;
           this->Pubs.param2 = this->Pubs.param2 + amember.inv_art;
	}
	if (amember.mag > 0){
           ListClass *maga = new ListClass(amember.name,amember.mag,-1,false);
           this->Magazine_Entries.addChild(maga);
           this->Magazine_Entries.param2 = this->Magazine_Entries.param2 + amember.mag;
	   this->Pubs.param2 = this->Pubs.param2 + amember.mag;
	}
	if (amember.man > 0){
           ListClass *mans = new ListClass(amember.name,amember.man,-1,false);
           this->Manuals.addChild(mans);
           this->Manuals.param2 = this->Manuals.param2 + amember.man;
           this->Pubs.param2 = this->Pubs.param2 + amember.man;
	}
	if (amember.mono > 0){
           ListClass *monog = new ListClass(amember.name,amember.mono,-1,false);
           this->Monographs.addChild(monog);
           this->Monographs.param2 = this->Monographs.param2 + amember.mono;
	   this->Pubs.param2 = this->Pubs.param2 + amember.mono;
	}
	if (amember.multi > 0){
           ListClass *media = new ListClass(amember.name,amember.multi,-1,false);
           this->Multimedia.addChild(media);
           this->Multimedia.param2 = this->Multimedia.param2 + amember.multi;
	   this->Pubs.param2 = this->Pubs.param2 + amember.multi;
	}
	if (amember.newsletter > 0){
           ListClass *nl = new ListClass(amember.name,amember.newsletter,-1,false);
           this->Newsletter_Articles.addChild(nl);
	   this->Newsletter_Articles.param2 = this->Newsletter_Articles.param2 + amember.newsletter;
           this->Pubs.param2 = this->Pubs.param2 + amember.newsletter;
	}
	if (amember.newspaper > 0){
           ListClass *nw = new ListClass(amember.name,amember.newspaper,-1,false);
           this->Newspaper_Articles.addChild(nw);
	   this->Newspaper_Articles.param2 = this->Newspaper_Articles.param2 + amember.newspaper;
           this->Pubs.param2 = this->Pubs.param2 + amember.newspaper;
	}
	if (amember.student_pub > 0){
           ListClass *stpub = new ListClass(amember.name,amember.student_pub,-1,false);
           this->Supervised_Student_Publications.addChild(stpub);
	   this->Supervised_Student_Publications.param2 = this->Supervised_Student_Publications.param2 + amember.student_pub;
           this->Pubs.param2 = this->Pubs.param2 + amember.student_pub;
	}
	if (amember.websites > 0){
           ListClass *web = new ListClass(amember.name,amember.websites,-1,false);
           this->Websites_Videos.addChild(web);
	   this->Websites_Videos.param2 = this->Websites_Videos.param2 + amember.websites;
           this->Pubs.param2 = this->Pubs.param2 + amember.websites;
	}
	if (amember.working_papers > 0){
           ListClass *wp = new ListClass(amember.name,amember.working_papers,-1,false);
           this->Working_Papers.addChild(wp);
	   this->Working_Papers.param2 = this->Working_Papers.param2 + amember.working_papers;
           this->Pubs.param2 = this->Pubs.param2 + amember.working_papers;
	}

}
void Pub_ListBuilder::printList(ListClass alist){
    
    printf("%s      ", alist.getName().c_str()); // print the list
    printf("%d\n", alist.getParam2());
    
    list<ListClass *> * temp = alist.getChildren(); // print its children
    if (temp!=NULL){
        list<ListClass *>::iterator i = temp->begin();
        while (i != temp->end()){
           printList(*(*i));
           i++;
        }
    }
}

