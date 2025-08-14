#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

class VectorDinamico
{
private: //DATOS
    int cant = 0;
    int* vector = nullptr;
public: //MÉTODOS
    VectorDinamico();

    /*a.) Saber tamaño*/
    int getCant() const;

    /*b.) Agregar*/
    void add(int n);

    /*c.) Eliminar*/
    void remove(int index);

    /*Imprimir*/
    int get(int index);

    /*d.) Promedio*/
    double prom();

    /*e.) Mayor*/
    int mayor();

    /*f.) Menor*/
    int menor();

};

#endif // VECTORDINAMICO_H
