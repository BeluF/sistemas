#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "casilla.h"

class Tablero {
private:
    //std::vector<Casilla*> casillas;
    //HACER CASILLA CON PUNTEROS O VECTOR?
    Casilla** casillas; // Arreglo dinámico de punteros a objetos Casilla (polimorfismo)
    const int CANTIDAD_CASILLAS = 63;

public:
    // Constructor: Inicializa el tablero con una cantidad específica de casillas.
    Tablero(int totalCasillas);

    // Destructor: Libera la memoria asignada dinámicamente para las casillas.
    ~Tablero();

    // Método inicializar():
    // Crea cada casilla e instancia el tipo que corresponda, definiendo la configuración del tablero.
    void inicializar();

    // Método getCasilla(int pos):
    // Accede a la casilla según el número de posición. Retorna un puntero a Casilla.
    Casilla* getCasilla(int pos) const;

    // Método mostrar():
    // Imprime un resumen del estado del tablero (solo números de casillas por ahora).
    void mostrar() const;

    // Retorna la cantidad total de casillas en el tablero.
    int getCantidadCasillas() const;
};

#endif // TABLERO_H
