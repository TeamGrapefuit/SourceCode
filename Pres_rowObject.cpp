//
//  Pres_rowObject.cpp
//  
//
//  Created by Jason Smash on 2015-10-22.
//
//

#include <stdio.h>
#include "Pres_rowObject.h"



Pres_rowObject::Pres_rowObject(bool error, string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle){
  
    this->errorFlag = error;
    
    name = memberName;
    domain = primaryDomain;
    type = presentationType;
    role = presentationRole;
    title = presentationTitle;
  
    date = presentationDate;
    numPresent = 1;
    
};

Pres_rowObject::Pres_rowObject(){
 
    this->errorFlag = 0;
    
    name = "";
    domain = "";
    type = "";
    role = "";
    title = "";
    
    date = 0;
    numPresent = 0;
}