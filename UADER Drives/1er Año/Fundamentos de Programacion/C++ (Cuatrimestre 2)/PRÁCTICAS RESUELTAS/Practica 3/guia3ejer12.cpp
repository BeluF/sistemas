#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*12) Escriba un programa que solicite n�meros al usuario hasta que se hayan introducido 10
	n�meros o la suma de todos los n�meros le�dos sea mayor que 100. A continuaci�n mostrar
	un mensaje indicando qu� condici�n se ha cumplido (es decir, si se han introducido 10
	n�meros o si su suma es mayor que 100).*/
	float num,sumanum=0;
	int c=0;
	while((sumanum<100) && (c<10) )
	{
		cout<<"Ingrese un n�mero"<<endl;
		cin>>num;
		sumanum=sumanum+num;
		c++;
		
	}
	if (sumanum>=100)
		cout<<"La suma de los n�meros ha superado a 100"<<endl;
	else cout<<"Se han introducido mas de 10 n�meros"<<endl;
	return 0;
}

