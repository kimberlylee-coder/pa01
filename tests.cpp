#include "card_list.h"
#include "card.h"
#include <iostream>
#include <string>

using namespace std;

int getTest();

int main() {
    CardBST bst1, bst2;

   
    bst1.insert(Card('s', "10"));
    bst1.insert(Card('h', "a"));
    bst1.insert(Card('c', "3"));
    bst1.insert(Card('d', "j"));
    bst1.insert(Card('s', "5"));

    bool all=true;
    int testnum=getTest();
    if(testnum){
        all=false;
    }


    if(all || testnum == 1){
        cout << "  in-order: " << endl;
        bst1.printInOrder();
        cout << endl;
    }

    if(all || testnum == 2){
        cout << "  contains s 10? " << (bst1.contains(Card('s', "10")) ? "Y" : "N") << endl;
        cout << "  contains h 3? " << (bst1.contains(Card('h', "3")) ? "Y" : "N") << endl;
    }


    if(all || testnum == 3){
        cout << "  removing s 10..." << endl;
        bst1.remove(Card('s', "10"));
        cout << "  contains s 10 now? " << (bst1.contains(Card('s', "10")) ? "Y" : "N") << endl;
        cout << "  new in-order: " << endl;
        bst1.printInOrder();
    }

 
    if(all || testnum == 4){
        cout << "  Testing Iterator Forward: " << endl;
        for (auto it = bst1.begin(); it != bst1.end(); ++it) {
            cout << "  " << *it << endl;
        }
    }


    if(all || testnum == 5){
        CardBST alice, bob;
        alice.insert(Card('s', "a"));
        alice.insert(Card('h', "k"));
        bob.insert(Card('s', "a"));
        
        cout << "  Testing playGame logic..." << endl;
        playGame(alice, bob);
        cout << "  Alice contains s a? " << (alice.contains(Card('s', "a")) ? "Y" : "N") << endl;
    }

    return 0;
}

int getTest(){
    cout << "Choice of tests:\n"
         << "  0. all tests\n"
         << "  1. printInOrder\n"
         << "  2. contains\n"
         << "  3. remove\n"
         << "  4. iterators\n"
         << "  5. playGame\n";
    int choice;
    cin >> choice;
    return choice;
}