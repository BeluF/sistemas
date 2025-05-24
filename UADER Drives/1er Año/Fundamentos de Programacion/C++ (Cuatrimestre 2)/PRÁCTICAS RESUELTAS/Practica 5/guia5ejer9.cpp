#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /*Escribir un programa que lea una matriz de 3 filas y 3 columnas de valores enteros. A
    continuación, el programa debe pedir el número de una fila. El programa deberá mostrar por
    pantalla, sólo los valores de esa fila.
    */
    int matriz [3][3],fila;
    for (int j=0; j<3;j++)
    {
        for (int i=0; i<3;i++)
        {
        cout<<"dato de fila "<<j<<" columna "<<i<<":"<<endl;
        cin>>matriz[j][i];
        }
    }
    cout<<endl;
    cout<<"Ingrese de que fila quiere obtener los valores"<<endl;
    cin>>fila;
    if (fila<=2)
    {
        for (int i = 0; i < 3; i++)
        {
        cout<<matriz[fila][i]<<" - ";
        }
    }
    else cout<<"El número de fila no existe en la matriz";
    return 0;
}
