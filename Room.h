#include <iostream>
#include <map>

class Room{
 public:
  Room(char*, vector<Item>, map<char*, Room>*);
  char* getDesc();
  char* getLongDesc();
  char* getExitString();
  Room getExitRoom();
 private:
  char* desc;
  vector<Item*>* itemList;
  map<char*, Room>* exits;
}
