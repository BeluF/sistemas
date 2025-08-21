// --- CLASE Casilla ---
// Clase base que representa una casilla del tablero.

#include "casilla.h"

using namespace std;

// Implementación del constructor de Casilla
Casilla::Casilla(int numero) : numero(numero) {}

// Obtiene el número de la casilla
int Casilla::getnumero()
{
    return numero;
}
// Método virtual puro que debe ser implementado por las clases derivadas
QString activarJugador(Jugador *jugador) 
{
    return QString(); 
}
