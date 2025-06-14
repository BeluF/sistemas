// Ejemplo 4.
// Este programa lee de un archivo un listado de structs.
// A priori no sabemos la cantidad de lineas que tiene el archivo.
// Pero si es necesario saber como están formadas las lineas para 
//poder realizar la lectura de forma consistente.
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
struct alumno { //CON ESTA ESTRUCUTRA SE GUARDARA 
string nombre; // EL CONTENIDO EN EL ARCHIVO
int edad;
};
int main(int argc, char *argv[]) {
ifstream archivo;
alumno lista[10];
int cuantos = 0;
archivo.open ("prueba_lista.txt");
if ( archivo.fail() ) {
cout << "Error en la apertura del archivo.";
}
else {
getline(archivo,lista[cuantos].nombre);
// Mientras NO se encuentre el final del archivo...
while ( !archivo.eof() ) {
archivo >> lista[cuantos].edad;
archivo.ignore();
cuantos++;
getline(archivo,lista[cuantos].nombre);
}
}
for (int i=0; i<cuantos; i++) {
cout << "Nombre: ";
cout << lista[i].nombre << " ";
cout << "Edad: ";
cout << lista[i].edad << endl;
}
archivo.close ();

return 0;
}
