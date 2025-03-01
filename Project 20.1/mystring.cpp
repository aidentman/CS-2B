#include <iostream>
#include "mystring.h"
#include <cstring>
#include <cassert>
using namespace std;

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
}