#ifndef CASILLA_NORMAL_H
#define CASILLA_NORMAL_H

#include "casilla.h"
#include <QString>

class CasillaNormal : public Casilla
{
public:
    CasillaNormal(int numero);
    QString activarJugador(Jugador *jugador) override;
};

#endif // CASILLA_NORMAL_H
