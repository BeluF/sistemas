#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	/*10) Generar n�meros al azar entre 0 y 999. Detener la generaci�n de n�meros cuando se
	haya generado 2 veces consecutivas un n�mero ingresado. Informar la cantidad de n�meros
	que fueron generados al momento de la detenci�n.*/
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

