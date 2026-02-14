// card.cpp
// Author: Kimberly Lee
// Implementation of the classes defined in card.h
#include "card.h"
#include <iostream>
#include <exception>
using namespace std;

int getSuitValue(char s){
    if(s=='c'){
        return 1;
    }
    if(s=='d'){
        return 2;
    }
    if(s=='s'){
        return 3;
    }
    if(s=='h'){
        return 4;
    }
    return 0;
}
int getRankValue(string r){
    if(r=="a"){
        return 1;
    }
    if(r=="2"){
        return 2;
    }
     if(r=="3"){
        return 3;
    }
     if(r=="4"){
        return 4;
    }
     if(r=="5"){
        return 5;
    }
     if(r=="6"){
        return 6;
    }
     if(r=="7"){
        return 7;
    }
     if(r=="8"){
        return 8;
    }
     if(r=="9"){
        return 9;
    }
     if(r=="10"){
        return 10;
    }
     if(r=="j"){
        return 11;
    }
     if(r=="q"){
        return 12;
    }
     if(r=="k"){
        return 13;
    }
     return 0;

}

Card::Card(char s, string r){
    suit=s;
    rank=r;

}

char Card::getSuit() const{
    return suit;
 }
string Card::getRank() const{
    return rank;
}
bool Card::operator<(const Card& other) const{
    if(this->suit!=other.suit){
            return getSuitValue(this->suit) < getSuitValue(other.suit);
    }
    return getRankValue(this->rank) < getRankValue(other.rank);
}

bool Card::operator>(const Card& other) const{
    if(this->suit!=other.suit){
            return getSuitValue(this->suit) > getSuitValue(other.suit);
    }
    return getRankValue(this->rank) > getRankValue(other.rank);
}

bool Card::operator==(const Card& other) const{
    if(this->suit!=other.suit){
            return false;
    }
    if(this->rank!=other.rank){
        return false;
    }
    return false;
   
}

ostream& operator<<(ostream& out, const Card& c){
    out << c.getSuit() << " " << c.getRank();
    return out;
}