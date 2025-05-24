#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	/*Determinar si un año ingresado por el usuario es bisiesto. Un año es bisiesto si múltiplo de
		4, a menos que sea múltiplo de 100. Sin embargo, si un año es múltiplo de 100 y además es
		múltiplo de 400, también resulta bisiesto.*/
	float anio;
	cout<<"Ingrese año"<<endl;
	cin>>anio;
	if ((anio/2== trunc(anio/2) && anio/100 != trunc(anio/100)) || (anio/100 == trunc(anio/100) && anio/400 == trunc(anio/400)))
		cout<<"El año es bisiesto";
	else cout<<"El año no es bisiesto";
	return 0;
}

