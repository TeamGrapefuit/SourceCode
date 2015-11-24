
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

    Grant_rowObject(bool error, string memberName, string primaryDomain, int startDate, int endDate, string fundType, string stat, bool peerReviewed, bool indGrant, string researchRole, string researchTitle, string principalInvestigator, string coInvestigator, long long totalAmount);

    Grant_rowObject();
};
