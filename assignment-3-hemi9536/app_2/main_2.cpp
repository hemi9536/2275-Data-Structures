#include "../code_2/CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

     // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
     // DO NOT MODIFY ABOVE.
    CUSatelliteNetwork sat;
    // TODO
    int userChoice = 0;
    do {
        displayMenu();
        cin >> userChoice;
        if (userChoice == 1) {
            sat.loadDefaultSetup();
            sat.printNetwork();  
        } else if (userChoice == 2) {
            sat.printNetwork();
        } else if (userChoice == 3) {
            string name;
            cout << "Enter name of the recipient to receive the message: " << endl;
            cin >> name;
            cout << endl;
            sat.transmitInfo(name);
        } else if (userChoice == 4) {
            string name;
            string prev;
            int distance;
            cout << "Enter a new satellite name: ";
            cin >> name;
            cout << endl;
            cout << "Enter distance of satellite from earth: ";
            cin >> distance;
            cout << endl;
            cout << "Enter the previous satellite name (or First): ";
            cin >> prev;
            cout << endl;
            if (prev == "First") {
                sat.addSatelliteInfo("", name, distance);
            } else {
                while (sat.searchForSatellite(prev) == nullptr) {
                    cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" << endl;
                    cin >> prev;
                }
                sat.addSatelliteInfo(prev, name, distance);
            }
            sat.printNetwork();
        }
    } while (userChoice != 5);
        cout << "Quitting..." << endl;
        cout << "Goodbye!" << endl;
    return 0;
}




/************************************************
           Definitions for main_2.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option: " << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Info " << endl;
    cout << " 4. Add Satellite " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
