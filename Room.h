#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room{
 public:
  Room(char*, vector<Item*>*, map<char*, Room*>*);
  char* getDesc();
  char* getLongDesc();
  char* getExitString();
  Room* getExitRoom();
 private:
  char* desc;
  vector<Item*>* itemList;
  map<char*, Room*>* exits;
};
#endif
