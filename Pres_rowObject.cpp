//
//  Pres_rowObject.cpp
//  
//
//  Created by Jason Smash on 2015-10-22.
//
//

#include <stdio.h>
#include "Pres_rowObject.h"



Pres_rowObject::Pres_rowObject(string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle){
  
    name = memberName;
    domain = primaryDomain;
    type = presentationType;
    role = presentationRole;
    title = presentationTitle;
    
    date = presentationDate;
    
};