
//
//  Pres_rowObject.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//
#include <stdio.h>
#include <string>

#pragma once

using namespace std;
#pragma once

class Pres_rowObject{
public:
    
    //flag: true = error, false = no error
    bool errorFlag;
    
    //Member variables for presentation rowObjects

    string name;//memberName
    string domain; //Primary Domain
    string type; //Presentation Type
    string role; //presentation role
    string title; // Presentation Title
    
    int date; // Presentation Date
    int numPresent; //Number of presentations

    Pres_rowObject(bool error, string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle);

    Pres_rowObject();
};
