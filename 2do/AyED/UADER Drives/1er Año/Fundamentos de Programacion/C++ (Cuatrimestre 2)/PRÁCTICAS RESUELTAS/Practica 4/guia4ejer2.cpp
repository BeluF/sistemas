#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/* Ingresar una cadena de caracteres y luego 2 valores que representan la posición inicial y la
	final. Informar la subcadena comprendida entre ambas posiciones.*/
	string cadena;
	cout<<"Ingrese una cadena de caracteres"<<endl;
	getline(cin,cadena);
	char inicio = cadena[0];
	char fin= cadena[cadena.size()-1];
	string subcadena= cadena.substr(1,cadena.size()-2);
	cout<<inicio<<endl<<fin<<endl<<subcadena;
	
	return 0;
}

