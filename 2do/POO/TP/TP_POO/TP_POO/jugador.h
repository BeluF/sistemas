#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "estadoJugador.h"

class Casilla;

// --- CLASE Jugador ---
class Jugador
{
private:
    std::string nombre;
    int posicion = 0;
    int turnosPerdidos;
    estadoJugador estadoEspecial;

public:
    Jugador(std::string nombre);
    std::string getNombre();
    int getPosicion();
    int setPosicion(int nuevaPosicion);
    void mover(int cantidad);
    void aplicarEfectoCasilla(Casilla *casilla);
    void resetEstado();
    bool estaCastigado();
    int getTurnosPerdidos();
    int setTurnosPerdidos(int turnos);
    estadoJugador getEstadoEspecial();
    void setEstadoEspecial(estadoJugador nuevoEstado);
};

#endif // JUGADOR_H
