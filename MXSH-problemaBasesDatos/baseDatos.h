#ifndef BD_H_INCLUDED
#define BD_H_INCLUDED

#include "pila.h"
#include "indice.h"

class baseDatos{
    pila datos;
    indice porNombre;
    indice porApellido;
    int cuantos;

public:

    /**
    *@brief Constructor de la clase baseDatos; inicializa las variables
    *
    */
    baseDatos();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Destructor de la clase baseDatos; deja todas las variables en nulo y cero
    *
    */
    ~baseDatos();

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que agrega un registro en la clase de datos; para esto primero lo agrega en la
    *       pila y posteriormente a los índices de datos
    *@param a: campo de nombre a agregar
    *
    *@param b: campo de apellido a agregar
    *
    */
    void agregarBD(int a, int b);


    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que imprime los registros del indice que ordena por criterio de nombre;
    *       de menor a mayor.
    *
    */
    void imprimirDatosI(); // Por nombre, menor a mayor

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que imprime los registros del indice que ordena por criterio de apellido;
    *       de menor a mayor.
    *
    */
    void imprimirDatosII(); // Por apellido, menor a mayor

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que imprime los registros del indice que ordena por criterio de nombre;
    *       de mayor a menor.
    *
    */
    void imprimirDatosIII(); // Por nombre, mayor a menor

    //--------------------------------------------------------------------------------------
    /**
    *@brief Función que imprime los registros del indice que ordena por criterio de apellido;
    *       de mayor a menor.
    *
    */
    void imprimirDatosIV(); // Por apellido, mayor a menor

};



#endif // BD_H_INCLUDED
