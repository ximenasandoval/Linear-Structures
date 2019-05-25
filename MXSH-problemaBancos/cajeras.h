#ifndef CAJERAS_H_INCLUDED
#define CAJERAS_H_INCLUDED

struct cajera {
    bool ocupada;
    int horaDesocupadar;
    int clientesAtendidos;
};


/**
 *@brief Función actualiza el estado de los elementos del arreglo cajeras, revisando si aun están atendiendo
 *          un cliente o ya están disponibles de nuevo
 *
 *@param c: Puntero de tipo cajera que señala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensión del arreglo o número de cajeras en la simulación
 *
 *@param horaInicial: Hora de inicio de las operaciones del banco (se proporciona en minutos)
 *
 *@param tiempoTranscurrido: Tiempo que ha pasado desde el inicio de las operaciones del banco
 *
 *
**/
void actualizarEstadoCajeras(cajera *c, int numCajeras, int horaInicial, int tiempoTranscurrido);

/**
 *@brief Función que revisa si alguna cajera dentro de un arreglo está disponible para atender el siguiente cliente
 *
 *@param c: Puntero de tipo cajera que señala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensión del arreglo o número de cajeras en la simulación
 *
 *@return Número de cajera en el arreglo que está disponible y que potencialmente puede atender al siguiente cliente
 *
**/
int disponible(cajera *c, int numCajeras);

/**
 *@brief Función que busca la cajera que se encuentre disponible y que tenga el menor número de clientes atendidos
 *          para que ésta atienda al siguiente cliente en la cola
 *
 *@param c: Puntero de tipo cajera que señala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensión del arreglo o número de cajeras en la simulación
 *
 *@param potencial: Primera cajera que encontró la función disponible
 *
 *@return Número de cajera en el arreglo que está disponible y que atenderá al siguiente cliente
 *
 **/
int pasarCajera(cajera *c, int numCajeras, int potencial);

/**
 *@brief Función pinta el arreglo de cajeras como cuadrados; si tienen un pequeño cuadrado en el centro, quiere decir
 *             que se encuentra atendiendo a un cliente
 *
 *@param c: Puntero de tipo cajera que señala donde inicia el arreglo cajeras
 *
 *@param numCajeras: Dimensión del arreglo o número de cajeras en la simulación
 *
 **/
void pintarCajeras(cajera *c, int numCajeras);


#endif // CAJERAS_H_INCLUDED
