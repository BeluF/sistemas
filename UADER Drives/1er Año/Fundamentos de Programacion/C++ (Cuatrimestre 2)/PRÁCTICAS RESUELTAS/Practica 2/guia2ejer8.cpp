#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	/*Determinar si un a�o ingresado por el usuario es bisiesto. Un a�o es bisiesto si m�ltiplo de
		4, a menos que sea m�ltiplo de 100. Sin embargo, si un a�o es m�ltiplo de 100 y adem�s es
		m�ltiplo de 400, tambi�n resulta bisiesto.*/
	float anio;
	cout<<"Ingrese a�o"<<endl;
	cin>>anio;
	if ((anio/2== trunc(anio/2) && anio/100 != trunc(anio/100)) || (anio/100 == trunc(anio/100) && anio/400 == trunc(anio/400)))
		cout<<"El a�o es bisiesto";
	else cout<<"El a�o no es bisiesto";
	return 0;
}

