
#include <iostream>
#include <sstream>
#include <fstream>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // your code here
    if (argc != 4) {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }
    ifstream inputFile;
    inputFile.open(argv[2]); // Sawyer File
    
    string *ignoreWords = new string[50];
    int numDoubled = 0;
    getIgnoreWords(argv[3], ignoreWords);
    int size = 100;
    wordRecord *distinctWords = new wordRecord[size];
    int length = 0;
    string word;
    stringstream s;
    s << inputFile.rdbuf();
    while(s >> word && word != " ") {
        if ((!isIgnoreWord(word, ignoreWords, 50)) && (word != " ")) {
            bool check = false;
            for (int i = 0; i < length; i++) {
                if (distinctWords[i].word == word) {
                    distinctWords[i].count++;
                    check = true;
                    break;
                }
            }
            if (!check) {
                if (length == size) {
                    wordRecord *temp = new wordRecord[size * 2];
                    for (int i = 0; i < size; i++) {
                        temp[i] = distinctWords[i];
                    }
                    delete [] distinctWords;
                    distinctWords = temp;
                    temp = nullptr;
                    size = size * 2;
                    numDoubled++;
                }
                distinctWords[length].count = 1;
                distinctWords[length].word = word;
                length++;
            }
        }
    }
    sortArray(distinctWords, length);
    int totalNumWords = getTotalNumberNonIgnoreWords(distinctWords, length);
    cout << "Array doubled: " << numDoubled << endl;
    cout << "Distinct non-common words: " << length << endl;
    cout << "Total non-common words: " << totalNumWords << endl;
    cout << "Probability of next 10 words from rank " << argv[1] << endl;
    cout << "---------------------------------------" << endl;
    printTenFromN(distinctWords, stoi(argv[1]), totalNumWords);
    

    delete [] distinctWords;
    distinctWords = nullptr;
    delete [] ignoreWords;
    ignoreWords = nullptr;
    inputFile.close();
    return 0;
}