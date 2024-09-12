#include <iostream>
#include <fstream>
#include "../code_1/fundamentals_1.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream inputFile;
    inputFile.open(argv[1]);

    //std::cout << "Test";
    if (inputFile.is_open()) {
    float arr[100];
    string line;
    int numElements = 0;
    //cout << "Testing";

    while(getline(inputFile, line)) {
        addToArrayDesc(arr, numElements, stof(line));
        numElements++;
        for (int i = 0; i < numElements - 1; i++) {
            cout << arr[i] << ",";
        }
        cout << arr[numElements - 1] << endl;
    }
    inputFile.close();
    return numElements;
    
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }
    return -1;
}