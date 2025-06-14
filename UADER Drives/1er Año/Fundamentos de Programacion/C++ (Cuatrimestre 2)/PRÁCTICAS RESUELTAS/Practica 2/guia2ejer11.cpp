#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*Un club cobra una cuota mensual a sus socios, a quienes divide en Activo, Familiar y
	Cadete. El socio activo paga el valor base, el familiar un 50 % más y el cadete paga un 20%
	menos. Se ingresa como primer dato el valor base de la cuota.
	Además se ingresa el nombre del club y los datos de un socio: número de socio, nombre y
	apellido y tipo ( ´activo ´,  ´familiar ´,  ´cadete ´).
	Informar lo que debe pagar el socio ingresado, con el siguiente formato:
	CLUB:..........................................
	NRO. DE SOCIO:.......................... NOMBRE DEL SOCIO:...................................
	TIPO DE SOCIO:........................... TOTAL APAGAR: $.....................*/
	string nya,nombreclub,tipo;
	int nrosocio;
	float cuota,cuotat;
	cout<<"Ingrese el valor base de la cuota"<<endl;
	cin>>cuota;
	cin.ignore();
	cout<< "Ingrese nombre del club"<<endl;
	getline(cin,nombreclub);
	cout<<"Ingrese número de socio y luego nombre y apellido"<<endl;
	cin>>nrosocio;
	cin.ignore();
	getline(cin,nya);
	cout<<"Ingrese tipo (activo, familiar o cadete)"<<endl;
	getline(cin,tipo);
	if (tipo=="familiar")
	{
	cuotat=(cuota*0.5);
	}
	else if (tipo=="cadete")
	{
	cuotat=(cuota*0.2);
	}
	else if (tipo=="activo")
	{
	cuotat=0;
	}
	cout<<"CLUB: "<<nombreclub<<endl;
	cout<<"Nro socio:: "<<nrosocio<<"         "<<"Nombre del socio: "<<nya<<endl;
	cout<<"Tipo de socio: "<<tipo<<"           "<<"Total a Pagar: $"<< cuotat+cuota<<endl;
	return 0;
}

