#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*4) Realice un algoritmo que solicite el ingreso de 2 n�meros A y B. Donde A debe ser menor
	que B. Luego liste los n�meros comprendidos entre A y B, incluy�ndolos.*/
	int a,b,i;
	cout<<"Ingrese dos numeros enteros A y B, donde A tiene que ser menor que B"<<endl;
	cin>>a>>b;
	i=a;
	do
	{
		cout<<i<<endl;
		(i++);
	}
	while (i<=b);
	return 0;
}

