//No puede usarse cin porque QT trabaja con bucle de eventos, es decir, no esper a que el usuario
//ingrese algo para continuar, simplemente continúa (eso generaba el bucle infinito en QT)
#include <QTextStream>
#include <QString>
#include <QDebug>


// --- CLASE Juego ---
// La clase principal que coordina todo el sistema del juego de la Oca.

#include "juego.h"
#include "jugador.h"
#include "tablero.h"
#include "dado.h"

using namespace std;

// Constructor
Juego::Juego(QObject *parent) : QObject(parent), jugadores(nullptr), cantidadJugadores(0), tablero(nullptr), turnoActual(0), terminado(false) {}

// Destructor: Libera la memoria asignada dinámicamente.
Juego::~Juego()
{
    if (jugadores)
    {
        for (int i = 0; i < cantidadJugadores; ++i)
        {
            delete jugadores[i]; // Libera cada Jugador
        }
        delete[] jugadores; // Libera el arreglo de punteros
    }
    delete tablero; // Libera el Tablero
}

// Método iniciar(): Inicializa jugadores y tablero.
void Juego::iniciar(int numJugadores)
{
    this->cantidadJugadores = numJugadores;
    jugadores = new Jugador *[cantidadJugadores];

    for (int i = 0; i < cantidadJugadores; ++i)
    {
        //No pedir el nombre, que se genere el Jugador de 1 a 4
        //Crear un objeto QString como plantilla, %1 es el marcador de posición p/1er argumento
        //Con arg(i+1) se reemplaza el valor de %1 con los nros de 1 a 4
        QString nombreAutogenerado = QString("Jugador %1").arg(i + 1);
        jugadores[i] = new Jugador(nombreAutogenerado.toStdString());
        // Los juagdores inician fuera del tablero: posición -1.
        jugadores[i]->setPosicion(-1);
    }

    tablero = new Tablero(63); // 63 casillas
    tablero->inicializar();    // Inicializa el tablero con las casillas correspondientes

    qInfo() << "El juego ha comenzado con " << cantidadJugadores << "jugadores";
    emit juegoIniciado(this->cantidadJugadores);
}

