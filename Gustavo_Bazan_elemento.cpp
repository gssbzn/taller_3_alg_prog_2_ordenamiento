#ifndef __GUSTAVO_BAZAN_ELEMENTO_CPP__
#define __GUSTAVO_BAZAN_ELEMENTO_CPP__
#include "Gustavo_Bazan_lib.h"
/************************************elemento**********************************/
//constructor por defecto
elemento :: elemento(){
    e=0;
}

// constructor general
elemento :: elemento(int ele){
    e = ele;
}
// constructor de copia
elemento :: elemento(const elemento& c){
    e = c.e;
}

void elemento :: set_elemento(int elem){
    e=elem;
    return;
}

void elemento :: set_elemento(elemento elem){
    e=elem.get_elemento();
    return;
}

int elemento :: get_elemento(){
    return(e);
}

// operador miembro de asignación sobrecargado
elemento& elemento :: operator= (const elemento &a){
    e = a.e;
    return (*this);
}

int operator< (const elemento &a, const elemento &b){
    if (a.e<b.e) return 1;
    else return 0;
}

int operator> (const elemento &a, const elemento &b){
    if (a.e>b.e) return 1;
    else return 0;
}

// operador friend de test de igualdad sobrecargado
int operator== (const elemento &a, const elemento &b){
    if (a.e==b.e) return 1;
    else return 0;
}

int operator== (const elemento &a, const int &b){
    if (a.e==b) return 1;
    else return 0;
}

// operador friend de test de desigualdad sobrecargado
int operator!= (const elemento& a, const elemento& b){
    if (a.e!=b.e) return 1;
    else return 0;
}

int operator!= (const elemento& a, const int& b){
    if (a.e!=b) return 1;
    else return 0;
}

// operador friend << sobrecargado
ostream& operator << (ostream& co, const elemento &elem){
    co << elem.e;
    return co;
}

// operador friend >> sobrecargado
istream& operator >> (istream& ci, elemento &elem){
    ci >> elem.e;
    return ci;
}
   
#endif
