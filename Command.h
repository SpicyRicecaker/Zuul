#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <cstring>

using namespace std;

class Command
{
public:
  //A command just needs a description
  Command(char *);
  char *getDesc();
  char *getExplanation();
  virtual int getType();
  virtual char *returnBurn();

private:
  char *desc;
};
#endif
