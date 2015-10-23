#ifndef ATTRIBUTERETRIEVER_H
#define ATTRIBUTERETRIEVER_H
#include <string>
using namespace std;


class AttributeRetriever
{
    private:
        string rowAttributes;

        /* isloateIntegers
         * returns a string with only the integers from the string subString.
         */
        string isolateIntegers(string subString);

    public:
        /* Constructor for the AttributeRetriver
         * Sets the incomming rowData string to the member string rowAttributes.
         */
        AttributeRetriever(string rowData);

        /* getAttribute
         * returns the string attribute at position pos.
         * The whole string at the given position will be grabbed and returned.
         */
        string getAttribute(int pos);

        /* getBoolAttribute
         * returns the bool value at position pos.
         */
        bool getBoolAttribute(int pos);

        /* grabFirstString
         * returns the first string at position pos.
         * Strings are separated by commas. The string before the first comma is returned.
         */
        string grabFirstString(string attribute);

        /* getIntAttribute
         * returns the first integer at position pos.
         */
        int getIntAttribute(int pos);

        /* countStrings
         * returns the number of strings in attribute. Zero if there are no strings.
         * Counts the number of strings inside the attribute string that are separated by commas.
         */
        int countStrings(string attribute);

        /* populateList
         * returns a pointer to an array of strings.
         * Builds an array of strings given a string containing strings separated by commas.
         */
        string* populateList(string attribute, int numberOfItems);


};

#endif // ATTRIBUTERETRIEVER_H
