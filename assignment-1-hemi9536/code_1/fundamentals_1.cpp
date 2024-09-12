#include "fundamentals_1.hpp"

int addToArrayDesc(float sortedArray[], int numElements, float newValue){
    int i = 0;
    while ((i < numElements) && (newValue < sortedArray[i])) {
        i++;
    }
    for (int j = numElements; j > i; j--) {
        sortedArray[j] = sortedArray[j - 1];
    }
    sortedArray[i] = newValue;
    //cout << sortedArray[0] << endl;
    numElements += 1;
    return numElements;
}
    
