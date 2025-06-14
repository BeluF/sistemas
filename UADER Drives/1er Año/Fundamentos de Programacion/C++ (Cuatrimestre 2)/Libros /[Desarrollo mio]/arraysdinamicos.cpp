/*Arreglos dinámicos.
new: reserva número de bytes solicitado por la declaración
delete: libera un bloque de bytes reservado con anterioridad. 
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h> //trae el new y el delete

using namespace std;

void carga();
void mostrar();

int dato1,*dir_dato;

int main(){
	carga();
	mostrar();
	
	delete[] dir_dato;	//liberando espacio de bytes de calificaciones 
	
	getch();
	return 0;
}

void carga(){
	cout<<"Digite cantidad de calificaciones: ";
	cin>>dato1;
	
	dir_dato= new int [dato1]; //con esto se crea el arreglo dinámico
	
	for (int i=0;i<dato1;i++){
		cout<<"Ingrese la nota de la materia "<<i<<" : ";
		cin>>dir_dato[i];
	}
}

void mostrar(){
	cout<<"\n\nMostrando notas del usuario:\n";
	for (int i=0; i<dato1;i++) cout<<"\nNota "<<i<<" : "<<dir_dato[i];
}
