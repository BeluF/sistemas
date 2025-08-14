#ifndef CASILLA_PUENTE_H
#define CASILLA_PUENTE_H
#include <QString>

#include "casilla.h"
#include "jugador.h"
#include "estadoJugador.h"

class CasillaPuente : public Casilla
{
public:
    CasillaPuente(int numero);
    QString activarJugador(Jugador *jugador) override;
};

#endif // CASILLA_PUENTE_H
