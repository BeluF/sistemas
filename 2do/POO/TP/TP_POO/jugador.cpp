#include "jugador.h"
#include "casilla.h"
#include "estadoJugador.h"
#include <QMessageBox>

const int CASILLA_META = 62;
using namespace std;

// --- CLASE Jugador ---

// Constructor
Jugador::Jugador(string nombre) : nombre(nombre), posicion(0), turnosPerdidos(0), estadoEspecial(noCastigado) {}

//Retorna el nombre del jugador
string Jugador::getNombre()
{
    return nombre;
}

//Obtiene la posición del jugador
int Jugador::getPosicion()
{
    return posicion;
}

// Establece una nueva posición para el jugador
// Retorna la nueva posición
int Jugador::setPosicion(int nuevaPosicion)
{
    posicion = nuevaPosicion;
    return posicion;
}

// Mueve al jugador una cantidad de casillas según el valor que se obtenga del dado
void Jugador::mover(int cantidad)
{
    // La posición inicial es -1 (fuera del tablero)
    // Si el jugador está fuera del tablero, la primera tirada lo coloca directamente.
    if (this->posicion == -1) {
        this->posicion = cantidad;
    } else {
        // Movimiento normal
        this->posicion += cantidad;
    }

    // --- META ---
    // Si se pasa de la meta
    if (this->posicion > (CASILLA_META + 1))
    {
        int excedente = this->posicion - (CASILLA_META + 1);
        int rebotePosicion = (CASILLA_META + 1) - excedente;
        QString mensaje = QString("¡Te pasaste de la casilla 63!\n"
                                  "Rebotás hacia atrás y caés en la casilla %1.")
                              .arg(rebotePosicion);

        QMessageBox::information(nullptr, "¡Rebote!", mensaje);

        this->posicion = rebotePosicion;
    }

}

// Aplica el efecto de la casilla actual al jugador
void Jugador::aplicarEfectoCasilla(Casilla *casilla)
{
    casilla->activarJugador(this); // Invoca el método activarJugador de la casilla actual, pasando el jugador actual
}

// Resetea el estado del jugador a no castigado y turnos perdidos a 0
void Jugador::resetEstado()
{
    estadoEspecial = noCastigado; turnosPerdidos = 0;
}

// Verifica si el jugador está castigado
bool Jugador::estaCastigado() 
{ 
    return (estadoEspecial == castigado) ? true : false; 
}

// Obtiene el número de turnos perdidos del jugador
int Jugador::getTurnosPerdidos() 
{ 
    return turnosPerdidos; 
}

// Establece el número de turnos perdidos del jugador
int Jugador::setTurnosPerdidos(int turnos)
{
    turnosPerdidos = turnos;
    return turnosPerdidos;
}

// Obtiene el estado especial del jugador
estadoJugador Jugador::getEstadoEspecial()
{
    return estadoEspecial;
}

// Establece el estado especial del jugador
void Jugador::setEstadoEspecial(estadoJugador nuevoEstado)
{
    estadoEspecial = nuevoEstado;
}
