//
//  Teach_rowObject.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include <stdio.h>
#include <string>

#pragma once

using namespace std;
#pragma once

class Teach_rowObject{
public:

    
    //flag: true = error, false = no error
    bool errorFlag;
    
//Column Types for Teaching
    
    string name; //Member Name
    string domain; // Primary domain
    string program; //Program
    string courseType; //Course Type
    string geoScope; //geographical scope
    
    int nTeach; // Number of teaching sessions
    int sDate;// Start Date
    int eDate; //End Date
    
    float hpTeach;//hours per teaching session or week
    float tHours;//total hours
    int totalStudents;  //Total number of students

    Teach_rowObject(bool error, string name, string domain,string program,string courseType,string  geoScope, int nTeach, int sDate, int eDate, float hpTeach, float tHours, int tStudents);
    
    Teach_rowObject();
};

