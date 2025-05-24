#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string codigo[40], descripcion[40],dat;
	float stock[40][2], preciou[40], totrecaudado = 0; //1 stock inicial, 2 stock final
	int pos, cantv;
	for (int i = 0; i < 3; i++) //carga de informacion sobre productos
	{
		cout << "Ingrese codigo del producto ";
		getline(cin,codigo[i]);
		cout << "Ingrese descripcion del producto ";
		getline(cin,descripcion[i]);
		cout << "ingrese stock inicial ";
		cin >> stock[i][0];
		stock[i][1] = stock[i][0];
		cout << "Ingrese precio unitario de venta ";
		cin >> preciou[i];
		cin.get();
	}
	cout << endl;
	cout << "Ingrese codigo de producto o X9Z01 para indicar fin de carga ";
	getline(cin,dat);
	while (dat != "X9Z01") // carga de ventas
	{
		for (int i = 0; i < 3 ; i++)
		{
			if (codigo[i] == dat)
			{
				pos = i;
				i = 40;
			}
		}
		cout << "Ingrese cantidad vendida de ese producto ";
		cin >> cantv;
		stock[pos][1] = stock[pos][1] - cantv; //calculo de stock final
		cin.get();
		totrecaudado = totrecaudado + (cantv * preciou[pos]); //total recaudado
		cout << "Ingrese codigo de producto o X9Z01 para indicar fin de carga ";
		getline(cin,dat);
	}
	cout << endl;
	cout << "CGO PRODUCTO 			DESCRIPCION 			STOCK INICIAL 			STOCK FINAL" << endl; //informe
	for (int i = 0; i < 3; i++)
	{
		cout << codigo[i] << "			" << descripcion[i] << "			" << stock[i][0] << " 				" << stock[i][1] << endl;
	}
	cout << endl;
	cout << "El total recaudado de las ventas: $" << totrecaudado << endl;
	cout << "CGO PRODUCTO			STOCK FINAL PONDERADO " <<endl;
	for (int i = 0; i < 3; i++)
	{
		cout << codigo[i] << "			" << stock[i][1] * preciou[i] << endl;
	}
	return 0;
}

