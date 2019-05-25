/*
    Nombre del archivo: problemaBancos.cbp
    Nombre del autor: Sandoval del Hoyo María Ximena
    Fecha: 220219
    Descripción: Programa de simulación de una cola en un banco,
                donde se puede escoger el número de cajeras para atender a los clientes durante el día.
                Se pueden cambiar las directivas del preprocesador para cambiar el tiempo de llegada
                máximo entre clientes y el tiempo de cajera máximo de los clientes (estos se generan aleatoriamente)
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

#include "auxiliares.h"
#include "cajeras.h"
#include "cola.h"

#define tiempoCajeraMaximo 30
#define tiempoLlegadaMaximo 5
#define NODISPONIBLE -1
#define ESPERA 10


using namespace std;

void imprimeEstado(cajera *c, int numCajeras, int tiempoTranscurrido, cola colaClientes, int horaInicio);
int main()
{
    ofstream archivo;

    archivo.open("problemaBancos.txt");
    archivo << "No. cliente \t Hora de llegada \t Clientes en cola \t Tiempo de espera \t Tiempo de cajera" << endl;

    int numCajeras, horaInicio, horaFinal;
    srand (time(NULL));
    cout << "PROGRAMA DE SIMULACI\xE0N DE COLA DE BANCO" << endl;
    CapturaNumero(numCajeras, "Introduce el n\xA3mero de cajeras para la simulaci\xA2n: ");
    CapturaNumero(horaInicio, "Introduce la hora de inicio (por ejemplo, si son las 09:00 am ingresa 900): ");
    CapturaNumero(horaFinal, "Introduce la hora de cierre (por ejemplo, si son las 04:00 pm ingresa 1600): ");

    cajera *c;
    c = new cajera[numCajeras]; // Arreglo de cajeras
    cajera *p;
    p = c;

    int tiempoTranscurrido = 0; // Se manejará el tiempo sólo en minutos

    horaFinal = 60 * (horaFinal / 100) + horaFinal % 100;
    horaInicio = 60 * (horaInicio / 100) + horaInicio % 100;
    int tiempoTotal = horaFinal - horaInicio;

     // Todas las cajeras inician desocupadas
    for (int i = 0; i < numCajeras; i++, p++){
            p->ocupada = false;
            p->clientesAtendidos = 0;
            p->horaDesocupadar = horaInicio;
    }

    cout << "Inicio de simulaci\xA2n" << endl;
    Sleep(ESPERA);

    // Se inicializa las variable de cada corrida

    cola colaClientes;
    int tiempoMaximo = 0;
    int longitudMaxima = 0;
    int turno = 0;
    int siguienteCajera = 0;
    int esperaPromedio = 0;


    while (tiempoTranscurrido < tiempoTotal){
        int siguiente = horaInicio + tiempoTranscurrido +  rand() % tiempoLlegadaMaximo;    // Genero la hora a la que llegará el siguiente cliente
        int tcajera = rand() % tiempoCajeraMaximo + 1; // Genero el tiempo de cajera del siguiente cliente

        // Mientras el banco esté abierto
        while (horaInicio + tiempoTranscurrido < siguiente){
            int estaDisponible = disponible(c, numCajeras);
            if (estaDisponible != NODISPONIBLE && colaClientes.longitud() > 0){
                int pasar = pasarCajera(c, numCajeras, estaDisponible);
                //system("pause");

                // Tiempo para atender al siguiente cliente
                cliente *nCliente;
                nCliente = colaClientes.sacar();
                (c + pasar)->horaDesocupadar = horaInicio + tiempoTranscurrido + nCliente->tiempoCajera;
                (c + pasar)->clientesAtendidos++;
                (c + pasar)->ocupada = true;

                nCliente->llegadaCajera = horaInicio + tiempoTranscurrido;

                // Se revisa el tiempo de espera de cada cliente
                if (nCliente->llegadaCajera - nCliente->horaLlegada > tiempoMaximo){
                        tiempoMaximo = nCliente->llegadaCajera - nCliente->horaLlegada;
                }

                // Se revisa cuanta cola había cuando llegó ese cliente
                if (nCliente->enCola > longitudMaxima){
                        longitudMaxima = nCliente->enCola;
                }
                esperaPromedio += (nCliente->llegadaCajera - nCliente->horaLlegada);

                // Guardar en el archivo
                archivo << "\t" << nCliente->turno << "\t\t";
                if (nCliente->horaLlegada / 60 <= 9){
                    archivo << "0" << nCliente->horaLlegada / 60;
                } else {
                    archivo << nCliente->horaLlegada / 60;
                }
                archivo << ":";
                if (nCliente->horaLlegada % 60 <= 9){
                    archivo << "0" << nCliente->horaLlegada % 60;
                } else {
                    archivo << nCliente->horaLlegada % 60;
                }
                archivo << "\t\t\t" << nCliente->enCola <<
                     "\t\t\t" << nCliente->llegadaCajera - nCliente->horaLlegada;
                archivo << "\t\t\t" << nCliente->tiempoCajera <<endl;

                delete nCliente;
            }

            tiempoTranscurrido++;
            actualizarEstadoCajeras(c, numCajeras, horaInicio, tiempoTranscurrido);
        }
        if (siguiente < horaFinal){
            // Una vez que pasó el tiempo, se agrega el siguiente cliente
            colaClientes.agregar(turno, siguiente, tcajera, 0, colaClientes.longitud() + 1);
            turno++;
        }

        tiempoTranscurrido++;
        actualizarEstadoCajeras(c, numCajeras, horaInicio, tiempoTranscurrido);
    }

    // Mientras el banco aún tenga clientes
    while (colaClientes.longitud() != 0){
        int estaDisponible = disponible(c, numCajeras);
        if (estaDisponible != NODISPONIBLE && colaClientes.longitud() > 0){
            // Tiempo para atender al siguiente cliente
            int pasar = pasarCajera(c, numCajeras, estaDisponible);
            //system("pause");

            // Tiempo para atender al siguiente cliente
            cliente *nCliente;
            nCliente = colaClientes.sacar();
            (c + pasar)->horaDesocupadar = horaInicio + tiempoTranscurrido + nCliente->tiempoCajera;
            (c + pasar)->clientesAtendidos++;
            (c + pasar)->ocupada = true;

            nCliente->llegadaCajera = horaInicio + tiempoTranscurrido;

            // Se revisa el tiempo de espera de cada cliente
            if (nCliente->llegadaCajera - nCliente->horaLlegada > tiempoMaximo){
                    tiempoMaximo = nCliente->llegadaCajera - nCliente->horaLlegada;
            }

            // Se revisa cuanta cola había cuando llegó ese cliente
            if (nCliente->enCola > longitudMaxima){
                    longitudMaxima = nCliente->enCola;
            }
            esperaPromedio += (nCliente->llegadaCajera - nCliente->horaLlegada);

             // Guardar en el archivo
            archivo << "\t" << nCliente->turno << "\t\t";
            if (nCliente->horaLlegada / 60 <= 9){
                archivo << "0" << nCliente->horaLlegada / 60;
            } else {
                archivo << nCliente->horaLlegada / 60;
            }
            archivo << ":";
            if (nCliente->horaLlegada % 60 <= 9){
                archivo << "0" << nCliente->horaLlegada % 60;
            } else {
                archivo << nCliente->horaLlegada % 60;
            }
            archivo << "\t\t\t" << nCliente->enCola <<
                     "\t\t\t" << nCliente->llegadaCajera - nCliente->horaLlegada;
            archivo << "\t\t\t" << nCliente->tiempoCajera <<endl;

            delete nCliente;

        }
        tiempoTranscurrido++;
        actualizarEstadoCajeras(c, numCajeras, horaInicio, tiempoTranscurrido);
    }

    p = c;
    int promedioClientes = 0;
    for (int i = 0; i < numCajeras; i++, p++){
        promedioClientes += p->clientesAtendidos;
    }

    promedioClientes = promedioClientes / numCajeras;
    esperaPromedio = esperaPromedio / turno;

    cout << "\nSimulaci\xA2n terminada" << endl << endl;
    cout << "Corrida de banco con " << numCajeras << " cajeras" << endl;
    cout << "Longitud de cola m\xA0xima: " << longitudMaxima << endl;
    cout << "Tiempo de espera m\xA0ximo (en minutos): " << tiempoMaximo << endl;
    cout << "Tiempo de espera promedio (en minutos): " << esperaPromedio << endl;
    cout << "Clientes atendidos en promedio por cajera: " << promedioClientes << endl;
    cout << "Clientes atendidos en total: " << turno << endl << endl;

    // Guardar información en el archivo de texto
    archivo << "\nCorrida de banco con " << numCajeras << " cajeras" << endl;
    archivo << "Longitud de cola maxima: " << longitudMaxima << endl;
    archivo << "Tiempo de espera maximo (en minutos): " << tiempoMaximo << endl;
    archivo << "Tiempo de espera promedio (en minutos): " << esperaPromedio << endl;
    archivo << "Clientes atendidos en promedio por cajera: " << promedioClientes << endl;
    archivo << "Clientes atendidos en total: " << turno << endl << endl;


    cout << "La informaci\xA2n de la llegada de cada cliente se ha guardado en un archivo llamado problemaBancos.txt" << endl;

    delete [] c;
    archivo.close();

    system("pause");
    return 0;
}

