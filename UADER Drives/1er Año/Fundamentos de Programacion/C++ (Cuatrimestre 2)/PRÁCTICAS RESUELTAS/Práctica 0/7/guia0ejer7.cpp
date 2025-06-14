#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Se desea conocer el valor del costo de un producto se se conoce: el precio de
	venta y su porcentaje de ganancia.*/
	float costo,precioventa,ganancia,aux;
	cout<<"Ingrese el precio de venta del producto y luego su porcentaje de ganancia"<<endl;
	cin>>precioventa>>ganancia;
	aux=precioventa*(ganancia/100);
	costo=precioventa-aux;
	cout<<"El costo del producto es de: $"<<costo;
	return 0;
}

