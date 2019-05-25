
#include "cajeras.h"
#include "auxiliares.h"

#define NODISPONIBLE -1

using namespace std;


int disponible(cajera *c, int numCajeras){
    cajera *p;
    p = c;

    for (int i = 0; i < numCajeras; i++, p++){
        if (p->ocupada == false){
            return i;
        }
    }
    return NODISPONIBLE;
}

int pasarCajera(cajera *c, int numCajeras, int potencial){
    int pasar = potencial;
    cajera *p, *q;
    p = c + potencial;
    q = p + 1;

    for (int i = potencial + 1; i < numCajeras; i++, q++){
        if (q->ocupada == false && q->clientesAtendidos < p->clientesAtendidos){
            p = q;
            pasar = i;
        }
    }
    return pasar;
}

void pintarCajeras(cajera *c, int numCajeras){
    cajera *p;
    p = c;
    enum simbSimple{BV= 179, ESD = 191, EII, BH = 196, EID = 217, ESI};

    for (int i = 0; i < numCajeras; i++, p++){
        gotoxy(10, 5 * (i + 1));
        cout << char (ESI);
        for (int j = 0; j < 3; j++){
            cout << char (BH);
        }
        cout << char (ESD);
        gotoxy(10, 5 * (i + 1) + 1);
        cout << char (BV);
        cout << " ";
        if (p->ocupada){
            cout << char (254);
        } else {
            cout << " ";
        }
        cout << " ";
        cout << char (BV);
        gotoxy(10, 5 * (i + 1) + 2);
        cout << char (EII);
        for (int j = 0; j < 3; j++){
            cout << char (BH);
        }
        cout << char (EID);
    }
}
