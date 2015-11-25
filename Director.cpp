//Director
//To-do: 
//	Error Stack
//	Value Summer: for those of same author, same start year & same type (still need to do for teach,pres, and pub)
//	Date Range: Keep track of start and end date and make getters to it (still need to do for teach,pres, and pub)
//  Figure out type of file
#include "Director.h"

using namespace std;

//attributes
string fileName; //for keeping track of name of file
int columnNumber;	//for keeping track of column number
string columnName;	//for keeping track of what is in column
string firstRow;  //string to hold all the data in the first row

//ints for Date Range, Grants
int firstDateGrants;
int lastDateGrants;
int firstDateTeach;
int lastDateTeach;

//multimaps
multimap<string, Grant_rowObject>* grantsDictionary; 
multimap<string, Teach_rowObject>* teachDictionary;
multimap<string, Pres_rowObject>* presentationsDictionary;
multimap<string, Pub_rowObject>* publicationsDictionary;

//ERROR section

//Error Arrays, place where we keep the arrays and counter to keep track of current place in 
pair<int,Grant_rowObject> grantsErrors[200];
int grantsErrorCounter = 0;
pair<int,Teach_rowObject> teachErrors[200];
int teachErrorCounter = 0;
pair<int, Pres_rowObject> presErrors[200];
int presErrorCounter = 0;
pair<int, Pub_rowObject> pubErrors[200];
int pubErrorCounter = 0;

//error method adders
void addGrantsError(int row, Grant_rowObject errorRow)
{
	if(grantsErrorCounter >= 199)
	{
		cout << "Too many errors" << endl;
	}
	else
	{	
		grantsErrors[grantsErrorCounter] = pair<int, Grant_rowObject>(row,errorRow);
		grantsErrorCounter++;
	}
}

void addTeachError(int row, Teach_rowObject errorRow)
{
	teachErrors[teachErrorCounter] = pair<int, Teach_rowObject>(row, errorRow);
	teachErrorCounter++;
}

void addPresError(int row, Pres_rowObject errorRow)
{
	presErrors[presErrorCounter] = pair<int, Pres_rowObject>(row, errorRow);
	presErrorCounter++;
}

void addPubError(int row, Pub_rowObject errorRow)
{
	pubErrors[pubErrorCounter] = pair<int, Pub_rowObject>(row, errorRow);
	pubErrorCounter++;
}

//File Detective
//figure out what type of file the inputted file is
//Outputs are 0 = not recognized, 1 = Grants, 2 = Teaching, 3 = Presentations, 4 = Publications
int Build(string input)
{

	//the output, what the marker for the solution will be
	int type = 0;

	//Open file
	//get the name of the file
	fileName = input;
	//start stream of object
	ifstream fileStream(fileName.c_str(), ios::in | ios::binary);
	//check if good
	if (fileStream.is_open())
	{
		cout << "good" << endl;
	}
	else
	{
		cout << "bad" << endl;
	}

	//FIRST ROW

	//get first row
	fileStream >> ws;
	getline(fileStream, firstRow);
	//seperate first row
	istringstream firstRowStream(firstRow);

	//string for keeping track of column
	string findColumn; 
	//go through the first row and find unique column, once you find one break from loop
	while (getline(firstRowStream, findColumn, ','))
	{
		//1. Grants
		if (findColumn == "Funding Type")
		{
			type = 1;
			break;
		}
		//2. Teaching
		else if (findColumn == "Program")
		{
			type = 2;
			break;
		}

		//3. Presentation
		else if (findColumn == "Education Presentation")
		{
			type = 3;
			break;
		}
		//4. Publications
		else if (findColumn == "Publication Status")
		{
			type = 4;
			break;
		}
	}

	//build correct dictionary
	if (type == 0)
	{
		cout << "File Type could not be identified" << endl;
	}
	//Grants
	else if (type == 1)
	{
		BuildGrants(fileName);
	}
	//Teaching
	else if (type == 2)
	{
		BuildTeacher(fileName);
	}
	//Presentation
	else if (type == 3)
	{
		BuildPresentation(fileName);
	}
	//Publications
	else if (type == 4)
	{
		BuildPublications(fileName);
	}


	return type;
}

