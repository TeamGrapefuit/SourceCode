#pragma once
#include <string>
#include <iostream> //include for streams
#include <fstream>
#include <sstream>
#include <map> //include for multimap
#include <list> //include for pair
#include <algorithm> //include for erase
#include "ColIndex.h" //include for the column index
#include "rowObject.h" //row objects
#include "GrantRowBuilder.h" //row builders
#include "TeachingRowBuilder.h"
#include "PresentationRowBuilder.h"
#include "PublicationRowBuilder.h"

using namespace std;
//Builder Functions

int Build(string input);

void BuildGrants(std::string input);

void BuildTeacher(std::string input);

void BuildPresentation(std::string input);

void BuildPublications(std::string input);

//getters
multimap<string, Grant_rowObject>* getGrants();

multimap<string, Teach_rowObject>* getTeachings();

multimap<string, Pres_rowObject>* getPresentations();

multimap<string, Pub_rowObject>* getPublications();

pair<int, Grant_rowObject>* getGrantsErrors();

pair<int,int> getDatesGrants();