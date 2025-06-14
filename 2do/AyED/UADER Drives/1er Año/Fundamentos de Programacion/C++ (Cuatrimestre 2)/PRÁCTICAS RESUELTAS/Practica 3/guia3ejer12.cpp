#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*12) Escriba un programa que solicite números al usuario hasta que se hayan introducido 10
	números o la suma de todos los números leídos sea mayor que 100. A continuación mostrar
	un mensaje indicando qué condición se ha cumplido (es decir, si se han introducido 10
	números o si su suma es mayor que 100).*/
	float num,sumanum=0;
	int c=0;
	while((sumanum<100) && (c<10) )
	{
		cout<<"Ingrese un número"<<endl;
		cin>>num;
		sumanum=sumanum+num;
		c++;
		
	}
	if (sumanum>=100)
		cout<<"La suma de los números ha superado a 100"<<endl;
	else cout<<"Se han introducido mas de 10 números"<<endl;
	return 0;
}

