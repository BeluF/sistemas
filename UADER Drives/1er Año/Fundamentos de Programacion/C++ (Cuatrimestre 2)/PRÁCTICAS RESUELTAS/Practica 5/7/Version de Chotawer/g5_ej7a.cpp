#include <iostream>
#include <string>

using namespace std;

// Ejercicio 7a, guia 5.
int main(void){
	string vector[] = {"uno","dos","tres","cuatro","cinco","seis","siete"};
	int i; const int N = 7;
	
	// Mostrar vector normalmente
	for (i = 0; i < N; i++)
		cout << vector[i] << " ";
		
	cout << endl;	
		
	//Mostrar vector ordenado
	for (i = 6; i >= 0; i--)
		cout << vector[i] << " ";
	
	return 0;
}

