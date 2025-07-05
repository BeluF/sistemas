#include "dado.h"
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

// Constructor que inicializa la semilla del generador de números aleatorios
Dado::Dado() {
    srand(time(nullptr));
}

// Devuelve un número aleatorio entre 1 y 6
//VER: Hacer con mt19937 que distribuye mejor los números
int Dado::tirar() {
    return 1 + (rand() % 6);
}
