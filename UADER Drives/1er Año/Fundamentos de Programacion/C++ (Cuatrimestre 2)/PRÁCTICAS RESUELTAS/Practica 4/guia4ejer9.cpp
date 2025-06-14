#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /* Se desea generar una dirección de correo en base a la información ingresada por un
estudiante. Se ingresa: nombre, apellido, fecha de nacimiento (DD/MM/AAAA) y facultad.
La dirección de correo se forma de la siguiente manera:
Primer letra del nombre + Apellido + DDMM + “@” + facultad + “.edu.ar”
*/
string nombre,apellido,fechadena,facultad;
cout<<"Ingrese nombre, luego appelido"<<endl;
getline(cin,nombre);
getline(cin,apellido);
cout<<"Ingrese fecha de nacimiento en formato DD/MM/AAAA"<<endl;
getline(cin,fechadena);
cout<<"Ingrese facultad"<<endl;
getline(cin,facultad);
char primerletra=nombre[0];
string dia=fechadena.substr(0,2);
cout<<dia;
string mes=fechadena.substr(3,2);
cout<<mes;
string mail= primerletra+apellido+dia+mes+"@"+facultad+".edu.ar";
cout<<"La dirección de correo sería: "<<mail;
    return 0;
}

