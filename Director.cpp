//Director
//To-do: 
//	Error Stack
//	Value Summer: for those of same author, same start year & same type
//	Date Range: Keep track of start and end date and make getters to it

#include "Director.h"
//#include "Pres_rowObject.h"
//#include "Pub_rowObject.h"
//#include "Teach_rowObject.h"
#include "ColIndex.h"
#include "GrantRowBuilder.h" //row builders
//#include "PresentationRowBuilder.h"
//#include "PublicationRowBuilder.h"

using namespace std;

//attributes
string fileName; //for keeping track of name of file
int columnNumber;	//for keeping track of column number
string columnName;	//for keeping track of what is in column
string firstRow;  //string to hold all the data in the first row

//ints for Date Range, Grants
int firstDateGrants;
int lastDateGrants;

//multimap for Grant Rows
multimap<string, Grant_rowObject>* grantsDictionary; 

//multimap for Presentation Rows
//multimap<string, Pres_rowObject>* presentationsDictionary;

//multimap for Grant Rows
//multimap<string, Pub_rowObject>* publicationsDictionary;

//multimap for Teaching Rows


//build Grants
//status: basics finished. but keep updating
multimap<string, Grant_rowObject>* BuildGrants(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str(), ios::in | ios::binary);
    if(fileStream.is_open())
    {
        cout << "good"<<endl;
    }
    else
    {
        cout<<"bad"<<endl;
    }

    if (fileStream.fail() || fileStream.bad())
    {
        cout << "Error fileStream" << endl;
    }
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 0;

	//keep track of max and min start dates
	firstDateGrants = 0;
	lastDateGrants = 0;


	//FIRST ROW FOR COLUMNS

	//get first row
	fileStream >> ws;
	getline(fileStream, firstRow);
	//seperate first row
	istringstream firstRowStream(firstRow);
	//now put in first rows value and put into struct
	while (getline(firstRowStream, columnName, ','))
	{
		//compare column name to variable, if a column appears, put in relevant 
		//name
		if (columnName == "Member Name")
		{
			colIndex.name_loc = columnNumber;
		}
		//domain
		else if (columnName == "Primary Domain")
		{
			colIndex.domain_loc = columnNumber;
		}
		//funding
		else if (columnName == "Funding Type")
		{
			colIndex.fundType_loc = columnNumber;
		}
		//status
		else if (columnName == "Status")
		{
			colIndex.stat_loc = columnNumber;
		}
		//research role
		else if (columnName == "Role")
		{
			colIndex.role_loc = columnNumber;
		}
		//Title
		else if (columnName == "Title") 
		{
			colIndex.title_loc = columnNumber;
		}
		//Primary Investigator
		else if (columnName == "Principal Investigator")
		{
			colIndex.pInvestigator_loc = columnNumber;
		}
		//Co-Investigator
		else if (columnName == "Co-Investigators")
		{
			colIndex.cpInvestigator_loc = columnNumber;
		}
		//peer-reviewed
		else if (columnName == "Peer Reviewed?")
		{
			colIndex.peerReviewed_loc = columnNumber;
		}
		//Industry Grant
		else if (columnName == "Industry Grant?")
		{
			colIndex.indGrant_loc = columnNumber;
		}
		//Start Date
		else if (columnName == "Start Date")
		{
			colIndex.sDate_loc = columnNumber;
		}
		//End Date
		else if (columnName == "End Date")
		{
			colIndex.eDate_loc = columnNumber;
		}
		//Total Amount
		else if (columnName == "Total Amount")
		{
			colIndex.totalAmount_loc = columnNumber;
		}


		//take note of column number, starts at 0
		columnNumber++;
	}

	//couts to check if right the right index number is being given
	//disregard
	//cout << colIndex.sDate_loc << endl;
	//cout << colIndex.eDate_loc << endl;



	//SEND RAW ROW AND STRUCT collndex TO rowObject TO MAKE ROW THAT WILL BE PUT IN DICTIONARY
	//use member name as dictionary

	string temp; 
	//Builder object
	GrantRowBuilder Builder;
	multimap<string, Grant_rowObject>* grantsDictionary = new multimap<string, Grant_rowObject>();
	
	//get raw row and put into temp 
	int count = 0;
	while (getline(fileStream, temp))
	{
		//cout << temp << endl; 
		//make new object and insert into map
		Grant_rowObject holder = Builder.buildRow(temp, colIndex);
		grantsDictionary->insert(pair<string, Grant_rowObject>(holder.name, holder));
		count++;
		//cout << temp << endl;
	}

	fileStream.close();

	//after you make the map, find out the min start date and max end date
	multimap<string, Grant_rowObject>::iterator it = grantsDictionary->begin();
	for (it = grantsDictionary->begin(); it != grantsDictionary->end(); ++it)
	{
		if (it->second.sDate >= firstDateGrants)
		{
			firstDateGrants = it->second.sDate;
		}

		if (it->second.edate >= lastDateGrants)
		{
			lastDateGrants = it->second.edate;
		}

	}

	return grantsDictionary;
}

