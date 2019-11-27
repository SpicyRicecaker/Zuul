#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Command.h"

using namespace std;

void init(bool& running, vector<Command*>* commandsptr);

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
  
  //Plan for commands: Have vector of Cstrings.  

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world set in a dystopian future where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;
  
  bool running;
 
  init(running, commandsptr);

  while(running){
    vector<Command*>::iterator comIt;
    exit(1);
  }
}

void init(bool& running, vector<Command*>* commandsptr){
  running = true;  
  commandsptr->push_back(new Command(new char[4]{'H','e','a','d'}));
  commandsptr->push_back(new Command(new char[4]{'G','r','a','b'}));
  commandsptr->push_back(new Command(new char[4]{'T','o','s','s'}));
}
