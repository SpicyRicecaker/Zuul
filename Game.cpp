#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#include "Room.h"
#include "Command.h"
#include "Head.h"
#include "Grab.h"
#include "Toss.h"

#define HEAD_TYPE 3
#define GRAB_TYPE 4
#define TOSS_TYPE 5

using namespace std;

void buildRoom (map<char*,Room*>*, char*, char*);
void processInput(char*, char*);
void processCommand(char* , char* , vector<Command*>*, map<char*, Room*>*, Room**);
void printExitString(map<char*, char*>*);

int main(){

  //List of Rooms
  vector<Room*> rooms;
  vector<Room*>* roomsptr = &rooms;

  //List of Visited Rooms (for Map)
  vector<Room*> encRooms;
  vector<Room*>* encRoomsptr = &encRooms;

  //List of Names of Rooms
  map<char*, Room*>* rm = new map<char*, Room*>;

  //Adding all the Rooms!
  buildRoom(rm, (char*)"Peter Pan's Jam", (char*)"Peter Pan is jamming with some songs + dance moves. (Custom Event)(He is spirited away by some EVIL PEANUT BUTTER)");
  buildRoom(rm, (char*)"Peter Pan's Fam", (char*)"Peter Pan's Nan is there to cheer you on. It fills you with DETERMINATION. (Custom Event)(Peter Pan's Uncle Sam hands you some SPAM and a map.");
  buildRoom(rm, (char*)"Peter Puffin", (char*)"Really nice but won't let you pass. (Custom Event)(Aggressive/shows true colors if you have the fin. Need safety pin to pass.");
  
  //Adding all the Exits
  ((*rm)[(char*)"Peter Pan's Jam"])->setExit((char*)"EAST", (char*)"Peter Pan's Fam");
  ((*rm)[(char*)"Peter Pan's Jam"])->setExit((char*)"SOUTH", (char*)"Peter Puffin");

  ((*rm)[(char*)"Peter Pan's Fam"])->setExit((char*)"WEST", (char*)"Peter Pan's Jam");
  
  //Inventory
  vector<Item*> bag;
  vector<Item*>* bagptr = &bag;

  //List of Commands
  vector<Command*> commands;
  vector<Command*>* commandsptr = &commands;
  
  //Current Room
  Room* currentRoom;
  Room** currentRoomptr = &currentRoom;
  
  //Command string and Keyword string
  char commandsarr[99];
  char* commandstr = commandsarr;
  char keywordsarr[99];
  char* keywordstr = keywordsarr;
  
  //Initiating commands
  commandsptr->push_back(new Head((char*)"HEAD"));
  //commandsptr->push_back(new Command((char*)"Toss"));
  //commandsptr->push_back(new Command((char*)"Grab"));
  
  bool running = true;
  
  currentRoom = ((*rm)[(char*)"Peter Pan's Jam"]);

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world set in a dystopian future, where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;
  
  //Print out long description of room.
  //Print out exits
  //Print out items
  //Then process commands
  while(running){
    cout << "You are at " << currentRoom->getTitle() << "!" << endl;
    cout << currentRoom->getDesc() << endl;
    //Finish this then sleep VVV
    cout << "Exits: ";
    printExitString(currentRoom->getExits());
    cout << "Items: " << endl;
    processInput(commandstr, keywordstr);
    processCommand(commandstr, keywordstr, commandsptr, rm, currentRoomptr);
  }
}

void buildRoom (map<char*,Room*>* rm, char* rmTitle, char* rmDesc) {
  (*rm)[rmTitle] = new Room(rmTitle, rmDesc, new vector<Item*>, new map<char*,char*>);
}

//process userin, decide if it is one or two words, then return one or two words
void processInput(char* commandstr, char* keywordstr){
  char in[99];
  while(true){
    int spaces = 0;
    
    cin.get(in, 99);
    cin.clear();
    cin.ignore(999, '\n');
    
    if(strlen(in) != 0){
      for(int a = 0; a < strlen(in); ++a){
      in[a] = toupper(in[a]);
        if(in[a] == ' '){
	  ++spaces;
        }
      }
      //If there are no spaces just return
      if(spaces == 0){
        strcpy(commandstr,in);
	strcpy(keywordstr,"");
	break;
	//If there is 1 space make sure that there are characters to the left and right of the space
      }else if(spaces == 1){
	int index;
	for(int a = 0; a < strlen(in); ++a){
	  if(in[a] == ' '){
	    index = a;
	    break;
	  }
	}
        if(index != 0 && index != strlen(in)-1){
	  //We add 1 more to the array length to hold the null terminating character
	  char first[index+1] = "";
	  char second[(strlen(in)-index)] = "";
	  
	  for(int a = 0; a < index; ++a){
	    first[a] = in[a];
	  }
	  for(int a = index + 1; a < strlen(in); ++a){
	    second[a-index-1] = in[a];
	  }
	  strcpy(commandstr,first);
	  strcpy(keywordstr,second);
	  break;
	}
      }
    }
    cout << "Invalid command. Make sure to type \"HELP\" if you need help!" << endl;
  }
}

void processCommand(char* commandstr, char* keywordstr, vector<Command*>* commandsptr, map<char*, Room*>* rm, Room** currentRoomptr){
    vector<Command*>::iterator commandsIt;
    bool found = false;
    for(commandsIt = commandsptr->begin(); commandsIt != commandsptr->end(); ++commandsIt){
      if(strcmp((*commandsIt)->getDesc(), commandstr) == 0){
	found = true;
	break;
      }
    }
    if(found == false){
      cout << "Sorry, but you entered an invalid command. Make sure to type \"HELP\" if you need help!" << endl;
    }else{
      int type = (*commandsIt)->getType();
      switch (type){
      case HEAD_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((Head*)(*commandsIt))->move(keywordstr, rm, currentRoomptr);
	}else{
	  cout << ((Head*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case GRAB_TYPE:
	break;
      case TOSS_TYPE:
	break;
      }      
    }
}

void printExitString(map<char*, char*>* exits){
  map<char*, char*>::iterator it;
  for(it = exits->begin(); it != exits->end(); ++it){
    cout << it->first << " ";
  }
  cout << endl;
}