//build Grants
//status: basics finished. but keep updating
void BuildGrants(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
	ifstream fileStream(fileName.c_str(), ios::in | ios::binary);
	if (fileStream.is_open())
	{
		cout << "good" << endl;
	}
	else
	{
		cout << "bad" << endl;
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
		//compare column name to variable, if a column appears, put in relevant index
		//erase "\n\r" from the string, this only applies if the column is at the very end of the line, but it messes upt it reading it
		columnName.erase(columnName.find_last_not_of("\n\r") + 1);
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
	grantsDictionary = new multimap<string, Grant_rowObject>();
	multimap<string, Grant_rowObject>::iterator check;
	bool existAlready = false;

	//get raw row and put into temp 
	int count = 0;
	//take only up to the Carriage return so that the line is read until you get a Carriage Return (CR)
	//this is in case that the excel file has multiple lines in a cell
	while (getline(fileStream, temp, '\r'))
	{
		//remove any new lines in temp, to make one line
		temp.erase(std::remove(temp.begin(), temp.end(), '\n'), temp.end());
		existAlready = false;

		//cout << temp << endl; 
		//make new object and insert into map
		Grant_rowObject holder = Builder.buildRow(temp, colIndex);

		//Error Check
		if (holder.errorFlag == false)
		{
			//find if holder has already entry
			//duplicate check

			check = grantsDictionary->find(holder.name);
			while (check != grantsDictionary->end())
			{
				//check if holder already exists
				if (check->second.name == holder.name && check->second.fundType == holder.fundType && check->second.peerReviewed == holder.peerReviewed && check->second.indGrant == holder.indGrant)
				{
					//if it does, add the total amount to the one that already exists
					check->second.totalAmount = check->second.totalAmount + holder.totalAmount;
					//confirm that this is a duplicate
					existAlready = true;
					count++;

				}
				check++;
			}
			//if there is no duplicate, add it in to the map
			if (existAlready == false)
			{
				grantsDictionary->insert(pair<string, Grant_rowObject>(holder.name, holder));
				count++;
				existAlready = false;
			}
		}
		else
		{
			//addGrantsError(count, holder);
		}

		//grantsDictionary->insert(pair<string, Grant_rowObject>(holder.name, holder));
		count++;

	}

	fileStream.close();

	//after you make the map, find out the min start date and max end date
	multimap<string, Grant_rowObject>::iterator it = grantsDictionary->begin();
	//intializing to high amount for start dates
	firstDateGrants = 2100;
	for (it = grantsDictionary->begin(); it != grantsDictionary->end(); ++it)
	{
		//checking if start date is lower and not counting zeroes
		if (it->second.sDate <= firstDateGrants && it->second.sDate != 0 )
		{
			firstDateGrants = it->second.sDate;
		}
		//checking if end date is higher and not counting to high amounts
		if (it->second.edate >= lastDateGrants && it->second.edate < 2100)
		{
			lastDateGrants = it->second.edate;
		}

	}

	if (grantsDictionary != NULL)
	{
		cout << "Grants Dictionary made" << endl;
	}

}

//build Teacher
//status: unfinished, waiting on row builder
void BuildTeacher(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str(),ios::in | ios::binary);
	//check if filestream opening worked
	if (fileStream.is_open())
	{
		cout << "good" << endl;
	}
	else
	{
		cout << "bad" << endl;
	}
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 0;



	//FIRST ROW FOR COLUMNS

	//get first row
	fileStream >> ws;
	getline(fileStream, firstRow);
	//seperate first row
	istringstream firstRowStream(firstRow);
	//now put in first rows value and put into struct
	while (getline(firstRowStream, columnName, ','))
	{
		//erase "\n\r" from the string, this only applies if the column is at the very end of the line, but it messes upt it reading it
		columnName.erase(columnName.find_last_not_of("\n\r") + 1);
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
		else if (columnName == "Type of Course / Activity")
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
		else if (columnName == "Number Of Trainees")
		{
			colIndex.tStudents_loc = columnNumber;
		}


		//take note of column number, starts at 0
		columnNumber++;
	}

	//SEND RAW ROW AND STRUCT collndex TO rowObject TO MAKE ROW THAT WILL BE PUT IN DICTIONARY
	//use member name as dictionary

	string temp;

	teachDictionary = new multimap<string, Teach_rowObject>();

	//Builder object
	TeachingRowBuilder Builder;
	

	//get raw row and put into temp 
	// go until carriage return
	while (getline(fileStream, temp, '\r'))
	{
		//erase the new lines in the line
		temp.erase(std::remove(temp.begin(), temp.end(), '\n'), temp.end());
		//make new object and insert into map
		//remember to change holder to right object type
		Teach_rowObject holder = Builder.buildRow(temp, colIndex);
		//Error Check
//		if (holder.errorFlag == false)
//		{
			teachDictionary->insert(pair<string, Teach_rowObject>(holder.name, holder));
//		}
//		else
//		{

//		}
	}

	fileStream.close();

	//after you make the map, find out the min start date and max end date
	multimap<string, Teach_rowObject>::iterator it = teachDictionary->begin();
	//intializing to high amount for start dates
	firstDateTeach = 2100;
	for (it = teachDictionary->begin(); it != teachDictionary->end(); ++it)
	{
		//checking if start date is lower and not counting zeroes
		if (it->second.sDate <= firstDateTeach && it->second.sDate != 0)
		{
			firstDateTeach = it->second.sDate;
		}
		//checking if end date is higher and not counting to high amounts
		if (it->second.eDate >= lastDateTeach && it->second.eDate < 2100)
		{
			lastDateTeach = it->second.eDate;
		}

	}

}

