#ifndef CASILLA_CASTIGO_H
#define CASILLA_CASTIGO_H

#include "casilla.h"
#include "jugador.h"
#include "estadoJugador.h"
#include <QString>

class CasillaCastigo : public Casilla
{
public:
    CasillaCastigo(int numero);
    QString activarJugador(Jugador *jugador) override;

private:
    Jugador* jugadorAtrapadoEnPozo = nullptr;
};

#endif // CASILLA_CASTIGO_H
