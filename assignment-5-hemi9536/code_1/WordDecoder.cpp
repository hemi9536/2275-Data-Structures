#include <iostream>
#include "WordDecoder.hpp"


using namespace std;


WordDecoder::WordDecoder()
{
    // TODO. Initialize all variables required
    stackHead = nullptr;
}

WordDecoder::~WordDecoder()
{
    //TODO. Free up to avoid memory leaks
    while (stackHead != nullptr) {
        Letter *temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
}

bool WordDecoder::isEmpty()
{
    // TODO. Checking if stack is empty
    return stackHead == nullptr;
}

void WordDecoder::push(string letter)
{
    //TODO Perform push operation stack
    Letter *temp = new Letter;
    temp->letter = letter;
    temp->next = nullptr;
    if (stackHead == nullptr) {
        stackHead = temp;
    } else {
        temp->next = stackHead;
        stackHead = temp;
    }
    
}

void WordDecoder::pop()
{
    //TODO Perform pop operation stack
    if (isEmpty()) {
        cout << "Stack empty, cannot pop a letter." << endl;
    } else {
        Letter *temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    
}

Letter* WordDecoder::peek()
{
    //TODO Perform peek operation stack
    return stackHead;
}

void WordDecoder::evaluate(string* s, int size)
{
    /* TODO:
    1. Push to stack if lette rin string not a ")"
    2. If ")" comes, then pop until "(", store somewhere. Put letters back to the stack in reverse order of pop.
    3. Finally, the elements are stored in reverse, so print in reverse order. */

    for (int i = 0; i < size; i++) {
        if (s[i] == ")") {
            string temp[size];
            int index = 0;
            while (peek()->letter != "(") {
                temp[index++] = peek()->letter;
                pop();
            }
            pop();
            for (int j = 0; j < index; j++) {
                push(temp[j]);
            }
        } else {
            push(s[i]);
        }
    }
    string arr[size];
    cout << "The decoded word: ";
    int count = 0;
    while (!isEmpty()) {
        arr[count] = peek()->letter;
        count++;
        pop();
    }
    for (int i = count; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;
}