#ifndef READFILE_H__
#define READFILE_H__

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct wordRecord {
	string word;
	int count;
};

// TODO add detailed explanation on what the function should do
// This function takes a parameter for the file name of ignore words, and an array of strings
// to put the ignore words in.
void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]);

// This function takes a specific word, the array of ignoreWords, and a length, and returns
// true if the word is an ignore word and false if it isn't
bool isIgnoreWord(string word, string ignoreWords[], int length);

// This function takes in an array of all the distinct words, and the length or number
// of elements in the array. It returns the total count of all the words that aren't ignore words.
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);

// This function takes in an array of all the distinct words, and the number of elements in the array.
// It sorts the array through bubble sort, and returns nothing.
void sortArray(wordRecord distinctWords[], int length);

// This function takes in an array of all the distinct words, where to start the rank (N), and the 
// total number of words that have been counted. It prints the top 10 starting from rank N, and returns nothing.
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);

#endif // READFILE_H__