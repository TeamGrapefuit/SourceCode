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
        attribute = "**ERROR_EMPTY_FIELD**";
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

string ErrorChecker::stringAssert(string attribute, bool &flag, int args, string* options){
    //NOTE: args is the Size of the string, not the index of the last entry - don't screw this up
    bool matchFoundFlag (0);
    
    for (int i (0); i<args; i++) {
        if (attribute == options[i]) {
            matchFoundFlag = true;
            break;
        }
    }
    
    if (matchFoundFlag == false) {
        attribute = "**ERROR_UNEXPECTED_ENTRY**";
        flag = true;
    }
    
    return attribute;
}