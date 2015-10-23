#include <string>
#include <list>

using namespace std;

class ListClass
{
    list<ListClass *> * children;

public:
    string name; //Name of the object as it appears in the +/- List
    int param1; //Set to -1 if unused
    int param2; //Set to -1 if unused
    
    ListClass(string name, int param1, int param2, bool hasList);   //Constructor
    ListClass();
    ~ListClass();   //Destructor

    void addChild(string name, int param1, int param2, bool hasList);
    void addChild(ListClass * child);

    string getName();
    int getParam1();
    int getParam2();
    list<ListClass *> * getChildren();

};
