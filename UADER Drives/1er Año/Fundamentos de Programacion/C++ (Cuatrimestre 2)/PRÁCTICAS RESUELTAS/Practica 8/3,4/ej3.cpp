#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
3. Se necesita generar un archivo con la cantidad de detenciones de los integrantes de las barras
bravas de un club. El archivo debe contener la información: apodo y la cantidad de veces que estuvo
detenido. El final de datos se determina con apodo igual a ‘ZZZ’. Nombre al archivo “BARRAS.TXT”.
En el archivo se almacena, por renglón, apodo y cantidad de detenciones separados por ‘|’
*/

int main(int argc, char *argv[]) {
	ofstream archivo;
	string apodo;
	int detenciones;
	
	archivo.open("./BARRAS.TXT", ios::app);
	
	if (archivo.fail()){
		cout << "Error de apertura del archivo "; 
		return 1;
	} else {
		cout << "Ingrese apodo: ";
		getline(cin, apodo);
		while (apodo != "ZZZ")
		{
			cout << "Ingrese cantidad de detenciones: ";
			cin >> detenciones;
			cin.ignore();
			
			archivo << apodo << "|" << detenciones << endl;
			
			cout << "Ingrese apodo: ";
			getline(cin, apodo);
		}
	}
	
	archivo.close();
	return 0;
}

