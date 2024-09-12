#include "array_double.hpp"

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]){
    ifstream inputFile;
    inputFile.open(ignoreWordFileName);

    if (!inputFile.is_open()) {
        cout << "Failed to open " << ignoreWordFileName << endl;
    } else {
        for (int i = 0; i < 50; i++) {
            getline(inputFile, ignoreWords[i]);
        }
    }
}


bool isIgnoreWord(string word, string ignoreWords[], int length){
    for (int i = 0; i < length; i++) {
        if (word == ignoreWords[i]) {
            return true;
        }
    }
    return false;
}


int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length){
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += distinctWords[i].count; 
    }
    return sum;
}


void sortArray(wordRecord distinctWords[], int length){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (distinctWords[j].count < distinctWords[j + 1].count) {
                swap(distinctWords[j], distinctWords[j + 1]);
            } else if (distinctWords[j].count == distinctWords[j + 1].count) {
                bool temp = true;
                int k = 0;
                do {
                    if (distinctWords[j].word[k] > distinctWords[j + 1].word[k]) {
                        swap(distinctWords[j], distinctWords[j + 1]);
                        temp = false;
                    }
                    else if (distinctWords[j].word[k] < distinctWords[j + 1].word[k]) {
                        temp = false;
                    }
                    k++;
                } //while((temp == true) && (distinctWords[j].word.size() < k) && (distinctWords[j + 1].word.size() < k));
                while ((temp == true) && (k < 5));
            }
        }
    }
}


void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){
    for (int i = N; i < N + 10; i++) {
        cout << fixed << setprecision(5) << (float) distinctWords[i].count / totalNumWords << " - " << distinctWords[i].word << endl;
    }
}

