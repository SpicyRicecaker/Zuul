#include <iostream>
#include <cstring>
#include "Item.h"

Item::Item(char* newName){
  strcpy(name,newName);
}

char* Item::getName(){
  return name;
}


