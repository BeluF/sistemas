//numero par e impar con punteros
#include <iostream>
#include <cstdlib>

using namespace std;

bool par (int &nu);

int main(){
	int n;
	cout<<"Digite un numero: ";
	cin>>n;
	if (par(n)){ cout<<"El número es par";
	}
	else cout<<"El número es impar";
	
	//test para saber si el numero se incrementó al salir de la función
	cout<<endl<<"El numero salido de la función vale: "<< n;
	return 0;	
}

bool par(int &nu){
	bool paridad=(nu%2==0);
	cout<<"El numero que llego es "<<nu<<endl;
	//Aquí pruebo si al incrementar "nu" en la función, también se incrementa en el programa principal.
	nu++;
	return paridad;
}

/*En caso de no hacer el pasaje de valores mediante referencia (usando punteros, &) el valor de "n" no se hubiese incrementado nunca en el programa principal. */

