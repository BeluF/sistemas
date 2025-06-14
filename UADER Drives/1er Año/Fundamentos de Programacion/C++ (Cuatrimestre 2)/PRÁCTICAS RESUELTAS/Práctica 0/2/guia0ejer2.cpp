#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	//Determinar e informar, el INDICE DE MASA CORPORAL (IMC) de una persona.
	//	Para ello se conoce: el nombre de la persona, su peso (en kgs) y su estatura (en metros).
	//Aplicar la siguiente fórmula: 
	float kg,altura;
	char nya[20];
	cout<<"Ingrese su nombre"<<endl;
	cin>>nya;
	cout<<"Ingrese peso (en kg) y luego altura (en metros)"<<endl;
	cin>>kg>>altura;
	float imc=kg/(altura*altura);
	cout<<"El imc de: "<<nya<< "es de: "<<imc;
	return 0;
}

