//en la version 2, hacer todo dentro de una misma función para no meter tantos bucles, usando arrays dinámicos.
//falta hacer que la matriz se ordene

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

//atoi(string.c_str()) -> convierte en numero un string
//atof string to double
//strtol string to long int

using namespace std;

int obtenerdatos(vector<string> &xy, ifstream &file);

void obtenernumeros(vector<string> &xi, int (*dir_xy)[2]){
	for (int i=0;i<xi.size();i++){
		//separar la cadena con istringstream
		istringstream iss(xi[i]);
		string ex,ey;
		iss>>ex>>ey;
	
		//convertir cadenas en nÃºmeros
	 	dir_xy[i][1] = atoi(ex.c_str());
		dir_xy[i][2] = atoi(ey.c_str());
	}
}

int main(int argc, char*argv[]){
	ifstream file;
	file.open("./ej1.txt");
//	cout<<"Línea: "<<file.tellg(); saber en que linea estamos
// Volver al principio del archivo: archivo.seekg(0, ios::beg);
	if (file.fail()) cout<<"error de apertura";
	else {
		//vector con las posiciones xy
		vector<string> xi;
		//declarar array para obtener los datos
		int n= obtenerdatos(xi,file);
		int xy[n][2];
		int (*dir_xy)[2]=xy;
		//mandar array para obtener los datos y luego ordenarlos.
		obtenernumeros(xi,dir_xy);
		//ver si el array numérico se obtuvo correctamente
		for (int k=0;k<xi.size();k++){
			cout<<"\nx: "<<xy[k][1];
			cout<<" | y: "<<xy[k][2];
		}
		// ordenar array de mayor a menor en base a la columna "y"
	
	
	}
	file.close();
	return 0;
}

int obtenerdatos(vector<string> &xy,ifstream &file){
	string aux;
	while(!file.eof()){
		//lectura de el archivo mandandolo a una variable auxiliar
		getline(file,aux);
		//metiendolo en un vector dinï¿½mico
		xy.push_back(aux);
		}
	return xy.size();
	}
	
