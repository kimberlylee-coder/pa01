// card_list.cpp
// Author: Kimberly Lee
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include "card.h"
#include <iostream>
using namespace std;

CardBST::CardBST(){
    root=nullptr;
}
CardBST::~CardBST(){
    clear(root);
}


void CardBST::clear(Node *n) {
if(n==nullptr){
    return;
}
clear(n->left);
clear(n->right);
delete n;
}


bool CardBST::insert(const Card& c){
    if(root==nullptr){
        root=new Node(c);
        return true;
    }
    return insert(c,root);
}

bool CardBST::insert(const Card& c, Node* n){
    if(c==n->card){
        return false;
    }
    if(c<n->card){
        if(n->left==nullptr){
            n->left=new Node(c);
            n->left->parent = n;
            return true;
        }
        return insert(c,n->left);
    }

    else{
        if(n->right==nullptr){
            n->right=new Node(c);
             n->right->parent = n; 
            return true;
        }
        return insert(c,n->right);
    }
}


bool CardBST::remove(const Card& c){
    Node* curr=root;
    while(curr!=nullptr && !(curr->card==c)){
        if(c<curr->card){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }

    if(curr==nullptr){
        return false;
    }

    if(curr->left!=nullptr && curr->right!=nullptr){
        Node* succ=curr->right;
        while(succ->left!=nullptr){
            succ=succ->left;
        }

        curr->card=succ->card;
        curr=succ;
    }

    Node* child=nullptr;
    if(curr->left!=nullptr){
        child=curr->left;

    }
    else{
        child=curr->right;
    }

    if(!curr->parent){
        root=child;

    }
    else if(curr->parent->left==curr){
        curr->parent->left=child;
    }
    else{
        curr->parent->right=child;
    }

    if(child){
        child->parent=curr->parent;
    }
    delete curr;
    return true;


}




bool CardBST::contains(const Card& c) const{
    Node* curr=root;

    while(curr){
        if(c==curr->card){
            return true;
        }
        if(c<curr->card){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }


    return false;

}


void CardBST::printInOrder() const{
    printInOrder(root);
}

void CardBST::printInOrder(Node* n) const{
    if(n==nullptr){
        return;
   }

   printInOrder(n->left);
   cout << n->card << " ";
   printInOrder(n->right);
}



CardBST::Iterator& CardBST::Iterator::operator++(){
   if(curr==nullptr){
    return *this;
   }

   if(curr->right!=nullptr){
    curr=curr->right;
  
        while(curr->left!=nullptr){
            curr=curr->left;
        }
   
   }
   else{
        Node* p=curr->parent;
        while(p != nullptr && curr==p->right){
    curr=p;
    p=p->parent;
   }
   curr=p;

   }


   return *this;


}


CardBST::Iterator& CardBST::Iterator::operator--(){
    if(curr==nullptr){
        return *this;
    }

    if(curr->left!=nullptr){
     curr=curr->left;
  
        while(curr->right!=nullptr){
            curr=curr->right;
        }
   
    }
    else{
        Node* p=curr->parent;
        while(p != nullptr && curr==p->left){
               curr=p;
               p=p->parent;
        }
     curr=p;

   }


   return *this;


}


CardBST::Iterator CardBST::begin() const{
    Node* n=root;
    if(n){
        while(n->left){
            n=n->left;
        }
        return Iterator(n);
    }
    return Iterator(n);
}

CardBST::Iterator CardBST::rbegin() const{
    Node* n=root;
    if(n){
        while(n->right){
            n=n->right;

        }

        return Iterator(n);
    }


    return Iterator(n);
}

CardBST::Iterator CardBST::end() const{
    return Iterator(nullptr);
}

CardBST::Iterator CardBST::rend() const{
    return Iterator(nullptr);
}


void playGame(CardBST& alice, CardBST& bob){


    
    bool matchFoundRound=true;
    while(matchFoundRound){
        matchFoundRound=false;

        bool aliceFound=false;
        Card matchAlice(' ',"");

        for(auto it=alice.begin();it!=alice.end() && !aliceFound;++it){
            if(bob.contains(*it)){
                matchAlice=*it;
                aliceFound=true;
                
        }
    }
  if(aliceFound){
    cout << "Alice picked matching card " << matchAlice << endl;
    alice.remove(matchAlice);
    bob.remove(matchAlice);
    matchFoundRound=true;
  }

  bool bobFound=false;
  Card matchBob(' ', "");
  for(auto it=bob.rbegin();it!=bob.rend() && !bobFound; ++it){
      if(alice.contains(*it)){
        matchBob=*it;
        bobFound=true;
       
      }
  }

  if(bobFound){
    cout << "Bob picked matching card " << matchBob << endl;
    alice.remove(matchBob);
    bob.remove(matchBob);
     matchFoundRound=true;
  }
 


}
}