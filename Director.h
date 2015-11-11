#pragma once
#include <string>
#include <iostream> //include for streams
#include <fstream>
#include <sstream>
#include <map> //include for multimap
#include <list> //include for pair
#include <algorithm> //include for erase
#include "rowObject.h" //row objects
#include "GrantRowBuilder.h" //row builders
#include "TeachingRowBuilder.h"
#include "PresentationRowBuilder.h"
#include "PublicationRowBuilder.h"

using namespace std;
//Builder Functions
multimap<string, Grant_rowObject>* BuildGrants(std::string input);

multimap<string, Teach_rowObject>* BuildTeacher(std::string input);

multimap<string, Pres_rowObject>* BuildPresentation(std::string input);

multimap<string, Pub_rowObject>* BuildPublications(std::string input);

//getters
multimap<string, Grant_rowObject>* getGrants();

//multimap<string, Pres_rowObject>* getPresentations(); 

//multimap<string, Pub_rowObject>* getPublications();



pair<int,int> getDatesGrants();