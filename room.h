#ifndef ROOM_H
#define ROOM_H

#include <iostrean>
#include <cstring>
#include <map>

using namespace std;

class Room 
{
 private:
  String description;
  HashMap exits;        // stores exits of this room.

 public:
  ArrayList<Item> items = new ArrayList<Item>();
  
   void Room(String description);

   void setExit();

   string getShortDescription();

   string getLongDescription();

 private:

   String getExitString();

 public:

   Room getExit(String direction);
    
   Item getItem(int index);

   Item getItem(String itemName);
    
   void removeItem(String itemName);
    
   void setItem(Item newitem);
    
   String getRoomItems();

#endif
