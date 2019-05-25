/*
Nombre del archivo: MXSH-Colas.cpp
Nombre del autor: Sandoval del Hoyo María Ximena
Fecha: 130219
Descripción: Programa de implementación de la clase cola con sus funciones básicas
*/

#include <iostream>
#include <cstdlib>

#define VACIO -9999
using namespace std;

struct caja{
    int valor;
    caja *siguiente;
};

class cola {
    caja *principio, *ultimo;
    int cuantos;

    public:

        /**
        *@brief Constructor de la clase cola; inicializa las variables
        *
        */
        cola();

        //-------------------------------------------------------------------------
        /**
        *@brief Destructor de la clase cola; deja las variables en nulo y en 0
        *
        */
        ~cola();

        //-------------------------------------------------------------------------
        /**
        *@brief Función que agrega un elemento a la cola; lo agrega por el final
        *       al igual que la convención
        *
        *@param a: Elemento a agregar a la cola
        */
        void agregar(int a);

        //-------------------------------------------------------------------------
        /**
        *@brief Función que saca un elemento a la cola; lo saca por el principio
        *       al igual que la convención
        *
        *@return primer elemento en la cola
        */
        int sacar();

         //-------------------------------------------------------------------------
        /**
        *@brief Función que pinta los elementos que se encuentren en la cola
        *
        */
        void pintar();

        //-------------------------------------------------------------------------
        /**
        *@brief Función que indice la longitud de la cola en el momento actual
        *
        *@return longitud de la cola
        */
        int longitud();
};


cola::cola(){
    principio = NULL;
    ultimo = NULL;
    cuantos = 0;
}

void cola::agregar(int a){
   caja *p;
   p = new caja;
   p->valor = a;
   if (principio == NULL){
        p->siguiente = NULL;
        principio = p;
        ultimo = p;
   } else {
        p->siguiente = NULL;
        ultimo->siguiente = p;
        ultimo = p;
   }
   cuantos++;
   return;
}

int cola::sacar(){
    caja *p;
    int valor;
    if (principio == NULL){
        return VACIO;
    } else {
        p = principio;
        principio = p->siguiente;
        valor = p->valor;
        delete p;
    }
    cuantos--;
    if (principio == NULL){
        ultimo == NULL;
    }
    return valor;
}

int cola::longitud(){
    return cuantos;
}

void cola::pintar(){
    caja *p;
    p = principio;
    while (p){
        cout << p->valor << "\t";
        p = p->siguiente;
    }
    cout << endl;
}

cola::~cola(){
    caja *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    ultimo = NULL;
    cuantos = 0;
    return;
}

int main()
{
    cola c;
    c.agregar(1);
    c.agregar(2);
    c.agregar(3);
    c.agregar(4);
    c.agregar(5);
    c.agregar(6);
    c.agregar(1);
    c.pintar();

    c.sacar();
    c.sacar();
    c.sacar();
    c.pintar();

    system("pause");
    return 0;
}
