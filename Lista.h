//
//  Lista.hpp
//  Progetto3
//
//  Created by Biagio Cubisino on 12/07/21.
//

#ifndef Lista_h
#define Lista_h

#include "Studenti.h"
#include <iostream>


using namespace std;

class Nodo{
public:
    Studenti valore;
    Nodo* succ;
    Nodo* prec;
};

class Lista{
private:
    Nodo* testa;
    
public:
    Lista(){testa=nullptr;}
    ~Lista();
    Nodo*getTesta() const {return this->testa;}
    void inserisci(Studenti val);
    Nodo* ricerca (Studenti val);
    Studenti rimuovi (Studenti val);
    
    
    
    friend
    ostream& operator<<(ostream& out,const Lista& ls);
};
#endif /* Lista_hpp */
