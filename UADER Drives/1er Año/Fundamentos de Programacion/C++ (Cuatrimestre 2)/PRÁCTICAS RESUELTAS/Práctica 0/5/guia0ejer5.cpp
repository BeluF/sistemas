#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*5) Calcule el porcentaje de hombres y mujeres que hay en una poblaci�n de la cual
	se conoce la cantidad de mujeres y el total general.*/
	int mujeres,totalgral,porcentajem,porcentajeh;
	cout<<"Ingrese la poblaci�n total"<<endl;
	cin>>totalgral;
	cout<<"Ingrese la cantidad de mujeres"<<endl;
	cin>>mujeres;
	porcentajem=(mujeres*100)/totalgral;
	porcentajeh=100-porcentajem;
	cout<<"El porcentaje de hombres es de: "<<porcentajeh<<"%,y el de mujeres de: "<<porcentajem<<"%";
	
	return 0;
}

