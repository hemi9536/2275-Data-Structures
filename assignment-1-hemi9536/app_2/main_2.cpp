#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    // your code here

    ifstream inputFile;
    inputFile.open(argv[1]);
    string temp[5];
    int numStudents = 0;
    string line;
    studentData students[10];

    if (!inputFile.is_open()) {
        cout << "File could not be read" << endl;
        return -1;
    }
    while(getline(inputFile, line)) {
        stringstream line2(line);
        for (int j = 0; j < 5; j++) {
            getline(line2, temp[j], ',');
        }
        addStudentData(students, temp[0], stoi(temp[1]), stoi(temp[2]), stoi(temp[3]), stoi(temp[4]), numStudents);

        numStudents++; 
    }
    inputFile.close();


    ofstream outputFile;
    outputFile.open(argv[2]);
    char lowerBound = (*argv[3]);
    char upperBound = (*argv[4]);
    for (int i = 0; i < numStudents; i++) {
        //cout << i << endl;
        char grade = calcLetterGrade(students[i].average);
        if ((grade <= lowerBound) && (grade >= upperBound)) {
            cout << students[i].studentName << "," << students[i].average << "," << grade << endl;
            outputFile << students[i].studentName << "," << students[i].average << "," << grade << endl;
        }
    }
    outputFile.close();
    return 0;
}