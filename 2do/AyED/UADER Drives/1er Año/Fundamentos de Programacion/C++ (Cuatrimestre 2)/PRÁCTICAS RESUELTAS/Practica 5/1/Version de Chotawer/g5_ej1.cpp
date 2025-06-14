#include <iostream>

using namespace std;

// Ejercicio 1 de la guia 5 (Arrays)
int main(void)
{
	// Consigna a
	int numeros[200];
	
	// Consigna b
	int alumnos;	 // cantidad de alumnos
	
	cout << "Ingrese cantidad de alumnos que posee la comision: ";
	cin >> alumnos;
	
	for (int i = 0; i < alumnos; i++) 
		cin >> numeros[i];
	
	// Consigna c
	int pos; 		//posición que se desea buscar en el array
	cin >> pos;
	while ((pos > 0) && ((pos-1) < alumnos))
	{
		cout << "Edad: " << setw(3) << numeros[pos-1];	
		cin >> pos;
	}
	
	return 0;	
}