// Método jugarTurno(): Gestiona el turno del jugador actual.
void Juego::jugarTurno()
{
    if (terminado)
        return;

    Jugador *jugadorActual = jugadores[turnoActual];

    //Validar el jugador
    if (!jugadorActual) {
        qCritical() << "Jugador actual es nullptr. Turno:" << turnoActual;
        return;
    }


    // Emitir la señal de a de a quién le toca
    emit mensajeEstado(QString("Turno de %1 (Posición: %2)")
                           .arg(QString::fromStdString(jugadorActual->getNombre()))
                           .arg(jugadorActual->getPosicion() + 1));

    if (jugadorActual->estaCastigado())
    {
        // ANUNCIO de castigo
        emit jugadorCastigado(QString::fromStdString(jugadorActual->getNombre()), jugadorActual->getTurnosPerdidos());

        if (jugadorActual->getTurnosPerdidos() > 0)
        {
            qInfo() << jugadorActual->getNombre() << " está castigado y pierde el turno. Turnos restantes: " << jugadorActual->getTurnosPerdidos();
            jugadorActual->setTurnosPerdidos(jugadorActual->getTurnosPerdidos() - 1);
            avanzarTurno();
            jugarTurno();
            return;
        }

        if (jugadorActual->getTurnosPerdidos() == -1) //Pozo
        {
            qInfo() << jugadorActual->getNombre() << " sigue atrapado en el Pozo y no puede jugar";
            avanzarTurno();
            jugarTurno();
            return;
        }

        jugadorActual->resetEstado();
        qInfo() << jugadorActual->getNombre() << " ha terminado su castigo y puede jugar.";
    }

    int posicionOriginal = jugadorActual->getPosicion();
    //Validar la posición
    if(posicionOriginal < -1 || posicionOriginal >= (tablero->getCantidadCasillas()+1)){
        qCritical() << "Posición fuera de rango" << posicionOriginal;
        return;
    }

    qDebug() << "--- INICIO DEL TURNO para" << QString::fromStdString(jugadorActual->getNombre()) << "---";
    qDebug() << "Posición Original:" << posicionOriginal;

    int tirada = dado.tirar();
    emit dadoLanzado(tirada);
    qDebug() << "Tirada del dado:" << tirada;


    qDebug() << "Llamando a jugadorActual->mover(" << tirada << ")...";
    jugadorActual->mover(tirada);
    emit jugadorMovido(turnoActual, posicionOriginal, jugadorActual->getPosicion());

    qDebug() << "Posición DESPUÉS de mover():" << jugadorActual->getPosicion();

    qDebug() << "Llamando a aplicarEfectoCasilla...";

    Casilla *casillaLlegada = tablero->getCasilla(jugadorActual->getPosicion());

    //Validar la casilla
    if (!casillaLlegada) {
        qDebug() << "ERROR: casillaLlegada es nullptr en la posición:" << posicionOriginal;
        return;
    }

    qDebug() << "casillaLlegada OK: índice" << jugadorActual->getPosicion();
    qDebug() << "Jugador nombre:" << QString::fromStdString(jugadorActual->getNombre());

    //Primero verificar el ganador
    int indiceGanador = verificarGanador();
    if (indiceGanador != -1)
    {
        //Hay ganador
        terminado = true;
        emit juegoGanado(QString::fromStdString(jugadores[indiceGanador]->getNombre()));
        qInfo() << jugadorActual->getNombre() << " ha ganado el juego.";
        return;
    }

    mensajeEspecial = casillaLlegada->activarJugador(jugadorActual);

    if (!mensajeEspecial.isEmpty())
    {
        emit mensajeParaMostrar(mensajeEspecial);
        return;
    }

    // Si no hay mensaje especial, seguimos normalmente:
    emit jugadorMovido(turnoActual, posicionOriginal, jugadorActual->getPosicion());

    avanzarTurno();
}

// Método verificarGanador(): Determina si algún jugador alcanzó la casilla 63.
int Juego::verificarGanador()
{
    for (int i = 0; i < cantidadJugadores; i++)
    {
        if (jugadores[i]->getPosicion() == (CASILLA_META + 1))
        {
            return i; //Devuelve el índice del ganador
        }
    }
    return -1; //No hay ganador
}

// Método estaTerminado(): Retorna true si el juego ha terminado.
bool Juego::estaTerminado() const
{
    return terminado;
}

// Método auxiliar para avanzar al siguiente turno.
void Juego::avanzarTurno()
{
    turnoActual = (turnoActual + 1) % cantidadJugadores;
    emit turnoCambiado(QString::fromStdString(jugadores[turnoActual]->getNombre()));
}

// Método obtenerJugadores(): Retorna una lista de punteros a los jugadores.
QList<Jugador*> Juego::obtenerJugadores() const
{
    QList<Jugador*> listaJugadores;
    for (int i = 0; i < cantidadJugadores; ++i)
    {
        listaJugadores.append(jugadores[i]);
    }
    return listaJugadores;
}

// Método continuarTurno(): Continúa el turno del jugador actual, verificando si hay ganador.
// Este método se llama después de que un jugador ha movido y se han aplicado los efectos
// de la casilla en la que ha caído.
void Juego::continuarTurno()
{
    Jugador *jugadorActual = jugadores[turnoActual];

    int posicionFinal = jugadorActual->getPosicion();
    emit jugadorMovido(turnoActual, jugadorActual->getPosicion(), posicionFinal);

    int indiceGanador = verificarGanador();
    if (indiceGanador != -1)
    {
        terminado = true;
        emit juegoGanado(QString::fromStdString(jugadores[indiceGanador]->getNombre()));
        qInfo() << jugadorActual->getNombre() << " ha ganado el juego.";
        return;
    }

    if (mensajeEspecial.contains("Repetís el turno!"))
    {
        mensajeEspecial.clear();
        emit turnoRepetido();
        return;
    }

    avanzarTurno();
}
