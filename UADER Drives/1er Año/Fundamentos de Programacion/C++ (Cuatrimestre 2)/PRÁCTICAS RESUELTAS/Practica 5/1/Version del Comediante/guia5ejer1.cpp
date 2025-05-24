#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /*1. a) Declarar un vector llamado números con la capacidad suficiente para almacenar las
edades de todos los alumnos de la comisión.
b) Ingresar la cantidad de alumnos que posee la comisión y luego almacenar en el vector las
edades de todos los alumnos.
c) Ingresar una posición y informar la edad almacenada en ella. Repetir c) hasta que se
ingrese una posición no válida.*/
int edad[99],cantal,posicion;
cout<<"Ingrese la cantidad de alumnos: "<<endl;
cin>>cantal;
for (int i = 0; i < cantal; i++)
{
    cout<<"Ingrese las edades del alumno nro: "<<i+1<<endl;
    cin>>edad[i];
}
do
{
    cout<<"Ingrese una posición del arreglo: "<<endl;
    cin>>posicion;
    if ((posicion >= 0) && (posicion < cantal ))
    {
        cout<<"La edad de la posición ingresada es: "<<edad[posicion]<<endl;
    }
    else cout<<"La posición ingresada no es valida";
    
} while ((posicion >= 0) && (posicion < cantal));
    return 0;
}
