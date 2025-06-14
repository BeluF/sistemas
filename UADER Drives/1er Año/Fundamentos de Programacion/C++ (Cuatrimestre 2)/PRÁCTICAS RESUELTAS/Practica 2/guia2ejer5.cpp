#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	/*Determinar e informar, el INDICE DE MASA CORPORAL (IMC) de una persona. Para ello
	se conoce: su peso (en kgs) y su estatura (en metros).
	Aplicar la siguiente fórmula:
	Informar el resultado de acuerdo a la siguiente tabla:
	[0..18,5) – Debajo del normal
	[18,5..25) – Normal
	[25..30) – Sobrepeso
	[30 y más] - Obesidad*/
	float peso,altura;
	cout<<"Ingrese su peso (en kgs) y luego su altura (en metros)"<<endl;
	cin>>peso>>altura;
	float imc=trunc(peso/(altura*altura));
	if (imc < 18.5)
	
		cout<<"Usted esta debajo del peso normal"<<endl;
	
	else if ((imc >= 18.5) && (imc < 25))
	{
		cout<<"Usted tiene peso normal"<<endl;
	}
	else if ((imc >= 25) && (imc < 30))
	{
			cout<<"Usted tiene sobrepeso"<<endl;
	}
	else cout<<"Usted tiene obesidad"<<endl;
	return 0;
}

