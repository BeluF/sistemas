#ifndef CASILLAOCA_H
#define CASILLAOCA_H
#include "casilla.h"
#include <QString>

class CasillaOca : public Casilla
{
public:
    CasillaOca();
    CasillaOca(int numero);
    QString activarJugador(Jugador* jugador);

};

#endif // CASILLAOCA_H
