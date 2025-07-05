// CasillaCastigo.cpp
#include "casillacastigo.h"
#include <iostream>

void CasillaCastigo::activar(Jugador* jugador) {
    if (retorno != -1) {
        std::cout << "¡Oh no! Vuelves a la casilla " << retorno << "!" << std::endl;
        jugador->setPosicion(retorno);
    } else {
        std::cout << "Pierdes " << turnosPerdidos << " turno(s)." << std::endl;
        jugador->perderTurnos(turnosPerdidos);
    }
}
