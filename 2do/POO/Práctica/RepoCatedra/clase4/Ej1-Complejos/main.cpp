/*
Realice una clase que represente números complejos
a)Un número complejo debe ser construido.
b)Un número complejo debe sumar, restar, multiplicar y dividir
*/

#include <iostream>
#include "complejo.h"

int main() {
    Complejo c1(4, 3);
    Complejo c2(1, -2);

    std::cout << "Primer número: ";
    c1.mostrar();

    std::cout << "Segundo número: ";
    c2.mostrar();

    Complejo suma = c1.sumar(c2);
    std::cout << "Suma: ";
    suma.mostrar();

    Complejo resta = c1.restar(c2);
    std::cout << "Resta: ";
    resta.mostrar();

    Complejo producto = c1.multiplicar(c2);
    std::cout << "Multiplicación: ";
    producto.mostrar();

    Complejo division = c1.dividir(c2);
    std::cout << "División: ";
    division.mostrar();

    return 0;
}
