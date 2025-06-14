#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Una empresa paga a sus operarios semanalmente, de acuerdo con la cantidad de horas
	trabajadas, a razón de un monto por hora si trabajan hasta 40 hs. y un 50% mas de ese
	monto por todas las horas que pasan de 40. Para calcular el salario a un empleado, se
	ingresa el total de horas trabajadas. Informar salario a cobrar por el trabajador. El monto por hora
	se ingresa como primer dato.*/
	float platahora,horast;
	cout<<"Ingrese el monto que se paga por hora"<<endl;
	cin>>platahora;
	cout<<"Ingrese las horas trabajadas esta semana"<<endl;
	cin>>horast;
	
	if (horast>40){
		
		float pagaextra=((horast-40)*(150*platahora/100)); float paga40=(40*platahora);
		cout<<"El salario a cobrar del trabajador es de: $"<<pagaextra+paga40;
	}
	else cout<<"El salario a cobrar del trabajador es de: $"<<platahora*horast;
	
	
	return 0;
}

