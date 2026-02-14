// card_list.h
// Author: Kimberly Lee
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
#include <iostream>
#endif


class CardBST{
    private:

        struct Node{
            Card card;
            Node* left;
            Node* right;
            Node* parent;
            Node(Card c) : card(c),left(nullptr),right(nullptr),parent(nullptr){}
        };
        Node *root;
        void clear(Node* n);
        bool insert(const Card& c, Node* n);
        void printInOrder(Node* n) const;

    public:
    CardBST();
    ~CardBST();
    bool insert(const Card& c);
    bool remove(const Card& c);
    bool contains(const Card& c) const;
    void printInOrder() const;

    class Iterator{
        private:
            Node* curr;
        public:

        Iterator(Node* n):curr(n){}
        const Card& operator*() const;
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Iterator& operator++();
        Iterator& operator--();

    };

    Iterator begin() const;
    Iterator end() const;
    Iterator rbegin() const;
    Iterator rend() const;

};
void playGame(CardBST& alice, CardBST& bob);

