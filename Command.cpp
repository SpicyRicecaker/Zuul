#include <iostream>
#include "Command.h"

using namespace std;

Command::Command(char* newDesc){
  desc = newDesc();
}
