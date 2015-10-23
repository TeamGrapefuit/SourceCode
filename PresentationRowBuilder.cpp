//
//  PresentationRowBuilder.cpp
//  
//
//  Created by Jason Smash on 2015-10-17.
//
//

#include "PresentationRowBuilder.h"

Pres_rowObject PresentationRowBuilder::buildRow(string data, ColIndex index){
    
    AttributeRetriever fetch(data);
    
    //retrieve each attribute - temporarily store them
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string type = fetch.getAttribute(index.type_loc);
    string role = fetch.getAttribute(index.role_loc);
    string title = fetch.getAttribute(index.title_loc);
    
    int date = fetch.getIntAttribute(index.date_loc);

    Pres_rowObject currentRow(name, domain, date, type, role, title);
    
    return currentRow;
    };
