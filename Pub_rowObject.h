//
//  Pub_rowObject.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//  This Class contains the implementation of the PUBLICATION row object (an easy-acess container structure for holing the data from an individual row on the CSV.
//  This data is held in public member variables for ease of programming (fewer getters/setters required)

#include <string>

using namespace std;

#pragma once

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
    
    //constructor - creates a fullly operational rowObject
    Pub_rowObject(bool error, string memberName, string primaryDomain, string publicationStatus, string journalType, string journalRole, string journalAuthor, string journalName, string journalTitle, int statusDate);
    
    //Default Constructor - required by director
    Pub_rowObject();

    // this is sort of like a ToString Function - used for dumping errors
    string infoDump();
};




