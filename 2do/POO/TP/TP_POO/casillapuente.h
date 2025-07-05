#ifndef CASILLA_PUENTE_H
#define CASILLA_PUENTE_H

#include "casilla.h"
#include "jugador.h"

class CasillaPuente : public Casilla {
private:
    int destino;

public:
    CasillaPuente(int num, int dest) : Casilla(num), destino(dest) {}

    void activar(Jugador* jugador) override;
};

#endif
