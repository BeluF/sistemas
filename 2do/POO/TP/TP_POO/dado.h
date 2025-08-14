#ifndef DADO_H
#define DADO_H

#include <random> // Para mt19937, random_device, uniform_int_distribution

// --- CLASE Dado ---
// Simula la tirada de un dado, devolviendo un número aleatorio entre 1 y 6.
class Dado
{
private:
    std::mt19937 generador;                       // Objeto para generar números aleatorios
    std::uniform_int_distribution<> distribucion; // Clase para distribución uniforme para el rango [1, 6]

public:
    // Constructor: Inicializa el generador con una semilla de tiempo.
    Dado();

    // Método tirar(): Simula el lanzamiento del dado y retorna un número aleatorio entre 1 y 6.
    int tirar();
};

#endif // DADO_H
