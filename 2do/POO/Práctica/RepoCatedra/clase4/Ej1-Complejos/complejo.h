#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo
{
private:
    double real;
    double imaginario;
public:
    //Constructor
    Complejo(double r = 0.0, double i = 0.0);

    // Métodos para operaciones
    Complejo sumar(const Complejo& otro) const;
    Complejo restar(const Complejo& otro) const;
    Complejo multiplicar(const Complejo& otro) const;
    Complejo dividir(const Complejo& otro) const;

    // Método para mostrar el número complejo
    void mostrar() const;
};

#endif // COMPLEJO_H
