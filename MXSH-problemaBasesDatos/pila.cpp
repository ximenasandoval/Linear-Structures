#include "pila.h"


pila::pila(){
    principio = NULL;
    cuantos = 0;
}

void pila::pilaConstructor(){
    principio = NULL;
    cuantos = 0;
}

cajaPila* pila::lugarAgregado(){
    return agregado;
}


void pila::agregar(int a, int b){
   cajaPila *p;
   p = new cajaPila;
   p->nombre = a;
   p->apellido = b;
   agregado = p;
   if (principio == NULL){
        p->siguiente = NULL;
        principio = p;
   } else {
        p->siguiente = principio;
        principio = p;
   }
   cuantos++;
   return ;
}


int pila::longitud(){
    return cuantos;
}

void pila::pintar(){
    cajaPila *p;
    p = principio;
    while (p){
        cout << "(" << p->nombre << ", " << p->apellido << ")  \t";
        p = p->siguiente;
    }
    cout << "\b\b" << endl;
}

pila::~pila(){
    cajaPila *p;
    while (principio){
    p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = NULL;
    agregado = NULL;
    cuantos = 0;
    return;
}

void pila::pilaDestructor(){
    cajaPila *p;
    while (principio){
    p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = NULL;
    agregado = NULL;
    cuantos = 0;
    return;
}
