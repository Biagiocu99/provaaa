//
//  main.cpp
//  Progetto3
//
//  Created by Biagio Cubisino on 12/07/21.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lista.h"
#include "Pila.h"

using namespace std;

void StudentiFile(const string& str, string cont[5])
{
    char delim = ';';
    stringstream ss(str);
    string token;
    int i = 0;
    while (getline(ss, token, delim)) {
        cont[i] = token;
        i++;
        if(i==5) break;
    }
}

 int punto1(const string filename, Lista& ls)
{
    ifstream file;
    string line;
    string buff[5];
Studenti ss;
    file.open(filename);
    int num = 0;
    if(file.is_open())
    {
        while(getline(file, line)){
            StudentiFile(line,buff);
            ss = Studenti(buff[0],buff[1],buff[2],buff[3],stof(buff[4]));
            ls.inserisci(ss);
            num++;
                                }

        file.close();
    }
    else
        cout << "Non posso aprire il file!" << endl;
    return num;
}
/*
Nodo* tmp = top;
int val = top->valore;
top = top->succ;
delete tmp;
return val;
*/

void printLista(Lista&ls){
    
Nodo* iter=ls.getTesta();
    cout<<"GRUPPO A: "<<endl;
while(iter->valore.getMedia()>=24){
    
     cout << iter->valore << " --> ";
    iter = iter->succ;
   
    
    
}
   

}

int punto2(const string filename, Stack& st)
{
    
   ifstream file;
   string line;
   string buff[5];
Studenti ss;
   file.open(filename);
   int num = 0;
   if(file.is_open())
   {
       while(getline(file, line)){
           StudentiFile(line,buff);
           ss = Studenti(buff[0],buff[1],buff[2],buff[3],stof(buff[4]));
           st.push(ss);
           if(stof(buff[4])<24)
           num++;
           
           
                               }
       

       file.close();
       
   }
   
    
   else
       cout << "Non posso aprire il file!" << endl;
    return num;
}

void gruppi(Lista& ls,Stack& st,int n){
    Nodo*iter=ls.getTesta();
    Lista sparsi;
    int x=1;
    int cont=0;
    n=punto2("Studenti.txt",st);
  
    Studenti a;
   Studenti b1;
Studenti b2;
  
    //Node* p=st.getTop();
    //for(p=st.getTop();p==nullptr;p=p->succ){
    
    for(int i=0;i<n;i++){
        b1=st.pop();
        b2=st.pop();
    
        if(b1.getMedia()+b2.getMedia()>=40){
            cout<<"GRUPPO : "<<x<<":"<<endl;
            cout<<"("<<b1.getMatricola()<<")\t"<<b1.getCognome()<<"\t"<<b1.getNome()<<"\tCittà:"<<b1.getCittà()<<"\tMedia:"<<b1.getMedia()<<endl;
            cout<<endl;
            cout<<"("<<b2.getMatricola()<<")\t"<<b2.getCognome()<<"\t"<<b2.getNome()<<"\tCittà:"<<b2.getCittà()<<"\tMedia:"<<b2.getMedia()<<endl;
            x++;
            cout<<endl;
            cout<<"La media dei voti totali è: "<<(b1.getMedia()+b2.getMedia())/2<<endl;
           
            
            
        }
        else{
            cout<<"GRUPPO  "<<x<<":"<<endl;
            
            cout<<"("<<b1.getMatricola()<<")\t"<<b1.getCognome()<<"\t"<<b1.getNome()<<"\tCittà: "<<b1.getCittà()<<"\tMedia:"<<b1.getMedia()<<endl;
            
            cout<<endl;
            
            cout<<"("<<b2.getMatricola()<<")\t"<<b2.getCognome()<<"\t"<<b2.getNome()<<"\tCittà:"<<b2.getCittà()<<"\tMedia:"<<b2.getMedia()<<endl;
            
            cout<<endl;
            
            cout<<iter->valore<<endl;
            
            cout<<"La media dei voti totali è: "<<(b1.getMedia()+b2.getMedia()+iter->valore.getMedia())/3<<endl;
            x++;
        
            
            cont++;
            iter=iter->succ;
           
          
        }
        
   
    }
    /*
    while(iter!=nullptr){
       cout<<"GRUPPO "<<x<<": "<<endl;
        cout<<iter->valore<<endl;
        cout<<iter->succ->valore<<endl;
        iter=iter->succ;
        x++;
        
    }
   */
    }
 
   

    
        
    
     
   
    
        
    
  



int main()
    {
        
    int stampafile;
        Lista Gruppi;
    Lista listaStudente;
    // Nodo* x=listaStudente.getTesta();
    Stack Pila;
    Studenti ss;
        Studenti a,b1,b2;
    int stampafile2;
      
   
    stampafile = punto1("Studenti.txt", listaStudente);
    
    
    cout<<"---------------CARICO FILE ORDINI-----------------"<<endl;
    
    
    cout << endl <<"----------------PRIMO PUNTO--------------------" << endl;
    cout << endl <<"-----------------------------------------------" << endl;
    cout << listaStudente;
    
    
    
    cout << endl <<"----------------SECONDO PUNTO--------------------" << endl;
    cout << endl <<"-----------------------------------------------" << endl;
    
    printLista(listaStudente);
    
    cout<<endl;
    cout<<"GRUPPO B: "<<endl;
    stampafile2=punto2("Studenti.txt", Pila);
    cout<<Pila;
    
    
    cout<<endl;
    cout<<endl;
        cout<<endl;
        cout<<endl;
        
        cout << endl <<"------------------TERZO PUNTO--------------------" << endl;
        cout << endl <<"--------------------------------------------------" << endl;
        
        cout << endl <<"------------------E QUARTO PUNTO--------------------" << endl;
        cout << endl <<"--------------------------------------------------" << endl;
        
       
        gruppi(listaStudente,Pila,punto2("Studenti.txt", Pila));
        
        
        cout<<endl;
        
    
       
        
        /*
        while(cont!=punto2("Studenti.txt", Pila)){
            cont++;
            for(int i=0;i<2;i++){
                Studenti primo=Pila.pop();
                Studenti secondo=Pila.pop();
                if((primo.getMedia()+secondo.getMedia())>=40){
                    Gruppi.inserisci(primo);
                    Gruppi.inserisci(secondo);
                    cout<<"GRUPPO 1: "<<endl;
                    cout<<Gruppi<<endl;
                }
                else{
                    Gruppi.inserisci(primo);
                    Gruppi.inserisci(secondo);
                    Gruppi.inserisci(listaStudente.rimuovi(x));
                    cout<<"GRUPPO 1: "<<endl;
                    cout<<Gruppi<<endl;
                }
               
            }
            */
        }
        
     
       
        

    
        
     
    

   

    

