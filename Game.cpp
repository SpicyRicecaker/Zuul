#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"
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
  currentRoom = new Room((char*)"Peter Pan's Jam", new vector<Item*>, new map<char*, Room*>);
}

//process userin, decide if it is one or two words, then return one or two words
void processInput(char* commandstr, char* keywordstr){
  char in[99];
  while(true){
    int spaces = 0;
    bool validChar = true;
    
    cin.get(in, 99);
    cin.clear();
    cin.ignore(999, '\n');
    
    for(int a = 0; a < strlen(in); ++a){
      if(in[a] == ' '){
	++spaces;
      }
    }

    if(spaces == 0){
      for(a = 0; a < strlen(in); ++a){
	if(isalpha(in[a]) == 1){
	  validChar = false;
	  break;
	}
      }
      if(validChar && in != NULL){
	commandstr = (char*)in;
	keywordstr = NULL;
	
      }
    }else if(spaces == 1){
      int index;
      for(int a = 0; a < strlen(in); a++){
	if(in[a] == ' '){
	  index = a;
	  break;
	}
      }
      if(index == strlen(in)-1){
	char[]
      }
    }
    
  }
}

void processCommand(char* commandstr, char* keywordstr){

}
