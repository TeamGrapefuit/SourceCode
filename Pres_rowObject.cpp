//
//  Pres_rowObject.cpp
//  
//
//  Created by Jason Smash on 2015-10-22.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//  This Class contains the implementation of the PRESENTATION row object (an easy-acess container structure for holing the data from an individual row on the CSV.


#include <stdio.h>
#include "Pres_rowObject.h"


//constructor
//input: all parameters
//output: Nope
Pres_rowObject::Pres_rowObject(bool error, string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle){
  
    errorFlag = error;
    
    name = memberName;
    domain = primaryDomain;
    type = presentationType;
    role = presentationRole;
    title = presentationTitle;
  
    date = presentationDate;
    numPresent = 1;
    
};

//default constructor
//input: nope
//output: nope
Pres_rowObject::Pres_rowObject(){
 
    errorFlag = 0;
    
    name = "";
    domain = "";
    type = "";
    role = "";
    title = "";
    
    date = 0;
    numPresent = 0;
}

//infoDump
//input: nope
//output: a string describing each member of this object
string Pres_rowObject::infoDump(){
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
    
    //fundtype
    rowObject.append("Presentation Type: ");
    rowObject.append(type);
    rowObject.append("\n");
    
    
    //role
    rowObject.append("Role: ");
    rowObject.append(role);
    rowObject.append("\n");
    
    //pinvestigator
    rowObject.append("Title: ");
    rowObject.append(title);
    rowObject.append("\n");
    
    
    // date
    rowObject.append("Date: ");
    rowObject.append(to_string(date));
    rowObject.append("\n");
    
    //number of presentations
    rowObject.append("Number of Presentations: ");
    rowObject.append(to_string(numPresent));
    rowObject.append("\n");
    
    return rowObject;
}
