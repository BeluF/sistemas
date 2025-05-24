#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*Una inmobiliaria que alquila departamentos ha divido la ciudad en tres zonas:
	1 - centro
	2 - residencial
	3 - barrio
	El importe mensual a pagar por el inquilino corresponde al precio base del departamento más
	el importe correspondiente a impuestos y comisiones, los cuales dependen de la zona de
	ubicación del inmueble, de acuerdo a las siguientes pautas:
	Zona Impuestos y comisiones
	1 15 % sobre el precio del alquiler
	2 10 % “
	3 8 % “
	Se desea calcular el monto total del alquiler de un departamento y para ello se ingresa el
	precio del alquiler y la zona donde se encuentra la vivienda (1, 2 ó 3).
	Informar el precio base del alquiler, el monto de impuestos y comisiones y el total a pagar por
	el inquilino con leyendas indicativas.*/
	int zona;
	float alquiler,impuesto;
	cout<<"Ingrese precio del alquiler"<<endl;
	cin>>alquiler;
	cout<<"Ingrese zona de la ciudad (1-centro, 2-residencial, 3-barrio)"<<endl;
	cin>>zona;
	switch (zona)
	{
		case 1: impuesto=(alquiler*0.15);
		break;
		case 2: impuesto=(alquiler*0.10);
		break;
		case 3: impuesto=(alquiler*0.08);
		break;
	}
	cout<<"Precio base: $"<<alquiler<<endl<<"Impuestos y comisiones: $"<<impuesto<<endl<<"Total a pagar: $"<<alquiler+impuesto;
	return 0;
}

