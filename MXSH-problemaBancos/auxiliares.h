#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED

#include <iostream>

#include <limits>
#include <windows.h>


/**
 *@brief Función de captura para un número de cualquier tipo; Se utiliza una plantilla para esto.
 *
 *@param &num: Referencia a la variable que se va a capturar con la plantilla de la función
 *
 *@param solicitud: Cadena de caracteres que se presentará para solicitar la captura del número
 *
**/

template <typename tipo> void CapturaNumero(tipo &num, const char solicitud[]){
    while (true){
        std::cout << solicitud;
        std::cin>> num;

        if(std::cin.bad()){
            std::cout << "Ocurri\xA2 un error irrecuperable" << std::endl;
            std::cout << "El programa terminar\xA0" << std::endl;
            system("pause");
            exit(1);
        }
        if (std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            return;
        }
        if (std::cin.fail()){
            std::cout << "\nTipo de datos inv\xA0lido"<< std::endl;
            std::cout << "Debe ser un n\xA3mero" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        }
    }
}

//--------------------------------------------------------------------------------------
/**
 *@brief Función que imprime el tiempo en formato de hora:minuto.
 *
 *@param horaInicial: Hora desde la que empezó el tiempo de operación
 *              del banco (se debe proporcionar en minutos únicamente)
 *
 *@param tiempoTranscurrido: Tiempo que ha transcurrido desde el inició de operaciones del banco
 *              (debe ser proporcionado en minutos)
 *
**/
void pintarTiempo(int horaInicial, int tiempoTranscurrido);

//--------------------------------------------------------------------------------------
/**
 *@brief Función que posiciona el cursor sobre una localización en específico
 *
 *@param x: Coordenada en x en donde posicionar el cursor
 *
 *@param y: Coordenada en y en donde posicionar el cursor
 *
 *@pre Los valores de x y de y deben ser valores enteros no negativos
 *
**/
void gotoxy(int x,int y);

#endif // AUXILIARES_H_INCLUDED
