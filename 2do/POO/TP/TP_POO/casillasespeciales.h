#ifndef CASILLAS_ESPECIALES_H
#define CASILLAS_ESPECIALES_H

#include "casilla.h"
#include "jugador.h"

// Casilla sin efecto especial. [cite: 312, 313]
class CasillaNormal : public Casilla {
public:
    CasillaNormal(int numero);
    void activar(Jugador* jugador) override;
};

// Casilla de Oca: "De oca a oca y tiro porque me toca". [cite: 31, 315]
class CasillaOca : public Casilla {
public:
    CasillaOca(int numero);
    void activar(Jugador* jugador) override;
};

// Casilla de Puente: "Del puente a la posada". [cite: 31, 317]
class CasillaPuente : public Casilla {
public:
    CasillaPuente(int numero);
    void activar(Jugador* jugador) override;
};

// Casillas de Castigo genéricas.
// Usaremos clases específicas para cada tipo de castigo para un mejor manejo.

// Posada: Pierde un turno. [cite: 31]
class CasillaPosada : public Casilla {
public:
    CasillaPosada(int numero);
    void activar(Jugador* jugador) override;
};

// Pozo: Atrapado hasta que otro caiga. [cite: 31]
class CasillaPozo : public Casilla {
public:
    CasillaPozo(int numero);
    void activar(Jugador* jugador) override;
};

// Laberinto: Retrocede a la casilla 30. [cite: 31]
class CasillaLaberinto : public Casilla {
public:
    CasillaLaberinto(int numero);
    void activar(Jugador* jugador) override;
};

// Cárcel: Pierde dos turnos. [cite: 31]
class CasillaCarcel : public Casilla {
public:
    CasillaCarcel(int numero);
    void activar(Jugador* jugador) override;
};

// Calavera: Vuelve a la casilla 1. [cite: 31]
class CasillaCalavera : public Casilla {
public:
    CasillaCalavera(int numero);
    void activar(Jugador* jugador) override;
};

// Jardín de la Oca (Meta). No tiene un efecto "activo", se maneja en la lógica del juego.
class CasillaFinal : public Casilla {
public:
    CasillaFinal(int numero);
    void activar(Jugador* jugador) override;
};


#endif // CASILLAS_ESPECIALES_H
