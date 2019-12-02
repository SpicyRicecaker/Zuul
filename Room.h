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
  Room(char*, char*, vector<Item*>*, map<char*, Room*>*);
  char* getTitle();
  char* getDesc();
  map<char*, Room*>* getExits();
  Room* getExitRoom();
  void setExit(char*, Room*);
 private:
  char* title;
  char* desc;
  vector<Item*>* itemList;
  map<char*, Room*>* exits;
};
#endif
