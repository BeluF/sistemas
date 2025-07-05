#ifndef CASILLA_CASTIGO_H
#define CASILLA_CASTIGO_H

#include "casilla.h"
#include "jugador.h"

class CasillaCastigo : public Casilla {
private:
    int turnosPerdidos;
    int retorno; // -1 si no aplica

public:
    CasillaCastigo(int num, int turnos, int retornoA = -1)
        : Casilla(num), turnosPerdidos(turnos), retorno(retornoA) {}

    void activar(Jugador* jugador) override;
};

#endif
