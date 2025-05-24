#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	/*10) Generar números al azar entre 0 y 999. Detener la generación de números cuando se
	haya generado 2 veces consecutivas un número ingresado. Informar la cantidad de números
	que fueron generados al momento de la detención.*/
	int c=0;
	float n1,ant;
	n1=rand()%1000;
	
	do 
	{
		ant=n1;
		n1=rand()%1000;
		c++;
		cout<<n1<<endl;
	} while(n1!=ant);
	cout<<"Cantidad de numeros generados: "<<c*2;
	return 0;
}

