#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Se desea contar con un algoritmo que calcule el ancho de un televisor teniendo
		como dato la cantidad de pulgadas del TV y el alto de la pantalla (expresado en cm). Informar el ancho del TV expresado en cm.*/
	float pulgadas,altura,ancho;
	cout<<"Ingrese la cantidad de pulgadas y luego la altura del TV"<<endl;
	cin>>pulgadas>>altura; //no hace falta preguntar por la altura pero el ejercicio lo pide
	ancho= pulgadas*2.21;
	cout<<"El ancho del TV es de: "<<ancho<<" cm";
	
	return 0;
}

