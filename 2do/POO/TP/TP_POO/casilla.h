#ifndef CASILLA_H
#define CASILLA_H

// Forward declaration para evitar dependencias circulares
class Jugador;

class Casilla {
protected:
    int numero;

public:
    Casilla(int numero);
    virtual ~Casilla() = default; // Destructor virtual

    int getNumero() const;

    // Método virtual puro que será implementado por cada tipo de casilla.
    virtual void activar(Jugador* jugador) = 0;
};

#endif // CASILLA_H
