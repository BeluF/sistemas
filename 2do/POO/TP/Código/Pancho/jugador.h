#ifndef JUGADOR_H
#define JUGADOR_H
#include "estadoJugador.h"
#include <string>
using namespace std;


class Jugador
{
    private:
        string nombre;
        int posicion= 0;
        int turnosPerdidos;
        estadoJugador estadoEspecial;
    public:
        Jugador(); //constructor vacio
        Jugador(string nombre);
        string getNombre();
        int getPosicion();
        void mover(int cantidad);
        //void aplicarEfectoCasilla(Casilla* casilla);
        void resetEstado();
        bool estaCastigado();
};

#endif // JUGADOR_H
