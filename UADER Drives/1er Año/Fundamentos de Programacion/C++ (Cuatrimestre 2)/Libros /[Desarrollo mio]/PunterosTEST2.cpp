//numero par e impar con punteros
#include <iostream>
#include <cstdlib>

using namespace std;

bool par (int &nu);

int main(){
	int n;
	cout<<"Digite un numero: ";
	cin>>n;
	if (par(n)){ cout<<"El n�mero es par";
	}
	else cout<<"El n�mero es impar";
	
	//test para saber si el numero se increment� al salir de la funci�n
	cout<<endl<<"El numero salido de la funci�n vale: "<< n;
	return 0;	
}

bool par(int &nu){
	bool paridad=(nu%2==0);
	cout<<"El numero que llego es "<<nu<<endl;
	//Aqu� pruebo si al incrementar "nu" en la funci�n, tambi�n se incrementa en el programa principal.
	nu++;
	return paridad;
}

/*En caso de no hacer el pasaje de valores mediante referencia (usando punteros, &) el valor de "n" no se hubiese incrementado nunca en el programa principal. */

