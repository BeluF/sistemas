#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float num1,num2;
	cout<<"Ingrese un número y luego otro"<<endl;
	cin>>num1>>num2;
	if (num1>num2)
		cout<<"El número "<<num1<<" es mayor que el número "<<num2<<endl;
	else cout<<"El número "<<num2<<" es mayor que el número "<<num1<<endl;
	return 0;
}

