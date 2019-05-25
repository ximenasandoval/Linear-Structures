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
        *@brief Funci�n que agrega una estructura de tipo cliente a la cola; al igual que la convenci�n
        *       se agrega por el final
        *@param turno: N�mero de turno del cliente
        *
        *@param hLlegada: hora en qu� lleg� el cliente al banco
        *
        *@param tCajera: tiempo que va a ocupar un cliente al llegar con la cajera
        *
        *@param lCajera: hora en qu� lleg� el cliente a una cajera
        *
        *@param enCola: n�mero de personas que hab�a en la cola (incluyendo al cliente) en el momento que lleg� al banco
        */
        void agregar(int turno, int hLLegada, int tCajera, int lCajera, int enCola);

        //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que saca una estructura de tipo cliente a la cola; al igual que la convenci�n
        *       se saca por el inicio
        *@return puntero a estructura de tipo cliente; "devuelve toda la estructura" en lugar de s�lo un valor
        */
        cliente* sacar(); // Regresa toda la estructura cliente

        //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que pinta la cola de clientes en relaci�n del n�mero de cajeras "con el fin de centrarlo"
        *
        *@param numCajeras: N�mero de cajeras total atendiendo en el banco
        *
        */
        void pintar(int numCajeras);

         //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que regresa el tama�o de la cola
        *
        *@return longitud de la cola
        *
        */
        int longitud();
};


#endif // COLA_H_INCLUDED
