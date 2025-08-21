#include "casillacastigo.h"
#include "jugador.h"
#include "estadoJugador.h"
#include <QDebug>
#include <QString>

using namespace std;

// --- CLASE Casilla Castigo ---
// Representa una casilla de castigo que afecta al jugador.
CasillaCastigo::CasillaCastigo(int numero) : Casilla(numero) {}

QString CasillaCastigo::activarJugador(Jugador *jugador)
{
    jugador->setEstadoEspecial(castigado); // Cambia estado
    switch (getnumero())
    {
    // Posada pierde un turno
    case 19:
        jugador->setTurnosPerdidos(1);
        qInfo() << "El jugador" << jugador->getNombre() << "cae en la Posada y pierde un turno.";
        return "¡Has caído en la Posada (casilla 19)! Pierdes un turno.";
        break;
    // Cárcel pierde dos turnos
    case 56:
        jugador->setTurnosPerdidos(1);
        qInfo() << "El jugador" << jugador->getNombre() << "cae en la Cárcel y pierde dos turnos.";
        return "¡Has caído en la Carcel (casilla 56)! Pierdes dos turnos.";

        break;
    // Pozo pierde los turnos necesarios hasta que otro jugador caiga en la casilla
    case 31:
        if (jugadorAtrapadoEnPozo == nullptr) {
            jugadorAtrapadoEnPozo = jugador;
            jugador->setEstadoEspecial(castigado);
            jugador->setTurnosPerdidos(-1); // -1 indica que está atrapado indefinidamente

            qInfo() << "El jugador" << jugador->getNombre() << "cae en el Pozo (casilla 31) y y queda atrapado hasta que otro jugador caiga allí.";
            return "¡Has caído en el Pozo (casilla 31)! Quedas atrapado hasta que otro jugador caiga en esta casilla.";
        }
        else if (jugadorAtrapadoEnPozo != jugador) {
            // Liberar al jugador atrapado anterior
            jugadorAtrapadoEnPozo->setEstadoEspecial(noCastigado);
            jugadorAtrapadoEnPozo->setTurnosPerdidos(0);

            qInfo() << "El jugador" << jugadorAtrapadoEnPozo->getNombre() << "es liberado del Pozo por" << jugador->getNombre();

            // El nuevo jugador queda atrapado
            jugadorAtrapadoEnPozo = jugador;
            jugador->setEstadoEspecial(castigado);
            jugador->setTurnosPerdidos(-1);

            qInfo() << "El jugador" << jugador->getNombre() << "cae en el Pozo (casilla 31) y y queda atrapado hasta que otro jugador caiga allí.";
            return "¡Has caído en el Pozo (casilla 31)! Quedas atrapado, pero liberaste al jugador anterior.";
        } else {
            // Si el mismo jugador vuelve a caer
            qInfo() << "El jugador" << jugador->getNombre() << "ya está atrapado en el Pozo.";
            return "Ya estás atrapado en el Pozo (casilla 31).";
        }
        break;
    // Laberinto no pierde turno, retrocede hasta la casilla 30
    case 42:
        jugador->setPosicion(30); // Retrocede a la casilla 30
        qInfo() << "El jugador" << jugador->getNombre() << "cae en el Laberinto (casilla 42) y retrocede hasta la casilla 30.";
        return "¡Has caído en el Laberinto (casilla 42)! Retrocedes a la casilla 30.";

        break;
    // Calavera vuelve a la casilla 1
    case 58:
        jugador->setPosicion(1); // Vuelve a la casilla 1
        qInfo() << "El jugador" << jugador->getNombre() << "cae en la Calavera (casilla 58) y vuelve a la casilla 1.";
        return "¡Has caído en la Calavera (casilla 58)! Retrocedes a la casilla 1.";

        break;
    }
}
