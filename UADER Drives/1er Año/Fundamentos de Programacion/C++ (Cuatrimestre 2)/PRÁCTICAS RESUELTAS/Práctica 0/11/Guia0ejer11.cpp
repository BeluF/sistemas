#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Un almacén de barrio necesita un programa para calcular el total a cobrar a un
	cliente por una compra. Se ingresan los datos de la venta: Nombre y Apellido del
	cliente, cantidad comprada del artículo y precio unitario del mismo. Al monto total
	de la venta, se le efectúa un descuento del 5%. Luego de realizado el descuento se
	calcula el IVA del 21% para obtener el total a pagar.*/
	char nombre[20],apellido[20];
	int cantcomprada;
	float preciou,aux,total;
	cout<<"Ingrese Nombre y luego apellido"<<endl;
	cin>>nombre>>apellido;
	cout<<"Ingrese Cantidad comprada del articulo y luego su precio unitario"<<endl;
	cin>>cantcomprada>>preciou;
	aux=preciou*cantcomprada;
	total=aux*1.16;
	cout<<"El precio de venta del producto es de: $"<<total;
	
	return 0;
}

