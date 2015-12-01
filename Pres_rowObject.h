
//
//  Pres_rowObject.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//  This Class contains the implementation of the PRESENTATION row object (an easy-acess container structure for holing the data from an individual row on the CSV.
//  This data is held in public member variables for ease of programming (fewer getters/setters required)

#include <stdio.h>
#include <string>

#pragma once

using namespace std;

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

    //constructor - creates a fullly operational rowObject
    Pres_rowObject(bool error, string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle);
    
    //default constructor - required by director
    Pres_rowObject();
};
