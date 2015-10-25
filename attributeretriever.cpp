#include "attributeretriever.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

AttributeRetriever::AttributeRetriever(string rowData)
{
    rowAttributes = rowData;
}

string AttributeRetriever::getAttribute(int pos)
{
    int encountered = 0;
    int start = 0;
    int end = 0;
    bool check(true);

    for(string::size_type i = 0; i < rowAttributes.size(); ++i)
    {

        if(rowAttributes[i] == '"')
        {
            check = !check;
        }

        if(rowAttributes[i] == ',' && check == true)
        {
            encountered++;
        }

        if(encountered == pos && rowAttributes[i] == ',' && check == true)
        {
            start = i+1;
        }

        if(encountered == (pos+1) && rowAttributes[i] == ',' && check == true)
        {
            end = i;
            break;
        }
    }




    int len = end - start;
    string attribute (rowAttributes, start, len);

    //Used to remove the quotations.
    if(attribute[0] == '"')
    {
        return string (attribute, 1, attribute.size()-2);
    }

    return attribute;
}

string AttributeRetriever::isolateIntegers(string subString)
{
    string result;

    for(string::size_type i = 0; i < subString.size(); ++i)
    {

        if (subString[i] >= '0' && subString[i]<= '9'){
            result.append(subString, i, 1);
        }
        else if(subString [i] =='.' || subString[i] == '/')
        {
            return result;
        }

    }
    return result;
}

int AttributeRetriever::getIntAttribute(int pos)
{
    int encountered = 0;
    int start = 0;
    int end = 0;
    bool check(true);

    for(string::size_type i = 0; i < rowAttributes.size(); ++i)
    {

        if(rowAttributes[i] == '"')
        {
            check = !check;

        }

        if(rowAttributes[i] == ',' && check == true)
        {
            encountered++;
        }

        if(encountered == pos && rowAttributes[i] == ',' && check == true)
        {
            start = i+1;
        }

        if(encountered == (pos+1) && rowAttributes[i] == ',' && check == true)
        {
            end = i;
        }
    }



    int len = end - start;

    string attribute (rowAttributes, start, len);

    int value = atoi(attribute.c_str());

    if(value == 0)
    {
        attribute = isolateIntegers(attribute);
        value = atoi(attribute.c_str());
    }

    return value;
}

bool AttributeRetriever::getBoolAttribute(int pos)
{
    int encountered = 0;
    int start = 0;
    int end = 0;
    bool check(true);

    for(string::size_type i = 0; i < rowAttributes.size(); ++i)
    {

        if(rowAttributes[i] == '"')
        {
            check = !check;
        }

        if(rowAttributes[i] == ',' && check == true)
        {
            encountered++;
        }

        if(encountered == pos && rowAttributes[i] == ',' && check == true)
        {
            start = i+1;
        }

        if(encountered == (pos+1) && rowAttributes[i] == ',' && check == true)
        {
            end = i;
            break;
        }
    }




    int len = end - start;
    string attribute (rowAttributes, start, len);

    //Used to remove the quotations.
    if(attribute.compare("True") == 0)
    {
        return true;
    }

    return false;
}

//temporary method for grabbing first string
string AttributeRetriever::grabFirstString(string attribute)
{
    int start = 0;
    int end = 0;
    bool first(true);

    for(string::size_type i = 0; i < attribute.size(); ++i)
    {

        if(attribute[i] == '"'&& first == true)
        {
            start = i+1;
        }

        if(attribute[i] == ',' && first == true)
        {
            end = i;
            first = false;
        }
    }

    int len = end - start;

    string name (attribute, start, len);

    return name;
}


int AttributeRetriever::countStrings(string attribute)
{
    if(attribute.size() == 0)
    {
        return 0;
    }
    int count = 1;

    for(string::size_type i = 0; i < attribute.size(); ++i)
    {

        if(attribute[i] == ',')
        {
            count ++;
        }
    }
    return count;
}

string* AttributeRetriever::populateList(string attribute, int numberOfItems)
{    
    string* temp = new string[numberOfItems];
    if(numberOfItems == 0)
    {
        return NULL;
    }

    string t = "";
    int start = 0;
    int end = 0;
    int len = 0;
    int j = 0;
    bool first(true);

    for(string::size_type i = 0; i < attribute.size(); ++i)
    {
        if(attribute[i] == ','&& first == true)
        {
            first = !first;
            start = 1;
            end = i;
            len = end - start;
            temp[j] = string (attribute, start, len);
            start = i+1;
            j++;
        }
        else if(attribute[i] == ',')
        {
           end = i;
           len = end - start;
           temp[j] = string (attribute, start, len);
           start = i+1;
           j++;
        }
     }

    return temp;
}

