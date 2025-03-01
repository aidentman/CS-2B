#include <iostream>
#include <cstring>
using namespace std;

/*
Aiden Man
CS 2B - Harden
11/23/2024
Project 25.1 - main.cpp

This program reverses the order of an array of characters, 
in the form of either a character array with set bounds of
reversal, or an entire cstring.
*/

void reverseWithinBounds(char charArray[], int lowerBound, int upperBound);
void reverseCString(char cstring[]);





int main(){
}






/*
This function reverses the order of an array of characters
with set index bounds. charArray refers to the character
array, lowerBound refers to the index of the lower bound and 
upperBound refers to the index of the upper bound of reversal. 
The function is a recursive function that only recurs if the 
bounds are far enough apart.  
*/
void reverseWithinBounds(char charArray[], int lowerBound, int upperBound){
    char temp = charArray[lowerBound];
    charArray[lowerBound] = charArray[upperBound];
    charArray[upperBound]  = temp;
    if (upperBound - lowerBound > 1){
        reverseWithinBounds(charArray, lowerBound + 1, upperBound - 1);
    }
}





/*
This function reverses the order of an entire c-string, using
the reverseWithinBounds function. cstring refers to the desired
c-string to reverse. The function sets the entire range of
the c-string as the bounds for the call to reverseWithinBounds. 
*/
void reverseCString(char cstring[]){
    reverseWithinBounds(cstring, 0, strlen(cstring) - 1);
}