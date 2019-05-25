/*
Nombre del archivo: MXSH-Pilas.cpp
Nombre del autor: Sandoval del Hoyo María Ximena
Fecha: 130319
Descripción: Programa de implementación de la clase pila con sus funciones básicas
*/

#include <iostream>
#include <cstdlib>

#define VACIO -9999
using namespace std;

struct caja{
    int valor;
    caja *siguiente;
};

class pila{
    caja *principio;
    int cuantos;

    public:

        /**
        *@brief Constructor de la clase pila; inicializa las variables
        *
        */
        pila();

        //-------------------------------------------------------------------------
        /**
        *@brief Destructor de la clase pila; deja las variables en nulo y 0
        *
        */
        ~pila();

        //-------------------------------------------------------------------------
        /**
        *@brief Función que agrega un nuevo elemento a la pila; lo agrega por el principio
        *
        *@param a: elemento a agregar
        */
        void agregar(int a);

        //-------------------------------------------------------------------------
        /**
        *@brief Función saca un elemento de la pila; lo saca por el principio
        *
        *@return elemento que se encontraba primero en la pila
        */
        int sacar();

          //-------------------------------------------------------------------------
        /**
        *@brief Función que pinta los elementos que se encuentren en la lista
        *
        */
        void pintar();

        //-------------------------------------------------------------------------
        /**
        *@brief Función que indica la longitud de la lista en el momento actual
        *
        *@return longitud de la lista
        */
        int longitud();

};

pila::pila(){
    principio = NULL;
    cuantos = 0;
}

void pila::agregar(int a){
   caja *p;
   p = new caja;
   p->valor = a;
   if (principio == NULL){
        p->siguiente = NULL;
        principio = p;
   } else {
        p->siguiente = principio;
        principio = p;
   }
   cuantos++;
   return;
}

int pila::sacar(){
    caja *p;
    int valor;
    if (principio == NULL){
        return VACIO;
    } else {
        p = principio;
        principio = p->siguiente;
    }
    valor = p->valor;
    delete p;
    cuantos--;
    return valor;
}

int pila::longitud(){
    return cuantos;
}

void pila::pintar(){
    caja *p;
    p = principio;
    while (p){
        cout << p->valor << "\t";
        p = p->siguiente;
    }
    cout << "\b\b" << endl;
}

pila::~pila(){
    caja *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    return;
}

int main()
{
    pila p;
    p.agregar(1);
    p.agregar(2);
    p.agregar(2);
    p.agregar(6);
    p.agregar(11);

    p.pintar();
    p.sacar();
    p.pintar();

    system("pause");
    return 0;
}
