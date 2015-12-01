//
//  ErrorChecker.h
//  Phase_1 Tests&Mods
//
//  Created by Jason Smash on 2015-11-16.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//  This class is a swiss-army-knife of error catching functions
//  used by all 4 row builders


#include <stdio.h>
#include <string>

#pragma once

using namespace std;

class ErrorChecker {
public:

    //for catching blank feilds
    string blankCatch(string attribute, bool &flag); //raises flag and returns "ERROR_BLANK_FEILD" if attribute is blank

    //catches empty integer feilds - mostly used for dates
    int zeroCatch (int attribute, bool &flag); //raises flag and returns -666 if attribute is 0
    
    //for catching cases when a string feild deviates from the given possibilities
    string stringAssert(string attribute, bool &flag, int args, string* options);//for catching unexpected values in string attributed (when there are a finite number of acceptable options)
    
};



