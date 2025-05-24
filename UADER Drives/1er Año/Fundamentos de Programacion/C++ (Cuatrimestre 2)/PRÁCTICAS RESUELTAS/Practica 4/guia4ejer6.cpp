#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /* Ingrese una cadena de caracteres e informe si la misma tiene más de una palabra, la letra
con la que empieza y la letra con la que termina.*/
string cadena;
cout<<"Ingrese una cadena de caracteres"<<endl;
getline(cin,cadena);
int n= cadena.find("");
char inicio= cadena[0];
char fin=cadena[cadena.size()-1];
if (n != -1)
{
cout<<"La cadena tiene mas de una palabra y su letra de inicio es "<<inicio<<" y su letra con la que termina es: "<<fin;
}
else{
    cout<<"La cadena solo posee una palabray su letra de inicio es "<<inicio<<" y su letra con la que termina es: "<<fin;
}

    return 0;
}
