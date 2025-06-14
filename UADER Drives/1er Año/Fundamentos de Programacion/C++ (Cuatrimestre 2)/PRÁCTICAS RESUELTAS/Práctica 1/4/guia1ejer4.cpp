#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int bolestudi,boltrabaja;
	float preciobol,totbol,totestudi,tottrabaja;
	cout<<"Ingrese el precio del boleto"<<endl;
	cin>>preciobol;
	cout<<"Ingrese la cantidad de boletos de estudiantes vendidos y luego la cantidad de boletos de trabajador"<<endl;
	cin>>bolestudi>>boltrabaja;
	totestudi=bolestudi*preciobol;
	tottrabaja=boltrabaja*preciobol;
	totbol=tottrabaja+totestudi;
	cout<<"La cantidad vendida de boletos de estudiantes es: "<<bolestudi<<endl;
	cout<<"La cantidad vendida de boletos de trabajador es: "<<boltrabaja<<endl;
	cout<<"El total recaudado es: $"<<totbol<<endl;
	return 0;
}

