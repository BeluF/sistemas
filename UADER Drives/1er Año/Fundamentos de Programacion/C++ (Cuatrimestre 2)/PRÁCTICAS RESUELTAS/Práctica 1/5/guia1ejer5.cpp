#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float presupuesto;
	cout<<"Ingrese el presupuesto"<<endl;
	cin>>presupuesto;
	float gineco=presupuesto*0.40,traumato=presupuesto*0.30,pediatria=presupuesto*0.30;
	cout<<"EL presupuesto a repartir es de: "<<endl<<"Ginecologia: $"<<gineco<<endl<<"Traumato: $"<<traumato<<endl<<"pediatria: $"<<pediatria<<endl;
	return 0;
}

