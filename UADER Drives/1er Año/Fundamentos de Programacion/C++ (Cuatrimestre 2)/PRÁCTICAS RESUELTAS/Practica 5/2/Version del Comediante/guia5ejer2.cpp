#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    /*2. Escribir un programa que pida 10 números enteros por teclado, los almacene en un vector
    llamado NUM y luego emita los siguientes informes:
    a) Cuántos de esos números son pares.
    b) Cuál es el valor del número máximo.
    c) Cuál es el valor del número mínimo.
    d) Se ingrese un valor entero e indique si este número está entre los almacenados en el
    arreglo.
    */
    float numeros [10];
    int nrospar=0,nromayor=0,nromenor=9999,valormaximo,valorminimo,nrobusqueda,c=0;
    for (int i=0; i < 10; i++)
    {
        cout<<"Ingrese un numero entero: "<<endl;
        cin>>numeros[i];
    }
    for (int i=0; i <10; i++)
    {
        if ((numeros[i]/2) == trunc(numeros[i]/2))
            nrospar++;
        if (numeros[i]>nromayor)
        {
            nromayor=numeros[i];
            valormaximo=numeros[i];
        }
        if (numeros[i]<nromenor)
        {
            nromenor=numeros[i];
            valorminimo=numeros[i];
        }
    }
    cout<<"La cantidad de numeros pares es de: "<<nrospar<<endl;
    cout<<"El valor máximo entre todos los números es de: "<<valormaximo<<"  y el valor mínimo es: "<<valorminimo<<endl;
    cout<<endl;
    cout<<"Ingrese un número (entero) que quiera buscar dentro del array"<<endl;
    cin>>nrobusqueda;
    for (int i = 0; i < 10; i++)
    {
        if (numeros[i]==nrobusqueda)
        {
            c++;
        }
    }
    if (c != 0)
    cout<<"El número ingresado fue encontrado en el arreglo";
    else cout <<"El número no está dentro del array";
    return 0;
}
