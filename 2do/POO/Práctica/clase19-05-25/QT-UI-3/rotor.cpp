#include "rotor.h"

rotor::rotor(int cant)
{
    this->cant = cant;
    elementos = new int[cant];
    for (int i = 0; i < cant; i++){
        this->elementos[i] = i;
    }
    this->indice = 0;
}

int rotor::next()
{
    //Devuelve el valor y apunta al sgte. Si llega al final, apunta al inicio (0)
    int res = this->elementos[indice];
    indice ++;
    if (indice == cant) indice = 0;
    return res;
}
