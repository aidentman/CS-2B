#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>
using namespace std;

namespace cs_mystring {
    class MyString {
        public:
            MyString();
            MyString(const char stringToCopy[]);
            MyString(const MyString& stringToCopy);
            ~MyString();

            int length() const;
            friend ostream& operator<<(ostream& out, const MyString& stringToPrint);
            MyString& operator=(const MyString& stringToCopy);

            char& operator[](int index);
            char operator[](int index) const;

            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);
        private:
            char* cstring;
    };
}


#endif //MYSTRING_H