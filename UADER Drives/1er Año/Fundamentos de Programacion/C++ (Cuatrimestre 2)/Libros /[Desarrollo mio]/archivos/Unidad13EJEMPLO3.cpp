// Ejemplo 3.
// Este programa escribe en un archivo un listado de structs.
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
struct alumno { //CON ESTA ESTRUCUTRA SE GUARDARA 
	string nombre; // EL CONTENIDO EN EL ARCHIVO
	int edad;
	};
int main(int argc, char *argv[]) {
	ofstream archivo;
	alumno lista[5];
	// El usuario carga el listado.
	for (int i=0; i<5; i++) {
		cout << "Nombre: ";
		getline(cin,lista[i].nombre);
		cout << "Edad: ";
		cin >> lista[i].edad;
		cin.ignore();
	}
// Lo guardamos en el archivo.
	archivo.open ("./prueba_lista.txt");
	if ( archivo.fail() ) {
		cout << "Error en la apertura del archivo.";
		}
	else {
	for (int i=0; i<5; i++) {
			 archivo << lista[i].nombre <<endl<< lista[i].edad <<endl;
		}
	}
	archivo.close ();
return 0;
}

