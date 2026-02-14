#include "card_list.h"
#include "card.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


void verifySequence(CardBST& bst, vector<Card> expected) {
    size_t i = 0;
    for (auto it = bst.begin(); it != bst.end(); ++it) {
        assert(*it == expected[i++]);
    }
    assert(i == expected.size());
}

int main() {
    //bst tests
    cout << "Testing BST Methods..." << endl;
    CardBST t;
    Card c1('c', "3"), c2('d', "j"), c3('s', "10"), c4('h', "a"), c5('s', "5");

    //empty tree contains
    assert(t.contains(c1) == false);

   //single node insert/contains
    t.insert(c1);
    assert(t.contains(c1) == true);

    //multiple node ordering
    t.insert(c2); 
    t.insert(c3); 
    t.insert(c4);
   
    verifySequence(t, {c1, c2, c3, c4});

    //edge case
    assert(t.insert(c1) == false);

    //memory management and removal
    t.remove(c4); 
    assert(!t.contains(c4));
    t.remove(c1); 
    assert(!t.contains(c1));
    
    //edge case
    assert(t.remove(c5) == false); 

    //iterator tests
    cout << "Testing Iterator Methods..." << endl;
    CardBST itTree;
    Card a('c', "2"), b('d', "4"), c('s', "6");

    //empty tree
    assert(itTree.begin() == itTree.end());
    assert(itTree.rbegin() == itTree.rend());

    //single node
    itTree.insert(b);
    auto it = itTree.begin();
    assert(*it == b);
    assert(++it == itTree.end());

    //multiple nodes
    itTree.insert(a); itTree.insert(c);
    auto itF = itTree.begin();
    assert(*itF == a); 
    ++itF;
    assert(*itF == b); 
    ++itF;
    assert(*itF == c);

    //Incrementing past the end and decrementing past the reverse end
    auto itR = itTree.rbegin();
    assert(*itR == c); --itR;
    assert(*itR == b); --itR;
    assert(*itR == a);

    //iterator comparison
    auto it1 = itTree.begin();
    auto it2 = itTree.begin();
    assert(it1 == it2);
    assert(!(it1 != it2));
    ++it2;
    assert(it1 != it2);

   
    //playgame
    cout << "Testing PlayGame Logic..." << endl;

    //common cards
    CardBST p1, p2;
    p1.insert(c3); p2.insert(c3);
    playGame(p1, p2);
    assert(!p1.contains(c3) && !p2.contains(c3));

    //no common hands
    p1.insert(Card('h', "k"));
    p2.insert(Card('c', "2"));
    playGame(p1, p2);
    assert(p1.contains(Card('h', "k")));

    //one empty hand
    CardBST empty;
    playGame(p1, empty); 
    
    cout << "\n>> ALL MANDATORY SCENARIOS PASSED <<" << endl;
    return 0;
}

