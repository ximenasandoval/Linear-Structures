
#include "indice.h"

indice::indice(){
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    cuantos = 0;
    donde = VACIO;
}

void indice::indiceConstructor(){
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    cuantos = 0;
    donde = VACIO;
}

bool indice::esIgual(cajaPila *a, cajaPila *b){
    if (a->nombre == b->nombre && a->apellido == b->apellido){
        return true;
    }
    return false;
}

bool indice::esMenorNombre(cajaPila *a, cajaPila *b){
    if (a->nombre < b->nombre){
        return true;
    } else if (a->nombre == b->nombre && a->apellido < b->apellido){
        return true;
    }
    return false;
}

bool indice::esMenorApellido(cajaPila *a, cajaPila *b){
    if (a->apellido < b->apellido){
        return true;
    } else if (a->apellido == b->apellido && a->nombre< b->nombre){
        return true;
    }
    return false;
}



void indice::buscarI(cajaPila *a){
    cajaIndice *p;

    // Si la lista está vacia
    if (principio == NULL){
        donde = VACIO;
        return;
    }

    p = principio;
    while (p){
            if (esIgual(a, p->direccion)){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                return;
            } else if (esMenorNombre(a, p->direccion)){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                return;
            } else {
                anterior = p;
                p = p->siguiente;
            }
    }
    donde = FINAL;

}


void indice::buscarII(cajaPila *a){
    cajaIndice *p;

    // Si la lista está vacia
    if (principio == NULL){
        donde = VACIO;
        return;
    }

    p = principio;
    while (p){
            if (esIgual(a, p->direccion)){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                return;
            } else if (esMenorApellido(a, p->direccion)){
                if (p == principio){
                    donde = PRINCIPIO;
                } else {
                    donde = ENMEDIO;
                }
                return;
            } else {
                anterior = p;
                p = p->siguiente;
            }
    }
    donde = FINAL;
}



void indice::agregarI(cajaPila *a){
    cajaIndice *p;
    p = new cajaIndice;
    p->direccion = a;

    buscarI(a);
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
    return;

}



void indice::agregarII(cajaPila *a){
    cajaIndice *p;
    p = new cajaIndice;
    p->direccion = a;

    buscarII(a);
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
    return;
}


int indice::longitud(){
    return cuantos;
}

indice::~indice(){
    cajaIndice *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    cuantos = 0;
    donde = VACIO;

    return;
}

void indice::imprimeIndice(){
    cajaIndice *p;
    p = principio;
    while (p){
        cout << "( " << p->direccion->nombre << ", " << p->direccion->apellido << ") " << endl;
        p = p->siguiente;
    }
}

void indice::imprimePorFinal(){
    cajaIndice *p;
    p = ultimo;
    while (p){
        cout << "( " << p->direccion->nombre << ", " << p->direccion->apellido << ") " << endl;
        p = p->anterior;
    }
}

void indice::indiceDestructor(){
    cajaIndice *p;
    while (principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    cuantos = 0;
    donde = VACIO;

    return;
}

