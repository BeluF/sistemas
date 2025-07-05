#ifndef CASILLA_NORMAL_H
#define CASILLA_NORMAL_H

#include "casilla.h"

class CasillaNormal : public Casilla {
public:
    CasillaNormal(int num) : Casilla(num) {}

    void activar(Jugador* jugador) override;  // solo declaración
};
#endif
