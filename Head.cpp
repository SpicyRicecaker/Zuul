#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include "Head.h"
#include "Room.h"

Head::Head(char* newDesc) : Command(newDesc) {
  
}

int Head::getType(){
  return 3;
}

char* Head::returnBurn(){
  return (char*) "You head in the clouds.";
}

void Head::move(char* key, map<char*, Room*>* rm, Room **currentRoomptr){
  map<char*, char*>::iterator eIt;
  map<char*, char*>* exits = (*currentRoomptr)->getExits();
  for(eIt = exits->begin(); eIt != exits->end(); ++eIt){
    if(strcmp(eIt->first, key) == 0){
      cout << "Now trying to move to: " << eIt->second << endl;
      (*currentRoomptr) = ((*rm)[eIt->second]);
    }
  }
}
