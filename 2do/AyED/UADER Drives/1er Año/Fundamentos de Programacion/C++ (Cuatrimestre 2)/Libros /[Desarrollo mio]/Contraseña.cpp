#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>;
using namespace std;
//test de intentar hacer una contraseņa por consola

//test1: guardar la contraseņa por un lado y con una variable mostrar los asteriscos 
//test 2 (no empezado): guardar la contraseņa pero mostrar los asteriscos sin tener que almacenarlos en la variable.

int main(){
	int n=10;
	cout<<"Ingrese longitud de la contraseņa"<<endl;
	cin>>n;
//	char contra[n];
	string contran="", contram=""; //contra no mostrada, contra mostrada
	for (int i=1;i<n;i++){
		contran=getch();
		//contran= contran+contra[i];
		for (int n=1;n<=contran.size();n++);{
			contram=contram+contran;
		}
		//system("cls");
		cout<<'*';
	} 
	cout<<endl<<"[termino el programa] "<<contram;
	getch();
	return 0;
}
