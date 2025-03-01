#include <iostream>
#include <cstring>
#include <cctype>
#include "mystring.h"
using namespace std;
using namespace cs_mystring;

/*
Aiden Man
CS 2B - Harden
11/23/2024
Project 25.2 - main.cpp
P
This program checks if a user-provided string is a palindrome. 
It prompts the user to enter a string, then checks and prints
whether or not it is a palindrome. It does so until the user
enters "quit" as the string. It skips over spaces and punctuation
marks, and is not case sensitive. 
*/

bool isAPalindrome (MyString string, int lowerBound, int upperBound);






int main(){
    MyString string;
    MyString reverseString;

    while (string != "quit"){ 
        cout << "Enter a string: ";
        cin >> string;
        
        if (isAPalindrome(string, 0, string.length() - 1)){
            cout << string;
            cout << " is a palindrome." << endl;
        }else{
            cout << string;
            cout << " is not a palindrome." << endl;
        }
    }
}






/*
This function checks if a MyString string is a palindrome via recursion. 
string refers to the inputted string, lowerBound refers to the lowest
index used to compare, and upperBound refers to the highest index used
to compare. The function begins at each end of the string and continues
to compare the inner pairs. The function skips over spaces and punctuation 
marks, only comparing alphanumeric characters (not case sensitive). 
*/
bool isAPalindrome(MyString string, int lowerBound, int upperBound){
    if (upperBound < lowerBound){
        return true;

    }else if(isspace(string[lowerBound]) || ispunct(string[lowerBound])){
        return isAPalindrome(string, lowerBound + 1, upperBound);
    
    } else if (isspace(string[upperBound]) || ispunct(string[upperBound])){
        return isAPalindrome(string, lowerBound, upperBound - 1);
    
    } else if (toupper(string[lowerBound]) == toupper(string[upperBound])){
        return isAPalindrome(string, lowerBound + 1, upperBound - 1);
    
    } else {
        return false;
    }
}