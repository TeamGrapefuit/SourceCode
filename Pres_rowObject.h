
#include <stdio.h>
#include <string>


using namespace std;

class Pres_rowObject{
public:
//Member variables for presentation rowObjects

    string name;//memberName
    string domain; //Primary Domain
    string type; //Presentation Type
    string role; //presentation role
    string title; // Presentation Title
    
    int date; // Presentation Date

 Pres_rowObject(string memberName, string primaryDomain, int presentationDate, string presentationType, string presentationRole, string presentationTitle);

};
