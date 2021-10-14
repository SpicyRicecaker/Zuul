#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Sack.h"
#include "Item.h"

Sack::Sack(char *newDesc) : Command(newDesc)
{
}

int Sack::getType()
{
  return 6;
}

char *Sack::returnBurn(char *key)
{
  return key;
}

void Sack::show(vector<Item *> *bag)
{

  vector<Item *>::iterator bagIt;
  if (bag->begin() != bag->end())
  {
    for (bagIt = bag->begin(); bagIt != bag->end(); ++bagIt)
    {
      cout << (*bagIt)->getName() << " ";
    }
    cout << endl;
  }
  else
  {
    cout << "You don't have anything..." << endl;
  }
}
