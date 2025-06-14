#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*13) Se ingresan al inicio los precios unitarios de los cinco artículos que comercializa un
	comercio (codificados de 1 a 5). Por cada venta que se realiza en el comercio se ingresa:
	Nombre del cliente, cantidad comprada y código de artículo. Un nombre de cliente “ZZZ”
	indica el fin de datos.
	Informar el monto total de ventas, la venta total de cada artículo, la cantidad de ventas
	realizadas y el nombre del cliente cuyo monto de venta sea el mayor.*/
	string nya,nyamayor;
	int cant,cod,cantventas=0;
	float p1,p2,p3,p4,p5;
	cout<<"Ingrese los precios de los productos"<<endl;
	cout<<"Producto 1: "<<endl;
	cin>>p1;
	cout<<"Producto 2: "<<endl;
	cin>>p2;
	cout<<"Producto 3: "<<endl;
	cin>>p3;
	cout<<"Producto 4: "<<endl;
	cin>>p4;
	cout<<"Producto 5: "<<endl;
	cin>>p5;
	cin.ignore();
	cout<<"Ingrese nombre y apellido o ZZZ para indicar fin del proceso"<<endl;
	getline(cin,nya);
	float ventas1=0, ventas2=0, ventas3=0, ventas4=0, ventas5=0,mayor=0;
	int i=0;
	while (nya != "ZZZ"){
		float ventasc=0;
		cout<<"Ingrese codigo de producto (1,2,3,4 o 5) y luego la cantidad comprada"<<endl;
		cin>>cod>>cant;
		cin.ignore();
		cantventas=cantventas+cant;
		switch (cod)
		{
		case 1:  ventasc=p1*cant;
		ventas1=ventas1+ventasc;
		break;
		case 2:  ventasc=p2*cant;
		ventas2=ventas2+ventasc;
		break;
		case 3:  ventasc=p3*cant;
		ventas3=ventas3+ventasc;
		break;
		case 4:  ventasc=p4*cant;
		ventas4=ventas4+ventasc;
		break;
		case 5:  ventasc=p5*cant;
		ventas5=ventas5+ventasc;
		break;
		}
		if (ventasc>mayor){
			mayor=ventasc;
			nyamayor=nya;
		}
		i++;
		cout<<"Ingrese nombre y apellido o ZZZ para indicar fin del proceso"<<endl;
		getline(cin,nya);
	}
	cout<<"Ventas articulo 1: $"<<ventas1<<endl;
	cout<<"Ventas articulo 2: $"<<ventas2<<endl;
	cout<<"Ventas articulo 3: $"<<ventas3<<endl;
	cout<<"Ventas articulo 4: $"<<ventas4<<endl;
	cout<<"Ventas articulo 5: $"<<ventas5<<endl;
	cout<<"Cantidad de ventas realizadas: "<<i<<endl;
	cout<<"Cliente con mayor monto de venta: "<<nyamayor;
	return 0;
}

	

	
