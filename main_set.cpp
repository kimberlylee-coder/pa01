// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  set<Card> alice_cards;
  while (getline (cardFile1, line) && (line.length() > 0)){
      Card c(line[0], line.substr(2));
      alice_cards.insert(c);
  }
  cardFile1.close();

 set<Card> bob_cards;
  while (getline (cardFile2, line) && (line.length() > 0)){
    Card c(line[0], line.substr(2));
    bob_cards.insert(c);
  }
  cardFile2.close();


bool game=true;

while(game){
  bool aliceFound=false;
  Card matchAlice(' ',"");

  for(auto it=alice_cards.begin();it!=alice_cards.end() && !aliceFound;++it){
    if(bob_cards.count(*it)){
      matchAlice=*it;
      aliceFound=true;


    }
  }
  if(aliceFound){
    cout << "Alice picked matching card " << matchAlice << endl;
    alice_cards.erase(matchAlice);
    bob_cards.erase(matchAlice);
  }

  bool bobFound=false;
  Card matchBob(' ', "");
  for(auto it=bob_cards.rbegin();it!=bob_cards.rend() && !bobFound; ++it){
      if(alice_cards.count(*it)){
        matchBob=*it;
        bobFound=true;
      }
  }

  if(bobFound){
    cout << "Bob picked matching card " << matchBob << endl;
    alice_cards.erase(matchBob);
    bob_cards.erase(matchBob);
  }

  if(!aliceFound && !bobFound){
    game=false;
  }

}
  cout << endl << "Alice's cards:" << endl;
  for(const auto& cards : alice_cards){
    cout << cards << endl;
  }
  
  cout << endl << "Bob's cards:" << endl;
  for(const auto& cards : bob_cards){
    cout << cards << endl;
  }
  return 0;

}
