//
//  Created by Jason Smash on 2015-10-22.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//

#include "Grant_rowObject.h"

//constructor
//input: all parameters
//output: nope
Grant_rowObject::Grant_rowObject(bool error, string memberName, string primaryDomain, int startDate, int endDate, string fundType, string stat, bool peerReviewed, bool indGrant, string researchRole, string researchTitle, string principalInvestigator, string coInvestigator, long long totalAmount){

    
    this->errorFlag = error;//set error
    
    this->name = memberName; //Member Name
    this->domain = primaryDomain; //Primary Domain
    this->fundType = fundType;//Funding Type
    this->stat = stat; //Status
    this->role = researchRole; //research role
    this->title = researchTitle; //Research Title
    this->pInvestigator = principalInvestigator; //Primary Investigator
    this->cpInvestigator = coInvestigator; //co Investogator
    
    this->peerReviewed = peerReviewed; //True = is peer reviewed, False = not peer reviewed
    this->indGrant = indGrant; //True = Industry Grant, False = not and industry grant

    this->sDate = startDate; //Start Date
    this->edate = endDate; // end date
    this->totalAmount = totalAmount; // total amount
    
    count = 1; //init count as 1 

}

//default constructor
//input:nope
//output:nope
Grant_rowObject::Grant_rowObject(){
    
    this->errorFlag = 0;
    
    this->name = "";
    this->domain = "";
    this->fundType = "";
    this->stat = "";
    this->role = "";
    this->title = "";
    this->pInvestigator = "";
    this->cpInvestigator = "";
    
    this->peerReviewed = 0;
    this->indGrant = 0;
    
    this->sDate = 0;
    this->edate = 0;
    this->totalAmount = 0;
    
    count = 0;
}

//infoDump
//input: nope
//output: a string describing each member of this object
string Grant_rowObject::infoDump(){
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
    rowObject.append("Funding Type: ");
    rowObject.append(fundType);
    rowObject.append("\n");
    
    //stat
    rowObject.append("Status: ");
    rowObject.append(stat);
    rowObject.append("\n");
    
    //role
    rowObject.append("Research Role: ");
    rowObject.append(role);
    rowObject.append("\n");
    
    //pinvestigator
    rowObject.append("Principal Investigator: ");
    rowObject.append(pInvestigator);
    rowObject.append("\n");
    
    //coinvestigator
    rowObject.append("CoInvestigator: ");
    rowObject.append(cpInvestigator);
    rowObject.append("\n");
    
    //Peer Reviewed
    if (peerReviewed) {
        rowObject.append("Paper is Peer Reviewed\n");
    }
    else{
        rowObject.append("Paper is not Peer Reviewed\n");
    }
    
    //industry grant
    if(indGrant) {
        rowObject.append("Industry Grant Received\n");
    }
    else{
        rowObject.append("industry Grant not Received\n");
    }
    
    
    //start date
    rowObject.append("Start Date: ");
    rowObject.append(to_string(sDate));
    rowObject.append("\n");
    
    //end date
    rowObject.append("End Date: ");
    rowObject.append(to_string(edate));
    rowObject.append("\n");
    
    return rowObject;
       
}