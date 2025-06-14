#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /*4) Ingrese 2 cadenas de caracteres y un valor entero X. Inserte la segunda cadena dentro de
la primera a partir de la posición X, salvo que dicha posición sea inválida.
*/
int a;
string cad1,cad2;
cout<<"Ingrese 2 cadenas de caracteres"<<endl;
getline(cin,cad1);
getline(cin,cad2);
cout<<"Ingrese un número entero"<<endl;
cin>>a;
if (cad1.length()<a)
{
  cout<<"La posición es invalida";  
}
else 
{
string result= cad1.insert(a,cad2);
cout<<result;
}
    return 0;
}


