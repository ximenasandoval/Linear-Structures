#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>
#include <cstdlib>

#define VACIOPILA -9999

using namespace std;

struct cajaPila{
    int nombre, apellido;
    cajaPila *siguiente;
};

class pila{
    cajaPila *principio, *agregado;
    int cuantos;

    public:

        /**
        *@brief Constructor de la clase pila; inicializa las variables
        *
        */
        pila();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Copia del constructor de la clase pila; inicializa las variables de la clase
        *
        */
        void pilaConstructor();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Destructor de la clase pila; deja todas las variables en nulo y cero
        *
        */
        ~pila();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Copia del destructor de la clase pila; deja todas las variables en nulo y cero
        *
        */
        void pilaDestructor();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que agrega un registro en la pila; Al igual que la convenci�n, lo agrega por el principio
        *
        *@param a: campo de nombre a agregar
        *
        *@param b: campo de apellido a agregar
        *
        */
        void agregar(int a, int b);

         //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que pinta los valores contenidos en la pila
        *
        */
        void pintar();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que indica el tama�o de la pila
        *
        *@return Longitud de la pila en el momento actual
        */
        int longitud();

        //--------------------------------------------------------------------------------------
        /**
        *@brief Funci�n que indica la direcci�n en memoria del �ltimo elemento agregado
        *
        *@return direcci�n del �ltimo elemento agregado
        */
        cajaPila* lugarAgregado();

};

#endif // PILA_H_INCLUDED

