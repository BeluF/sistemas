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

int cantidadlineas(ifstream &file){
	int cl; string linea;
	while (!file.eof()){
		getline(file,linea);
		cl++;
	}
	return cl;
}

int obtenerdatos(int xy[][2],ifstream &file){
	string aux;
	int i=0;
	while(!file.eof()){
		//lectura de el archivo mandandolo a una variable auxiliar
		getline(file,aux);

		istringstream iss(aux);
		string ex,ey;
		iss>>ex>>ey;
		//cout<<ex<<"|"<<ey<<endl;
		xy[i][1] = atoi(ex.c_str());
		xy[i][2] = atoi(ey.c_str());
		//cout<<xy[i][1]<<"|"<<xy[i][2]<<endl<<"--------------"<<endl;;
		i++;
		}
		return i;
	}

int main(int argc, char*argv[]){
	ifstream file;
	file.open("./ej1.txt");
	
//	file.seekg(0, ios::beg); manda el archivo devuelta al inicio
	
	if (file.fail()) cout<<"error de apertura";
	else {
		//declarar array para obtener los datos
		int n= cantidadlineas(file);
		file.close();
		ifstream file;
		file.open("./ej1.txt");
		
		int xy[n][2];
		int i= obtenerdatos(xy,file);
		//ver si el array numérico se obtuvo correctamente
		cout<<"======================";
		for (int k=0;k<i;k++){
			cout<<endl<<xy[k][1]<<"|"<<xy[k][2]<<endl<<"--------------";
		}
		// ordenar array de mayor a menor en base a la columna "y"
	
	}
	file.close();
	return 0;
}

	
