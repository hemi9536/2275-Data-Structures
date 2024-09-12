/*******************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*       This class uses a linked-list of CUSatellite nodes to      */
/*       represent communication paths between Satellites           */
/*******************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUSatelliteNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new Satellite to the network
 *   between the Satellite previous and the Satellite that follows it in the network.
 * @param previous - name of the Satellite that comes before the new Satellite
 * @param SatelliteName - name of the new Satellite 
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{     

    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: populates the network with the predetermined CUSatellites
 * @param none
 * @return none
 */
void CUSatelliteNetwork::loadDefaultSetup()
{

    deleteEntireNetwork();
    // TODO: Copy-paste your solution from Assignment 3
    addSatelliteInfo("", "MAVEN", 9);
    addSatelliteInfo("", "JUNO", 4);
    addSatelliteInfo("", "PIONEER", 5);
    addSatelliteInfo("", "GALILEO", 6);
    addSatelliteInfo("", "KEPLER", 10);
    addSatelliteInfo("", "TESS", 2);
    
}

/*
 * Purpose: Search the network for the specified Satellite and return a pointer to that node
 * @param SatelliteName - name of the Satellite to look for in the network
 * @return pointer to node of SatelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    // TODO: Copy-paste your solution from Assignment 3
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
 * Purpose: Relay a message through the linked list until the specified Satellite
 * @param string receiver - name of the Satellite 
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver)
{
    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: prints the current list in an organized manner
 * @param none
 * @return none

 */
void CUSatelliteNetwork::printNetwork() 
{
    /* finished. do not touch. */
    cout << "== CURRENT PATH ==" << endl;

    if (head)
    {
        CUSatellite* temp = head;
        
        while (temp)
        {
            cout << temp->name << "(" << temp->distanceFromEarth << ") -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    else
    {
        cout << "nothing in path";
    }

    cout << endl << "===" << endl;


}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the Satellite in the network with the specified name.
 * @param SatelliteName - name of the Satellite to delete in the network
 * @return none
 */
void CUSatelliteNetwork::deleteCUSatellite(string satelliteName) 

{
    // TODO: Complete this function

  if(searchForSatellite(satelliteName) == nullptr) {
    cout << "Satellite does not exist." << endl;
    return;
  }
     // Special case to delete the head
    if (head->name == satelliteName) {
       //todo
       CUSatellite *temp = head;
       head = head->next;
       delete temp;
       return;
    } else {
      CUSatellite *pres = head;
      CUSatellite *prev = NULL;
      while (pres != nullptr) {
        if (pres->name == satelliteName) {
          prev->next = pres->next;
          delete pres;
          return;
        }
        prev = pres;
        pres = pres->next;
      }
    }
}

/*
 * Purpose: deletes all Satellites in the network starting from the head Satellite.

 * @param: none
 * @return: none
 */
void CUSatelliteNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function
    CUSatellite *temp = head;
    CUSatellite *prev = nullptr;

    while (temp != nullptr) {
      prev = temp;
      temp = temp->next;
      head = temp;
      delete prev;
    }
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUSatelliteNetwork::detectLoop() 
{
    // TODO: Complete this function
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    CUSatellite *tortoise = head;
    CUSatellite *hare = head->next;
    while ((hare != nullptr && hare->next != nullptr)) {
        if (tortoise == hare) {
            return true;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return false;
}

/*
* Purpose: Creates a loop from last node to the Satellite specified.
* @param SatelliteName - name of the Satellite to loop back to
* returns the last node before loop creation (to break the loop)
*/
CUSatellite* CUSatelliteNetwork::createLoop(string satelliteName) 
{
    // TODO: Complete this function
    if (head == nullptr) {
        return nullptr;
    }
    CUSatellite *temp = head;
    CUSatellite *cyc = nullptr;
    while (temp->next != nullptr) {
        if (temp->name == satelliteName) {
            cyc = temp;
        }
        temp = temp->next;
    }

    if (temp->name == satelliteName) {
        temp->next = temp;
        return temp;
    }
    temp->next = cyc; 
    return temp;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index and
 *          move that chunk to the end of the List
 * @param: start_index, end_index - indices of start node and the end node
 * @return: none
 */
void CUSatelliteNetwork::readjustNetwork(int start, int end)
{
    // TODO: Complete this function
    if (head == nullptr) {
        cout << "Linked List is Empty" << endl;
        return;
    } else if (start > end) {
        cout << "Invalid indices" << endl;
        return;
    } else if (end < 0) {
        cout << "Invalid end index" << endl;
        return;
    } else if (start < 0) {
        cout << "Invalid start index" << endl;
        return;
    }

    CUSatellite *temp = head;
    CUSatellite *startIndex = nullptr;
    CUSatellite *endIndex = nullptr;
    CUSatellite *endIndex2 = nullptr;
    CUSatellite *tail = nullptr;
    int count = 0;
    if (start == 0) {
        startIndex = temp;
    }
    while (temp != nullptr) {
        if (start == count + 1) {
            startIndex = temp;
        }
        if (end == count) {
            endIndex = temp;
            endIndex2 = temp->next;
        }
        tail = temp;
        temp = temp->next;
        count++;
    }
    if (startIndex == nullptr) {
        cout << "Invalid start index" << endl;
        return;
    } else if (endIndex == nullptr || endIndex2 == nullptr) {
        cout << "Invalid end index" << endl;
        return;
    }

    if (start == 0) {
        tail->next = startIndex;
        head = endIndex2;
        endIndex->next = nullptr;


    } else {
        tail->next = startIndex->next;
        startIndex->next = endIndex2;
        endIndex->next = nullptr;
    }
}

/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUSatelliteNetwork::~CUSatelliteNetwork()
{
    // TODO: Complete this function
    CUSatellite *temp = head;
    CUSatellite *prev = nullptr;
    while (temp != nullptr) {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    
}