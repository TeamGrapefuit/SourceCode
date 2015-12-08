//
//  Pub_rowObject.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-22.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//

#include "Pub_rowObject.h"

//Constructor
//input: all parameters
//output: nope
Pub_rowObject::Pub_rowObject(bool error, string memberName, string primaryDomain, string publicationStatus, string journalType, string journalRole, string journalAuthor, string journalName, string journalTitle, int statusDate){
    
    this->errorFlag = error;
    
    name = memberName;
    domain = primaryDomain;
    pubStatus = publicationStatus;
    type = journalType;
    role = journalRole;
    title = journalTitle;
    author = journalAuthor;
    jName = journalName;
    
    statDate = statusDate;
    totalPub = 1;
}

//default constructor
//inout: nope
//output: nope

Pub_rowObject::Pub_rowObject(){
    
    this->errorFlag = 0;
    
    name = "";
    domain = "";
    pubStatus = "";
    type = "";
    role = "";
    title = "";
    author = "";
    jName = "";
    
    statDate = 0;
    totalPub = 0;
}



//infoDump
//input: nope
//output: a string describing each member of this object
string Pub_rowObject::infoDump(){
    string rowObject = "";
    
    //error flag
    rowObject.append("Error in Row: ");
    if (errorFlag) {
        rowObject.append("true\n");
    }
    else{
        rowObject.append("false\n");
    }
    
    
    //Member Name
    rowObject.append("Member Name: ");
    rowObject.append(name);
    rowObject.append("\n");
    
    //Primary Domain
    rowObject.append("Primary Domain: ");
    rowObject.append(domain);
    rowObject.append("\n");
    
    //stat
    rowObject.append("Status: ");
    rowObject.append(pubStatus);
    rowObject.append("\n");
    
    //fundtype
    rowObject.append("Journal Type: ");
    rowObject.append(type);
    rowObject.append("\n");
    
    //role
    rowObject.append("Journal Role: ");
    rowObject.append(role);
    rowObject.append("\n");
    
    //Journal Title
    rowObject.append("Journal Title: ");
    rowObject.append(title);
    rowObject.append("\n");
    
    //j author
    rowObject.append("Journal Author: ");
    rowObject.append(author);
    rowObject.append("\n");
    
    //j name
    rowObject.append("Journal Name: ");
    rowObject.append(jName);
    rowObject.append("\n");
    
    
    //start date
    rowObject.append("Date Status was Updated: ");
    rowObject.append(to_string(statDate));
    rowObject.append("\n");
    
    //end date
    rowObject.append("Total Number of Publications: ");
    rowObject.append(to_string(totalPub));
    rowObject.append("\n");
    
    return rowObject;
    
}
