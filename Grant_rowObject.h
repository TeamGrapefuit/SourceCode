//
//  Pub_rowObject.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//  This Class contains the implementation of the GRANTS row object (an easy-acess container structure for holing the data from an individual row on the CSV.
//  This data is held in public member variables for ease of programming (fewer getters/setters required)

#include <string>

using namespace std;

#pragma once

class Grant_rowObject{

    public:
//flag: true = error, false = no error
    bool errorFlag;
    
//Member varables for Grants

    string name; //Member Name
    string domain; //Primary Domain
    string fundType;//Funding Type (Grants or Clinical Trials)
    string stat; //Status
    string role; //research role
    string title; //Research Title
    string pInvestigator; //Primary Investigator
    string cpInvestigator; //co Investogator
    
    bool peerReviewed; //True = is peer reviewed, False = not peer reviewed
    bool indGrant; //True = Industry Grant, False = not and industry grant

    int sDate; //Start Date
    int edate; // end date
    
    long long totalAmount; // total amount
    
    int count; //number of grants (same member, same year etc.), starts as 1
    
    //constructor - creates a fullly operational rowObject
    Grant_rowObject(bool error, string memberName, string primaryDomain, int startDate, int endDate, string fundType, string stat, bool peerReviewed, bool indGrant, string researchRole, string researchTitle, string principalInvestigator, string coInvestigator, long long totalAmount);
    
    //defult constructor - used by director
    Grant_rowObject();
};
