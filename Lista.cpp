//
//  Lista.cpp
//  Progetto3
//
//  Created by Biagio Cubisino on 12/07/21.
//

#include "Lista.h"
#include <iostream>
#include <ostream>


using namespace std;

Lista::~Lista()    {
    Nodo* iter=this->testa;

    while(iter!=nullptr)    {
        Nodo* temp= iter->succ;
        delete iter;
        iter=temp;
    }
}

ostream& operator<<(ostream& out, const Lista& ls)
{
    Nodo* primo;


    for(primo=ls.testa; primo!=nullptr; primo = primo->succ)
        out << primo->valore << " - "<< endl;
    
    
    return out;

}


Nodo* Lista::ricerca(Studenti val){
    Nodo *p;

    for(p=this->testa;p!=nullptr;p = p->succ)
        if(p->valore==val)
            return p;

    return nullptr;
}

void Lista::inserisci(Studenti val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;

    Nodo* iter = this->testa;
    // Inserimento in testa
   
    if(this->testa == nullptr || this->testa->valore < val){
        nuovo->succ = this->testa;
        this->testa = nuovo;
    }
    else{
        while((iter->succ!=nullptr)&&(val < iter->succ->valore))
            iter = iter->succ;

        nuovo->succ = iter->succ;
        iter->succ = nuovo;
    }

}


Studenti Lista::rimuovi(Studenti val){

    Nodo* prec;
    Nodo* current;
    Studenti x;

    if(this->testa == nullptr)
        cout << "Lista vuota: impossibile rimuovere elementi."<<endl;
    else if(this->testa->valore == val){
        prec = this->testa;
        this->testa = this->testa->succ;
        delete prec;
    }
    else{
        prec = this->testa;
        current = this->testa->succ;
        while((current!=nullptr)&&(current->valore!= val)){
            prec = prec->succ;
            current = current->succ;
        }

        if(current!=nullptr){
            prec->succ = current->succ;
            x=current->valore;
            delete current;
            
        }
    

    }
    return x;
}
