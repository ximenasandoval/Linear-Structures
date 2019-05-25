/*
Nombre del archivo: problemaBasesDatos.cbp
Nombre del autor: Sandoval del Hoyo María Ximena
Fecha: 270219
Descripción: Programa que simula el funcionamiento de una base de datos por medio de una clase llamada baseDatos;
            ésta a su vez tiene en sus miembros dos clases de tipo indice (lista ordenada), y de una pila
*/

#include <iostream>
#include "baseDatos.h"

using namespace std;

int main()
{
    baseDatos BD;
    BD.agregarBD(4, 2);
    BD.agregarBD(1, 3);
    BD.agregarBD(3, 2);
    BD.agregarBD(8, 2);
    BD.agregarBD(1, 3);
    BD.agregarBD(3, 7);
    BD.agregarBD(4, 10);

    BD.imprimirDatosI();
    cout << endl;
    BD.imprimirDatosII();
    cout << endl;
    BD.imprimirDatosIII();
    cout << endl;
    BD.imprimirDatosIV();
    cout << endl;


    return 0;
}
