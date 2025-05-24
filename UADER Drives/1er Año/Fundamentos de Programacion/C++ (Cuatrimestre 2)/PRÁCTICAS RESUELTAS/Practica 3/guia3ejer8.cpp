#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*8) Realice un algoritmo que solicite el ingreso de nombres. Finalizar el ingreso cuando se
	ingrese un nombre igual al último ingresado. Informar cuantos nombres se ingresaron.*/
	string nya,ant;
	int c=1;
	cout<<"Ingrese nombre"<<endl;
	cin>>nya;
	do
	{
		ant=nya;
		cout<<"Ingrese nombre"<<endl;
		cin>>nya;
		c++;
	}
	while  (nya!=ant);
	cout<<"La cantidad de nombres ingresados fue de: "<<c;
	return 0;
}

