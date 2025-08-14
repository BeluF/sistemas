// --- CLASE Casilla Castigo ---
// Representa una casilla de castigo que afecta al jugador.
#include "casillacasitigo.h"
#include "jugador.h"      // Para usar Jugador y sus métodos
#include "estadoJugador.h" // Para usar el enum estadoJugador
#include <iostream>       // Para cout
#include <QDebug>

using namespace std;

CasillaCastigo::CasillaCastigo(int numero) : Casilla(numero) {}

// Método que activa el efecto de la casilla sobre el jugador
// Cambia el estado del jugador y aplica las penalizaciones correspondientes según la casilla.
void CasillaCastigo::activarJugador(Jugador *jugador)
{
    jugador->setEstadoEspecial(castigado); // Cambia estado
    switch (getnumero())
    {
    // Posada pierde un turno
    case 19:
        jugador->setTurnosPerdidos(1);
        qDebug() << QString("El jugador %1 cae en la Posada (Casilla %2) y pierde 1 turno.")
                    .arg(QString::fromStdString(jugador->getNombre()))
                    .arg(getnumero() + 1);
        cout << jugador->getNombre() << " cae en la Posada (Casilla " << getnumero() + 1 << ") y pierde 1 turno." << endl;
        break;
    // Cárcel pierde dos turnos
    case 56:
        jugador->setTurnosPerdidos(2);
        cout << jugador->getNombre() << " cae en la Cárcel (Casilla " << getnumero() + 1 << ") y pierde 2 turnos." << endl;
        break;
    // Pozo pierde los turnos necesarios hasta que otro jugador caiga en la casilla
    case 31:
        // ---------------- PENDIENTE !!!!!!!!!
        jugador->setTurnosPerdidos(0); // Aquí se debe implementar la lógica para que el jugador pierda turnos hasta que otro jugador caiga en la casilla
        cout << jugador->getNombre() << " cae en el Pozo (Casilla " << getnumero() + 1 << "). ¡Queda atrapado hasta que otro jugador caiga aquí!" << endl;
        break;
    // Laberinto no pierde turno, retrocede hasta la casilla 31
    case 42:
        jugador->setPosicion(31); // Retrocede a la casilla 31
        cout << jugador->getNombre() << " cae en el Laberinto (Casilla " << getnumero() + 1 << ") y retrocede a la casilla 32 (Pozo)." << endl;
        break;
    // Calavera vuelve a la casilla 1
    case 58:
        jugador->setPosicion(0); // Vuelve a la casilla 1
        cout << jugador->getNombre() << " cae en la Calavera (Casilla " << getnumero() + 1 << ") y vuelve a la casilla 1." << endl;
        break;
    }
}
