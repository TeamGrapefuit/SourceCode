
#include <stdio.h>
#include <string>

using namespace std;

class Teach_rowObject{
public:
 
//Column Types for Teaching
    
    string name; //Member Name
    string domain; // Primary domain
    string program; //Program
    string courseType; //Course Type
    string geoScope; //
    
    int nTeach; // Number of teaching sessions
    int sDate;// Start Date
    int eDate; //End Date
    
    float hpTeach;//hours per teaching session or week
    float tHours;//total hours

Teach_rowObject(string name, string domain,string program,string courseType,string  geoScope, int nTeach, int sDate, int eDate, float hpTeach, float tHours);

};

