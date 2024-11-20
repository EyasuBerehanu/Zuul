// USING CLASSES AS A SKELTON FOR ZUUL WHICH IS WHY THERES SO MUCH CODE ALREADY :)


#include <iostream>
#include <vector>
#include <memory>
#include <cstring> 
//#include <iomanip> 

#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std;


import java.util.ArrayList;

/**
 * Eyasu Berehanu
 * 11/22/2023
 *
 *  This class is the main class of the "World of Zuul" application. 
 *  "World of Zuul" is a very simple, text based adventure game.  Users 
 *  can walk around some scenery. That's all. It should really be extended 
 *  to make it more interesting!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 * 
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */

class Game 
{
    private Parser parser;
    private Room currentRoom;
    Room frontentrence, nurseroom, supplycloset, 
    mainhall, labroom, bathroom, onehall, 
    computerroom, studyroom, gym, supplyroom, 
    cafetria, kitchen, dinningroom, field;
    ArrayList<Item> inventory = new ArrayList<Item>(); 
    int itemAmount = 0;
    /**
     * Create the game and initialise its internal map.
     */
    public Game() 
    {
        createRooms();
        parser = new Parser();
    }
    
    public static void main(String[] args) {
    	Game mygame = new Game();
    	mygame.play();
    }

    /**
     * Create all the rooms and link their exits together.
     */
    private void createRooms()
    {
        
      
        // create the rooms
    	frontentrence = new Room("outside the main entrance of the university");
        nurseroom = new Room("in a nurse room");
        supplycloset = new Room("in a suplly closet (smells funky)");
        mainhall = new Room("in the main hallway");
        labroom = new Room("in the labratory room (nerd.)");
        bathroom = new Room("in the bathroom (did you flush...)");
        onehall = new Room("in 1-hall");
        computerroom = new Room("in the computing room");
        studyroom = new Room("in the study hall");
        gym = new Room("in the gym");
        supplyroom = new Room("in a room with equipment (so much stuff...)");
        field = new Room("in the track field");
        cafetria = new Room("in the cafetria (yum!)");
        dinningroom = new Room("in the dinning room (its time to grub!)");
        kitchen = new Room("in the kitchen (you cooking bro?)");
        
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

    /**
     *  Main play routine.  Loops until end of play.
     */
    public void play() 
    {            
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
                
        boolean finished = false;
        while (! finished) {
            Command command = parser.getCommand();
            finished = processCommand(command);
        }
        
        System.out.println("Thank you for playing.  Good bye.");
    }

    /**
     * Print out the opening message for the player.
     */
    private void printWelcome()
    {
        System.out.println();
        System.out.println("Welcome to Adventure!");
        System.out.println("Adventure is a new, incredibly boring adventure game.");
        System.out.println("Type 'help' if you need help.");
        System.out.println("Find all of the tech you missed placed while sleep walking the day before and return them to the Computer Room!");
        System.out.println(currentRoom.getLongDescription());
    }

    /**
     * Given a command, process (that is: execute) the command.
     * If this command ends the game, true is returned, otherwise false is
     * returned.
     */
    private boolean processCommand(Command command) 
    {
        boolean wantToQuit = false;

        if(command.isUnknown()) {
            System.out.println("I don't know what you mean...");
            return false;
        }

        String commandWord = command.getCommandWord();
        if (commandWord.equals("help"))
            printHelp();
        else if (commandWord.equals("go")) {
            wantToQuit = goRoom(command);
        }
        else if (commandWord.equals("quit")) {
            wantToQuit = quit(command);
        }
        else if (commandWord.equals("inventory")) {
        	printInventory();
        }
        else if (commandWord.equals("get")) {
        	getItem(command);
        }
        else if (commandWord.equals("drop")) {
        	dropItem(command);
        }
        return wantToQuit;
    }

    private void printInventory() {
		// TODO Auto-generated method stub
		String output = "";
		for (int i = 0; i < inventory.size(); i++) {
			output += inventory.get(i).getDescription() + "";
		}
OAOAOA		System.out.println("Your are carrying: ");
		System.out.println(output);
	}

	// implementations of user commands:

    /**
     * Print out some help information.
OAOAOA     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
    private void printHelp() 
    {
        System.out.println("You are lost. You are alone. You wander");
        System.out.println("around at the university.");
        System.out.println();
        System.out.println("Your command words are:");
        parser.showCommands();
    }
OBOBOB    /** 
     * Try to go to one direction. If there is an exit, enter the new
OBOBOB     * room, otherwise print an error message.
OBOBOB     */
    private boolean goRoom(Command command) 
    {
OBOBOB        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Go where?");
            return false;
        }

        String direction = command.getSecondWord();

        // Try to leave current room.
        Room nextRoom = currentRoom.getExit(direction);
        
        
        if (nextRoom == null)
            System.out.println("Thre is no door!");
        else {
            currentRoom = nextRoom;
            System.out.println(currentRoom.getLongDescription());
            if (currentRoom == computerroom && itemAmount == -5) {
            	System.out.println("You win!");
            	System.out.println("HORRAY! You returned all the items before your Computer Science Teacher noticed.");
            	return true;
            }
        }
        return false;
    }
    private void dropItem(Command command) // allows us to drop collected items from our inventory
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know what we want to drop...
            System.out.println("Drop what?");
            return;
        }

        String item = command.getSecondWord();

        // Try to leave current room.
        Item newItem = null;
        int index = 0;
        for (int i = 0; i < inventory.size(); i++) {
			if (inventory.get(i).getDescription().equals(item)) {
