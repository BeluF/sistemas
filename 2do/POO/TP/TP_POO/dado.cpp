#include "dado.h" // Incluye la declaración de la clase Dado

// Constructor: Inicializa el generador con una semilla de tiempo.
Dado::Dado() : generador(std::random_device()()), distribucion(1, 6) {}

// Método tirar(): Simula el lanzamiento del dado y retorna un número aleatorio entre 1 y 6.
int Dado::tirar()
{
    return distribucion(generador);
}
