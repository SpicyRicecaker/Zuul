#include <iostream>

class Command
{
 public:
  //A command just needs a description
  Command(char*);
  bool checkFor();
  void head();
  void grab();
  void toss();
 private:
  char* desc;
}
