// --- CLASE Casilla Puente ---
// Representa una casilla puente que permite avanzar de la casilla 6 a la 12.

#include "casillapuente.h"
#include "jugador.h"
#include "estadoJugador.h"
#include <QDebug>

using namespace std;

CasillaPuente::CasillaPuente(int numero) : Casilla(numero) {}

QString CasillaPuente::activarJugador(Jugador *jugador)
{
    if (jugador == nullptr)
        return "";
    jugador->setPosicion(12);
    jugador->setEstadoEspecial(noCastigado);
    qInfo() << "El jugador" << jugador->getNombre() << "cruza el puente y avanza a la casilla 12.x";
    return "¡Has caído en el Puente (casilla 6)! Avanza hasta la casilla 12.";

}
