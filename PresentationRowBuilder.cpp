//
//  PresentationRowBuilder.cpp
//  
//
//  Created by Jason Smash on 2015-10-17.
//
//

#include "PresentationRowBuilder.h"

//build presentation row
//input: string of row from csv, column index map
//ooutput: fully build row object
Pres_rowObject PresentationRowBuilder::buildRow(string data, ColIndex index){
    
    // *** Instantiate classes that will help out in this function
    AttributeRetriever fetch(data);
    bool hasError = 0; //This will be set to 1 if an error is found
    ErrorChecker filter;
    bool enableErrorChecking (1); //for debugging
    
    //*** retrieve each attribute - temporarily store them
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string type = fetch.getAttribute(index.type_loc);
    string role = fetch.getAttribute(index.role_loc);
    string title = fetch.getAttribute(index.title_loc);
    
    int date = fetch.getIntAttribute(index.date_loc);

    //*** Error Checking
    
    if (enableErrorChecking){
        
        //Strings - check for blanks fields
        name = filter.blankCatch(name, hasError);
        domain = filter.blankCatch(domain, hasError);
        type = filter.blankCatch(type, hasError);
        role = filter.blankCatch(role, hasError);
        title = filter.blankCatch(title, hasError);
        
        //dates - check for zeroes
        date = filter.zeroCatch(date, hasError);
        
    }
        
    //*** Build Row
    Pres_rowObject currentRow(hasError, name, domain, date, type, role, title);
    

    return currentRow;
    };
