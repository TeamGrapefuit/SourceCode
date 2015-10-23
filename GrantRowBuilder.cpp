//
//  GrantRowBuilder.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "GrantRowBuilder.h"


Grant_rowObject GrantRowBuilder::buildRow(string data, ColIndex index){
    
    AttributeRetriever fetch(data);
    
    //retrieve each attribute - temporarily store them
    
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string fundType = fetch.getAttribute(index.fundType_loc);
    string stat = fetch.getAttribute(index.stat_loc);
    string role = fetch.getAttribute(index.role_loc);
    string title = fetch.getAttribute(index.title_loc);
    string pInvestigator = fetch.getAttribute(index.pInvestigator_loc);
    
    // Deal with multiple co-investigators in a cell
    string cpInvestigator = fetch.getAttribute(index.cpInvestigator_loc);
    fetch.grabFirstString(cpInvestigator);//TEMPORARY -returns first co-investigator
    
    bool peerReviewed = fetch.getBoolAttribute(index.peerReviewed_loc);
    bool indGrant = fetch.getBoolAttribute(index.indGrant_loc);
    
    int sDate = fetch.getIntAttribute(index.sDate_loc);
    int eDate = fetch.getIntAttribute(index.eDate_loc);
    int totalAmount = fetch.getIntAttribute(index.totalAmount_loc);
    
    
    Grant_rowObject currentRow (name, domain, sDate, eDate, fundType, stat, peerReviewed,indGrant, role, title, pInvestigator, cpInvestigator, totalAmount);
    
    return currentRow;
};