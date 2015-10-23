
#include "Grant_rowObject.h"

Grant_rowObject::Grant_rowObject(string memberName, string primaryDomain, int startDate, int endDate, string fundType, string stat, bool peerReviewed, bool indGrant, string researchRole, string researchTitle, string principalInvestigator, string coInvestigator, int totalAmount){

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

