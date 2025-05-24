#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /*Generar un vector numérico de N elementos, luego ingrese por cada elemento: posición en
    el vector y valor a asignar. El valor N se ingresa como primer dato.*/
    int x,posición;
    cout<<"Ingrese la cantidad de elementos"<<endl;
    cin>>x;
    x-=1;
    int numeros[x];
    for (int i=0; i<x;i++)
    {
        cout<<"Ingrese la posición que quiere elegir del vector"<<endl;
        cin>>posición;
            cout<<"Ingrese el valor que le quiere asignar a esa posición"<<endl;
            cin>>numeros[posición];
    }
    for (int i = 0; i < x; i++)
    {
        cout<<numeros[i]<<" - ";
    }
    
    return 0;
}
