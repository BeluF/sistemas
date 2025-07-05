#include "casillasespeciales.h"
#include <iostream>

// --- CasillaNormal ---
CasillaNormal::CasillaNormal(int numero) : Casilla(numero) {}
void CasillaNormal::activar(Jugador* jugador) {
    // No hace nada, el jugador simplemente se queda en la casilla. [cite: 314]
    std::cout << jugador->getNombre() << " ha caido en la casilla " << numero << ". Es una casilla normal." << std::endl;
}

// --- CasillaOca ---
CasillaOca::CasillaOca(int numero) : Casilla(numero) {}
void CasillaOca::activar(Jugador* jugador) {
    // Avanza a la siguiente oca. La lógica de volver a tirar se maneja en la clase Juego.
    std::cout << "¡De oca a oca y tiro porque me toca! ";
    int proximaOca = 0;
    switch(numero) {
    case 9: proximaOca = 18; break;
    case 18: proximaOca = 27; break;
    case 27: proximaOca = 36; break;
    case 36: proximaOca = 45; break;
    case 45: proximaOca = 54; break;
    case 54: proximaOca = 63; break; // La última oca lleva a la meta
    }
    jugador->setPosicion(proximaOca);
    std::cout << jugador->getNombre() << " salta a la casilla " << proximaOca << "." << std::endl;
}

// --- CasillaPuente ---
CasillaPuente::CasillaPuente(int numero) : Casilla(numero) {}
void CasillaPuente::activar(Jugador* jugador) {
    // Avanza a la casilla 12 (la Posada). [cite: 31]
    std::cout << "¡De puente a puente y tiro porque me lleva la corriente! ";
    jugador->setPosicion(12);
    std::cout << jugador->getNombre() << " salta a la casilla 12." << std::endl;
}

// --- CasillaPosada ---
CasillaPosada::CasillaPosada(int numero) : Casilla(numero) {}
void CasillaPosada::activar(Jugador* jugador) {
    std::cout << jugador->getNombre() << " ha caido en la Posada. ¡Pierde 1 turno!" << std::endl;
    jugador->penalizar(1); // Pierde 1 turno [cite: 31]
}

// --- CasillaPozo ---
CasillaPozo::CasillaPozo(int numero) : Casilla(numero) {}
void CasillaPozo::activar(Jugador* jugador) {
    std::cout << jugador->getNombre() << " ha caido en el Pozo. ¡Atrapado!" << std::endl;
    jugador->setEnPozo(true); // Queda atrapado [cite: 31]
}

// --- CasillaLaberinto ---
CasillaLaberinto::CasillaLaberinto(int numero) : Casilla(numero) {}
void CasillaLaberinto::activar(Jugador* jugador) {
    std::cout << jugador->getNombre() << " se ha perdido en el Laberinto. ¡Retrocede!" << std::endl;
    jugador->setPosicion(30); // Retrocede a la casilla 30 [cite: 31]
}

// --- CasillaCarcel ---
CasillaCarcel::CasillaCarcel(int numero) : Casilla(numero) {}
void CasillaCarcel::activar(Jugador* jugador) {
    std::cout << jugador->getNombre() << " ha caido en la Carcel. ¡Pierde 2 turnos!" << std::endl;
    jugador->penalizar(2); // Pierde 2 turnos [cite: 31]
}

// --- CasillaCalavera ---
CasillaCalavera::CasillaCalavera(int numero) : Casilla(numero) {}
void CasillaCalavera::activar(Jugador* jugador) {
    std::cout << "¡Oh no! " << jugador->getNombre() << " ha caido en la Calavera. ¡Vuelve al inicio!" << std::endl;
    jugador->setPosicion(1); // Vuelve a la casilla 1 [cite: 31]
}

// --- CasillaFinal ---
CasillaFinal::CasillaFinal(int numero) : Casilla(numero) {}
void CasillaFinal::activar(Jugador* jugador) {
    // La lógica de la victoria se maneja en la clase Juego.
    std::cout << "¡" << jugador->getNombre() << " ha llegado al Jardin de la Oca!" << std::endl;
}
