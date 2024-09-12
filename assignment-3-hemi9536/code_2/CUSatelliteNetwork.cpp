/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) {
    // TODO
    CUSatellite *newSat = new CUSatellite;
    newSat->name = satelliteName;
    newSat->distanceFromEarth = distance;
    newSat->next = nullptr;
    newSat->numberMessages = 0;
    CUSatellite *temp = head;

    if (head == nullptr) {
        head = newSat;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
        return;
    } else if (previous == "") {
        newSat->next = head;
        head = newSat;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
        return;
    } else {
        while((temp != nullptr)) {
            if (temp->name == previous) {
                newSat->next = temp->next;
                temp->next = newSat;
                cout << "adding: " << satelliteName << " (prev: " << previous << ")" << endl;
                return;
            }
        temp = temp->next;
        }
    }
    cout << "Cannot add new node; previous node not found\n" << endl;
}


/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup(){
    // TODO
    addSatelliteInfo("", "MAVEN", 9);
    addSatelliteInfo("", "JUNO", 4);
    addSatelliteInfo("", "PIONEER", 5);
    addSatelliteInfo("", "GALILEO", 6);
    addSatelliteInfo("", "KEPLER", 10);
    addSatelliteInfo("", "TESS", 2);
}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName){
    // TODO
    CUSatellite *temp = head;
    while(temp != nullptr) {
        if (temp->name == satelliteName) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) {
    // TODO
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    CUSatellite *temp = head;
    while (temp != nullptr) {
        temp->numberMessages++;
        temp->message = "distance of " + temp->name + " from earth is " + to_string(temp->distanceFromEarth);
        if (temp->name == receiver) {
            CUSatellite *temp2 = head;
            while (temp2->name != receiver) {
                cout << temp2->name << " [# messages received: " << to_string(temp2->numberMessages) << "] received: " << temp2->message << endl;
                temp2 = temp2->next;
            }
            cout << temp2->name << " [# messages received: " << to_string(temp2->numberMessages) << "] received: " << temp2->message << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Satellite not found" << endl;
}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() {
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->distanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
