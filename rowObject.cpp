#include "rowObject.h"

	//Constructor for Teaching
	rowObject::rowObject(string memberName, string primaryDomain, int startDate, int endDate, string prog, string typeOfCourse, string scope, float hpt, int numberTeach, float totalHours)
	{
		name = memberName;
		domain = primaryDomain;
		sDate = startDate;
		eDate = endDate;
		program = prog;
		courseType = typeOfCourse;
		hpTeach = hpt;
		nTeach = numberTeach;
		tHours = totalHours;
		geoScope = scope;
	}

	//Constructor for Publication
	rowObject::rowObject(string memberName, string primaryDomain, string publicationStatus, string journalType, int statusDate, string journalRole, string journalName, string journalAuthor, string journalTitle)
	{
		name = memberName;
		domain = primaryDomain;
		pubStatus = publicationStatus;
		type = journalType;
		statDate = statusDate;
		role = journalRole;
		title = journalTitle;
		jName = journalName;
		statDate = statusDate;
		author = journalAuthor;
	}

	//Constructor for Grants and Funding
	rowObject::rowObject(string memberName, string primaryDomain, int startDate, int endDate, string fundType, string stat, bool peerReviewed, bool indGrant, string researchRole, string researchTitle, string principalInvestigator,
		string coInvestigator, int totalAmount)
	{
		name = memberName;
		domain = primaryDomain;
		sDate = startDate;
		eDate = endDate;
		fundingType = fundType;
		status = stat;
		peerReview = peerReviewed;
		industryGrant = indGrant;
		role = researchRole;
		title = researchTitle;
		pInvestigator = principalInvestigator;
		cInvestigator = coInvestigator;
		tAmount = totalAmount;
	}

	//Constructor for Presentations
	rowObject::rowObject(string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle)
	{
		name = memberName;
		domain = primaryDomain;
		date = presentationDate;
		type = presentationType;
		role = presentationRole;
		title = presentationTitle;
	}

