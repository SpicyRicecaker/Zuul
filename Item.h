#ifndef ADD_H
#define ADD_H

#include <iostream>
#include <cstring>

class Item
{
public:
  //An item has a name
  Item(char *);
  char *getName();

private:
  char *name;
};
#endif
