#ifndef READFILE2_H__
#define READFILE2_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct studentData {
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

// TODO add detailed explanation on what the function should do
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length);
char calcLetterGrade(double avg);


#endif // READFILE2_H__