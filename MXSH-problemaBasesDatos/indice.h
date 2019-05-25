#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include "pila.h"


using namespace std;

struct cajaIndice{
    cajaPila *direccion;
    cajaIndice *siguiente, *anterior;
};

class indice {
    cajaIndice *principio, *anterior, *ultimo;
    int cuantos;
    bool encontrado;

    enum {VACIO = 0, PRINCIPIO, ENMEDIO, FINAL};
    int donde;
public:
    /**
    *@brief Constructor de la clase indice; inicializa las variables
    *
    */
    indice();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Destructor de la clase indice; deja todas las variables en nulo y cero
    *
    */
    ~indice();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Copia del constructor de la clase indice; inicializa las variables
    *
    */
    void indiceConstructor();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Copia del destructor de la clase indice; deja todas las variables en nulo y cero
    *
    */
    void indiceDestructor();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que busca entre los elementos de un objeto tipo indice los datos
    *        almacenados en una struct de tipo cajaPila; esta función busca por nombre
    *
    *@param a: Puntero a cajaPila donde se están guardando los datos a buscar en el indice
    */
    void buscarI(cajaPila *a); // Buscar por nombre

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que busca entre los elementos de un objeto tipo indice los datos
    *        almacenados en una struct de tipo cajaPila; esta función busca por apellido
    *
    *@param a: Puntero a cajaPila donde se están guardando los datos a buscar en el indice
    */
    void buscarII(cajaPila *a); // Buscar por apellido

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que agrega un elemento de tipo cajaIndice a un indice; Se agrega por nombre
    *
    *@param a: Puntero a cajaPila donde se están guardando los datos a agregar en el indice
    */
    void agregarI(cajaPila *a);

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que agrega un elemento de tipo cajaIndice a un indice; Se agrega por apellido
    *
    *@param a: Puntero a cajaPila donde se están guardando los datos a agregar en el indice
    */
    void agregarII(cajaPila *a);

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que regresa la longitud del indice en el momento actual
    *
    *@return Longitud del índice
    */
    int longitud();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que pintar el indice, lo hace de menor a mayor
    */
    void imprimeIndice();


    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que pintar el indice, lo hace de mayor a menor
    */
    void imprimePorFinal();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que compara el contenido de dos cajaPilas, verificando si
    *       son iguales (nombre y apellido)
    *@return true si sus contenidos son los mismos; false de lo contrario
    *
    */
    bool esIgual(cajaPila *a, cajaPila *b);

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que compara el contenido de dos cajaPilas, verificando si
    *       la primera caja es menor que la segunda (nombre y apellido);
    *       toma como criterio primero el nombre
    *@return true si el contenido de la primera es menor que el de la segunda; false de lo contrario
    *
    */
    bool esMenorNombre(cajaPila *a, cajaPila *b);

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que compara el contenido de dos cajaPilas, verificando si
    *       la primera caja es menor que la segunda (nombre y apellido);
    *       toma como criterio primero el apellido
    *@return true si el contenido de la primera es menor que el de la segunda; false de lo contrario
    *
    */
    bool esMenorApellido(cajaPila *a, cajaPila *b);
};


#endif // INDICE_H_INCLUDED
