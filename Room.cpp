#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#include "Room.h"

Room::Room(char* newTitle, char* newDesc, vector<Item*>* newItemList, map<char*, Room*>* newExits){
  title = newTitle;
  desc = newDesc;
  itemList = newItemList;
  exits = newExits;
}

char* Room::getTitle(){
  //cout << "???" << endl;
  return title;
}

char* Room::getDesc(){
  return desc;
}

map<char*, Room*>* Room::getExits(){
  //Need to get cardinal directions later
  return exits;
}

Room* Room::getExitRoom(){
  //Hashmap direction
}

void Room::setExit(char* direction, Room* destination){
  (*exits)[direction] = destination; 
}
