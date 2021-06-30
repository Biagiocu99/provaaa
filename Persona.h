#include<iostream>
#ifndef PERSONA_H
#define PERSONA_H



class Persona{
 public:
  int eta;
  std::string nome;
};


class Studente: public Persona{
public:
  int eta;
  std::string nome;
  Studente(int _eta, std::string _nome){
  	eta = _eta;
  	nome = _nome;
  }
  Studente(){};
   bool operator<(const Studente& stu){
    	return eta < stu.eta;
  }
    friend
  std::ostream& operator<<(std::ostream& out, const Studente& stu){
  out<<"nome:"<<stu.nome<<" eta':"<<stu.eta<<std::endl;
  return out;
}

};

class Lavoratore: public Persona{
public:
int eta;
std::string nome;
Lavoratore(){};
Lavoratore(int _eta, std::string _nome){
  	eta = _eta;
  	nome = _nome;
  }
      bool operator<(const Lavoratore& lav){
    	return eta < lav.eta;
  }
    friend
  std::ostream& operator<<(std::ostream& out, const Lavoratore& lav){
  out<<"nome:"<<lav.nome<<" eta':"<<lav.eta<<std::endl;
  return out;
}
};

class Pensionato: public Persona{
public:
  int eta;
  std::string nome;
  Pensionato(){};
  Pensionato(int _eta, std::string _nome){
  	eta = _eta;
  	nome = _nome;
  }
    bool operator<(const Pensionato& pens){
    	return eta < pens.eta;
  }
  friend
  std::ostream& operator<<(std::ostream& out, const Pensionato& pens){
  out<<"nome:"<<pens.nome<<" eta':"<<pens.eta<<std::endl;
  return out;
}


  
};
#endif // PERSONA_H

