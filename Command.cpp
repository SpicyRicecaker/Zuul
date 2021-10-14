#include <iostream>
#include <cstring>
#include "Command.h"

using namespace std;

Command::Command(char *newDesc)
{
  desc = newDesc;
}

char *Command::getDesc()
{
  return desc;
}

int Command::getType()
{
  return 0;
}

char *Command::returnBurn()
{
  return new char[0];
}
