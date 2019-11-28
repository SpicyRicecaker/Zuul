#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#include "Room.h"
#include "Command.h"

using namespace std;

void init(bool& running, vector<Command*>* commandsptr, Room* currentRoom);
void processInput(char* commandstr, char* keywordstr);
void processCommand(char* commandstr, char* keywordstr);

int main(){

  //List of Rooms
  vector <Room*> rooms;
  vector <Room*>* roomsptr = &rooms;

  //List of Visited Rooms
  vector <Room*> encRooms;
  vector <Room*>* encRoomsptr = &encRooms;
  
  //Inventory
  vector <Item*> bag;
  vector <Item*>* bagptr = &bag;

  //List of Commands
  vector <Command*> commands;
  vector <Command*>* commandsptr = &commands;
  
  //Current Room
  Room* currentRoom;

  //Command string and Keyword string, oneword
  char* commandstr;
  char* keywordstr;

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world set in a dystopian future where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;
  
  bool running;


  Room* hi = new Room((char*) "HI", new vector<Item*>, new map<char*, Room*>);
  init(running, commandsptr, currentRoom);

  while(running){
    processInput(commandstr, keywordstr);
    processCommand(commandstr, keywordstr);
  }
}

void init(bool& running, vector<Command*>* commandsptr, Room* currentRoom){
  running = true;  
  commandsptr->push_back(new Command((char*)"Head"));
  commandsptr->push_back(new Command((char*)"Toss"));
  commandsptr->push_back(new Command((char*)"Grab"));
  currentRoom = new Room((char*) "Peter Pan's Jam", new vector<Item*>, new map<char*, Room*>);
}

//process userin, decide if it is one or two words, then return one or two words
void processInput(char* commandstr, char* keywordstr){
  char in[99];
  while(true){
    int spaces = 0;
    
    cin.get(in, 99);
    cin.clear();
    cin.ignore(999, '\n');

    for(int a = 0; a < strlen(in); ++a){
      if(in[a] == ' '){
	++spaces;
      }
    }
    
    if(in != NULL){
      //If there are no spaces just return
      if(spaces == 0){
	  commandstr = (char*) in;
	  keywordstr = NULL;
	  break;
	  //If there is 1 space make sure that there are characters to the left and right of the space
      }else if(spaces == 1){
	int index;
	for(int a = 0; a < strlen(in); a++){
	  if(in[a] == ' '){
	    index = a;
	    break;
	  }
	}
        if(index != 0 && index != strlen(in)-1){
	  char first[index];
	  char second[strlen(in)-1-index];

	  for(int a = 0; a < index; a++){
	    first[a] = in[a];
	  }
	  for(int a = index + 1; a < strlen(in); a++){
	    second[a] = in[a];
	  }
	  commandstr = (char*) first;
	  keywordstr = (char*) second;
	  break;
	}
      }
    }
    cout << "Sorry, but you entered an invalid command. Make sure to type \"HELP\" if you need help!" << endl;
    
  }
}

void processCommand(char* commandstr, char* keywordstr){
  if(keywordstr == NULL){
    vector<Room*>::iterator roomListIt;
    for(roomListIt = 
  }else{
    
  }

  
}
