#include <string>

using namespace std;
#pragma once
class Pub_rowObject{
    public:
    //Column Types for Publication (duplicates not included)
    string name; //memberName
    string domain; //primary Domain
    string pubStatus; // Publication Status
    string type; //Journal Type
    string role; //Journal Role
    string title; //Journal Title
    string author;// Journal Author
    string jName; //Journal Name
    
    int statDate; //Status Date
    int totalPub; //Total number of publications
    Pub_rowObject(string memberName, string primaryDomain, string publicationStatus, string journalType, string journalRole, string journalAuthor, string journalName, string journalTitle, int statusDate);

};




