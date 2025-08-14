#include "cambio.h"

Cambio::Cambio(int m) {
    monto = m;
    resultado = nullptr;
    cantidad = 0;
}

Cambio::~Cambio() {
    if (resultado != nullptr) delete[] resultado;
}

//Métodos
void Cambio::calcular(){
    //Saber cuantos billetes y monedas se necesitan
    int tempMonto = monto;
    int total = 0;
    for (int i = 0; i < 10; i++){
        total += tempMonto / denominaciones[i];
        tempMonto %= denominaciones[i];
    }

    //Reservar la memoria
    resultado = new int [total];
    cantidad = 0;
    int restante = monto;

    //Llenar el vector
    for (int i = 0; i < 10; i++) {
        while (restante >= denominaciones[i]) {
            resultado[cantidad++] = denominaciones[i];
            restante -= denominaciones[i];
        }
    }
}

int* Cambio::getRes() {
    return resultado;
}

int Cambio::getCant() {
    return cantidad;
}