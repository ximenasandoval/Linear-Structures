/*
 Nombre: listaOrdenada.cpp
 Autor: Sandoval del Hoyo María Ximena
 Fecha: 010319
 Descripción: Programa de implementación de la clase lista ordenada, en la cual permite repeticiones,
                agregar una struct caja siempre que se vaya a agregar
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct caja{
    int valor;
    caja *siguiente;
};

class listaOrdenadaPRepeticiones {
    caja *principio, *anterior;
    int cuantos;
    bool encontrado;

    enum {VACIO = 0, PRINCIPIO, ENMEDIO, FINAL};
    int donde;

public:

    /**
    *@brief Constructor de la clase listaOrdenadaPRepeticiones; inicializa las variables
    *
    */
    listaOrdenadaPRepeticiones();

    //-------------------------------------------------------------------------
    /**
    *@brief Destructor de la clase listaOrdenadaPRepeticiones; deja las variables en nulo y en 0
    *
    */
    ~listaOrdenadaPRepeticiones();

    //-------------------------------------------------------------------------
    /**
    *@brief Función que agrega un elemento a la lista
    *
    *@param a: elemento a agregar
    *
    *@return true si se agregó a la lista; false de lo contrario
    */
    bool agregar(int a);

    //-------------------------------------------------------------------------
    /**
    *@brief Función de busqueda de cierto elemento a dentro de los elementos ya existentes en
    *       la lista
    *@param a: elemento a buscar
    *
    *@return true si ya se encuentra en la lista; false de lo contrario
    */
    bool buscar(int a);

    //-------------------------------------------------------------------------
    /**
    *@brief Función que borra un elemento a la lista
    *
    *@param a: elemento a borrar
    *
    *@return true si se borró de la lista; false de lo contrario
    */
    bool borrar(int a);
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

listaOrdenadaPRepeticiones::listaOrdenadaPRepeticiones(){
    principio = NULL;
    anterior = NULL;
    cuantos = 0;
    encontrado = false;
    donde = VACIO;
}

bool listaOrdenadaPRepeticiones::buscar(int a){
    caja *p;

    // Si la lista está vacia
    if (principio == NULL){
        encontrado = false;
        donde = VACIO;
        return false;
    }

    p = principio;
    while (p){
         if (p->valor == a){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                encontrado = true;
                return true;
            } else if (a < p->valor){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                encontrado = false;
                return false;
            } else {
                encontrado = false;
                anterior = p;
                p = p->siguiente;
            }
    }

    donde = FINAL;
    encontrado = false;
    return false;
}

bool listaOrdenadaPRepeticiones::agregar(int a){
    caja *p;
    buscar(a);

    p = new caja;
    p->valor = a;
    if (donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    } else if (donde == PRINCIPIO){
        p->siguiente = principio;
        principio = p;
    } else if (donde == FINAL){
        p->siguiente = NULL;
        anterior->siguiente = p;
    } else {
        p->siguiente = anterior->siguiente;
        anterior->siguiente = p;
    }
    cuantos++;
    return true;
}

bool listaOrdenadaPRepeticiones::borrar(int a){
    caja *p;
    buscar(a);

    // No se puede borrar porque no está en la lista
    if (!encontrado){
        return false;
    }
    p = anterior->siguiente;

    if (donde == PRINCIPIO){
        p = principio;
        principio = p->siguiente;
    } else if (donde == ENMEDIO){
        p = anterior->siguiente;
        anterior->siguiente = p->siguiente;
    } else {
        p = anterior->siguiente;
        anterior->siguiente = NULL;
    }
    delete p;
    return true;
}

int listaOrdenadaPRepeticiones::longitud(){
    return cuantos;
}

void listaOrdenadaPRepeticiones::pintar(){
    caja *p;
    p = principio;
    while (p){
        cout << p->valor << "\t";
        p = p->siguiente;
    }
    cout << endl;
}

listaOrdenadaPRepeticiones::~listaOrdenadaPRepeticiones(){
    caja *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    anterior = NULL;
    cuantos = 0;
    encontrado = false;
    donde = VACIO;
    return;
}


int main()
{

    listaOrdenadaPRepeticiones lista;
    lista.agregar(2);
    lista.agregar(5);
    lista.agregar(7);
    lista.agregar(-1);
    lista.agregar(1);
    lista.agregar(2);
    lista.pintar();


	system("pause");
	return 0;
}
