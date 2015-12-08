//
//  Created by Jason Smash on 2015-10-22.
//  Copyright (c) 2015 Team Grapefruit. All rights reserved.
//

#include <stdio.h>
#include "Teach_rowObject.h"

//constructor
//input: all parameters
//output: nope
Teach_rowObject::Teach_rowObject(bool error, string memberName, string primaryDomain,string teachProgram,string teachCourseType,string  teachGeoScope, int teach_nTeach, int teach_sDate, int teach_eDate, float teach_hpTeach, float teach_tHours, int tStudents){
    
    this->errorFlag = error;
    
    name = memberName;
    domain = primaryDomain;
    program = teachProgram;
    courseType =teachCourseType;
    geoScope = teachGeoScope;
    
    nTeach = teach_nTeach;
    sDate = teach_sDate;
    eDate = teach_eDate;
    
    hpTeach = teach_hpTeach;
    tHours = teach_tHours;

    totalStudents = tStudents;

};

//default constructor
//input:nope
//output:nope
Teach_rowObject::Teach_rowObject(){
    
    this->errorFlag = 0;
    
    name = "";
    domain = "";
    program = "";
    courseType ="";
    geoScope = "";
    
    nTeach = 0;
    sDate = 0;
    eDate = 0;
    
    hpTeach = 0;
    tHours = 0;
    
    totalStudents = 0;
}


//infoDump
//input: nope
//output: a string describing each member of this object
string Teach_rowObject::infoDump(){
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
    
    //program
    rowObject.append("Program: ");
    rowObject.append(program);
    rowObject.append("\n");
    
    //coursetype
    rowObject.append("Course Type: ");
    rowObject.append(courseType);
    rowObject.append("\n");
    
    //geoscope
    rowObject.append("Geographical Scope: ");
    rowObject.append(geoScope);
    rowObject.append("\n");
    
    
    //number of teaching sessions.
    rowObject.append("Number of Teaching Sessions: ");
    rowObject.append(to_string(nTeach));
    rowObject.append("\n");
    
    //start date
    rowObject.append("Start Date: ");
    rowObject.append(to_string(sDate));
    rowObject.append("\n");
    
    //end date
    rowObject.append("End Date: ");
    rowObject.append(to_string(eDate));
    rowObject.append("\n");
    
    //hours per teaching session
    rowObject.append("Hours Per Teaching Session: ");
    rowObject.append(to_string(hpTeach));
    rowObject.append("\n");
    
    //thours
    rowObject.append("Total Hours: ");
    rowObject.append(to_string(tHours));
    rowObject.append("\n");
    
    //total students
    rowObject.append("Total Number of Students: ");
    rowObject.append(to_string(totalStudents));
    rowObject.append("\n");
    
    return rowObject;
    
}

