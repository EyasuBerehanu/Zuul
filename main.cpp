// USING CLASSES AS A SKELTON FOR ZUUL WHICH IS WHY THERES SO MUCH CODE ALREADY :)


#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include "room.h"

using namespace std;

void add(vector<room*>& rooms);
void search(const vector<room*>& rooms);
void drop(vector<room*>& rooms);

void menu() {
  cout << "you are currrently in " << currentRoom << endl;
}
void createRooms(){
        // create the rooms
    	frontentrence = new room("outside the main entrance of the university");
        nurseroom = new room("in a nurse room");
        supplycloset = new room("in a suplly closet (smells funky)");
        mainhall = new room("in the main hallway");
        labroom = new room("in the labratory room (nerd.)");
        bathroom = new room("in the bathroom (did you flush...)");
        onehall = new room("in 1-hall");
        computerroom = new room("in the computing room");
        studyroom = new room("in the study hall");
        gym = new room("in the gym");
        supplyroom = new room("in a room with equipment (so much stuff...)");
        field = new room("in the track field");
        cafetria = new room("in the cafetria (yum!)");
        dinningroom = new room("in the dinning room (its time to grub!)");
        kitchen = new room("in the kitchen (you cooking bro?)");
        
        // initialise room exits
        frontentrence.setExit("west", mainhall);
        frontentrence.setExit("south", nurseroom);
        
        nurseroom.setExit("north", frontentrence);
        nurseroom.setExit("south", supplycloset);
        
        supplycloset.setExit("north", nurseroom);
        
        mainhall.setExit("north", labroom);
        mainhall.setExit("south", bathroom);
        mainhall.setExit("east", frontentrence);
        mainhall.setExit("west", onehall);
        
        bathroom.setExit("north", mainhall);
        
        labroom.setExit("west", computerroom);
        labroom.setExit("south", mainhall);
        
        onehall.setExit("north", computerroom);
        onehall.setExit("south", studyroom);
        onehall.setExit("east", mainhall);
        onehall.setExit("west", gym);
        
        computerroom.setExit("east", labroom);
        computerroom.setExit("south", onehall);
        
        gym.setExit("west", field);
        gym.setExit("north", supplyroom);
        gym.setExit("east", onehall);
        
        field.setExit("east", gym);
        
        supplyroom.setExit("south", gym);
        
        studyroom.setExit("north", onehall);
        studyroom.setExit("south", cafetria);
        
        cafetria.setExit("north", studyroom);
        cafetria.setExit("south", dinningroom);
        cafetria.setExit("west", kitchen);
        
        kitchen.setExit("east", cafetria);
        
        dinningroom.setExit("north", cafetria);
        
        currentRoom = frontentrence;  // start game outside
        
        
        
        
        kitchen.setItem(new Item("Computer"));
        
        
        bathroom.setItem(new Item("VR"));
        
        
        supplycloset.setItem(new Item("Mouse"));
        
        
        supplyroom.setItem(new Item("Keyboard"));
        
        
        gym.setItem(new Item("Headphones"));    
}

int main() {
    vector<room*> rooms; 
    char choice[80];
    bool start = true;
    
    menu();
    while(start) { 
        cin.getline(choice, 80);
        if(strcmp(choice, "Add") == 0) {
            add(mediaData);
        } 
        else if (strcmp(choice, "Exit") == 0) {
            search(mediaData);
        }
        else if (strcmp(choice, "Drop") == 0) {
            deletee(mediaData);
        }
        else if (strcmp(choice, "Quit") == 0) {
            start = false; 
        }
       // else {
          //  cout << "Invalid choice so try again." << endl;
           // menu();
        //}
    }

    
    for (size_t i = 0; i < mediaData.size(); ++i) { 
        delete mediaData[i];  
    }
        mediaData.clear();
    
}

void add(vector<room*>& rooms) {
   char type[20];
    cout << "Do you want to add info for Video Game, Music, or Movie: " << endl;
    cin.getline(type, 20);
    
    if (strcmp(type, "Video Game") == 0) {
        char title[80];
  
        room.push_back(item);
	cout << "Added Video Game: " << title << endl; 
        menu();
       
    else {
        cout << "Invalid type.\n" << endl;;
        menu();
    }
    
}
}
void search(const vector<room*>& rooms) {  
    char choice[80];
    cout << "Search by Title or Year (Type it in to choose): ";
    cin.getline(choice, 80);

    bool found = false;

    if (strcmp(choice, "Title") == 0) { 
        char keyword[80];
        cout << "Enter title to search: ";
        cin >> ws;  
        cin.getline(keyword, 80);

        for (DigitalMedia* media : mediaData) {
            if (strcmp(media->getTitle(), keyword) == 0) {  
                media->displayInfo();
                found = true;
            }
        }
    } else if (strcmp(choice, "Year") == 0) {
        int keyyear;
        cout << "Enter year to search: ";
        cin >> keyyear;

        for (DigitalMedia* media : mediaData) {
            if (media->getYear() == keyyear) {  
                media->displayInfo();
                found = true;
            }
        }
    } else {
        cout << "Invalid choice try a difftrent command.\n";
        return;  
    }

    if (!found) { 
        cout << "Search not found.\n";
    }
}

 void drop(vector<room*>& rooms) { 
    char keyword[80];
    
    cout << "Enter title to delete: ";
    cin >> ws;  
    cin.getline(keyword, 80);  

    for (size_t i = 0; i < mediaData.size(); ++i) { 
        if (strcmp(mediaData[i]->getTitle(), keyword) == 0) {  
            mediaData[i]->displayInfo();  
            
            char confrim[80];
            cout << "Are you sure you want to delete this? (Yes/No): ";
            cin >> confrim;
            
            if (strcmp(confrim, "Yes") == 0) {
                delete mediaData[i];  
                mediaData.erase(mediaData.begin() + i);
                cout << "Item deleted.\n";
                return;  
            } else {
                cout << "Deletion failed.\n";
                return;  
            }
        }
    }

    cout << "Nothing matches with your serach.\n";  
}
