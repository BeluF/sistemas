// CasillaPuente.cpp
#include "casillapuente.h"
#include <iostream>

void CasillaPuente::activar(Jugador* jugador) {
    std::cout << "¡Del puente a la posada!" << std::endl;
    jugador->mover(destino - jugador->getPosicion());
}
