#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*11) Un jardín de infantes tiene N alumnos y desea hacer un control de los mismos. Por cada
	alumno se ingresa Nombre y Apellido, Peso y Altura. Informar cuál es el alumno más alto y
	cuál es el de menor peso. El Valor N se ingresa como primer dato.*/
	float peso,altura;
	string nya,nyamayor,nyamenor;
	int cantal,c=0,mayor=0,menor=999;
	cout<<"Ingrese la cantidad de alumnos"<<endl;
	cin>>cantal;
	cin.ignore();
	do 
	{
		cout<<"Ingrese nombre y apellido del alumno"<<endl;
		getline(cin,nya);
		cout<<"Ingrese el peso(en kg) y luego la altura (en cm)"<<endl;
		cin>>peso>>altura;
		cin.ignore();
		c++;
		if (altura>mayor)
		{
			mayor=altura;
			nyamayor=nya;
		}
		if (peso<menor)
		{
			menor=peso;
			nyamenor=nya;
		}
	} while(c!=cantal);
	cout<<"EL alumno mas alto es: "<<nyamayor<<endl;
	cout<<"El alumno con el menor peso es: "<<nyamenor<<endl;
	return 0;
}

