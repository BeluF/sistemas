//numero par e impar con punteros
#include <iostream>
#include <cstdlib>

using namespace std;

bool par (int *nu);

int main(){
	int n;
	cout<<"Digite un numero: ";
	cin>>n;
	if (par(&n)){ cout<<"El número es par";
	}
	else cout<<"El número es impar";
	return 0;	
}

bool par(int *nu){
	bool paridad=(*nu%2==0);
	return paridad;
}

