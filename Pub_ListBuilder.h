#pragma once
#include <stdio.h>
#include <string>

#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "listclass.h"
#endif
//#include "listclass.h"
#include "Pub_rowObject.h"
#include <map>
#include <functional>

struct pubmember{
	string name;
	int pub_ab;
	int journals;
	int books;
	int book_chapters;
	int book_edit;
	int letter_to_ed;
	int case_rep;
	int clinical;
	int comments;
	int confer;
	int editorials;
	int inv_art;
	int mag;
	int man;
	int mono;
	int multi;
	int newsletter;
	int newspaper;
	int student_pub;
	int websites;
	int working_papers;
};
class Pub_ListBuilder {
public:
    Pub_ListBuilder(int startyear,int endyear,multimap<string,Pub_rowObject> *data);
	void scanMap();
    void printList(ListClass);
	
	ListClass Pubs;

 	ListClass Book_Chapters;
	ListClass Books;
	ListClass Book_Edited;
	ListClass Case_Reports;
	ListClass Clinical_Care_Guidelines;
	ListClass Commentaries;
	ListClass Conference_Proceedings;
	ListClass Editorials;
	ListClass Invited_Articles;
	ListClass Journal_Article;
	ListClass Letters_to_Editor;
	ListClass Magazine_Entries;
	ListClass Manuals;
	ListClass Monographs;
	ListClass Multimedia;
	ListClass Newsletter_Articles;
	ListClass Newspaper_Articles;
	ListClass Published_Abstract;
	ListClass Supervised_Student_Publications;
	ListClass Websites_Videos;
	ListClass Working_Papers;

private: 
        int year_s;
        int year_e;
        multimap<string,Pub_rowObject>* data;
        pubmember tally(string);
        void addMember(pubmember);

};
	
