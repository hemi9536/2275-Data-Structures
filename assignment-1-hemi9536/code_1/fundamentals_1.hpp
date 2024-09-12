#ifndef READFILE_H__
#define READFILE_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// TODO add detailed explanation on what the function should do
// This function takes in a already sorted array, the size or number of elements in the array,
// and a value to insert into the array.
// It sorts the array and returns the number of elements the array now has.
int addToArrayDesc(float sortedArray[], int numElements, float newValue);

#endif // READFILE_H__