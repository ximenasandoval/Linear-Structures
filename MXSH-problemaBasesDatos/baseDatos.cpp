
#include <iostream>
#include <cstdlib>
#include "baseDatos.h"

using namespace std;


baseDatos::baseDatos(){
    datos.pilaConstructor();
    porNombre.indiceConstructor();
    porApellido.indiceConstructor();
    cuantos = 0;
}

void baseDatos::agregarBD(int a, int b){
    datos.agregar(a, b);
    cajaPila *agregado = datos.lugarAgregado();

    porNombre.agregarI(agregado);
    porApellido.agregarII(agregado);


}

void baseDatos::imprimirDatosI(){
    porNombre.imprimeIndice();
}

void baseDatos::imprimirDatosII(){
    porApellido.imprimeIndice();
}

void baseDatos::imprimirDatosIII(){
    porNombre.imprimePorFinal();
}

void baseDatos::imprimirDatosIV(){
    porApellido.imprimePorFinal();
}


baseDatos::~baseDatos(){
    datos.pilaDestructor();
    porNombre.indiceDestructor();
    porApellido.indiceDestructor();
    cuantos = 0;
}

