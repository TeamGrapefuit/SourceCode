//
//  TeachingRowBuilder.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "TeachingRowBuilder.h"

Teach_rowObject TeachingRowBuilder::buildRow(string data, ColIndex index){
    
    AttributeRetriever fetch(data);
    
    //retrieve each attribute - temporarily store them
    
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string program = fetch.getAttribute(index.program_loc);
    string courseType = fetch.getAttribute(index.courseType_loc);
    string geoScope = fetch.getAttribute(index.geoScope_loc);
    string title = fetch.getAttribute(index.title_loc);
    
    int sDate = fetch.getIntAttribute(index.sDate_loc);
    int eDate = fetch.getIntAttribute(index.eDate_loc);
    int nTeach = fetch.getIntAttribute(index.nTeach_loc);
    
    float hpTeach = fetch.getIntAttribute(index.hpTeach_loc);
    float tHours = fetch.getIntAttribute(index.tHours_loc);
    
    
    Teach_rowObject currentRow (name, domain, program, courseType, geoScope, nTeach, sDate, eDate, hpTeach, tHours);
    
    return currentRow;
};