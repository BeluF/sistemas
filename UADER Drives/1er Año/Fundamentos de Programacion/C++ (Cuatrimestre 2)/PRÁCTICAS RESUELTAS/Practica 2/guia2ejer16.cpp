#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*16. Una fábrica de alfajores que elabora los mismos de Dulce de Leche, Frutales o Mouse, y
	los vende envasados en cajas de 6, 12 y 24 unidades.
	Los precios unitarios de cada gusto se leen al inicio, y cada caja solo incluye un solo gusto.
	Para la venta por cajas rigen los siguientes precios: la caja de 6 alfajores, se los cobra al
	precio del alfajor que contiene por la cantidad de unidades, según el gusto, la caja de 12 tiene
	un 10 % de descuento sobre el valor del alfajor que contiene, la caja de 24 tiene el 20 % de
	descuento.
	Si el cliente solicitó que se le prepare un paquete especial para regalo, se cobra $ 250,00.-
	por el servicio. Además a cada venta se le debe adicionar el IVA (21%).
	Se conocen como datos de una venta: Cliente, gusto (“Dulce de Leche”, “Frutal” o “Mouse”),
	tipo de caja (6, 12 o 24), y si es para regalo(V o F).
	Informar según el siguiente esquema:
	Cliente: xxxxxxxx Tipo de caja: xx Gusto: xxxxxxxxxxxxxx
	SubTotal: xxxx Recargo Regalo: xxxx
	Iva 21%: xxxx
	Total: xxxx
	Obs: en el caso de no corresponder el recargo debe ir en 0 (cero).*/
	float ddl,frutal,mouse,auxp,subt;
	string gusto,nya,regalo;
	int caja,recargor;
	cout<<"Ingrese precio unitario de cada gusto"<<endl;
	cout<<"Dulce de leche"<<endl;
	cin>>ddl;
	cout<<"Frutal"<<endl;
	cin>>frutal;
	cout<<"Mouse"<<endl;
	cin>>mouse;
	cin.ignore();
	cout<<"Ingrese nombre del cliente"<<endl;
	getline(cin,nya);
	cout<<"Ingrese el gusto de alfajor(Dulce de Leche, Frutal o Mouse)"<<endl;
	getline(cin,gusto);
	cout<<"Ingrese el tipo de caja (6,12 o 24)"<<endl;
	cin>>caja;
	cin.ignore();
	cout<<"¿El pedido es para regalo? (V o F)"<<endl;
	getline(cin,regalo);
	if (gusto=="Dulce de Leche")
	{
	auxp=(caja*ddl);
	}
	else if (gusto=="Frutal")
	{
	auxp=(caja*frutal);
	}
	else auxp=(caja*mouse);
	switch (caja)
	{
	case 6: subt=(auxp*1);
	break;
	case 12: subt= (auxp*0.9);
	break;
	case 24: subt= (auxp*0.8);
	break;
	}
	if (regalo=="V")
	recargor=250;
	else recargor=0;
	float iva= ((subt+recargor)*0.21);
	cout<<"Cliente: "<<nya<<"        "<<"Tipo de Caja: "<<caja<<"         "<<"Gusto: "<<gusto<<endl;
	cout<<"Subtotal: $"<<subt<<"       "<<"Recargo regalo: $"<<recargor<<endl;
	cout<<"IVA 21%: $"<<iva<<endl;
	cout<<"Total: $"<<subt+recargor+iva;
	return 0;
}

