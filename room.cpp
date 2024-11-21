File Edit Options Buffers Tools CSS Help
//Room cpp/header
// Main cpp
//Items strut or cpp/header do the memory storing thing like search

#include "room.h"
#include <iostream>
#include <cstring>
using namespace std;

room::room(char* cr, char* e, char* si, char* d) { //constructor for the DigitalMedia

    currentRoom = new char[80];
    strpy(currentRoom, cr);
  
    exits = new char[80];
    strcpy(exits, t);  //copys t into the array

    storedItems = new char[80];
    strcpy(storedItems, si)

    description = new char[80];
    strcpy(description, d)
}

// room::~room() { //destructor for the DigitalMedia
//    delete[] title;
//}

char* room::getCurrentRoom() {
  return currentRoom();
}
char* room::getExits() { //getter for the exits
    return exits;
}

char* room::getStoredItems() { //getter for the stored items in the room
    return storedItems;
}

char* room::getDescription() { //getter for the desription
  return description;
}




