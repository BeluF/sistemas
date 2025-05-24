#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
	float num;
	cout<<"Ingrese un número entero"<<endl;
	cin>>num;
	if (num>0)
	{
		cout<<"El número ingresado es positivo"<<endl;
	}
	else if (num<0)
	{
		cout<<"El número ingresado es negativo"<<endl;
		cout<<"El número es 0"<<endl;
	}
	if (num/2==trunc(num/2))
		cout<<"El número ingresado es par"<<endl;
		else cout<<"El número es impar"<<endl;
	if ((num/5==trunc(num/5)) &&  (num/3==trunc(num/3)))
		cout<<"El numero ingresado es multiplo de 3 y 5"<<endl;
	
	
	return 0;
}

