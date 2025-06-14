#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*18. Un bazar de venta de electrodom�sticos, tiene diferentes promociones seg�n la forma de
	pago, para los siguientes productos seleccionados: 1. Calefactores, 2. Radiadores, 3.
	Caloventores, 4. Cualquier otro producto del local.
	Para determinar el monto a cobrar a un cliente, se ingresan los siguientes datos: Nombre y
	apellido del cliente, DNI, Rubro producto (1, 2, 3 o 4), Cantidad comprada, Precio unitario,
	Forma de Pago (�C�: Contado � �D�: D�bito � �T�: Tarjeta de Cr�dito).
	Si el pago es al Contado, al Subtotal (precio x cantidad), se le realiza:
	- un descuento del 15% si el rubro del producto es 1, 2 o 3.
	- ning�n recargo o descuento si el rubro del producto es 4.
	Si el pago es con D�bito, el Subtotal, no lleva descuento ni recargo sin importar el rubro del
	producto comprado.
	Si el pago es con Tarjeta de Cr�dito se debe ingresar adem�s, la siguiente informaci�n: Tipo
	Tarjeta (�Visa�, �Mastercard� o �Naranja�), Banco (�BERSA�, �FRANCES�, �GALICIA� u
	�OTROS�), cantidad de cuotas (1, 3, 6, 12 o 18). Al Subtotal, se le realiza un recargo del 20%.
	Pero, si la Tarjeta es �VISA� y el Banco �BERSA� debe, al Subtotal ya calculado, descontarle
	un 15%.
	Efectuar todos los c�lculos necesarios para informar seg�n el siguiente detalle:
	DNI: xxxxxxxxxx CLIENTE: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	RUBRO DEL PRODUCTO: x CANTIDAD: xx
	PRECIO UNITARIO: $ xxxxxxxx FORMA DE PAGO: x
	SUBTOTAL: $ xxxxxxxxx
	DESCUENTOS: $ xxxx
	RECARGOS: $ xxxxxxxx
	DESCUENTO TARJETA CR�DITO: $ xxxx
	RECARGO TARJETA CR�DITO: $ xxxxxxxx
	TOTAL A PAGAR: $ xxxxxxx
	Observaciones: En FORMA DE PAGO se muestra la letra identificatoria del mismo. En todos
	los descuentos y recargos, debe figurar 0 si no corresponde efectuarlo.*/
	string nya,fdp,tarjeta,banco;
	int dni,rubro,cantc,cuotas;
	float preciou,dto,recargo=0,dtot=0,recargot=0;
	cout<<"Ingrese nombre y apellido"<<endl;
	getline(cin,nya);
	cout<<"Ingrese DNI del cliente"<<endl;
	cin>>dni;
	cout<<"Ingrese rubro del producto a comprar (1. Calefactores, 2. Radiadores, 3.Caloventores, 4. Cualquier otro producto del local.)"<<endl;
	cin>>rubro;
	cout<<"Ingrese la cantidad comprada"<<endl;
	cin>>cantc;
	cout<<"Ingrese precio unitario"<<endl;
	cin>>preciou;
	cin.ignore();
	cout<<"Ingrese forma de pago C Contado  D D�bito  T Tarjeta de Credito"<<endl;
	getline(cin,fdp);
	float subt=(preciou*cantc);
	if ((rubro != 4) && (fdp=="C"))
	{
	dto=(subt*0.15);
	}
	else dto=0;
	if (fdp=="T")
	{
	cout<<"Ingrese tipo de tarjeta Visa, Mastercard o Naranja."<<endl;
	getline(cin,tarjeta);
	cout<<"Ingrese el banco BERSA, FRANCES, GALICIA u OTROS."<<endl;
	getline(cin,banco);
	cout<<"Ingrese la cantidad de cuotas: 1, 3, 6, 12 o 18 "<<endl;
	cin>>cuotas;
	}
	if ((tarjeta=="Visa") && (banco=="BERSA"))
	{
	dtot=(subt*0.15);
	recargot=0;
	}
	if ((tarjeta !="Visa") && (fdp=="T"))
	{
	recargot=(subt*0.2); 
	dtot=0;
	}
	cout<<"DNI: "<<dni<<"       "<<"Cliente: "<<nya<<endl;
	cout<<"Rubro del producto: "<<rubro<<"      "<<"Cantidad: "<<cantc<<endl;
	cout<<"Precio Unitario: $"<<preciou<<"      "<<"Forma de pago: "<<fdp<<endl;
	cout<<"Subtotal: $"<<subt<<endl;
	cout<<"Descuentos: $"<<dto<<endl;
	cout<<"Recargos: $"<<recargo<<endl;
	cout<<"Recargos Tarjetas de cr�dito: $"<<recargot<<endl;
	cout<<"Descuentos Tarjetas de cr�dito: $"<<dtot<<endl;
	cout<<"Total a pagar: $"<<subt-dtot+recargot-dto+recargo;
	
	
	
	
	
	
	return 0;
}

