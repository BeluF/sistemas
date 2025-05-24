#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	/*Una distribuidora de zapatos vende distintos modelos de zapatos los cuales se pueden
	pagar de la siguiente forma: 1: contado, 2: 6 cuotas, 3: 12 cuotas.
	Si el pago es al contado se hace un 10% de descuento sobre el total.
	Si el pago es en 12 cuotas se hace un recargo del 23% sobre el total y si es en 6 cuotas no se
	hace ningún descuento o recargo.
	Se ingresa para ello, el nombre del cliente, el precio de lista del zapato, la cantidad y la forma
	de pago (1, 2, 3). El nombre de la distribuidora es el primer dato a ingresar.
	Se pide Informar lo siguiente:
	• El Nombre de la distribuidora y el Nombre del cliente.
	• La cantidad de zapatos vendidos y el precio de lista.
	• El texto correspondiente a la forma de pago elegida.
	• El recargo o Descuento si correspondiera.
	• Si el pago es en cuotas el monto de la cuota.
	• El total a pagar*/
	int fdp,cantidad;
	string nombred, nya, text;
	float preciol,dto=0, aumento=0,cuota;
	cout<<"Ingrese nombre de la distribuidora"<<endl;
	getline(cin,nombred);
	cout<<"Ingrese el nombre del cliente"<<endl;
	getline(cin,nya);
	cout<<"Ingrese el precio de lista del zapato y luego la cantidad"<<endl;
	cin>>preciol>>cantidad;
	cout<<"Ingrese forma de pago (1: contado, 2: 6 cuotas, 3: 12 cuotas)"<<endl;
	cin>>fdp;
	float aux= (preciol * cantidad);
	switch (fdp)
	{
	case 1: dto=(aux*0.10), text="Contado";
	break;
	case 2: text="6 cuotas";
	case 3: aumento= (aux*0.23), text="12 cuotas";
	break;
	}
	cout<<"Nombre de la distribuidora: "<<nombred<<endl;
	cout<<"Cantidad de zapatos vendidos: "<<cantidad<<"        "<<"Precio de lista: $"<<preciol<<endl;
	cout<<"Forma de pago: "<<text<<endl;
	if (text=="Contado")
	{
	cout<<"El Descuento es de: $"<<dto<<endl;
	}
	else if (text=="12 cuotas")
	{
	cout<<"El recargo es de: $"<<aumento<<endl;
	cuota= ((aumento+aux)/12);
	}
	else cuota=(aux/6);
	if (text != "Contado")
	cout<<"El valor de las cuotas es de: $"<<cuota<<endl;
	cout<<"El total a pagar es de: $"<<aux-dto+aumento<<endl;
	
	
	return 0;
}

