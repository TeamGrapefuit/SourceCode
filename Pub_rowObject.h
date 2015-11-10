//
//  Pub_rowObject.h
//  Phase1
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include <stdio.h>
#include <string>


using namespace std;

class Pub_rowObject{
public:
    
    
    //flag: true = error, false = no error
    bool errorFlag;
    
//Column Types for Publication (duplicates not included)
    string name; //memberName
    string domain; //primary Domain
    string pubStatus; // Publication Status
    string type; //Journal Type
    string role; //Journal Role
    string title; //Journal Title
    string author;// Journal Author
    string jName; //Journal Name
    
    int statDate; //Status Date
    int totalPub; //Total number of publications
    
    Pub_rowObject(bool error, string memberName, string primaryDomain, string publicationStatus, string journalType, string journalRole, string journalAuthor, string journalName, string journalTitle, int statusDate);

};




