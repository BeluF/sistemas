#include "complejo.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

Complejo Complejo::sumar(const Complejo &otro) const{
    return Complejo(real + otro.real, imaginario + otro.imaginario);
}

Complejo Complejo::restar(const Complejo &otro) const{
    return Complejo(real - otro.real, imaginario - otro.imaginario);
}

Complejo Complejo::multiplicar(const Complejo& otro) const {
    double r = real * otro.real - imaginario * otro.imaginario;
    double i = real * otro.imaginario + imaginario * otro.real;
    return Complejo(r, i);
}

Complejo Complejo::dividir(const Complejo& otro) const {
    double denominador = otro.real * otro.real + otro.imaginario * otro.imaginario;
    double r = (real * otro.real + imaginario * otro.imaginario) / denominador;
    double i = (imaginario * otro.real - real * otro.imaginario) / denominador;
    return Complejo(r, i);
}

void Complejo::mostrar() const {
    cout<<real<<(imaginario >= 0 ? " + " : " - ")<<abs(imaginario)<<"i"<<endl;
}
