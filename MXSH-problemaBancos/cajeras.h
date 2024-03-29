#ifndef CAJERAS_H_INCLUDED
#define CAJERAS_H_INCLUDED

struct cajera {
    bool ocupada;
    int horaDesocupadar;
    int clientesAtendidos;
};


/**
 *@brief Funci�n actualiza el estado de los elementos del arreglo cajeras, revisando si aun est�n atendiendo
 *          un cliente o ya est�n disponibles de nuevo
 *
 *@param c: Puntero de tipo cajera que se�ala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensi�n del arreglo o n�mero de cajeras en la simulaci�n
 *
 *@param horaInicial: Hora de inicio de las operaciones del banco (se proporciona en minutos)
 *
 *@param tiempoTranscurrido: Tiempo que ha pasado desde el inicio de las operaciones del banco
 *
 *
**/
void actualizarEstadoCajeras(cajera *c, int numCajeras, int horaInicial, int tiempoTranscurrido);

/**
 *@brief Funci�n que revisa si alguna cajera dentro de un arreglo est� disponible para atender el siguiente cliente
 *
 *@param c: Puntero de tipo cajera que se�ala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensi�n del arreglo o n�mero de cajeras en la simulaci�n
 *
 *@return N�mero de cajera en el arreglo que est� disponible y que potencialmente puede atender al siguiente cliente
 *
**/
int disponible(cajera *c, int numCajeras);

/**
 *@brief Funci�n que busca la cajera que se encuentre disponible y que tenga el menor n�mero de clientes atendidos
 *          para que �sta atienda al siguiente cliente en la cola
 *
 *@param c: Puntero de tipo cajera que se�ala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensi�n del arreglo o n�mero de cajeras en la simulaci�n
 *
 *@param potencial: Primera cajera que encontr� la funci�n disponible
 *
 *@return N�mero de cajera en el arreglo que est� disponible y que atender� al siguiente cliente
 *
 **/
int pasarCajera(cajera *c, int numCajeras, int potencial);

/**
 *@brief Funci�n pinta el arreglo de cajeras como cuadrados; si tienen un peque�o cuadrado en el centro, quiere decir
 *             que se encuentra atendiendo a un cliente
 *
 *@param c: Puntero de tipo cajera que se�ala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensi�n del arreglo o n�mero de cajeras en la simulaci�n
 *
 **/
void pintarCajeras(cajera *c, int numCajeras);


#endif // CAJERAS_H_INCLUDED
