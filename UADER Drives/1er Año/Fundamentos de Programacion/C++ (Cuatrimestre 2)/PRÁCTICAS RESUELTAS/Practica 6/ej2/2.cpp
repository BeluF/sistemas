#include <iostream>	//ORDENAMIENTOS
#include <conio.h>
#include <cstdlib>
#include <string>
using namespace std;
/*
2) Realice una aplicación que muestre varios arreglos que previamente ha sido llenado con nombres,
documentos, materias aprobadas y año de ingreso, el tipo de dato de los arreglos defínalos de acuerdo a
su conveniencia. Luego ingrese un valor (1, 2, 3, 4 ó 5). Si se ingresó 1, ordene por nombre. Si se
ingresó 2, ordene por documento. Si se ingresó 3, ordene por materias aprobadas. Si se ingresó 4,
ordene por año de ingreso. Luego del ordenamiento vuelva a mostrar los datos. Si se ingresa 5, termine
la aplicación.
*/
const int k=5;	//cantidad de alumnos

void ordenar(int opcion,int doc[][3], string n[]){
	int o= opcion-50;
	if (opcion=='1'){
		for (int i=0; i<k; i++){
		for (int j=i+1; j<k; j++){
			if (n[i]>n[j]){
				string aux= n[i];
				n[i]=n[j];
				n[j]=aux;
				for (int l=0; l<3;l++){
					int aux2= doc[i][l];
					doc[i][l]=doc[j][l];
					doc[j][l]=aux2;
				}
			}
			}
		}
	}
	else {
		for (int i=0; i<k; i++){
			for (int j=i+1; j<k; j++){
				if (doc[i][o]<doc[j][o]){
					for (int l=0; l<3;l++){
						int aux2= doc[i][l];
						doc[i][l]=doc[j][l];
						doc[j][l]=aux2;
					}
					string aux= n[i];
					n[i]=n[j];
					n[j]=aux;
					}
				}
		}
	}
	
}

int main(int argc, char **argv){
	char opcion;
	//lote de prueba
	string nombres[k]={"tomas","raul","juan","armando","kevin"}; 
	int doc[k][3]={445501,5,2002,415501,2,2005,425501,6,2000,305501,9,1985,474505,1,2006};
	for (int i=0; i<k; i++) cout<<"Nombre: "<< nombres[i]<<" | DNI: "<< doc[i][0]<< " | MATERIAS APROBADAS: "<<doc[i][1]<<" | ANIO DE INGRESO: "<<doc[i][2]<<endl;
	do{
		cout<<"\n1. Ordenar por nombre\n2. Ordenar por documento\n3. Orden por materias aprobadas\n4. Orden por año de ingreso\n5. Salir\n";
		opcion=getch();
		if (opcion=='5') break;
		system("cls");
		ordenar(opcion,doc,nombres);
		switch (opcion){
			case '1': cout<<"Arreglo ordenado por nombre:\n";
			break;
			case '2': cout<<"Arreglo ordenado por documento:\n";
			break;
			case '3': cout<<"Arreglo ordenado por materias aprobadas:\n";
			break;
			case '4': cout<<"Arreglo ordenado por ingreso:\n";
			break;
		}
		for (int i=0; i<k; i++) cout<<"Nombre: "<< nombres[i]<<" | DNI: "<< doc[i][0]<< " | MATERIAS APROBADAS: "<<doc[i][1]<<" | ANIO DE INGRESO: "<<doc[i][2]<<endl;
	}while(opcion!='5');
	
	return 0;
	
}

