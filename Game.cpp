#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Command.h"

using namespace std;

void init(bool& running, vector<Command*>* commandsptr, Room* currentRoom);

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

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world set in a dystopian future where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;
  
  bool running;
 
  init(running, commandsptr, currentRoom);

  while(running){
    vector<Command*>::iterator comIt;
    exit(1);
  }
}

void init(bool& running, vector<Command*>* commandsptr, Room* currentRoom){
  running = true;  
  commandsptr->push_back(new Command((char*)"Head"));
  commandsptr->push_back(new Command((char*)"Toss"));
  commandsptr->push_back(new Command((char*)"Grab"));
  currentRoom = new Room((char*)"Peter Pan's Jam", new vector<Item*>, new map<char*, Room*>);
}
