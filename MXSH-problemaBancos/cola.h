#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include "auxiliares.h"


using namespace std;

struct cliente {
    cliente *siguiente;
    int turno;
    int horaLlegada, tiempoCajera, llegadaCajera, enCola;
};

class cola {
    cliente *principio, *ultimo;
    int cuantos;

    public:
        /**
        *@brief Constructor de la clase cola; inicializa las variables
        *
        */
        cola();

        //--------------------------------------------------------------------------------------
         /**
        *@brief Destructor de la clase cola; deja todas las variables en nulo y cero
        *
        */
        ~cola();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Función que agrega una estructura de tipo cliente a la cola; al igual que la convención
        *       se agrega por el final
        *@param turno: Número de turno del cliente
        *
        *@param hLlegada: hora en qué llegó el cliente al banco
        *
        *@param tCajera: tiempo que va a ocupar un cliente al llegar con la cajera
        *
        *@param lCajera: hora en qué llegó el cliente a una cajera
        *
        *@param enCola: número de personas que había en la cola (incluyendo al cliente) en el momento que llegó al banco
        */
        void agregar(int turno, int hLLegada, int tCajera, int lCajera, int enCola);

        //--------------------------------------------------------------------------------------
        /**
        *@brief Función que saca una estructura de tipo cliente a la cola; al igual que la convención
        *       se saca por el inicio
        *@return puntero a estructura de tipo cliente; "devuelve toda la estructura" en lugar de sólo un valor
        */
        cliente* sacar(); // Regresa toda la estructura cliente

        //--------------------------------------------------------------------------------------
        /**
        *@brief Función que pinta la cola de clientes en relación del número de cajeras "con el fin de centrarlo"
        *
        *@param numCajeras: Número de cajeras total atendiendo en el banco
        *
        */
        void pintar(int numCajeras);

         //--------------------------------------------------------------------------------------
        /**
        *@brief Función que regresa el tamaño de la cola
        *
        *@return longitud de la cola
        *
        */
        int longitud();
};


#endif // COLA_H_INCLUDED
