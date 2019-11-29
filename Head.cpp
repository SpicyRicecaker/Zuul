#include <iostream>
#include <cstring>
#include "Head.h"

Head::Head(char* newDesc) : Command(newDesc) {
  
}

int Head::getType(){
  return 3;
}

char* Head::returnBurn(){
  return (char*) "You head in the clouds.";
}

void Head::doStuff(char* com, char* key){
  
}
