#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Calcular el n�mero de pulsaciones que una persona debe tener por cada 10
	segundos de ejercicio, si la f�rmula es:
	num. pulsaciones = (220 - edad)/10*/
	int edad,pulsaciones;
	cout<<"Ingrese su edad"<<endl;
	cin>>edad;
	pulsaciones=(220-edad)/10;
	cout<<"Sus pulsaciones por cada 10 segundos de ejercicio deber�a ser: "<<pulsaciones;
	return 0;
}

