#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/// Funciones
int busqueda(string dato, string datos[][2], int max);
void sort(string curso[][2], int caract[][3], int max); 
bool extraccionDatos(string datos[][2], string direc, int &cantidad);
int funcionb (int cur[][3], string c[][2], char &pt, string &codcur, int ct);

int main(int argc, char *argv[]) {
	/// Datos:
	string cursos[200][2], asistentes[200][2], dni, codcurso;
	int caract_part[200][3] = {0};	// Caracter de participacion
	bool inasistentes[200] = {true}; // Asistentes que no participaron en ningun curso. 
	char caracter;	
	int cantidadCursos = 0, cantidadAsistentes = 0;
	
	/// Extracción de datos:
	if (extraccionDatos(cursos,"./cursos.txt",cantidadCursos))
		return 1;
	if (extraccionDatos(asistentes,"./asistentes.txt",cantidadAsistentes))
		return 1;
	
	/// Carga de caracter de participacion:
	cout << "Ingrese DNI del asistente: ";
	cin >> dni;
	while (dni != "0")
	{
		int pos = busqueda(dni, asistentes, cantidadAsistentes);
		if (pos == -1)
			cout << "No se encontro el DNI\n";
		else 
			{
				cout << "Ingrese codigo de curso: ";
				cin >> codcurso;
				int pos2 = busqueda(codcurso, cursos, cantidadCursos);
				if (pos2 == -1)
					cout << "No se encontro el curso\n";
				else 
					{
						cout<<"Ingrese caracter de participacion [0. Ninguna | 1. Investigadores | 2. Profesionales | 3. Productores]\n";
						cin >> caracter;
						int c = caracter - 49; // 48 es el caracter 0 en la tabla ASCII, por lo tanto restamos eso para obtner donde se debe guardar
						if ((c > -1) && (c < 3)){
							caract_part[pos2][c]++;	
							inasistentes[pos] = false;
						}
					}
			}
		cout << "Ingrese DNI del asistente: ";
		cin >> dni;
	}
	
	/// Consigna A
	sort(cursos,caract_part,cantidadCursos);
	
	cout << "Cod. Curso                       Nombre Curso              Cant. Investigadores    Cant. Profesionales    Cant. Productores    Cant. Total\n";
	for (int i = 0; i < cantidadCursos; i++){
		int total = 0;
		for (int j = 0; j < 3; j++)
			total += caract_part[i][j];
		cout << setw(7) << cursos[i][0] << setw(50) << cursos[i][1] << setw(10) << caract_part[i][0] << setw(22) << caract_part[i][1] << setw(22) << caract_part[i][2] << setw(22) << total << endl;  
	}
	
	/// Consigna B
	char part; string curso;
	int max = funcionb(caract_part, cursos, part , curso, cantidadCursos);
	cout<<"\nEl curso "<<curso<<" fue el que tuvo mayor caracter de participacion, con participacion tipo "<< part<<" y un maximo de "<<max<<".";
	
	/// Consigna C
	ofstream noa; noa.open("./no_asistentes.txt");
	for (int i=0; i<cantidadAsistentes; i++){
		if (inasistentes[i]) {
			//Respetamos el formato del documento con el que trabajamos inicialmente.
			noa<<asistentes[i][0]<<endl<<asistentes[i][1]<<endl;
		}
	}
	noa.close();
	
	
	return 0;
}

int busqueda(string dato, string datos[][2], int max) {
	for (int i = 0; i < max; i++)
		if (datos[i][0] == dato)
			return i;
	
	return -1;
}

void sort(string curso[][2], int caract[][3], int max) {
	for (int i = 0; i < max -1; i++)
		for (int j = i + 1; j < max; j++)
	{
			int total1 = caract[i][0] + caract[i][1] + caract[i][2];
			int total2 = caract[j][0] + caract[j][1] + caract[j][2];
			
			if (total1 < total2){
				for (int k = 0; k < 2; k++)
				{
					string aux = curso[i][k];
					curso[i][k] = curso[j][k];
					curso[j][k] = aux;
				}
				for (int k = 0; k < 3; k++)
				{
					int aux = caract[i][k];
					caract[i][k] = caract[j][k];
					caract[j][k] = aux;
				}
			}
	}
}

bool extraccionDatos(string datos[][2], string direc, int &cantidad)
{
	ifstream archivo; archivo.open(direc);
	
	if (archivo.fail()){
		cout << "Error al abrir el archivo " << direc;
		return true;
	} else {
		while (getline(archivo,datos[cantidad][0]))
			getline(archivo,datos[cantidad++][1]);
	}
	
	archivo.close();
	return false;
}

int funcionb (int cur[][3], string c[][2], char &pt, string &codcur, int ct){		
	int max=0;					
	for (int i=0; i < ct; i++){
		//Se queda con el valor maximo del caracter de partipacion, el tipo y de paso guarda del nombre del curso.
		if (max<cur[i][0]) {
			max=cur[i][0];
			codcur= c[i][1];
			pt='1';
		}
		if (max<cur[i][1]){
			max=cur[i][1];
			codcur= c[i][1];
			pt='2';
		}
		if (max<cur[i][2]){
			max=cur[i][2];
			codcur= c[i][1];
			pt='3';
		}
	}
	
	return max;	
}
