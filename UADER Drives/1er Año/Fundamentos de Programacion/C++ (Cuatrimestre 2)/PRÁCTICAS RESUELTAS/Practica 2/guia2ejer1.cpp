#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float num1,num2;
	cout<<"Ingrese un n�mero y luego otro"<<endl;
	cin>>num1>>num2;
	if (num1>num2)
		cout<<"El n�mero "<<num1<<" es mayor que el n�mero "<<num2<<endl;
	else cout<<"El n�mero "<<num2<<" es mayor que el n�mero "<<num1<<endl;
	return 0;
}

