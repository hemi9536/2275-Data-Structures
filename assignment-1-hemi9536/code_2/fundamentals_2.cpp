#include "fundamentals_2.hpp"

char calcLetterGrade(double avg)
{
    if (avg >= 90) {
        return 'A';
    } else if (avg >= 80) {
        return 'B';
    } else if (avg >= 70) {
        return 'C';
    } else if (avg >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int index)
{
    studentData temp;
    temp.studentName = studentName;
    temp.homework = homework;
    temp.recitation = recitation;
    temp.quiz = quiz;
    temp.exam = exam;
    temp.average = (homework + recitation + quiz + exam) / 4.0;
    students[index] = temp;
}