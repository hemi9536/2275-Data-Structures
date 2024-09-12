#include "../code_2/WaitlistQueue.hpp"
#include <iostream>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
    cout << "*----------------------------------------*" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Resize" << endl;
    cout << "5. Quit" << endl;
    cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    // DO NOT MODIFY THIS.
    if(argc > 2)
    {
        freopen(argv[2],"r",stdin);
    }
    
    /* TODO */
    WaitlistQueue a;
    string input;
    do {
        menu();
        cin >> input;
        if (input == "1") {
            cout << "Enter the value to add into queue:";
            cin >> input;
            cout << endl;
            a.enqueue(input);
        } else if (input == "2") {
            a.dequeue();
        } else if (input == "3") {
            cout << a.peek() << endl;
        } else if (input == "4") {
            cout << "Enter the new capacity:" << endl;
            cin >> input;
            cout << "Resizing from " << a.capacity() << " to " << input << endl;
            a.resize(stoi(input));
        } else if (input != "5") {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        } 
    } while (input != "5");

    cout << "Quitting..." << endl;
    cout << "Contents of the queue:" << endl;
    while (!a.isEmpty()) {
        string s = a.peek();
        if (s.length() > 0) {
            cout << s << endl;
        }
        a.dequeue();
    }
    cout << "Goodbye!" << endl;

    return 0;
}