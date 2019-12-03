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
#include "Sack.h"
#include "Talk.h"
#include "Help.h"
#include "Plot.h"

#define HELP_TYPE 2
#define HEAD_TYPE 3
#define GRAB_TYPE 4
#define TOSS_TYPE 5
#define SACK_TYPE 6
#define TALK_TYPE 7
#define PLOT_TYPE 8

using namespace std;

void buildRoom (map<char*,Room*>*, char*, char*);
void processInput(char*, char*);
void processCommand(char* , char* , vector<Command*>*, map<char*, Room*>*, Room**, vector<Item*>*, vector<Command*>*, vector<Room*>*);
void printExitString(map<char*, char*>*);
void printItemString(vector<Item*>*);
void printRoomString(Room*);

int main(){
  
  //List of Visited Rooms (for Map)
  vector<Room*> encRooms;
  vector<Room*>* encRoomsptr = &encRooms;

  //List of Rooms
  map<char*, Room*>* rm = new map<char*, Room*>;
  
  //Adding all the Rooms!
  buildRoom(rm, (char*)"Peter Pan's Jam", (char*)"Peter Pan is jamming with some songs + dance moves.");
  buildRoom(rm, (char*)"Peter Pan's Fam", (char*)"Peter Pan's Nan is there to cheer you on. It fills you with DETERMINATION.");
  buildRoom(rm, (char*)"Peter Pan's Clan", (char*)"Peter Pan's former clan is in tears after they heard about Peter Pan's fast departure. (Custom Event Event)(Peter Pan's Saucepan)");
  buildRoom(rm, (char*)"Peter Pan's Madame Ma'am", (char*)"I told that Peter Pan that he should've just stayed with his fam on the farm! That young man pan, not a wise man! (Custom Event)(Peter Pan's Yam)");
  buildRoom(rm, (char*)"Peter Jin's North Berlin", (char*)"Peter Pan's P (Custom Event)(Peter Pan's Yam)");
  buildRoom(rm, (char*)"Peter Puffin", (char*)"Really nice but won't let you pass. (Custom Event)(Aggressive/shows true colors if you have the fin. Need safety pin to pass.");
  
  //Adding all the Exits
   
  ((*rm)[(char*)"Peter Pan's Fam"])->setExit((char*)"WEST", (char*)"Peter Pan's Jam");

  ((*rm)[(char*)"Peter Puffin"])->setExit((char*)"NORTH", (char*)"Peter Pan's Jam");

  //Adding all the items!
  
  //Inventory
  vector<Item*> bag;
  vector<Item*>* bagptr = &bag;

  //List of Commands
  vector<Command*> commands;
  vector<Command*>* commandsptr = &commands;
  
  //Current Room
  Room* currentRoom;
  Room** currentRoomptr = &currentRoom;
  Room* lastRoom = ((*rm)[(char*)"Peter Pan's Jam"]);
  
  //Command string and Keyword string
  char commandsarr[99];
  char* commandstr = commandsarr;
  char keywordsarr[99];
  char* keywordstr = keywordsarr;
  
  //Initiating commands
  commandsptr->push_back(new Help((char*)"HELP"));
  commandsptr->push_back(new Head((char*)"HEAD"));
  commandsptr->push_back(new Grab((char*)"GRAB"));
  commandsptr->push_back(new Toss((char*)"TOSS"));
  commandsptr->push_back(new Sack((char*)"SACK"));
  int* e = new int[15];
  for(int a = 0; a < 15; ++a){
    e[a] = 0;
  }
  commandsptr->push_back(new Talk((char*)"TALK", e));
  
  bool running = true;
  
  currentRoom = ((*rm)[(char*)"Peter Pan's Jam"]);

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world set in a dystopian future, where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;

  printRoomString(currentRoom);
  
  //Print out long description of room.
  //Print out exits
  //Print out items
  //Then process commands
  while(running){
    if(lastRoom != currentRoom){
      printRoomString(currentRoom);
      lastRoom = currentRoom;
    }
    processInput(commandstr, keywordstr);
    processCommand(commandstr, keywordstr, commandsptr, rm, currentRoomptr, bagptr, commandsptr, encRoomsptr);
    
    int* ev = ((Talk*)(commands.at(5)))->getEv();
    if(currentRoom == (*rm)[(char*)"Peter Pan's Jam"]){
      if(ev[0] == true){
	((*rm)[(char*)"Peter Pan's Jam"])->setExit((char*)"EAST", (char*)"Peter Pan's Fam");
        ((*rm)[(char*)"Peter Pan's Jam"])->setExit((char*)"SOUTH", (char*)"Peter Puffin");

	((*rm)[(char*)"Peter Pan's Jam"])->addItem((char*)"Peter's_Jam");
	ev[0] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Fam"]){
      if(ev[1] == true){
	commandsptr->push_back(new Plot((char*)"PLOT"));
	ev[1] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Clan"]){
      if(ev[2] == true){
	ev[2] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Madame Ma'am"]){
      if(ev[3] == true){
	ev[3] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's North Berlin"]){
      if(ev[4] == true){
	ev[4] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Puffin"]){
      if(ev[5] == true){
	ev[5] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Jin & Out Fanbase"]){
      if(ev[6] == true){
	ev[6] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Jin & Out"]){
      if(ev[7] == true){
	ev[7] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's Inn"]){
      if(ev[8] == true){
	ev[8] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Dam"]){
      if(ev[9] == true){
	ev[9] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Evil Twin"]){
      if(ev[10] == true){
	ev[10] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Milk Can"]){
      if(ev[11] == true){
	ev[11] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's Tin Bin"]){
      if(ev[12] == true){
	ev[12] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's LITTI IN MY CITY"]){
      if(ev[13] == true){
	ev[13] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's South Berlin"]){
      if(ev[14] == true){
	ev[14] = 2;
	printRoomString(currentRoom);
      }
    }
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

void processCommand(char* commandstr, char* keywordstr, vector<Command*>* commandsptr, map<char*, Room*>* rm, Room** currentRoomptr, vector<Item*>* bagptr, vector<Command*>* commands, vector<Room*>* encRoomsptr){
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
	if(strcmp(keywordstr,"") != 0){
	  ((Grab*)(*commandsIt))->take(currentRoomptr, bagptr, keywordstr);
	}else{
	  cout << ((Grab*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case TOSS_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((Toss*)(*commandsIt))->drop(currentRoomptr, bagptr, keywordstr);
	}else{
	  cout << ((Toss*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case SACK_TYPE:
	if(strcmp(keywordstr,"") == 0){
	  ((Sack*)(*commandsIt))->show(bagptr);
	}else{
	  cout << "You rummaged through your sack to find \"" << keywordstr << "\", but then you realized that \"sack\" is a one word command..." << endl;
	}
	break;
      case TALK_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Talk*)(*commandsIt))->act(rm, currentRoomptr, bagptr);
	}else{
	  cout << ((Talk*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case HELP_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Help*)(*commandsIt))->printHelp(commands);
	}else{
	  cout << ((Help*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case PLOT_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Plot*)(*commandsIt))->printMap(currentRoomptr, rm, encRoomsptr);
	}else{
	  cout << ((Plot*)(*commandsIt))->returnBurn() << endl;
	}
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

void printItemString(vector<Item*>* items){
  vector<Item*>::iterator iIt;
  for(iIt = items->begin(); iIt != items->end(); ++iIt){
    cout << (*iIt)->getName() << " ";
  }
  cout << endl;
}

void printRoomString(Room* currentRoom){
  cout << "You are at " << currentRoom->getTitle() << "!" << endl;
  cout << currentRoom->getDesc() << endl;
  cout << "Exits: ";
  printExitString(currentRoom->getExits());
  cout << "Items: ";
  printItemString(currentRoom->getItems());
}
