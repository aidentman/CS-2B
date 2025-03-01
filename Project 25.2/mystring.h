#ifndef MYSTRING_H
#define MYTRING_H
#include <iostream>
#include <cstring>
using namespace std;

/*
Aiden Man
CS 2B - Harden
11/23/24
Project 25.2 - mystring.h

The MyString class can be used to create objects that store a string,
which can contain multiple words.

The following functions are available:

MyString();
    pre: This constructor takes in no arguments.
    post: The constructor creates a MyString item with value of "".

MyString(const char stringToCopy[]);
    pre: This constructor takes in a char array (c-string).
    post: The constructor creates a MyString item by copying the string
    to the c-string data member.

MyString(const MyString& stringToCopy);
    pre: This copy constructor takes in a MyString object.
    post: The constructor creates a MyString item by copying the c-string
    data member of the passed object to that of the calling object.

~MyString();
    pre: This destructor takes in no arguments.
    post: The destructor deallocates the c-string data member.

int length() const;
    pre: This member function takes in no arguments
    post: This function returns the character length of the c-string.

friend ostream& operator<<(ostream& out, const MyString& stringToPrint);
    pre: This function takes in an ostream "out" and a
    MyString "stringToPrint"
    post: The function inserts the string into ostream
    and returns the ostream.

friend istream& operator>>(istream& in, MyString& string);
    pre: This function takes in an istream "in" and a MyString "string"
    post: The function extracts the string from the istream object and
    copies it to the MyString object. This copying limits the length to
    127 characters. It then returns the istream.

MyString& operator=(const MyString& stringToCopy);
    pre: This function takes in a MyString object "stringToCopy"
    post: The function copies the passed string to the calling
    string. The calling string allocates new memory to remain efficient.
    The function returns the newly copied calling MyString object.

char& operator[](int index);
    pre: This function takes in an integer "index", where "index" is a
    valid index of the c-string.
    post: The function returns an address to the index, allowing editing
    of individual indices.

char operator[](int index) const;
    pre: This function takes in an integer "index", where "index" is a
    valid index of the c-string.
    post: The function returns the character at the index. It does not
    allow editing of individual indices.

friend bool operator==(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function returns a boolean representing if the string
    comparison of the ASCII values of the characters in the string is 0.

friend bool operator!=(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function returns a boolean representing if the string
    comparison of the ASCII values of the characters in the string is not 0.

friend bool operator<(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function returns a boolean representing if the string
    comparison of the ASCII values of the characters in the string is
    less than 0.

friend bool operator>(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function returns a boolean representing if the string
    comparison of the ASCII values of the characters in the string
    greater than 0.

friend bool operator<=(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function returns a boolean representing if the string
    comparison of the ASCII values of the characters in the string is
    less than or equal to 0.

friend bool operator>=(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function returns a boolean representing if the string
    comparison of the ASCII values of the characters in the string is
    greater than or equal to 0.

void read(istream& in, const char& delimitingChar);
    pre: The function passes an istream "in" and a charcter "delimitingChar".
    post: The function copies a line from the istream to the calling object,
    up to the delimiting character "delimitingChar". The function does not
    return anything.

friend MyString operator+(const MyString& left, const MyString& right);
    pre: The function passes two MyString objects called "left" and "right".
    The function can also pass char arrays, which will automatically construct
    to MyString objects.
    post: The function concatenates the right string to the left string, and
    returns the resulting string as a MyString object.

MyString operator+=(const MyString& stringToAdd);
    pre: The function passes a MyString objects called "stringToAdd".
    The function can also pass char arrays, which will automatically construct
    to a MyString object.
    post: The function concatenates "stringToAdd" to the calling string, and
    returns the calling MyString object.
*/

namespace cs_mystring {
    class MyString {
    public:
        MyString();
        MyString(const char stringToCopy[]);
        MyString(const MyString& stringToCopy);
        ~MyString();

        int length() const;
        friend ostream& operator<<(ostream& out, const MyString& stringToPrint);
        friend istream& operator>>(istream& in, MyString& string);
        MyString& operator=(const MyString& stringToCopy);

        char& operator[](int index);
        char operator[](int index) const;

        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);

        void read(istream& in, const char& delimitingChar);
        friend MyString operator+(const MyString& left, const MyString& right);
        MyString operator+=(const MyString& stringToAdd);
    private:
        char* cstring;
    };
}

#endif //MYSTRING_H