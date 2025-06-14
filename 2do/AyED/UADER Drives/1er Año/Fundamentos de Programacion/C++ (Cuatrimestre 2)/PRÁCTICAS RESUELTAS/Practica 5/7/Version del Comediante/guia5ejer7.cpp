#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /*7. Cargar un vector con N palabras. Luego intercambiar los valores del vector: el 1ero con el
    enésimo, el 2do con el enésimo -1, y así sucesivamente. Informar en 2 strings el vector
    original y el intercambiado.*/
    string palabras[999];
    int cantpalabras;
    cout<<"Ingrese cantidad de palabras"<<endl;
    cin>>cantpalabras;
    for (int i = 0; i < cantpalabras; i++)
    {
        cout<<"Ingrese la palabra"<<endl;
        cin>>palabras[i];
    }
    for (int i = 0; i < cantpalabras; i++)
    {
        cout<<palabras[i]<<" - ";
    }
    cout<<endl;
    for (int i = cantpalabras-1; i > -1; i--)
    {
        cout<<palabras[i]<<" - ";
    }
    
    return 0;
}
