//
//  RowObjectArray.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-19.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//


#include <stdio.h>

#include "Grant_rowObject.h"
#include "Teach_rowObject.h"
#include "Pres_rowObject.h"
#include "Pub_rowObject.h"

class RowObjectArray{
public:
    int arraySize; // for array with one element in it, this will be 1
    
    Grant_rowObject* grantObjects;
    Teach_rowObject* teachObjects;
    Pres_rowObject* presObjects;
    Pub_rowObject* pubObjects;
    
    RowObjectArray();
    ~RowObjectArray();
};

/*

HOW TO USE THIS CLASS:

this class is for handshaking b/w the RowBuilder Classes and the Director Class - allowing multiple RowObjects to be returned from the rowbuilder

to use:

-lets say our RowObjectArray is called "container"
 
for(i = 0; i < container.arraySize; i++){

    currentRowObject = grantObjects [i]; //or teachObjects, pubObjects etc.
 
    //any processing on RowObject
    //add rowObject to MultiMap
 
 }

*/