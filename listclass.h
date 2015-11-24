/*
    Team Grapefruit
    Oct 26th/2015
    This file contains the implementation of a class
    which stores data to be displayed in the plus/minus list.
    It works with each of the 4 files.
*/
#include <string>
#include <list>

using namespace std;

class ListClass
{
    list<ListClass *> * children;   //This is a pinter to the children in thre tree hierarchy

public:
    string name;    //Name of the object as it appears in the +/- List
    int param1;     //Set to -1 if unused
    int param2;     //Set to -1 if unused
    
    ListClass(string name, int param1, int param2, bool hasList);       //Constructor
    ListClass();                                                        //Constructor    
    ~ListClass();                                                       //Destructor

    void addChild(string name, int param1, int param2, bool hasList);   //Inserts an entry into the children list
    void addChild(ListClass * child);                                   //Inserts an entry into the children list

    string getName();   //Return the name as displayed in the +/- List
    int getParam1();    //Returns parameter as to be displayed in the +/- List
    int getParam2();    //Returns parameter as to be displayed in the +/- List
    list<ListClass *> * getChildren();  //Returns the children

};
