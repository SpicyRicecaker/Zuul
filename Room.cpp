#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

Room::Room(char* newDesc, vector<Item*>* newItemList, map<char*, Room*>* newExits){
  strcpy(desc, newDesc);
  itemList = newItemList;
  exits = newExits;
}

char* Room::getDesc(){
  return desc;
}

char* Room::getLongDesc(){
  //(For Now)
  return desc;
}

char* Room::getExitString(){
  //Need to get cardinal directions later
}

Room* Room::getExitRoom(){
  //Hashmap direction
}
