#include "casillaoca.h"
#include "jugador.h"
#include "estadoJugador.h"
#include "casilla.h"
#include <QDebug>
#include <QString>

using namespace std;

// --- CLASE Casilla Oca ---
// Representa una casilla Oca que permite avanzar a la siguiente Oca.

CasillaOca::CasillaOca(int numero) : Casilla(numero) {}

QString CasillaOca::activarJugador(Jugador *jugador)
{
    if (jugador == nullptr)
        return "";

    const int cantidadCasillasOca = 6;
    int casillasOca[cantidadCasillasOca] = {9, 18, 27, 36, 45, 54};

    int pos = getnumero();
    for (int i = 0; i < cantidadCasillasOca - 1; i++)
    {
        if (pos == casillasOca[i])
        {
            jugador->setPosicion(casillasOca[i + 1]);
            // El estado debe ser noCastigado
            jugador->setEstadoEspecial(noCastigado);
            qInfo() << "El jugador" << jugador->getNombre() << "avanza de Oca a Oca a la casilla" << casillasOca[i] + 1;
            return "¡Has caído en la casilla " + QString::number(pos) +
                " de Oca! Avanza hasta la próxima Oca en la casilla " +
                QString::number(casillasOca[i + 1]) + ".Repetís el turno!";
        }
    }
    return "Has caído en la última casill Oca. No hay próxima Oca para avanzar.Repetís el turno!";
}
