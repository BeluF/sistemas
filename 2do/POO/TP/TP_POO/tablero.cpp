#include "tablero.h" // Incluye la declaración de la clase Tablero
#include <iostream>  // Para std::cout, std::cerr

// Incluir los encabezados reales de las clases de Casilla de tu compañero aquí:
#include "casilla.h"        // Asume que Casilla.h declara la clase base abstracta Casilla
#include "casillanormal.h"  // Asume CasillaNormal.h contiene la declaración de CasillaNormal
#include "casillaoca.h"     // Asume CasillaOca.h contiene la declaración de CasillaOca
#include "casillapuente.h"  // Asume CasillaPuente.h contiene la declaración de CasillaPuente
#include "casillacastigo.h" // Asume CasillaCastigo.h contiene la declaración de CasillaCastigo


// Constructor de la clase Tablero
// Inicializa el tablero con una cantidad específica de casillas.
// Asigna memoria para el arreglo de punteros a Casilla.
Tablero::Tablero(int totalCasillas) : cantidadCasillas(totalCasillas) {
    casillas = new Casilla*[cantidadCasillas];
    // Las casillas individuales se inicializan en el método inicializar()
}

// Destructor de la clase Tablero
// Libera la memoria asignada dinámicamente para cada casilla
// y luego para el arreglo de punteros a Casilla.
// Es crucial para evitar fugas de memoria.
Tablero::~Tablero() {
    for (int i = 0; i < cantidadCasillas; ++i) {
        delete casillas[i]; // Libera cada objeto Casilla individual
    }
    delete[] casillas; // Libera el arreglo de punteros
}

// Implementación del método inicializar()
// Crea cada casilla e instancia el tipo que corresponda.
// Este método es donde se define la configuración específica del tablero de la Oca.
void Tablero::inicializar() {
    std::cout << "Inicializando tablero con " << cantidadCasillas << " casillas..." << std::endl;
    for (int i = 0; i < cantidadCasillas; ++i) {
        // Lógica para instanciar diferentes tipos de casillas.
        // Asegúrate de que esta lógica coincida con las reglas del juego de la Oca.
        if (i == 5 || i == 9 || i == 14 || i == 18 || i == 23 || i == 27 || i == 32 || i == 36 || i == 41 || i == 45 || i == 50 || i == 54 || i == 59) {
            casillas[i] = new CasillaOca(i); // Casillas de la Oca
        } else if (i == 6 || i == 12) {
            casillas[i] = new CasillaPuente(i); // Casillas del Puente
        } else if (i == 19 || i == 31 || i == 42 || i == 52 || i == 58) {
            casillas[i] = new CasillaCastigo(i); // Casillas de Castigo (Posada, Pozo, Cárcel)
        } else {
            casillas[i] = new CasillaNormal(i); // Casillas normales por defecto
        }
    }
    std::cout << "Tablero inicializado." << std::endl;
}

// Implementación del método getCasilla(int pos)
// Accede a la casilla según el número de posición.
// Retorna un puntero a Casilla, permitiendo el uso polimórfico de activar().
Casilla* Tablero::getCasilla(int pos) const {
    if (pos >= 0 && pos < cantidadCasillas) {
        return casillas[pos];
    }
    std::cerr << "Error: Posición de casilla fuera de rango: " << pos << std::endl;
    return nullptr; // Retorna nullptr si la posición es inválida
}

// Implementación del método mostrar()
// Imprime un resumen del estado del tablero.
void Tablero::mostrar() const {
    std::cout << "\n--- Estado del Tablero ---" << std::endl;
    for (int i = 0; i < cantidadCasillas; ++i) {
        std::cout << "Casilla " << casillas[i]->getNumero();
        if (i < cantidadCasillas - 1) {
            std::cout << " - ";
        }
    }
    std::cout << "\n--------------------------" << std::endl;
}

// Retorna la cantidad total de casillas en el tablero.
int Tablero::getCantidadCasillas() const {
    return cantidadCasillas;
}
