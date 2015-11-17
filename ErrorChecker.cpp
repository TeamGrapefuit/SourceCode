//
//  ErrorChecker.cpp
//  Phase_1 Tests&Mods
//
//  Created by Jason Smash on 2015-11-16.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "ErrorChecker.h"

string ErrorChecker::blankCatch(string attribute, bool &flag){
    
    if (attribute.empty()) {
        attribute = "**ERROR_EMPTY_FEILD**";
        flag = true;
        return attribute;
    }
    else{
        return attribute;
    }
}

int ErrorChecker::zeroCatch(int attribute, bool &flag){
    
    if (attribute==0) {
        flag = true;
        return -666;
    }
    else{
        return attribute;
    }
}