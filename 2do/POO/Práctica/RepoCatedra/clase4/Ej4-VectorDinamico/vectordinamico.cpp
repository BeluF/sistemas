#include "vectordinamico.h"
#include <iostream>
#include <limits>

using namespace std;

//Constructor
VectorDinamico::VectorDinamico() {
    datos = NULL;
    cant = 0;
}

//Destructor
VectorDinamico::~VectorDinamico(){
    delete[] datos;
}

//a. Saber cuantos elementos hay
int VectorDinamico::getCant(){
    return cant;
}

//b. Agregar un elemento
void VectorDinamico::add(int n){
    int* nuevoVec = new int [cant+1];
    for (int i = 0; i < cant; i++){
        nuevoVec[i] = datos[i];
    }
    nuevoVec[cant] = n;
    delete [] datos;
    datos = nuevoVec;
    cant++;
}

//c. Remover un elemento
void VectorDinamico::remove(int n){
    int pos = -1;
    for (int i = 0; i < cant; i++){
        if (datos[i] == n) pos = i;
    }

    if(pos == -1) return;

    int* nuevoVec = new int [cant-1];
    int i = 0;
    while (pos != i){
        nuevoVec[i] = datos[i];
        i++;
    }

    for (int i = 1, j = 0; i < cant; i++){
        nuevoVec[j] = datos[i];
    }

    delete[] datos;
    datos = nuevoVec;
    cant--;
}

//d. Calcular el promedio
double VectorDinamico::prom(){
    if (cant == 0) return 0;

    double suma = 0.0;
    for(int i = 0; i < cant; i++){
        suma += datos[i];
    }
    return (suma/cant);
}

//e. Mayor elemento
int VectorDinamico::may(){
    if (cant == 0) return -1;

    int max = datos[0];
    for (int i = 0; i < cant; i++){
        if (datos[i] > max) max = datos[i];
    }

    return max;
}

//f. Menor elemento
int VectorDinamico::min(){
    if (cant == 0) return -1;

    int min = datos[0];
    for (int i = 0; i < cant; i++){
        if (datos[i] < min) min = datos[i];
    }

    return min;
}

// Mostrar elementos
void VectorDinamico::show() {
    cout << "[ ";
    for (int i = 0; i < cant; ++i) {
        cout << datos[i] << " ";
    }
    cout << "]" << endl;
}


























