//
//  TeachingRowBuilder.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//
//  This class creates a Teaching row object
//  error checking is also included here



#include <stdio.h>
#include "Teach_rowObject.h"
#include <string>
#include "attributeretriever.h"
#include "ColIndex.h"
#include "ErrorChecker.h"

class TeachingRowBuilder{
public:
    //default constructor - does nothing
    TeachingRowBuilder(){};
    
    //fetch each attribute, error checking, build rowObject
    Teach_rowObject buildRow(string data, ColIndex index);
    
};