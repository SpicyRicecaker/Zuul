#include <iostream>
#include <cstring>
#include "Command.h"

class Head : public Command {
 public:
  Head(char*);
  int getType();
  char* returnBurn();
  void doStuff(char*, char*);
 private:
};
