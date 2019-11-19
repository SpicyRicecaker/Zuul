#include <iostream>
#include "Command.h"

using namespace std;

Command::Command(char* newDesc){
  strcpy(desc, newDesc);
}

void Command::head(){

}

void Command::grab(){

}

void Command::toss(){

}
