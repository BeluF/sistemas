#include "casilla.h"
#include <iostream>


Casilla::Casilla(int numero) : numero(numero) {}

int Casilla::getNumero() const {
    return numero;
}
