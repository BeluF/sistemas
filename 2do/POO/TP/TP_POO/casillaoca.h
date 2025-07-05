#ifndef CASILLA_OCA_H
#define CASILLA_OCA_H

#include "casilla.h"
#include "jugador.h"

class CasillaOca : public Casilla {
private:
    int siguienteOca;

public:
    CasillaOca(int num, int siguiente) : Casilla(num), siguienteOca(siguiente) {}

    void activar(Jugador* jugador) override;
};

#endif
