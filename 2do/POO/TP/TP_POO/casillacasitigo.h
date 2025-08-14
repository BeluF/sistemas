#ifndef CASILLA_CASTIGO_H
#define CASILLA_CASTIGO_H

#include "casilla.h"
#include "jugador.h"
#include "estadoJugador.h"

class CasillaCastigo : public Casilla
{
public:
    CasillaCastigo(int numero);
    void activarJugador(Jugador *jugador) override;
};

#endif // CASILLA_CASTIGO_H
