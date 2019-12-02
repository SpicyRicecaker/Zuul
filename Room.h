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
  Room(char*, char*, vector<Item*>*, map<char*, char*>*);
  char* getTitle();
  char* getDesc();
  map<char*, char*>* getExits();
  Room* getExitRoom();
  void setExit(char*, char*);
 private:
  char* title;
  char* desc;
  vector<Item*>* itemList;
  map<char*, char*>* exits;
};
#endif
