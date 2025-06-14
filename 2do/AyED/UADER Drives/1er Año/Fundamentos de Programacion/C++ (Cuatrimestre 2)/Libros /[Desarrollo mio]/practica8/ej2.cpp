#include <iostream>
#include <string>

using namespace std;

void show_array(string lista[],int n);

const int n=5,m=2,k=5;

struct ficha_alumno {
	string nya;
	string mataprob[n];
	string matcurs[n];
	int nma[n]; //Notas Materias Aprobadas
	int parciales[n][m];
};

int main(){
	
	ficha_alumno x[k];
	for (int i=1;i<k+1;i++){
		cout<<"Nombre y apellido "<<x[i].nya<<endl<<"Materias aprobadas: "<<endl;
		show_array(x[i].mataprob,n);
		cout<<"Materias que está cursando: ";
		show_array(x[i].matcurs,n);
		
	return 0;
	}
	
}

void show_array(string lista[],int n){
	for (int j=1;j<n;j++){
			cout<<lista[n]<<endl;
		}
}