//build Teacher
//status: unfinished, waiting on row builder
void BuildTeacher(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str());
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 1;



	//FIRST ROW FOR COLUMNS

	//get first row
	fileStream >> ws;
	getline(fileStream, firstRow);
	//seperate first row
	istringstream firstRowStream(firstRow);
	//now put in first rows value and put into struct
	while (getline(firstRowStream, columnName, ','))
	{
		//compare column name to variable, if a column appears, put in relevant 
		//name
		if (columnName == "Member Name")
		{
			colIndex.name_loc = columnNumber;
		}
		//domain
		else if (columnName == "Primary Domain")
		{
			colIndex.domain_loc = columnNumber;
		}
		//Start date
		else if (columnName == "Start Date")
		{
			colIndex.sDate_loc = columnNumber;
		}
		//End Date
		else if (columnName == "End Date")
		{
			colIndex.eDate_loc = columnNumber;
		}
		//Program
		else if (columnName == "Program")
		{
			colIndex.program_loc = columnNumber;
		}
		//Course Type
		else if (columnName == "Type of Course")
		{
			colIndex.courseType_loc = columnNumber;
		}
		//Geoscope
		else if (columnName == "Geographical Scope")
		{
			colIndex.geoScope_loc = columnNumber;
		}
		//# of Lessons
		else if (columnName == "Number of Teching Sessions or Weeks")
		{
			colIndex.nTeach_loc = columnNumber;
		}
		//Teaching hours per week
		else if (columnName == "Hours per Teaching Session or Week")
		{
			colIndex.hpTeach_loc = columnNumber;
		}
		//Total hours
		else if (columnName == "Total Hours")
		{
			colIndex.tHours_loc = columnNumber;
		}


		//take note of column number, starts at 1
		columnNumber++;
	}



	//SEND RAW ROW AND STRUCT collndex TO rowObject TO MAKE ROW THAT WILL BE PUT IN DICTIONARY
	//use member name as dictionary

	string temp;

	multimap<string, Grant_rowObject>* Dictionary = new multimap<string, Grant_rowObject>();

	//Builder object
	GrantRowBuilder Builder;
	

	//get raw row and put into temp 
	while (getline(fileStream, temp))
	{
		//make new object and insert into map
		//remember to change holder to right object type
		Grant_rowObject holder = Builder.buildRow(temp, colIndex);
		Dictionary->insert(pair<string, Grant_rowObject>(holder.name, holder));
	}



}

