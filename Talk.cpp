#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Talk.h"
#include "Item.h"
#include "Room.h"

Talk::Talk(char* newDesc, int* newEv) : Command(newDesc){
  ev = newEv;
}

int Talk::getType(){
  return 7;
}

char* Talk::returnBurn(){
  return (char*) "Unfortunately, you do not have the rights to free speech in this game.";
}


int* Talk::getEv(){
  return ev;
}

void Talk::act(map<char*, Room*>* rm, Room** currentRoom, vector<Item*>* bag){
  char scrollText[999] = ""; 
  if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Jam") == 0){
    if(ev[0] == false){
      cout << "You try to jam along with Peter Pan. Suddenly, he is spirited away by some EVIL PEANUT BUTTER" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "All that remains is Peter's Jam. It fills you with DETERMINATION" << endl;
      ev[0] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Fam") == 0){
    if(ev[1] == false){
      cout << "Suddenly, a broad-shouldered handsome man stumbles into the room." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "*sniff* I'm Peter Pan's Uncle Sam. *sniff* Here, take this map. I don't need it anymore." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "You got the map! Type \"Plot\" to read it!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[1] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Clan") == 0){
    if(ev[2] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[2] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Madame Ma'am") == 0){
    if(ev[3] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[3] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's North Berlin") == 0){
    if(ev[4] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[4] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Puffin") == 0){
    if(ev[5] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[5] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Jin & Out Fanbase") == 0){
    if(ev[6] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[6] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Jin & Out") == 0){
    if(ev[7] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[7] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's Inn") == 0){
    if(ev[8] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[8] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Dam") == 0){
    if(ev[9] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[9] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Evil Twin") == 0){
    if(ev[10] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[10] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Milk Can") == 0){
    if(ev[11] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[11] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's Tin Bin") == 0){
    if(ev[12] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[12] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's LITTI IN MY CITY") == 0){
    if(ev[13] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[13] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's South Berlin") == 0){
    if(ev[14] == false){
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[14] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }
}
