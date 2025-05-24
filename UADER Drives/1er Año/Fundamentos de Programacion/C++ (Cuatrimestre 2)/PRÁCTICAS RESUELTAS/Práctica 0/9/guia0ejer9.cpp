#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Se desea contar con un algoritmo que, ingresado el sueldo neto de una persona,
		calcule su aporte jubilatorio (16% del sueldo neto) y el sueldo líquido (sueldo neto – aporte jubilatorio).*/
	float sueldo,sueldoliq,aporte;
	cout<<"Ingrese su sueldo neto"<<endl;
	cin>>sueldo;
	aporte=sueldo*0.16;
	sueldoliq=sueldo-aporte;
	cout<<"Su aporte jubilatorio va a ser de: $"<<aporte<<", Dejando su sueldo líquido en: $"<<sueldoliq;
	
	return 0;
}

