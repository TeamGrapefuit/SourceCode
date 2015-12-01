//
//  PublicationRowBuilder.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//  This class creates a publication row object
//  error checking is also included here


#include <stdio.h>
#include "Pub_rowObject.h"
#include <string>
#include "attributeretriever.h"
#include "ColIndex.h"
#include "ErrorChecker.h"

class PublicationRowBuilder{
public:
    //default constructor - does nothing
    PublicationRowBuilder(){};
    
    //fetch all attributes, error checking, build rowobject
    Pub_rowObject buildRow(string data, ColIndex index);
    
};