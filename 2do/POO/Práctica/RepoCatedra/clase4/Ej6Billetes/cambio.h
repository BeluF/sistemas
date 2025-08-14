#ifndef CAMBIO_H
#define CAMBIO_H


class Cambio
{
private:
    int monto;
    int* resultado;     // puntero dinámico
    int cantidad;       // cantidad de billetes/monedas
    const int denominaciones[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

public:
    Cambio(int monto);
    ~Cambio();
    void calcular();
    int* getRes();
    int getCant();
};

#endif // CAMBIO_H
