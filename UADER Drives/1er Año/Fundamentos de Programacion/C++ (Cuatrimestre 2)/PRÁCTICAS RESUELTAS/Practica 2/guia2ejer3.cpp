#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
	float num;
	cout<<"Ingrese un n�mero entero"<<endl;
	cin>>num;
	if (num>0)
	{
		cout<<"El n�mero ingresado es positivo"<<endl;
	}
	else if (num<0)
	{
		cout<<"El n�mero ingresado es negativo"<<endl;
		cout<<"El n�mero es 0"<<endl;
	}
	if (num/2==trunc(num/2))
		cout<<"El n�mero ingresado es par"<<endl;
		else cout<<"El n�mero es impar"<<endl;
	if ((num/5==trunc(num/5)) &&  (num/3==trunc(num/3)))
		cout<<"El numero ingresado es multiplo de 3 y 5"<<endl;
	
	
	return 0;
}

