#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*YPF Serviclub otorga puntos canjeables por premios por las cargas de combustibles en
	sus estaciones de servicio. Los tipos de combustibles están codificados:
	1) INFINIA
	Apunte elaborado por la cátedra Fundamentos de Programación – Sede Oro Verde Pág. Nro. 4
	
	2) INFINIA DIESEL
	3) SÚPER
	4) ULTRADIESEL
	5) DIESEL 500
	Los puntos se asignan de acuerdo a la siguiente tabla:
	INFINIA 80 puntos $ 1.000,00
	INFINIA DIESEL 75 puntos $ 1.000,00
	SÚPER 40 puntos $ 1.000,00.-
	ULTRADIESEL 40 puntos $ 1.000,00.-
	DIESEL 500 35 puntos $ 1.000,00.-
	Pero, además, si la carga supera los $3.500 se duplican los puntos obtenidos, sin importar el
	tipo de combustible cargado. Se ingresan los datos de una carga: el importe cargado y el
	código del combustible. Informar los puntos obtenidos por dicha carga.*/
	int codigo;
	float importe,puntos;
	cout<<"Ingrese el codigo del combustible que cargó (1 INFINIA,	2) INFINIA DIESEL,3) SuPER,4) ULTRADIESEL,5) DIESEL 500)"<<endl;
	cin>>codigo;
	cout<<"Ingrese el importe cargado"<<endl;
	cin>>importe;
	switch (codigo)
	{
	case 1: puntos= (importe*80)/1000;
	break;
	case 2: puntos= (importe*75)/1000;
	break;
	case 3: puntos= (importe*40)/1000;
	break;
	case 4: puntos= (importe*40)/1000;
	break;
	case 5: puntos= (importe*35)/1000;
	}
	if (importe>3500)
	puntos=puntos*2;
	
	cout<<"La cantidad de puntos obtenidos de la compra es de: "<<puntos;
	return 0;
}

