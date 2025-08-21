#ifndef TABLERO_H
#define TABLERO_H

#include "casilla.h"

// --- CLASE Tablero ---
// Estructura del contenedor de las 63 casillas de juego.
class Tablero
{
private:
    Casilla **casillas;   // Arreglo dinámico de punteros a objetos Casilla
    int cantidadCasillas; // Total de casillas en el tablero

public:
    Tablero(int totalCasillas);
    ~Tablero();
    void inicializar();
    Casilla *getCasilla(int pos) const;
    void mostrar() const;
    int getCantidadCasillas() const;
};

#endif // TABLERO_H
