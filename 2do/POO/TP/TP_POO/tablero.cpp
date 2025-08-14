#include "tablero.h"
#include "casilla.h"
#include "casillanormal.h"
#include "casillaoca.h"
#include "casillapuente.h"
#include "casillacastigo.h"
#include <QDebug>

using namespace std;

// --- CLASE Tablero ---
// Estructura del contenedor de las 63 casillas de juego.

// Constructor: Inicializa el tablero con una cantidad específica de casillas.
Tablero::Tablero(int totalCasillas) : cantidadCasillas(totalCasillas)
{
    casillas = new Casilla *[cantidadCasillas]; // Reserva memoria para el arreglo de punteros a Casilla.
}

// Destructor: Libera la memoria asignada dinámicamente para las casillas.
Tablero::~Tablero()
{
    for (int i = 0; i < cantidadCasillas; ++i)
    {
        delete casillas[i]; // Libera cada objeto Casilla.
    }
    delete[] casillas; // Libera el arreglo de punteros.
}

// Método inicializar(): Crea cada casilla e instancia el tipo que corresponda.
void Tablero::inicializar()
{
    for (int i = 0; i < cantidadCasillas; ++i)
    {
        // Instanciar diferentes tipos de casillas según las relgas del juego.
        // Casillas de la Oca
        if (i == 9 || i == 18 || i == 27 || i == 36 || i == 45 || i == 54)
        {
            casillas[i] = new CasillaOca(i);
        }
        // Fin Casillas de la Oca

        // Casillas Puente
        else if (i == 6)
        {
            casillas[i] = new CasillaPuente(i);
        }
        // Fin Casillas Puente

        // Casillas Castigo: Posada (19), Pozo (31), Laberinto (42), Cárcel (56), Calavera (58) (índices 0-based)
        else if (i == 19 || i == 31 || i == 42 || i == 56 || i == 58)
        {
            casillas[i] = new CasillaCastigo(i);
        }
        // Fin Casillas Castigo

        // Casilla normal
        else
        {
            casillas[i] = new CasillaNormal(i);
        }
        // Fin Casilla normal
    }
}

// Acceder a la casilla según la posición.
Casilla *Tablero::getCasilla(int pos) const
{
    if (pos >= 0 && pos < (cantidadCasillas+1))
    {
        return casillas[pos];
    }
    qCritical() << "Error: Posición de casilla fuera de rango: " << pos;
    return nullptr;
}

// Retorna la cantidad total de casillas en el tablero.
int Tablero::getCantidadCasillas() const
{
    return cantidadCasillas;
}
