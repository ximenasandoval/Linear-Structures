/*
Nombre del archivo: MXSH-listaDoble.cpp
Nombre del autor: Sandoval del Hoyo María Ximena
Fecha: 010319
Descripción: Programa de implementación de la clase lista doblemente ligada, con sus funciones básicas
*/

#include <iostream>
#include <cstdlib>


using namespace std;
struct caja{
    int valor;
    caja *siguiente, *anterior;
};

class listaDoble {
    int cuantos;
    caja *principio, *anterior, *ultimo;
    enum {VACIO, PRINCIPIO, ENMEDIO, FINAL};
    int donde;
    bool encontrado;

public:

    /**
    *@brief Constructor de la clase listaDoble; inicializa las variables
    *
    */
    listaDoble();

    //-------------------------------------------------------------------------
    /**
    *@brief Destructor de la clase listaDoble; deja las variables en nulo y en 0
    *
    */
    ~listaDoble();

    //-------------------------------------------------------------------------
    /**
    *@brief Función de busqueda de cierto elemento a dentro de los elementos ya existentes en
    *       la lista doble
    *@param a: elemento a buscar
    *
    *@return true si ya se encuentra en la lista; false de lo contrario
    */
    bool buscar(int a);

    //-------------------------------------------------------------------------
    /**
    *@brief Función que agrega un elemento a la lista doble
    *
    *@param a: elemento a agregar
    *
    *@return true si se agregó a la lista; false de lo contrario
    */
    bool agregar(int a);

    //-------------------------------------------------------------------------
    /**
    *@brief Función que borra un elemento a la lista doble
    *
    *@param a: elemento a borrar
    *
    *@return true si se borró de la lista; false de lo contrario
    */
    bool borrar(int a);

    //-------------------------------------------------------------------------
    /**
    *@brief Función que indica la longitud de la lista en el momento actual
    *
    *@return longitud de la lista
    */
    int longitud();

    //-------------------------------------------------------------------------
    /**
    *@brief Función que pinta los elementos que se encuentren en la lista
    *
    */
    void pintar();

    //-------------------------------------------------------------------------
    /**
    *@brief Función que pinta los elementos que se encuentren en la lista;
    *       lo hace comenzando por el final
    *
    */
    void pintarPorFinal();

};

listaDoble::listaDoble(){
    cuantos = 0;
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    donde = VACIO;
}

bool listaDoble::buscar(int a){
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

bool listaDoble::agregar(int a){
    if (buscar(a)){
        // No se agregó a la lista
        return false;
    }
    caja *p;
    p = new caja;
    p->valor = a;

    if (buscar(a)){
        // No se agregó a la lista
        return false;
    }
    if (donde == VACIO){
        p->siguiente = NULL;
        p->anterior = NULL;
        principio = p;
        ultimo = p;
    } else if (donde == PRINCIPIO){
        p->siguiente = principio;
        p->anterior = NULL;
        (p->siguiente)->anterior = p;
        principio = p;
    } else if (donde == ENMEDIO){
        p->siguiente = anterior->siguiente;
        p->anterior = anterior;
        (p->siguiente)->anterior = p;
        anterior->siguiente = p;
    } else {
        p->siguiente = NULL;
        p->anterior = ultimo;
        ultimo = p;
        (p->anterior)->siguiente = p;;
    }
    cuantos++;
    return true;

}

void listaDoble::pintar(){
    caja *p;
    p = principio;
    while (p){
        cout << p->valor << "\t";
        p = p->siguiente;
    }
    cout << endl;
}

void listaDoble::pintarPorFinal(){
    caja *p;
    p = ultimo;
    while (p){
        cout << p->valor << "\t";
        p = p->anterior;
    }
    cout << endl;
}

listaDoble::~listaDoble(){
   caja *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    cuantos = 0;
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    donde = VACIO;
}
int main()
{

    listaDoble p;
    p.agregar(1);
    p.agregar(2);
    p.agregar(-1);
    p.agregar(10);
    p.agregar(8);

    p.pintar();
    p.pintarPorFinal();


    system("pause");
    return 0;
}
