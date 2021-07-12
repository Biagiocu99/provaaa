//
//  Studenti.cpp
//  Progetto3
//
//  Created by Biagio Cubisino on 12/07/21.
//

#include "Studenti.h"

#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& out,const Studenti& ss){
    out<<"("<<ss.matricola<<")\t"<<ss.cognome<<"\t "<<ss.nome<<"\t Città: "<<ss.città<<"\t media:"<<ss.media_voti<<endl;
    return out;
}

string Studenti::getCognome()const{return cognome;}
string Studenti::getMatricola()const{return matricola;}
//void Studenti::setCognome(string cogn){cognome=cogn;}
string Studenti::getNome()const{return nome;}
string Studenti::getCittà()const{return città;}
float Studenti::getMedia()const{return media_voti;}


Studenti::Studenti(){};
Studenti:: Studenti(string _matricola,string _cognome,string _nome, string _città, float _media_voti):matricola(_matricola),cognome(_cognome),nome(_nome),città(_città),media_voti(_media_voti){}

bool Studenti::operator>(const Studenti& ss)const{
    return media_voti>ss.getMedia();
}

bool Studenti::operator==(const Studenti& ss)const{
    return media_voti==ss.getMedia();
}

bool Studenti::operator!=(const Studenti& ss)const{
    return media_voti!=ss.getMedia();
}


bool Studenti::operator<( const Studenti& ss)const{
    return media_voti<ss.getMedia();
}


