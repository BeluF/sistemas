#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>
#include <QString>

#include "dado.h"
#include "jugador.h"
#include "tablero.h"


// --- CLASE Juego ---
// La clase principal que coordina todo el sistema del juego de la Oca.
class Juego : public QObject
{
     Q_OBJECT //Macro
private:
    Jugador **jugadores;
    int cantidadJugadores;
    Tablero *tablero;
    Dado dado;
    int turnoActual;
    bool terminado;
    bool repetirTurno = false;

    const static int CASILLA_META = 62;

public:
    Juego(QObject *parent = nullptr);
    ~Juego();
    int getTurno(){return turnoActual;}
    void iniciar(int numJugadores);
    int verificarGanador();
    void mostrarEstado() const;
    bool estaTerminado() const;
    QList<Jugador*> obtenerJugadores() const;


public slots:
    void jugarTurno();
    void continuarTurno();

signals:
    void juegoIniciado(int numJugadoresActivos);
    void dadoLanzado(int valorDado);
    void turnoCambiado(const QString &nombreSiguienteJugador);
    void jugadorCastigado(const QString &nombreJugador, int turnosRestantes);
    void juegoGanado(const QString &nombreGanador);
    void mensajeEstado(const QString &mensaje);
    void turnoRepetido();
    // Envía: índice del jugador, casilla de origen, casilla de destino.
    void jugadorMovido(int jugadorIndex, int casillaOrigen, int casillaDestino);
    void mensajeParaMostrar(const QString &mensaje);

private:
    void avanzarTurno();
    QString mensajeEspecial;


};


#endif // JUEGO_H
