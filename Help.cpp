#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Help.h"

Help::Help(char *newDesc) : Command(newDesc)
{
}

int Help::getType()
{
  return 2;
}

char *Help::returnBurn()
{
  return (char *)"Just type \"Help\" lol";
}

void Help::printHelp(vector<Command *> *commands)
{
  vector<Command *>::iterator comIt;
  cout << "Your commands are: " << endl;
  for (comIt = commands->begin(); comIt != commands->end(); ++comIt)
  {
    cout << (*comIt)->getDesc() << " = ";

    if (strcmp("HELP", (*comIt)->getDesc()) == 0)
    {
      cout << "Lists all commands and gives a description of them." << endl;
    }
    else if (strcmp("HEAD", (*comIt)->getDesc()) == 0)
    {
      cout << "Moves to a room in a given cardinal direction. HEAD <DIRECTION>" << endl;
    }
    else if (strcmp("GRAB", (*comIt)->getDesc()) == 0)
    {
      cout << "Picks up a specified item. GRAB <ITEM_NAME>" << endl;
    }
    else if (strcmp("TOSS", (*comIt)->getDesc()) == 0)
    {
      cout << "Drops a specified item. TOSS <ITEM_NAME>" << endl;
    }
    else if (strcmp("SACK", (*comIt)->getDesc()) == 0)
    {
      cout << "Lists all items in your inventory." << endl;
    }
    else if (strcmp("TALK", (*comIt)->getDesc()) == 0)
    {
      cout << "a VERY IMPORTANT COMMAND!!! Make sure to talk to all the NPCs in every room to advance the story / progress!" << endl;
    }
    else if (strcmp("QUIT", (*comIt)->getDesc()) == 0)
    {
      cout << "Exits the game." << endl;
    }
    else if (strcmp("PLOT", (*comIt)->getDesc()) == 0)
    {
      cout << "Gives a (very scuffed) outline of visited rooms." << endl;
    }
  }
}
