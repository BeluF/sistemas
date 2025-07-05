#ifndef JUEGO_H
#define JUEGO_H

#include <string> // Para std::string
#include "dado.h"    // Incluye el encabezado de Dado
#include "tablero.h" // Incluye el encabezado de Tablero

// Declaraciones anticipadas para las clases de tu compañero.
// En el .cpp de Juego.cpp, deberás incluir los .h reales de estas clases.
class Jugador;
class Casilla; // Aunque ya está en Tablero.h, lo mantenemos por claridad si Juego interactúa directamente.

// Clase Juego
// La clase principal que coordina todo el sistema del juego de la Oca.
// Administra el flujo de la partida, los turnos, el dado, el tablero y los jugadores.
class Juego {
private:
    Jugador** jugadores;       // Puntero a un arreglo de punteros a objetos Jugador (composición)
    int cantidadJugadores;     // Total de jugadores en partida
    Tablero* tablero;          // Juego posee y controla la existencia de Tablero (composición)
    Dado dado;                 // Instancia del dado para simular las tiradas
    int turnoActual;           // Índice del jugador que tiene el turno
    bool terminado;            // Indica si hay un ganador

    static const int CASILLA_META = 62; // La última casilla es la 63, pero el índice es 62 (0-62)

public:
    // Constructor: Inicializa los atributos principales del juego.
    Juego();

    // Destructor: Libera la memoria asignada dinámicamente para los jugadores y el tablero.
    ~Juego();

    // Método iniciar():
    // Pide la cantidad y los nombres de los jugadores. Inicializa jugadores y tablero.
    void iniciar();

    // Método jugarTurno():
    // Gestiona un turno completo para el jugador actual.
    void jugarTurno();

    // Método verificarGanador():
    // Determina si algún jugador ha alcanzado exactamente la casilla 63.
    void verificarGanador();

    // Método mostrarEstado():
    // Imprime un resumen del estado actual del juego.
    void mostrarEstado() const;

    // Método estaTerminado():
    // Retorna true si el juego ha terminado (hay un ganador), false en caso contrario.
    bool estaTerminado() const;

private:
    // Método auxiliar para avanzar al siguiente turno.
    void avanzarTurno();
};

#endif // JUEGO_H
