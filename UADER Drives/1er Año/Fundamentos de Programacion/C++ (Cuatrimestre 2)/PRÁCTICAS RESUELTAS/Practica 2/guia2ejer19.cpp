#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*19. Dado el siguiente enunciado, completar el código.
	Se desea contar con una aplicación que obtenga el total a cobrar por una transacción
	comercial.
	Los datos que se ingresan corresponden a la venta de productos enlatados. Los mismos son:
	Código de barras, cantidad y precio unitario.
	Los productos comprados de origen nacional (cuyo código de barras comienza con “779”)
	pueden comprarse con los planes “Ahora 3”, “Ahora 6” o en 1 cuota. Por lo tanto, si el
	producto comprado es nacional se debe permitir el ingreso de la cantidad de cuotas en que se
	compra el producto.
	El informe debe tener el siguiente formato:
	Producto: xxxxxxxxxxxxx
	Apunte elaborado por la cátedra Fundamentos de Programación – Sede Oro Verde Pág. Nro. 7
	
	Cantidad: xx Precio Unitario: $ xxxx,xx
	Total: $ xxxx,xx
	Cantidad de Cuotas: xx Comprado con el plan “xxxxxxxx” **
	Valor de la Cuota: $ xxxx,xx
	Obs: En **Debe informarse “Ahora 3” o “Ahora 6”. Si no fue comprado en cuotas no debe
	mostrarse este cartel.*/
	string cb,text;
	int cant,cuotas;
	float preciou;
	cout<<"Ingrese el codigo de barras del producto"<<endl;
	cin>>cb;
	cout<<"Ingrese la cantidad de producto comprado"<<endl;
	cin>>cant;
	cout<<"Ingrese precio unitario"<<endl;
	cin>>preciou;
	if (cb.substr(0,3)=="779"){
	cout<<"Ingrese cantidad de cuotas (Ahora 3, Ahora 6 o 1 cuota)"<<endl;
	cin>>cuotas;
	}
	if (cuotas==1)
	{
	text="1 cuota";
	}
	else if (cuotas==3)
	{
	text="Ahora 3";
	}
	else if (cuotas==6)
	{
	text="Ahora 6";
	}
	cout<<"Producto: "<<cb<<endl;
	cout<<"Cantidad: "<<cant<<"     "<<"Precio Unitario: $"<<preciou<<endl;
	cout<<"Total: $"<<cant*preciou<<endl;
	if ((cuotas==1) || (cuotas==3) || (cuotas==6))
	cout<<"Cantidad de cuotas: "<<cuotas;
	if ((cuotas==6) || (cuotas==3))
	cout<<"            "<<"Comprado con el plan: "<<text<<endl;
	cout<<"Valor de la cuota: $"<<(cant*preciou)/cuotas;
	

	return 0;
}

