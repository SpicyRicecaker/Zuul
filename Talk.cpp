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
      cout << "All that remains is Peter's Jam. It fills you with DETERMINATION!" << endl;
      ev[0] = true;
    }else{
      cout << "There's no one to talk to ... maybe you should check in with Peter Pan's Fam to the East?" << endl;
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
      cout << "*sniff* You look healthy... take some SPAM. (Not sponsored by SPAM)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[1] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Clan") == 0){
    if(ev[2] == false){
      cout << "Wahhhhhh! It's not fair! He was too young! (Wails and Sobs drown you like flowing water)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "But carleston, what are we going going to do with Peter Pan's Saucepan?" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Jacob, no one cares! Just throw it in the corner somewhere!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(The crying continues)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[2] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Madame Ma'am") == 0){
    if(ev[3] == false){
      cout << "I told that Peter Pan that he should've just stayed with his fam on the farm!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "That young man pan, not a wise man!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Here, take some yam" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(Peter Pan's Yam drifts through the air and lands at your feet, as deft as a feather)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[3] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's North Berlin") == 0){
    if(ev[4] == false){
      cout << "We want tasty lamb stew! We want tasty lamb stew!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(In the corner, a small band of faithful Peter Pan Followers Huddle around ... a plump and tasty lamb...)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(If only they had something that was cheap to eat, comes in large quantities, and can be prepared quickly)" << endl;
      //ev[4] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Puffin") == 0){
    if(ev[5] == false){
      cout << "Hey there! Sorry, but I'll have to pass on letting you pass!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      //ev[5] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Jin & Out Fanbase") == 0){
    if(ev[6] == false){
      cout << "Hey yo! Are you Peter Pan's Fan? Of course you are! (A folded fan slaps you right on the forhead)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Everyone is investing their stocks into the Peter Jin Bin megacorp(tm) after Peter Pan's disappearance, but you better stay faithful!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(You really don't know what do say)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[6] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Jin & Out") == 0){
    if(ev[7] == false){
      cout << 
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
