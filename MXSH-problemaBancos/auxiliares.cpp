
#include "auxiliares.h"
#include "cajeras.h"

using namespace std;

void pintarTiempo(int horaInicial, int tiempoTranscurrido){
    int hora, minutos;
    hora = horaInicial / 60 + tiempoTranscurrido / 60;
    minutos = horaInicial % 60 + tiempoTranscurrido % 60;

    gotoxy(10, 1);
    if (minutos < 10) {
        cout << "HORA: " << hora << ":0" << minutos << endl;
    } else {
        cout << "HORA: " << hora << ":" << minutos << endl;
    }

}

void gotoxy(int x,int y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x-1,y-1};
    SetConsoleCursorPosition(handle,coord);
}

void actualizarEstadoCajeras(cajera *c, int numCajeras, int horaInicial, int tiempoTranscurrido){
    cajera *p;
    p = c;
    for (int i = 0; i < numCajeras; i++, p++){
        if (p->horaDesocupadar > horaInicial + tiempoTranscurrido){
            p->ocupada = true;
        } else {
            p->ocupada = false;
        }
    }
}
