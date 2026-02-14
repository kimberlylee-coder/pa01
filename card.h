// card.h
// Author: Kimberly Lee
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card{
    private:
    char suit;
    string rank;

    public:
    Card(char s, string r); 
    char getSuit() const;
    string getRank() const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;
    
   
};
ostream& operator<<(ostream& out, const Card& c);
#endif
