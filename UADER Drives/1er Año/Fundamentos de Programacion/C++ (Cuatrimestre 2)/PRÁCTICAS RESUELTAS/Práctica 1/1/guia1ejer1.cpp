#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float peso,dolar,rial,euro;
	cout<<"Ingrese la cantidad de pesos"<<endl;
	cin>>peso;
	cout<<"Ingrese cotización en dolar,euro y reales"<<endl;
	cin>>dolar>>euro>>rial;
	cout<<"$"<<peso<<" equivalen a: "<<peso/dolar<<" dolar/es, a: "<<peso/euro<<" euro/s y a: "<<peso/rial<<" real/es";
	return 0;
}

