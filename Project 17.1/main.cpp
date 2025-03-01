#include <chrono>
#include <iostream>
#include <cstring>
using namespace std;

/*
Aiden Man
CS 2B - Harden
10/8/24
Project 17.1 - main.cpp
*/

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);






const int LOWER_A_ASCII = 97; //"a" ASCII value
const int LOWER_Z_ASCII = 122; //"z" ASCII value
const int UPPER_A_ASCII = 65; //"A" ASCII value
const int UPPER_Z_ASCII = 90; //"Z" ASCII value
const int UPPER_LOWER_ASCII = 32; //Difference between upper/lowercase ASCII values

int main() {
}






/*
This function finds the last index where the target character is in
the string. It returns -1 if the target character is not in the string
and is case-sensitive. "inString" represents the input string, "target"
represents the character of interest, "lastIndex" represents the last
index of the string where the character of interest exists.
*/
int lastIndexOf(const char* inString, char target) {
    int i = 0;
    int lastIndex = -1;

    while(inString[i] != '\0') {
        if(inString[i] == target) {
            lastIndex = i;
        }
        i++;
    }
    return lastIndex;
}






/*
This function reverses the string by exchanging characters starting from
opposite ends of the string. "inString" represents the input string,
"stringLength" is used to hold value for string length, "tempChar" is
used to store a temporary character to exchange opposite characters.
*/
void reverse(char* inString) {
    int stringLength = strlen(inString);
    int tempChar;
    for (int i = 0; i < stringLength / 2; i++) {
        if (inString[i] != inString[stringLength - i - 1]) {
            tempChar = inString[i];
            inString[i] = inString[stringLength - i - 1];
            inString[stringLength - i - 1] = tempChar;
        }
    }
}






/*
This function finds all instances of a target character in the string
and replaces them with the specific replacement character. It returns
the number of replacements that it makes. If the target character does
not appear in the string, it will return 0. "inString" represents the
input string, "target" represents the character to replace and
"replacementChar" represents the character that will replace the target.
*/
int replace(char* inString, char target, char replacementChar) {
    int i = 0;
    int counter = 0;
    while(inString[i] != '\0') {
        if(inString[i] == target) {
            inString[i] = replacementChar;
            counter++;
        }
        i++;
    }
    return counter;
}





/*
This function returns true if the argument string is a palindrome
and returns false if it is not. The function is not case-sensitive.
"inString" represents the input string and "stringLength" represents
the length of the string.
*/
bool isPalindrome(const char* inString) {
    int stringLength = strlen(inString);
    for (int i = 0; i < stringLength / 2; i++) {
        if (toupper(inString[i]) != toupper(inString[stringLength - i - 1])) {
            return false;
        }
    }
    return true;
}






/*
This function converts all letters in the string to all uppercase.
It uses the ASCII values of each character and alters them to become
the values of the uppercase counterpart. "inString" represents the input
string.
*/
void toupper(char* inString) {
    int i = 0;
    while (inString[i] != '\0') {
        if (inString[i] >= LOWER_A_ASCII && inString[i] <= LOWER_Z_ASCII) {
            inString[i] = inString[i] - UPPER_LOWER_ASCII;
            cout << inString[i];
        }
        i++;
    }
}





/*
This function returns the number of letters in the string.
"inString" represents the input string and "counter" represents
the count for how many letters are there.
*/
int numLetters(const char* inString) {
    int i = 0;
    int counter = 0;
    while (inString[i] != '\0') {
        if(inString[i] >= UPPER_A_ASCII && inString[i] <= LOWER_Z_ASCII) {
            if(inString[i] <= UPPER_Z_ASCII || inString[i] >= LOWER_A_ASCII) {
                counter++;
            }
        }
        i++;
    }
    return counter;
}