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

Pub_rowObject PublicationRowBuilder::buildRow(string data, ColIndex index){
    
    //*** instantiate classes that will help us out in this function
    AttributeRetriever fetch(data);
    bool hasError = 0; //Set this to true if an error is found
    ErrorChecker filter;
    
    //*** retrieve each attribute - temporarily store them
    
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string pubStatus = fetch.getAttribute(index.pubStatus_loc);
    string type = fetch.getAttribute(index.type_loc);
    string role = fetch.getAttribute(index.role_loc);
    string title = fetch.getAttribute(index.title_loc);
    string jName = fetch.getAttribute(index.jName_loc);

    cout << "The column is: " << index.type_loc << endl;
    //Dealing with the potential for multiple authors or zero authors
    string author = fetch.getAttribute(index.author_loc);
    int numberOfAuthors = fetch.countStrings(author);
    if (numberOfAuthors == 0){
        author = "NO_AUTHOR_LISTED"; //to become error message
        hasError = true;
    }
    else{
        author = fetch.grabFirstString(author);
    }
    
    int statDate = fetch.getIntAttribute(index.statDate_loc);

    //*** Error Checking
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
    
    
    
    
    Pub_rowObject currentRow (hasError, name, domain, pubStatus, type, role, author, jName, title, statDate);
    
    return currentRow;
};
