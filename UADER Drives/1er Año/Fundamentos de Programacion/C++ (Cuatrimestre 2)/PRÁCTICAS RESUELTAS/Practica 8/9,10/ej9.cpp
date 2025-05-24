#include "C:\Users\TomsS\Documents\C++\C++ (C2)\Practica 8\archivos.cpp"
#include <stdlib.h>

using namespace std;

/*9. Una empresa posee N empleados, y de cada uno de ellos, los siguientes datos: Código de
empleado (numérico), cantidad de horas normales trabajadas, cantidad de horas extras trabajadas.
La cantidad de empleados y el valor de la hora normal de trabajo se leen como primeros datos
Se pide:
a) Generar un archivo SUELDOS.TXT donde figure Cod de empleado, sueldo a cobrar. 
Tenga en cuenta que las horas extras se pagan el doble que las horas normales de trabajo.
*/

void cargadatos(int empleados[][1],int n){
	for (int cod=0;cod<n;cod++){
		cout<<"Codigo de empleado: "<<cod<<"\nIngrese cantidad de horas normales trabajadas y cantidad de horas extra: ";
		cin>>empleados[cod][0]>>empleados[cod][1];
	}
}

int main(int argc, char **argv){
	int n, vh;
	cout<<"Ingrese cantidad de empleados y el valor de la hora normal de trabajo: ";cin>>n>>vh;
	int empleados[n][1];
	cargadatos(empleados,n);
	ofstream sueldo; sueldo.open("./SUELDOS.txt");
	sueldo<<"Codigo de empleado	  Sueldo a cobrar | Cantidad: "<<n<<endl;
	for (int i=0;i<n;i++){
		int total;
		total=(empleados[i][0]*vh)+(empleados[i][1]*(vh*2));
		sueldo<<i<<"				"<<total<<endl;	
	} 
	sueldo.close();
	return 0;
}
