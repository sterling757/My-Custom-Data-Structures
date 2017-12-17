#include "dsstring.h"
#include <cstring>
#include <iostream>
//default constructor
dsString::dsString()
{
    length = 1;
    strArr = new char[length+1];
}

//constructor that makes a string object
dsString::dsString(const char* stringInput){
    length = strlen(stringInput);

    strArr = new char[length+1];

    for(int i = 0; i < length + 1; i++){
        strArr[i] = stringInput[i];
    }  
}

//copy constructor
dsString::dsString(const dsString& S){

    length = S.length;
    strArr = new char[length];

    for(int i = 0; i < length + 1; i++){
        strArr[i] = S.strArr[i];
    }
}
//overloads the ">" operator using pass by reference
bool dsString::operator > (const dsString& rSide){
    return this->compareStrings(rSide) > 0;
}

//overloads the '=' (assignment) operator using char*
dsString& dsString::operator= (const char* c){
    delete[] strArr; //deletes the old contents of strArr
    length = strlen(c);
    strArr = new char[length+1]; //length + 1 due to null terminator
    strcpy(strArr, c); //copys the contents of c into array strArr
    return *this; //this refers to
}

//overloads the '=' (assignment) operator using pass by reference
dsString& dsString::operator= (const dsString& string){
    delete[] strArr;
    length = string.length;
    char* point = string.strArr;
    strArr = new char[length + 1];
    strcpy(strArr, point);
    return *this;
}
dsString dsString::operator- (const char rSide){

        int numDel = 0;
        int length = this->length;
        for(int i = 0; i < this->length; i++){
            if(strArr[i] == rSide){
               for(int j = i; j < this->length-1; j++){
                   strArr[j] = strArr[j+1];
               }
               strArr[3];

            }

        }
    return *this;
}

//overloads the '+' operator using pass by reference
dsString dsString::operator+ (const dsString& rSide){



    int addLength = length + rSide.length;
    char addCharArr[addLength+1]; // + 1 for null terminator
    strcpy(addCharArr, strArr);
    strcat(addCharArr, rSide.c_str());
    return dsString(addCharArr);
}

//overloads extraction operator ('<<') using pass by reference
std::ostream& operator<< (std::ostream& output, const dsString& string){
     if(string.length != 0){ //checks if there's anything inside the string to begin
         output << string.strArr;
     }
     return output; //returns contents of the string
 }

//returns a substring of a specified string
dsString dsString:: substring(int startOfStr, int endOfStr){
    int beginning = 0; //initialize var
    int ending = 0; //initilize var

    if(startOfStr < 0){ //checks if beginning (x-value coordinate) of substring is negitive
        beginning = length + startOfStr + 1;
    }

    else
        beginning = startOfStr;

    if(endOfStr < 0){ //checks if ending (y-value coordinate) of string is negitive
        ending = length + endOfStr + 1;
    }
    else
        ending = endOfStr;

    int substringLength = ending - beginning;
    char arr[substringLength + 1]; //makes an array with length of substring +1

    for(int i = 0; i < substringLength; i++){
        arr[i] = strArr[beginning + i];
    }
    arr[substringLength] = '\0';
    return dsString(arr);

}

//overloads "[]" operator
char&dsString::operator [](const int pos){
    int position = 0;
    if(pos < 0){ // checks for negitive position input
        position = length + pos;
    }
    else{ //if position input is positive
       position = pos;
    }
    //int position = pos < 0 ? length + pos : pos;
    return strArr[position];

}

//makes a string all lower case
void dsString::toLower(dsString &wordToLower){
    for(int i = 0; i < strlen(wordToLower.c_str()); i++){
        strArr[i] = tolower(wordToLower.c_str()[i]);
    }
}

//makes a string all lower case
void dsString::toUpper(dsString &wordToUpper){
    for(int i = 0; i < strlen(wordToUpper.c_str()); i++){
        strArr[i] = toupper(wordToUpper.c_str()[i]);
    }
}

//clears the string array
void dsString::clear(){
    delete[] strArr; // deletes existing strArr
    length = 0;
    strArr = new char[length]; //makes a fresh strArr with nothing in it
}

//c_str function returns strArr
const char*dsString::c_str() const{
    return strArr;
}

//compares the contents of strings input
int dsString::compareStrings(const dsString& string){

    return strcmp(strArr, string.c_str()); //uses strcmp function to compare strings
}

//overloads '==' operator using pass by reference
bool dsString::operator== (const dsString& rSide)
{
    return this->compareStrings(rSide) == 0;
}
//overloads "==" operator using char*
bool dsString::operator== (const char* rSide){
    return this->compareStrings(rSide) == 0;
}

//checks to see is a string is empty (length of 0)
bool dsString::empty(){
    return length == 0; // if length of string is zero return true;
}

//returns the size of a string
int dsString::size() const{
    return length;
}

//finds a value within a string
int dsString::find(int posOfChar, char charToFind){
    for(int i = posOfChar; i < length; i++){
        if(charToFind == strArr[i]){
            return i;
        }

    }
    return -1; //
}

//destructor
dsString::~dsString()
{
        delete[] strArr; //deletes strArr;
}
