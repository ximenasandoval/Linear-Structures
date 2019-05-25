/*
Nombre del archivo: MXSH-listaMitad.cpp
Nombre del autor: Sandoval del Hoyo María Ximena
Fecha: 010319
Descripción: Programa de implementación de la clase lista ordenada donde se guarda la mitad de ésta en
            en un apuntador mitad; esto permite menos comparaciones a la hora de buscar
*/

#include <iostream>
#include <cstdlib>


using namespace std;

struct caja{
    int valor;
    caja *siguiente, *anterior;
};

class listaMitad {
    caja *principio, *anterior, *ultimo, *mitad;
    int cuantos;
    bool encontrado;
    enum {VACIO = 0, PRINCIPIO, ENMEDIO, FINAL};
    int donde;
    int menores, mayores;

public:

    /**
    *@brief Constructor de la clase listaMitad; inicializa las variables
    *
    */
    listaMitad();

    //-------------------------------------------------------------------------
    /**
    *@brief Destructor de la clase listaMitad; deja las variables en nulo y en 0
    *
    */
    ~listaMitad();

    //-------------------------------------------------------------------------
    /**
    *@brief Función de busqueda de cierto elemento a dentro de los elementos ya existentes en
    *       la lista con mitad
    *@param a: elemento a buscar
    *
    *@return true si ya se encuentra en la lista; false de lo contrario
    */
    bool buscar(int a);

    //-------------------------------------------------------------------------
    /**
    *@brief Función de busqueda de cierto elemento a dentro de los elementos ya existentes en
    *       la lista con mitad; lo hace cuando anteriormente ya se comparó con el valor que
    *       está en la mitad de la lista
    *@param a: elemento a buscar
    *
    *@param empezar: puntero que señala donde se comenzará a buscar en la lista
    *
    *@return true si ya se encuentra en la lista; false de lo contrario
    */
    bool buscarCriterio(int a, caja *empezar);

    //-------------------------------------------------------------------------
    /**
    *@brief Función que agrega un elemento a la lista con mitad
    *
    *@param a: elemento a agregar
    *
    *@return true si se agregó a la lista; false de lo contrario
    */
    bool agregar(int a);

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

    //-------------------------------------------------------------------------
    /**
    *@brief Función que indica el valor que se encuentra en la mitad de la lista
    *
    *@return valor que está en la mitad de la lista
    */
    int mitadValor();
};

listaMitad::listaMitad(){
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    mitad = NULL;
    cuantos = 0;
    menores = 0;
    mayores = 0;

    donde = VACIO;

}

bool listaMitad::buscarCriterio(int a, caja *empezar){
    caja *p;
    p = empezar;
    anterior = p->anterior;
    while (p){
         if (p->valor == a){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                return true;
            } else if (a < p->valor){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                return false;
            } else {
                anterior = p;
                p = p->siguiente;
            }
    }

    if (p == NULL){
        donde = FINAL;
    } else {
        donde = ENMEDIO;
    }
    return false;
}

bool listaMitad::buscar(int a){
    caja *p;

    // Si la lista está vacia
    if (principio == NULL){
        donde = VACIO;
        return false;
    }
    if (a == mitad->valor){
        return true;
    }

    bool criterio;
    if (a < mitad->valor){
        criterio = buscarCriterio(a, principio);
        return criterio;
    }

    if (a > mitad->valor){
        criterio = buscarCriterio(a, mitad);
        return criterio;
    }
}



bool listaMitad::agregar(int a){
    if (buscar(a)){
        return false;
    }

    caja *p;
    p = new caja;
    p->valor = a;

    if (donde == VACIO){
        p->siguiente = NULL;
        p->anterior = NULL;
        principio = p;
        ultimo = p;
        mitad = p;
    }
    if (donde == PRINCIPIO){
        p->siguiente = principio;
        p->anterior = NULL;
        (p->siguiente)->anterior = p;
        principio = p;
    }

    if (donde == ENMEDIO){
        p->siguiente = anterior->siguiente;
        p->anterior = anterior;
        (p->siguiente)->anterior = p;
        anterior->siguiente = p;
    }

    if (donde == FINAL){
        p->siguiente = NULL;
        p->anterior = ultimo;
        ultimo = p;
        (p->anterior)->siguiente = p;;
    }
    cuantos++;

    if (p->valor < mitad->valor) menores++;
    if (p->valor > mitad->valor) mayores++;

    if (mayores > menores && mitad->siguiente != NULL){
        mitad = mitad->siguiente;
        mayores--;
        menores++;
    }

    if (menores > mayores + 1 && mitad->anterior != NULL) {
        mitad = mitad->anterior;
        mayores++;
        menores--;
    }
    return true;

}

int listaMitad::longitud(){
    return cuantos;
}

listaMitad::~listaMitad(){
    caja *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    mitad = NULL;
    cuantos = 0;
    donde = VACIO;

    return;
}

void listaMitad::pintar(){
    caja *p;
    p = principio;
    while (p){
        cout << p->valor << "\t";
        p = p->siguiente;
    }
    cout << endl << endl;
}

int listaMitad::mitadValor(){
    return mitad->valor;
}

int main()
{
    listaMitad a;
    a.agregar(1);
    a.agregar(4);
    a.agregar(2);
    a.agregar(3);
    a.agregar(-1);
    a.agregar(10);
    a.agregar(8);
    a.agregar(11);
    a.agregar(-10);
    a.agregar(2);
    a.pintar();


    system("pause");
    return 0;
}
