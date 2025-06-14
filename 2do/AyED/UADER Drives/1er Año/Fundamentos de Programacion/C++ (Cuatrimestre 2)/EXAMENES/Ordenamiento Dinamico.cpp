#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char *argv[]) {
	string nya[999];
	string DNI[999];
	float nota[999];
	int cont = 0;
	
	do{
		cout << "Ingrese NOMBRE Y APELLIDO, DNI Y NOTA DEL ALUMNO: ";
		getline(cin,nya[cont]);
		cin >> DNI[cont] >> nota[cont];
		cin.ignore();
		cont++;
	}while(nota[cont-1] != -1);
	cont--;
	
	
	cout << "Ingrese formato del ordenamiento: " 
		<< "\n1. Por Nombre y Apellido"
		<< "\n2. Por DNI"
		<< "\n3. Por Nota"
		<< "\n4. Cerrar\n ===================\n\n";
	char letra = getch();
	
	while(letra != '4'){
		bool Condicion;
		/// Ordenamiento
		for (int i = 0; i < cont; i++)
			for (int j = i+1; j < cont; j++){
				switch (letra){
					case '1': Condicion = (nya[i] > nya[j]);
					break;
					case '2': Condicion = (DNI[i] < DNI[j]);
					break;
					case '3': Condicion = (nota[i] < nota[j]);
					break;
				}
				
				if (Condicion){
					string aux = nya[i];
					nya[i] = nya[j];
					nya[j] = aux;
					
					aux = DNI[i];
					DNI[i] = DNI[j];
					DNI[j] = aux;
					
					float aux2 = nota[i];
					nota[i] = nota[j];
					nota[j] = aux2;
				}
			}
		
		/// Muestreo de datos
		for (int i = 0; i < cont; i++)
			cout << nya[i] << "   " << DNI[i] << "   " << nota[i] << endl;
			
		cout << "\n ===================\n Ingrese formato del ordenamiento: " 
			<< "\n1. Por Nombre y Apellido"
			<< "\n2. Por DNI"
			<< "\n3. Por Nota"
			<< "\n4. Cerrar\n";
		letra = getch();
	}
	
	return 0;
}

