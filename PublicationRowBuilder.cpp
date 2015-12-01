//
//  PublicationRowBuilder.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "PublicationRowBuilder.h"

#include <iostream>
using namespace std;

//retrieve each attribute, error checking, build rowobject
//input: string of row from CSV, column index
//output: completd row object
Pub_rowObject PublicationRowBuilder::buildRow(string data, ColIndex index){
    
    //*** instantiate classes that will help us out in this function
    AttributeRetriever fetch(data);
    bool hasError = 0; //Set this to true if an error is found
    ErrorChecker filter;
    bool enableErrorChecking (1);
    
    //*** retrieve each attribute - temporarily store them
    
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string pubStatus = fetch.getAttribute(index.pubStatus_loc);
    string type = fetch.getAttribute(index.type_loc);
    string role = fetch.getAttribute(index.role_loc);
    string title = fetch.getAttribute(index.title_loc);
    string jName = fetch.getAttribute(index.jName_loc);

    //Dealing with the potential for multiple authors or zero authors
    string author = fetch.getAttribute(index.author_loc);
    int numberOfAuthors = fetch.countStrings(author);
    if (numberOfAuthors == 0){
        author = "NO_AUTHOR_LISTED";
        hasError = true;
    }
    else{
        author = fetch.grabFirstString(author);
    }
    
    int statDate = fetch.getIntAttribute(index.statDate_loc);

    //*** Error Checking
    if(enableErrorChecking){
        
        //strings - check for blanks
        name = filter.blankCatch(name, hasError);
        domain = filter.blankCatch(domain, hasError);
        pubStatus = filter.blankCatch(pubStatus, hasError);
        type = filter.blankCatch(type, hasError);
        role = filter.blankCatch(role, hasError);
        title = filter.blankCatch(title, hasError);
        jName = filter.blankCatch(jName, hasError);
        
        //dates check for zeroes
        statDate = filter.zeroCatch(statDate, hasError);
        
        //Assert Publication Statuses
        string acceptable_PubStatuses [3] = {"Published","In-Press","Accepted"};
        pubStatus = filter.stringAssert(pubStatus, hasError, 3, acceptable_PubStatuses);
        
        //Assert Role
        string acceptable_roles[6] = {"Principal Author","Co-Author","Collaborator","Senior Responsible Author","Editor","Reviewer"};
        role = filter.stringAssert(role, hasError, 6, acceptable_roles);
        
        //Assert Type
        // there are 21 possible types of publication. to improve error checking efficiency, we will not be asserting publication type here - if this becomes a problem in future, the code to do so will go here
    }
    
    Pub_rowObject currentRow (hasError, name, domain, pubStatus, type, role, author, jName, title, statDate);
    
    return currentRow;
};
