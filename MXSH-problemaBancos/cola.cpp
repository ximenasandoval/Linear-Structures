
#include "auxiliares.h"
#include "cola.h"



using namespace std;

cola::cola(){
    principio = NULL;
    ultimo = NULL;
    cuantos = 0;
}

void cola::agregar(int turno, int hLLegada, int tCajera, int lCajera, int eCola){
   cliente *p;
   p = new cliente;
   p->turno = turno;
   p->horaLlegada = hLLegada;
   p->tiempoCajera = tCajera;
   p->llegadaCajera = lCajera;
   p->enCola = eCola;


   // Si no es el primero
   if (principio != NULL){
        p->siguiente = NULL;
        ultimo->siguiente = p;
        ultimo = p;

   } else {
    // Si es el primero
        p->siguiente = NULL;
        principio = p;
        ultimo = p;
   }
   cuantos++;
   return;
}

cliente* cola::sacar(){
    cliente *p;
    if (principio == NULL){
        return NULL;
    } else {
        p = principio;
        principio = p->siguiente;
    }
    cuantos--;
    if (principio == NULL){
        ultimo == NULL;
    }
    return p;
}

int cola::longitud(){
    return cuantos;
}

void cola::pintar(int numCajeras){
    cliente *p;
    p = principio;
    gotoxy(20, 5 + (numCajeras* 5) / 2);
    while (p){
        cout << p->turno << "\t";
        p = p->siguiente;
    }
    cout << endl;
}

cola::~cola(){
    cliente *p;
    p = principio;
    while (p){
        principio = p->siguiente;
        delete p;
    }
    return;
}
