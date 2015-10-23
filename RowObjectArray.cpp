//
//  RowObjectArray.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-19.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "RowObjectArray.h"


RowObjectArray::RowObjectArray(){
    
    arraySize = 0;
    
    grantObjects = NULL;
    teachObjects = NULL;
    presObjects = NULL;
    pubObjects = NULL;
    
};

RowObjectArray::~RowObjectArray(){
  
    delete [] grantObjects;
    grantObjects = NULL;

    delete [] teachObjects;
    teachObjects = NULL;
    
    delete [] presObjects;
    presObjects = NULL;
    
    delete [] pubObjects;
    pubObjects = NULL;
    
    
    arraySize = 0;
    
};