//build Presentations
//status: unfinished, needs right objects
void BuildPresentation(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str(), ios::in | ios::binary);
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 0;



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
		//erase "\n\r" from the string, this only applies if the column is at the very end of the line, but it messes upt it reading it
		columnName.erase(columnName.find_last_not_of("\n\r") + 1);
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
		else if (columnName == "Type") 
		{
			colIndex.type_loc = columnNumber;
		}
		//Presentation Date
		else if (columnName == "Date") 
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
	PresentationRowBuilder Builder;
	presentationsDictionary = new multimap<string, Pres_rowObject>();

	//get raw row and put into temp 
	// go until carriage return
	while (getline(fileStream, temp, '\r'))
	{
		//erase the new lines in the line
		temp.erase(std::remove(temp.begin(), temp.end(), '\n'), temp.end());
		//make new object and insert into map
		Pres_rowObject holder = Builder.buildRow(temp, colIndex);
		if (holder.errorFlag == false)
		{
			presentationsDictionary->insert(pair<string, Pres_rowObject>(holder.name, holder));
		}
		else
		{

		}
	}

}

//build Publications
//status: unfinished, needs right objects
void BuildPublications(string input)
{
	//get the name of the file
	fileName = input;
	//start stream of object
    ifstream fileStream(fileName.c_str(), ios::in | ios::binary);
	if (fileStream.is_open())
	{
		cout << "good" << endl;
	}
	else
	{
		cout << "bad" << endl;
	}
	//start keeping track of column
	ColIndex colIndex;
	columnNumber = 0;


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
		//erase "\n\r" from the string, this only applies if the column is at the very end of the line, but it messes upt it reading it
		columnName.erase(columnName.find_last_not_of("\n\r") + 1);
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
		//Journal role
		else if (columnName == "Role")
		{
			colIndex.role_loc = columnNumber;
		}
		//Type
		else if (columnName == "Type")
		{
            colIndex.type_loc = columnNumber;
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
	PublicationRowBuilder Builder;
	publicationsDictionary = new multimap<string, Pub_rowObject>();
	//get raw row and put into temp 
	// go until carriage return
	while (getline(fileStream, temp, '\r'))
	{
		//erase the new lines in the line
		temp.erase(std::remove(temp.begin(), temp.end(), '\n'), temp.end());
		//make new object and insert into map
		//remember to change holder to right object type
		Pub_rowObject holder = Builder.buildRow(temp, colIndex);
		if (holder.errorFlag == false)
		{
			publicationsDictionary->insert(pair<string, Pub_rowObject>(holder.name, holder));
		}
		else
		{

		}
	}

}


//getters for the Dictionaries
//has a checker that checks if the pointer is NULL, meaning the Dictionary was never made
//if it is NULL then NULL is returned and it says that it wasn't made
multimap<string, Grant_rowObject>* getGrants()
{
	if (grantsDictionary != NULL)
	{
		return grantsDictionary;
	}
	else
	{
		cout << "Can't Find Grants" << endl;
		return NULL;
	}
	
}

multimap<string, Teach_rowObject>* getTeachings()
{
	if (teachDictionary != NULL)
	{
		return teachDictionary;
	}
	else
	{
		cout << "Can't Find Teachings" << endl;
		return NULL;
	}

}

multimap<string, Pres_rowObject>* getPresentations()
{
	if (presentationsDictionary != NULL)
	{
		return presentationsDictionary;
	}
	else
	{
		cout << "Can't Find Presentations" << endl;
		return NULL;
	}

}

multimap<string, Pub_rowObject>* getPublications()
{
	if (publicationsDictionary != NULL)
	{
		return publicationsDictionary;
	}
	else
	{
		cout << "Can't Find Publications" << endl;
		return NULL;
	}

}

//getter for max start and end date
pair<int,int> getDatesGrants()
{
	if (firstDateGrants == 0 && lastDateGrants == 0)
	{
		cout << endl << "No Grants File given in" << endl; 
	}
	else
	{
		return pair<int, int>(firstDateGrants, lastDateGrants);
	}
}

pair<int, int> getDatesTeach()
{
	if (firstDateTeach == 0 && lastDateTeach == 0)
	{
		cout << endl << "No Grants File given in" << endl;
	}
	else
	{
		return pair<int, int>(firstDateTeach, lastDateTeach);
	}
}

pair<int,Grant_rowObject>* getGrantsErrors()
{
	return grantsErrors;
}
