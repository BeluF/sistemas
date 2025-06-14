#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*¿Cuánto dinero hay en una Caja de Seguridad?
	Para ello se ingresa la cantidad de billetes que hay de $5, $10, $20, $50 y $100
	respectivamente. Informar el total existente.*/
	int b5,b10,b20,b50,b100,total;
	cout<<"Ingrese cuantos billetes hay de $5"<<endl;
	cin>>b5;
	cout<<"Ingrese cuantos billetes hay de $10"<<endl;
	cin>>b10;
	cout<<"Ingrese cuantos billetes hay de $20"<<endl;
	cin>>b20;
	cout<<"Ingrese cuantos billetes hay de $50"<<endl;
	cin>>b50;
	cout<<"Ingrese cuantos billetes hay de $100"<<endl;
	cin>>b100;
	total=(5*b5)+(10*b10)+(20*b20)+(50*b50)+(100*b100);
	cout<<"El total de la caja fuerte es de: $"<<total;
	return 0;
}

