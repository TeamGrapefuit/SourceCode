#pragma once
#include <iostream>
#include <string>
using std::string;

class rowObject
{
public:
	//Column Types for Teaching
	string name, domain, program, courseType, geoScope;
	int nTeach, sDate, eDate;
	float hpTeach, tHours;

	//Column Types for Publication (duplicates not included)
	string pubStatus, type, role, title, author, jName;
	int statDate;

	//Column Types for Grants and Funding (duplicates not included)
	string fundingType, status, pInvestigator, cInvestigator;
	bool peerReview, industryGrant;
	int tAmount;

	//Column Types for Presentations (duplicates not included)
	int date;


	//Constructor Declarations
	rowObject(string memberName, string primaryDomain, int startDate, int endDate, string prog, string typeOfCourse, string scope, float hpt, int numberTeach, float totalHours);

	rowObject(string memberName, string primaryDomain, string publicationStatus, string journalType, int statusDate, string journalRole, string journalName, string journalAuthor, string journalTitle);

	rowObject(string memberName, string primaryDomain, int startDate, int endDate, string fundType, string stat, bool peerReviewed, bool indGrant, string researchRole, string researchTitle, string principalInvestigator,
		string coInvestigator, int totalAmount);

	rowObject(string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle);

};


