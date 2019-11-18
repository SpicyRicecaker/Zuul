#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

int main(){

  //List of Rooms
  vector <Room*> rooms;
  vector <Room*>* roomsptr = &rooms;

  //List of Visited Rooms
  vector <Room*> encRooms;
  vector <Room*> encRoomsptr = &encRooms;
  
  //Inventory
  vector <Item*> bag;
  vector <Item*>* bagptr = &bag;
  
  //Plan for commands: Have vector of Cstrings.  

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world in a set in a dystopian future where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;
  
  bool running = true;
  
  while(running){
    
  }
}
