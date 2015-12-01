
//
//  PresentationRowBuilder.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 team grapefruit. All rights reserved.
//  This class creates a presentation row object
//  error checking is also included here

#include <stdio.h>
#include "Pres_rowObject.h"
#include <string>
#include "attributeretriever.h"
#include "ColIndex.h"
#include "ErrorChecker.h"

class PresentationRowBuilder{
public:
    //default constructor - doesn't do anything
    PresentationRowBuilder(){};
    
    //fetch all attributes, run error checking, build row
    Pres_rowObject buildRow(string data, ColIndex index);
    
};

