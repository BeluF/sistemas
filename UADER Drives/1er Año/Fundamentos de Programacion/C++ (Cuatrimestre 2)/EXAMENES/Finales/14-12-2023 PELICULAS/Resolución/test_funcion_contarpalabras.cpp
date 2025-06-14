#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int contar_palabras(string texto, string dato); 

int main(int argc, char *argv[]) {
	string texto = "Muy buena peli de miedo, me gustó mucho porque daba mucho miedo.";
	string buscar = "miedo";
	
	int palabra = contar_palabras(texto,buscar);
	cout << "Cantidad de palabras encontradas: " << palabra;
	
	return 0;
}

int contar_palabras(string texto, string dato){
	int total = 0;
	int pos = 0;
	int palabra_Encontrada = texto.find(dato);
	while (palabra_Encontrada != -1){
		total++;
		pos =  palabra_Encontrada;
		palabra_Encontrada = texto.find(dato,pos+1);
	}
	return total;
}
