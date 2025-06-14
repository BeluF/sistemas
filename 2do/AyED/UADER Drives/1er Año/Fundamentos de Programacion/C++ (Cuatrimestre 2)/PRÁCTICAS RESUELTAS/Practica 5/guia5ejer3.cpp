#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /*Escribir un programa que lea un vector de 10 números enteros. Deberá mostrar el mismo
    vector por pantalla pero invertido. Ejemplo: dado el vector 1 2 3 4 5 6 7 8 9 10 el programa
    debería imprimir 10 9 8 7 6 5 4 3 2 1.*/
    int numeros [10];
    for (int i = 0; i < 10; i++)
    {
        cout<<"Ingrese un número entero"<<endl;
        cin>>numeros[i];
    }
    for (int i = 10; i > 0; i--)
    {
        cout<<numeros[i-1]<<" - ";
    }
    
    return 0;
}
