//
//  Pub_rowObject.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-22.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "Pub_rowObject.h"

Pub_rowObject::Pub_rowObject(bool error, string memberName, string primaryDomain, string publicationStatus, string journalType, string journalRole, string journalAuthor, string journalName, string journalTitle, int statusDate){
    
    this->errorFlag = error;
    
    name = memberName;
    domain = primaryDomain;
    pubStatus = publicationStatus;
    type = journalType;
    role = journalRole;
    title = journalTitle;
    author = journalAuthor;
    jName = journalName;
    
    statDate = statusDate;
    totalPub = 1;
}
