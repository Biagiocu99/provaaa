//
//  Pila.hpp
//  Project3
//
//  Created by Biagio Cubisino on 12/07/21.
//

#ifndef Pila_h
#define Pila_h
#include <iostream>
#include <stdio.h>
#include "Studenti.h"
#include "studenti.h"
using namespace std;

class Node{
public:
    Studenti valore;
    Node *succ;
};


class Stack{
    Node* top;
public:
    Stack();
    ~Stack();
    int push(Studenti&);
    Node* getTop()const {return this->top;}
   
    Studenti pop();
    void pop2();
    
    friend
    ostream& operator<<(ostream& out, const Stack& s);
};
ostream& operator<<(ostream& out, const Stack& s){
    Node *iter = s.top;
    while(iter!=nullptr){
        out << iter->valore << endl;
        iter = iter->succ;
    }
    return out;
}

Stack::Stack() {top = nullptr;}
Stack::~Stack(){
    while(top!=nullptr){
        Node* tmp = top;
        top = top->succ;
        delete tmp;
    }
}

int Stack::push(Studenti& n){
    Node *ptr = new Node;
    int cont=0;
    ptr->succ = top;
    ptr->valore = n;
    if(ptr->valore.getMedia()<24){
        cont++;
        top= ptr;
        
    }
    return cont;
 
  
}

Studenti Stack::pop(){
    Node* tmp = top;
    Studenti val = top->valore;
    top = top->succ;
    delete tmp;
    
    return val;
}

void Stack::pop2(){
    Node* tmp = top;
  
    top = top->succ;
    delete tmp;
    
   
}




#endif /* Pila_hpp */
