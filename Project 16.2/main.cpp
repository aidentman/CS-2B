#include <iostream>
#include <string>
using namespace std;

/*
Aiden Man
CS 2B - Harden
10/7/24
Project 16.2 - main.cpp

This program uses dynamically allocated arrays to store scores (integers)
and names (strings). Functions include "readData" to read the data from
user input, "sortData" to sort data based on scores (higher first), and
"displayData" to output the scores. The code will prompt the user with
how many score/name pairs to record, then create the arrays using that
input as the number of elements. It will then take in the data, sort it,
then display it before deallocating the arrays.
*/

void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);






int main() {
    int size = 0;

    cout << "How many scores will you enter?: ";
    cin >> size;

    string* names = new string[size];
    int* scores = new int[size];

    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    delete[] names;
    delete[] scores;
}






/*
This function reads the data and inputs it into the arrays. "names" is the
array of names (strings), "scores" is the array of scores (integers), and
size is the number of elements in each.
*/
void readData(string names[], int scores[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i];
    }
    cout << endl;
}






/*
This function sorts the data through the bubble sort algorithm. "names"
represents the array of names, "scores" represents the array of scores,
and size represents the number of elements in each.
*/
void sortData(string names[], int scores[], const int size) {
    string tempName = "";
    int tempScore = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (scores[j] < scores[j+1]){
                tempScore = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = tempScore;

                tempName = names[j];
                names[j] = names[j+1];
                names[j+1] = tempName;
            }
        }
    }
}






/*
This function outputs the pairs of names and scores on each newline. "names"
is the array of names (strings), "scores" is the array of scores (integers),
and size is the number of elements in each.
 */
void displayData(const string names[], const int scores[], const int size) {
    cout << "Top Scorers: " << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}