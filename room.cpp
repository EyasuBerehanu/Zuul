File Edit Options Buffers Tools CSS Help
File Edit Options Buffers Tools C Help
#ifndef ROOM_H
#define ROOM_H

#include <iostrean>
#include <cstring>

using namespace std;

class Room
{
  String description;
  HashMap exits;        // stores exits of this room.

  ArrayList<Item> items = new ArrayList<Item>();

    room::Room(String description)
    {
        this.description = description;
        exits = new HashMap();
    }

   room::void setExit()
    {
        exits.put(direction, neighbor);
    }


  room::string getShortDescription()
    {
        return description;
    }

  room::string getLongDescription()
    {
        return "You are " + description + ".\n" + getExitString();
    }

  room::String getExitString()
    {
        String returnString = "Exits:";
        Set keys = exits.keySet();
        for(Iterator iter = keys.iterator(); iter.hasNext(); )
            returnString += " " + iter.next();
        returnString += "\nItems in the room:\n";
        returnString += getRoomItems() + "\n";
        return returnString;
    }

  room::Room getExit(String direction)
    {
        return (Room)exits.get(direction);
    }

  room::Item getItem(int index) {
        return getItem(index);
    }

  room::Item getItem(String itemName) {
        for (int i = 0; i < items.size(); i++) {
  IF (ITEMS.GET(I).GETDESCRIPTION().EQUALS(ITEMNAME)) {
                                RETURN ITEMS.GET(I);

                        }
                }
        RETURN NULL;
    }

  ROOM::VOID REMOVEITEM(STRING ITEMNAME) {

        FOR (INT I = 0; I < ITEMS.SIZE(); I++) {
                        IF (ITEMS.GET(I).GETDESCRIPTION().EQUALS(ITEMNAME)) {
                                ITEMS.REMOVE(I);

                        }
                }
    }

  ROOM::VOID SETITEM(ITEM NEWITEM) {
        ITEMS.ADD(NEWITEM);
    }

  ROOM::STRING GETROOMITEMS() {
        // TODO AUTO-GENERATED METHOD STUB
                        STRING OUTPUT = "";
                        FOR (INT I = 0; I < ITEMS.SIZE(); I++) {
                                OUTPUT += ITEMS.GET(I).GETDESCRIPTION() + "";
                       }






