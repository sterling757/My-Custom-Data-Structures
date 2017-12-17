#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>
using namespace std;
class dsString
{
public:
     //default constructor
    dsString();
    //constructor that takes in a string and makes an object
    dsString(const char* stringInput);
    //Copy constructor
    dsString(const dsString & S);
    //overloaded assignment ("=") operator using char*
    dsString& operator= (const char*);
    //overloaded "=" operator using pass by reference
    dsString& operator= (const dsString&);
     //overloaded "+' using pass by reference
    dsString operator+ (const dsString& rSide);
    dsString operator- (const char rSide);
    dsString toString(int a);
    //overloaded "==" operator using char*
    bool operator== (const char*);
    //overloaded "==" using pass by reference
    bool operator== (const dsString&);
    //overloaded greater than symbol ">" using pass by reference
    bool operator> (const dsString&);
    char& operator[] (const int);
    //compares two strings
    int compareStrings(const dsString& string);


    void clear(); //clears string
    bool empty(); //checks if string is empty
    int size() const; //function returns size of string
    int find(int, char);
    dsString substring(int, int); //returns a substring of a string
    const char* c_str() const;
    void toLower(dsString& wordToLower);
    void toUpper(dsString& wordToUpper);

    friend std::ostream& operator<< (std::ostream&, const dsString&); //overloads stream insertion operator ("<<")

    ~dsString(); //string class destructor

private:
    int length; //var for string length
    char* strArr; //string array containing contents of passed in strings
};

#endif // DSSTRING_H
