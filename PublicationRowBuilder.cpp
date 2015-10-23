//
//  PublicationRowBuilder.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "PublicationRowBuilder.h"


Pub_rowObject PublicationRowBuilder::buildRow(string data, ColIndex index){
    
    AttributeRetriever fetch(data);
    
    //retrieve each attribute - temporarily store them
    
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
        author = "NO AUTHOR LISTED"; //to become error message
    }
    else{
        author = fetch.grabFirstString(author);
    }
    
    int statDate = fetch.getIntAttribute(index.statDate_loc);
    
    
    Pub_rowObject currentRow (name, domain, pubStatus, type, role, author, jName, title, statDate);
    
    return currentRow;
};