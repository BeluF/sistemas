#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Realice un algoritmo que solicite el ingreso de un número (entero positivo) e informe su
	tabla de multiplicar (del 1 al 10).*/
	int num,i=1;
	cout<<"Ingrese un número entero y positivo"<<endl;
	cin>>num;
	do
	{
		cout<<i*num<<endl;
		(i++);
	}
	while (i<11);
	return 0;
}

