/*10. Se desea realizar un informe ordenado por el sueldo a percibir por cada empleado de mayor a
menor con la informaciï¿½n existente en el archivo SUELDOS.TXT*/
#include "C:\Users\TomsS\Documents\C++\C++ (C2)\Practica 8\archivos.cpp"
#include <tgmath.h>

using namespace std;

void busquedabinaria(int a[][2], int n, int busqueda, bool prim=false){
	//espacios de busqueda
	int min=0, max=n, mid=(min+max)/2;
	//busqueda hasta que no haya más indices para buscar
	while ((min<=max) && (busqueda != a[mid][1])){
		if (busqueda>a[mid][1]) 
			max=mid-1;
		else min=mid+1;
		mid=(min+max)/2;
	}
	if (min>max) cout<<"No hay trabajador que posea ese sueldo";
	else cout<<"\nCódigo de trabajador: "<<a[mid][0]<<" | Sueldo: "<<a[mid][1];
}

int main (int argc, char **argv){
	ifstream file; file.open("./SUELDOS.TXT");
	if (!file.fail()){
		string linea;
		getline(file,linea);
		int pos= linea.find(":")+2;
		int n= stoi(linea.substr(pos));	//obteniendo cantidad de empleados
		//cout<<n;
		//cargar datos del archivo a un array
		int empleados[n][2];
		for (int i=0;i<n;i++){
			file>>empleados[i][0];
			file>>empleados[i][1];
		} 	
	//orxdenamiento de datos
		cout<<"Sueldos ordenados de mayor a menor:\n";
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				if (empleados[i][1]<empleados[j][1]){
					for (int k=0;k<2;k++){
						int aux=empleados[i][k];
						empleados[i][k]=empleados[j][k];
						empleados[j][k]=aux;
					}
				} 
			}
		}
		for (int i=0;i<n;i++){
			cout<<empleados[i][0]<<" "<<empleados[i][1]<<endl;
		}
		//busqueda dicotómica de datos
		cout<<"Desea buscar un salario en especifico?\n";
		int valor; cin>>valor;
		cout<<"Resultados:";
		busquedabinaria(empleados,n,valor,true);
	}
	else cout<<"Error al abrir el archivo";
	
	file.close();
	return 0;
}
