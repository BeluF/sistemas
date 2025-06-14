#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structs
struct PRODUCTO_EN_DOLARES{
	int codigo;
	string descripcion,precio;
};

int main(){
	PRODUCTO_EN_DOLARES prod[999];
	float cotizacion;
	int cant_Productos = 0; // Cantidad de productos
	
	cout << "Ingrese cotizacion: $";
	cin >> cotizacion;
	
	ifstream archivo; archivo.open("./PRODUCTOS_EN_DOLARES.txt");
	if (archivo.fail())
		return 1;
	else 
		while (archivo >> prod[cant_Productos].codigo){
			archivo.ignore();
			getline(archivo,prod[cant_Productos].descripcion);
			archivo >> prod[cant_Productos].precio;
			
			cant_Productos++;
		}
	archivo.close();
		
	// Generar productos en pesos
	ofstream pesos; pesos.open("./PRODUCTOS_EN_PESOS.txt");
	for (int i = 0; i < cant_Productos; i++){
		string precio = prod[i].precio;
		int largo = precio.size() - 1;
		precio = precio.substr(1,largo);
		
		float valor_en_dolar = stof(precio);
		float valor_en_pesos = valor_en_dolar * cotizacion;
		
		pesos << prod[i].codigo << endl << prod[i].descripcion << endl << "$" << valor_en_pesos << endl;
	}	
	pesos.close();
	
	return 0;
}
