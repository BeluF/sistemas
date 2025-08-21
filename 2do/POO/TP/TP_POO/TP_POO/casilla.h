#ifndef CASILLA_H
#define CASILLA_H
#include <QString>

class Jugador;

// --- CLASE Casilla ---
// Clase base que representa una casilla del tablero.
class Casilla
{
private:
    int numero;

public:
    Casilla(int numero);
    int getnumero();
    virtual QString activarJugador(Jugador *jugador) = 0;
    virtual ~Casilla() = default; // Agregamos destructor virtual para manejo polimórfico
};

#endif // CASILLA_H
