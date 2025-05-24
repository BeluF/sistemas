#include <iostream>
#include <iomanip>
using namespace std;

//	11. Generar una matriz de N x N elementos con números al azar. La matriz se completa
//	generando al azar el valor del elemento y los valores de fila y columna. Solo se deben asignar
//	las posiciones que no han sido previamente asignadas. La aplicación debe terminar de
//	generar valores cuando toda la matriz haya sido llenada.
//	Además muestre en otra matriz la cantidad de veces que se generaron valores para cada
//	celda de la matriz.
//	Informar la matriz visualizándola en forma correcta en la pantalla.

/// Resolucion by el jefe

int main(int argc, char *argv[]) {
	const int N=999;
	int matriz[N][N]={0}, n, cont=0;
	int matriz2[N][N]={0};
	cout<< "Ingrese valor de N: "<<endl;
	cin>> n;
	
	while (cont < (n*n)){
		int i=rand()%n;
		int j=rand()%n;
		if (matriz[i][j]==0){
			matriz[i][j]=rand()%999+1;
			cont++;
			matriz2[i][j]++;
		} else matriz2[i][j]++;
	}
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++)
			cout<<setw(4)<< matriz[i][j];
		cout<<endl;
	}
	cout<<"------------------------[Matriz de usos]----------------------------"<<endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++)
			cout<<setw(4)<< matriz2[i][j];
			cout<<endl;
	}
	
	return 0;
}

