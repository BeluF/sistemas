#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /*Ingresar 5 números enteros por teclado. Luego, generar un nuevo arreglo, donde sus
    elementos sean los del arreglo anterior, pero multiplicados por 3. Mostrar por pantalla el
    segundo arreglo.*/
    int numeros[5],multiplos[5];
    cout<<"Ingrese 5 números enteros"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Numero "<<i+1<<" :"<<endl;
        cin>>numeros[i];
    }
    cout<<"Resultado de los numeros multiplicados por 3"<<endl;
    for (int i = 0; i < 5; i++)
    {
        multiplos[i]=(numeros[i]*3);
        cout<<multiplos[i]<<endl;
    }
    
    return 0;
}