//build Presentations
//status: unfinished, needs right objects
void BuildPresentation(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str());
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 1;



	//FIRST ROW FOR COLUMNS

	//get first row
	fileStream >> ws;
	getline(fileStream, firstRow);
	//seperate first row
	istringstream firstRowStream(firstRow);
	//now put in first rows value and put into struct
	while (getline(firstRowStream, columnName, ','))
	{
		//compare column name to variable, if a column appears, put in relevant 
		//name
		if (columnName == "Member Name")
		{
			colIndex.name_loc = columnNumber;
		}
		//domain
		else if (columnName == "Primary Domain")
		{
			colIndex.domain_loc = columnNumber;
		}
		//research role
		else if (columnName == "Role")
		{
			colIndex.role_loc = columnNumber;
		}
		//research role
		else if (columnName == "Title") //there is also Short Title
		{
			colIndex.title_loc = columnNumber;
		}
		//presentation type
		else if (columnName == "Type") //there is also Short Title
		{
			colIndex.type_loc = columnNumber;
		}
		//Presentation Date
		else if (columnName == "Date") //there is also Short Title
		{
			colIndex.date_loc = columnNumber;
		}


		//take note of column number, starts at 1
		columnNumber++;
	}



	//SEND RAW ROW AND STRUCT collndex TO rowObject TO MAKE ROW THAT WILL BE PUT IN DICTIONARY
	//use member name as dictionary

	string temp;

	//Builder object
	//PresentationRowBuilder Builder;
	//presentationsDictionary = new multimap<string, Pres_rowObject>();

	//get raw row and put into temp 
	while (getline(fileStream, temp))
	{
		//make new object and insert into map
		//Pres_rowObject holder = Builder.buildRow(temp, colIndex);
		//presentationsDictionary->insert(pair<string, Pres_rowObject>(holder.name, holder));
	}

}

//build Publications
//status: unfinished, needs right objects
void BuildPublications(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str());
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 1;



	//FIRST ROW FOR COLUMNS

	//get first row
	fileStream >> ws;
	getline(fileStream, firstRow);
	//seperate first row
	istringstream firstRowStream(firstRow);
	//now put in first rows value and put into struct
	while (getline(firstRowStream, columnName, ','))
	{
		//compare column name to variable, if a column appears, put in relevant 
		//name
		if (columnName == "Member Name")
		{
			colIndex.name_loc = columnNumber;
		}
		//domain
		else if (columnName == "Primary Domain")
		{
			colIndex.domain_loc = columnNumber;
		}
		//research role
		else if (columnName == "Role")
		{
			colIndex.role_loc = columnNumber;
		}
		//Title
		else if (columnName == "Title")
		{
			colIndex.title_loc = columnNumber;
		}
		//Publication Status
		else if (columnName == "Publication Status")
		{
			colIndex.pubStatus_loc = columnNumber;
		}
		//Author Names
		else if (columnName == "Author(s)")
		{
			colIndex.author_loc = columnNumber;
		}
		//Journal Name
		else if (columnName == "Journal Name | Published In | Book Title | etc.")
		{
			colIndex.jName_loc = columnNumber;
		}
		//Status Date
		else if (columnName == "Status Date")
		{
			colIndex.statDate_loc = columnNumber;
		}



		//take note of column number, starts at 1
		columnNumber++;
	}



	//SEND RAW ROW AND STRUCT collndex TO rowObject TO MAKE ROW THAT WILL BE PUT IN DICTIONARY
	//use member name as dictionary

	string temp;

	//Builder object
	//PublicationRowBuilder Builder;
	//publicationsDictionary = new multimap<string, Pub_rowObject>();
	//get raw row and put into temp 
	while (getline(fileStream, temp))
	{
		//make new object and insert into map
		//remember to change holder to right object type
		//Pub_rowObject holder = Builder.buildRow(temp, colIndex);
		//publicationsDictionary->insert(pair<string, Pub_rowObject>(holder.name, holder));
	}

}


//getters for the Hash Tables
multimap<string, Grant_rowObject>* getGrants()
{
	return grantsDictionary;
}

/*
multimap<string, Pres_rowObject>* getPresentations()
{
	return presentationsDictionary;
}

multimap<string, Pub_rowObject>* getPublications()
{
	return publicationsDictionary;
}
*/

//getter for max start and end date
pair<int,int> getDatesGrants()
{
	return pair<int, int>(firstDateGrants, lastDateGrants);
}
