#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/* 
	Se desea realizar un informe con las cantidades de multas por exceso de velocidad que se labran
	en el pa�s durante un mes.
	Se cuenta con la informaci�n que env�an todos los municipios: c�digo de provincia y cantidad de
	multas. Un c�digo de provincia igual a 99 indica el fin de datos.
	Informe:
	Nombre de la Provincia 			Cantidad de multas
	 xxxxxxxxxxxxxxxxxxxx			 xxxxx
	 xxxxxxxxxxxxxxxxxxxx			 xxxxx
	 Total de multas: xxxxx
*/
struct p{
	string nombre;
	int multas=0;
};

void informe(p prov[]){
	int total=0;
	cout<<"Nombre de provincia					Cantidad de multas"<<endl;
	for (int i=0;i<24;i++){
		cout<<prov[i].nombre<<"					"<<prov[i].multas<<endl;
		total=total+prov[i].multas;
	}	
	cout<<"Total de multas: "<< total;
};

int main(int argc, char *argv[]){
	p prov[24];
	ifstream file; file.open("./PROVINCIAS.txt");
	if (file.fail()) cout<<"Archivo provincias no se pudo abrir correctamente, ejecute el programa anterior para crearlo y cargarlo.";
	else{
		//cargar datos desde el archivo
		string nombre; 
		int contador=0;
		while (getline(file,nombre)){
			int pos= nombre.find(" ");
			prov[contador++].nombre=nombre.substr(pos+1);
		} 
		//cerrar archivo
		file.close();
		//carga de multas
		int codigo;	
		do{
			cout<<"Ingrese codigo de provincia ";cin>>codigo;
			if (codigo==99) break;
			else {
				if (codigo<=23 && codigo>=0) {
				cout<<"Provincia: "<<prov[codigo].nombre<<endl;
				cout<<"Ingrese cantidad de multas: ";cin>>prov[codigo].multas;
				}
				else cout<<"El c�digo ingresado no corresponde a una provincia\n";
			}
		}while(codigo<100);
		//informe
		informe(prov);
	}
	return 0;
}
