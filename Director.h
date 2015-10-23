#pragma once
#include <string>
#include <iostream> //include for streams
#include <fstream>
#include <sstream>
#include <map> //include for multimap
#include <list> //include for pair
#include "rowObject.h" //row objects
#include "Grant_rowObject.h"

using namespace std;
//Builders
multimap<string, Grant_rowObject>* BuildGrants(std::string input);

void BuildTeacher(std::string input);

void BuildPresentation(std::string input);

void BuildPublications(std::string input);

//getters
multimap<string, Grant_rowObject>* getGrants();

//multimap<string, Pres_rowObject>* getPresentations(); 

//multimap<string, Pub_rowObject>* getPublications();



