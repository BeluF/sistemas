#include "casillaoca.h"
#include <iostream>

void CasillaOca::activar(Jugador* jugador) {
    std::cout << "¡De oca a oca y tiro porque me toca!" << std::endl;
    jugador->mover(siguienteOca - jugador->getPosicion());
    jugador->setTiroExtra(true);
}
