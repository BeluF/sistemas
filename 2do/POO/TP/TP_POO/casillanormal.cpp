// --- CLASE Casilla Normal ---
// Representa una casilla normal que no tiene efectos especiales.
#include "casillanormal.h"


CasillaNormal::CasillaNormal(int numero) : Casilla(numero) {}

QString CasillaNormal::activarJugador(Jugador *jugador)
{
    // No tiene efecto especial
    return "";
}
