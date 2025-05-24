#include <iostream>
using namespace std;

//Añadir un elemento
int* add(int* vec, int nuevo, int tam){
    int* aux = new int [tam + 1];
    for (int i = 0; i < tam; i++)
        aux [i] = vec [i];
    aux[tam] = nuevo;
    return aux;
}

//Borrar un elemento en un índice determinado del vector
int* remove(int* vec, int index, int tam){
    if (index >= tam - 1)
        return vec;
    int* aux = new int [tam - 1];
    int j = 0;
    for (int i = 0; i < tam; i++){
        if (i != index){
            aux[j]=vec[i];
            j++;
        }
    }
    return aux;
}

//Buscar cantidad de ocurrencias
int count (int* vec, int find, int tam){
    int cant = 0;
    for (int i = 0; i < tam; i++){
        if (vec[i] == find){
            cant++;
        }
    }

    return cant;
}

int* removeOcu(int* vec, int value, int tam){
    int cant = count(vec, value, tam);
    if (cant == 0) return vec;
    if (cant == tam) return NULL; //0 = NULL

    int* aux = new int [tam - cant];
    int j = 0;

    for (int i = 0; i < tam; i++){
        if (vec[i] != value){
            aux[j] = vec[i];
            j++;
        }
    }

    return aux;

}

int main(){
    int * vec = new int [5];
    for (int i = 0; i < 5; i++)
        vec [i] = i;

    int * vec2 = add(vec, 20, 5);
    delete []vec;

    int* vec3 = remove(vec2, 2, 6);
    delete []vec2;

    vec[2] = 4;

    for (int i = 0; i <6; i++)
        cout<<vec3[i]<<endl;
    cout<<"---------------------------"<<endl;

    int* vec4 = removeOcu(vec3, 4, 5);
    delete[] vec3;
    for (int i = 0; i < 3; i++)
        cout<<vec4[i]<<endl;

    return 0;

}
