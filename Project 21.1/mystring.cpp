#include "mystring.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

/*
Aiden Man
CS 2B - Harden
11/2/24
Project 21.1 - mystring.cpp

Class Invariant: a MyString object has 1 character array pointer,
called "cstring", which stores the defining string as a c-string.
Reading from input limits the c-string length to 127 characters,
but this can be exceeded with concatenation or construction.
*/

static const int MAX_STRING_SIZE = 127;

namespace cs_mystring {
    MyString::MyString(){
        cstring = new char[1];
        strcpy(cstring, "");
    }






    MyString::MyString(const char stringToCopy[]){
        cstring = new char[strlen(stringToCopy) + 1];
        strcpy(cstring, stringToCopy);
    }






    MyString::MyString(const MyString& stringToCopy){
        cstring = new char[stringToCopy.length() + 1];
        strcpy(cstring, stringToCopy.cstring);
    }






    MyString::~MyString(){
        delete[] cstring;
    }






    int MyString::length() const{
        return strlen(cstring);
    }






    ostream& operator<<(ostream& out, const MyString& stringToPrint){
        out << stringToPrint.cstring;
        return out;
    }






    istream& operator>>(istream& in, MyString& string){
        char tempString[MAX_STRING_SIZE];
        in >> tempString;
        delete[] string.cstring;
        string.cstring = new char[strlen(tempString) + 1];
        strcpy(string.cstring, tempString);
        return in;
    }






    MyString& MyString::operator=(const MyString& stringToCopy){
        if (this != &stringToCopy){
            delete[] cstring;
            cstring = new char[strlen(stringToCopy.cstring) + 1];
            strcpy(cstring, stringToCopy.cstring);
        }
        return *this;
    }






    char& MyString::operator[](int index){
        assert(index >= 0 && index < length());
        return cstring[index];
    }






    char MyString::operator[](int index) const{
        assert(index >= 0 && index < length());
        return cstring[index];
    }





    bool operator==(const MyString& left, const MyString& right){
        return strcmp(left.cstring, right.cstring) == 0;
    }






    bool operator!=(const MyString& left, const MyString& right){
        return strcmp(left.cstring, right.cstring) != 0;
    }






    bool operator<(const MyString& left, const MyString& right){
        return strcmp(left.cstring, right.cstring) < 0;
    }






    bool operator>(const MyString& left, const MyString& right){
        return strcmp(left.cstring, right.cstring) > 0;
    }






    bool operator<=(const MyString& left, const MyString& right){
        return strcmp(left.cstring, right.cstring) <= 0;
    }






    bool operator>=(const MyString& left, const MyString& right){
        return strcmp(left.cstring, right.cstring) >= 0;
    }






    void MyString::read(istream& in, const char& delimitingChar){
        char tempString[MAX_STRING_SIZE];
        in.getline(tempString, MAX_STRING_SIZE, delimitingChar);
        delete[] cstring;
        cstring = new char[strlen(tempString) + 1];
        strcpy(cstring, tempString);
    }






    MyString operator+(const MyString& left, const MyString& right){
        MyString combined;
        combined.cstring =  new char[left.length() + right.length() + 1];
        strcpy(combined.cstring, left.cstring);
        strcat(combined.cstring, right.cstring);
        return combined;
    }






    MyString MyString::operator+=(const MyString& stringToAdd){
        *this = *this + stringToAdd;
        return (*this);
    }
}