#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>

using namespace std;

class room { //defins of the DigitalMedia
protected:
    char* currentRoom;
    char* exits;
    char* storedItems;
    char* description
  int year;

public:
    room(); 
  room(char* cr, char* e, char* si, char* d); //constructor that takes char pointer and the int
    virtual ~DigitalMedia();
  
  char* getCurrentRoom();
    char* getTitle();
    char* getStoredItems();
    char* getDescription();
 
    virtual void displayInfo() = 0; //overridden in child classes
    //the 0 means it has to  be implemented by child class making 
    //it pure virtual function
};

#endif
