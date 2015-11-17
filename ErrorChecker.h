//
//  ErrorChecker.h
//  Phase_1 Tests&Mods
//
//  Created by Jason Smash on 2015-11-16.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#ifndef __Phase_1_Tests_Mods__ErrorChecker__
#define __Phase_1_Tests_Mods__ErrorChecker__

#include <stdio.h>
#include <string>


using namespace std;

class ErrorChecker {
public:

    string blankCatch(string attribute, bool &flag);
    int blankCatch (int attribute, bool &flag);
    
    
};



#endif /* defined(__Phase_1_Tests_Mods__ErrorChecker__) */
