#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    int posicion;
    int turnosPerdidos;
    bool enPozo;

public:
    Jugador(std::string nombre);

    std::string getNombre() const;
    int getPosicion() const;
    int getTurnosPerdidos() const;

    void setPosicion(int nuevaPosicion);
    void mover(int cantidad);

    // Métodos para manejar penalizaciones
    void penalizar(int turnos);
    void reducirTurnoPenalidad();
    bool estaCastigado() const;

    // Métodos específicos para la casilla Pozo
    void setEnPozo(bool estado);
    bool estaEnPozo() const;
};

#endif // JUGADOR_H
