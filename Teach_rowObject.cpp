
#include <stdio.h>
#include "Teach_rowObject.h"

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