#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Calcular la media de X cantidad de n�meros, para lo cual se ingresar�n valores enteros
	reiteradamente, siendo el fin de la carga un valor igual a 0. Informar el valor medio y la
	cantidad de datos ingresados.*/
	int c=0;
	float num, media=0;
	do
	{
		cout<<"Ingrese n�mero"<<endl;
		cin>>num;
		media=media+num;
		c++;
	} while(num!=0);
	cout<<"Cantidad de datos ingresados: "<<c<<endl;
	cout<<"Valor medio: "<<media/c;
	
	
	return 0;
}

