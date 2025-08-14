#include "vectordinamico.h"

//Definición de todos los métodos de la clase VectorDinamico

int VcetorDinamico::getCant() const
{
    return cant;
}

void VectorDinamico::add(int n)
{
    int* aux = new int[this->cant+1];

    for(int i=0; i<this->cant; i++){
        aux[i] = this->vector[i];
    }

    aux[this->cant] = n;
    delete [] this->vector;
    this->vector = aux;
    this->cant++;
}

void VectorDinamico::remove(int index)
{
    //Verificar que el índice esté en el rango existente
    if (this->cant < index){
        return;
    }

    int* aux = new int[this->cant-1];
    int j = 0; //Índice auxiliar

    for(int i = 0; i < this->cant; i++){
        if (i != index){
            aux[j] = this->vector[i];
            j++;
        }
    }

    delete [] this->vector;
    this->vector = aux;
    this->cant--;
}

int VectorDinamico::get(int index)
{
    return this->vector[index];
}

double VectorDinamico::prom()
{
    double p = 0;
    for (int i = 0; i < this->cant; i++){
        p += this->vector[i];
    }

    return p / this->cant;
}

int VectorDinamico::mayor()
{
    int aux = vector[0];
    for (int i = 0; i < this->cant; i++){
        if (aux < vector[i]){
            aux = vector [i];
        }
    }

    return aux;
}

int VectorDinamico::menor()
{
    int aux = vector[0];
    for (int i = 1; i < this->cant; i++){
        if (aux > vector[i]){
            aux = vector [i];
        }
    }

    return aux;
}



VectorDinamico::VectorDinamico() {

}
