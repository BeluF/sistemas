#include <iostream>
#include <string>

using namespace std;

void show_array(int lista[]);

const int n=2,k=3;	//k lista de alumnos

struct ficha_alumno {
	string nya="t";		//nombre y apellido del alumno
	int materias[n]; //contiene calificaciones del alumno
	//string nombremat[32]; //contiene el nombre de la materia
	};

int main(){
	
	ficha_alumno x[k];
	
	for (int i=1;i<=k;i++){
		cout<<"Nombre y apellido "<<x[i].nya<<endl<<"Materias: "<<endl;
		for (int j=1;j<n+1;j++){
			cout<<x[i].materias[j]<<endl;
		}
	}
	
	cout<<"Las notas de las materias 6, 11 y 12 son reemplazadas por 8, 7 y 10 respectivamente.";
	int d;
	cin>>d;
	x[1].materias[6]=8;
	x[1].materias[11]=7;
	x[1].materias[12]=10;
	
	
	return 0;
}

