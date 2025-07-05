#include "jugador.h"
#include "casilla.h"
// El jugador se inicializa con su nombre, en la posición 0 (fuera del tablero) y sin penalizaciones.
Jugador::Jugador(std::string nombre)
    : nombre(nombre), posicion(0), turnosPerdidos(0), enPozo(false) {}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getPosicion() const {
    return posicion;
}

int Jugador::getTurnosPerdidos() const {
    return turnosPerdidos;
}

void Jugador::setPosicion(int nuevaPosicion) {
    posicion = nuevaPosicion;
}

// Mueve al jugador una cantidad de casillas.
void Jugador::mover(int cantidad) {
    posicion += cantidad;
}

// Asigna una cantidad de turnos que el jugador debe perder. [cite: 319]
void Jugador::penalizar(int turnos) {
    turnosPerdidos = turnos;
}

// Reduce en uno el contador de turnos perdidos.
void Jugador::reducirTurnoPenalidad() {
    if (turnosPerdidos > 0) {
        turnosPerdidos--;
    }
}

// Verifica si al jugador le quedan turnos por perder. [cite: 258]
bool Jugador::estaCastigado() const {
    return turnosPerdidos > 0;
}

// Establece el estado del jugador respecto a la casilla Pozo.
void Jugador::setEnPozo(bool estado) {
    enPozo = estado;
}

// Verifica si el jugador está atrapado en el Pozo. [cite: 31]
bool Jugador::estaEnPozo() const {
    return enPozo;
}
