#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

class VectorDinamico
{
private:
    int* datos, cant;
public:
    //Constructor
    VectorDinamico();
    //Destructor
    ~VectorDinamico();

    //Métodos
    int getCant();      //a. Saber cuántos elementos hay en el vector
    void add(int n);    //b. Agregar un elemento al vector
    void remove(int n); //c. Remover un elemento del vector
    double prom();      //d. Obtener el promedio de los elementos del vector
    int may();          //e. Obtener el mayor de los elementos
    int min();          //f. Obtener el menor de los elementos
    //Mostrar los elementos del vector
    void show();
};

#endif // VECTORDINAMICO_H
