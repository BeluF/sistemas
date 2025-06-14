#include <iostream>
#include <fstream>
using namespace std;

int busqueda(string datos[][7], int max, string buscar);
void extraer_anio(string fecha, int &anio);
bool esJubilado(string anio_nacimiento, string anio_ingreso, int cantidad);
void ordenar(string datos[][6], int max);

int main(int argc, char *argv[]) {
	// leyendo datos del enunciado:
	ifstream archivo("./datos_personales.txt");
	if (archivo.fail())
		return 1;
	
	string datos[500][7]; // dni, nombre, fechanac, fecha ing;
	int max;
		
	int i = 0;
	archivo >> datos[i][0]; // dni
	while (!archivo.eof()){
		archivo.ignore();
		getline(archivo, datos[i][1]);
		archivo >> datos[i][2] >> datos[i][3];
		
		i++;
		archivo >> datos[i][0]; // dni
	}
	max = i;
	
	archivo.close();
	archivo.open("./docentes_catedras.txt");
	if (archivo.fail())
		return 1;
	
	string dni;
	archivo >> dni;
	while (!archivo.eof()){
		int pos = busqueda(datos, max, dni);
		archivo.ignore();
		getline(archivo, datos[pos][4]);
		archivo >> datos[pos][5] >> datos[pos][6];
		archivo >> dni; // dni
	}
	archivo.close();
	
	// consigna 1:
	int anio;
	cin >> anio;
	
	string jubilados[500][6]; // dni, apellido, anio; catedra, funcion, cargo;
	int cantidad_jubilados = 0;
	for (int i = 0; i < max; i++)
		if (esJubilado(datos[i][2], datos[i][3], anio)){
			jubilados[cantidad_jubilados][0] = datos[i][0]; 
			jubilados[cantidad_jubilados][1] = datos[i][1]; 
			for (int k = 2; k < 6; k++) // porque aca datos se desfaza por 1
				jubilados[cantidad_jubilados][k] = datos[i][k+1];
			cantidad_jubilados++;
		}
	
	ordenar(jubilados, cantidad_jubilados);
	
	cout << "DNI APELLIDO Y NOMBRE A�O DE INGRESO" << endl;
	for (int i = 0; i < cantidad_jubilados; i++)
		cout << jubilados[i][0] << " | " << jubilados[i][1] << " | " << jubilados[i][2] << endl;
		
	// consigna 2
	ofstream salida("./catedras_concurso.txt");
	for (int i = 0; i < cantidad_jubilados; i++)
		salida << jubilados[i][3] << " | " << jubilados[i][4] << " | " << jubilados[i][5] << endl;
		// CATEDRA << FUNCION << CARGO
		
		
	return 0;
}

int busqueda(string datos[][7], int max, string buscar){
	for (int i = 0; i < max; i++)
		if (datos[i][0] == buscar)
			return i;
	return max;
}

bool esJubilado(string an, string ai, int anio){
	int anio_nacimiento, anio_ingreso;
	extraer_anio(an, anio_nacimiento);
	extraer_anio(ai, anio_ingreso);
	
	int anios = anio - anio_nacimiento;
	int antiguedad = anio - anio_ingreso;
	
	if (anios >= 52 && antiguedad >= 25)
		return true;
	
	return false;
}	

void extraer_anio(string fecha, int &anio){
	fecha = fecha.substr(0,4);
	anio = stoi(fecha);
}

void ordenar(string datos[][6], int max){
	for (int i = 0; i < max-1; i++)
		for (int j = i + 1; j < max; j++)
			if (datos[i][1] > datos[j][1])
				for (int k = 0; k < 6; k++){
					string aux = datos[i][k];
					datos[i][k] = datos[j][k];
					datos[j][k] = aux;
				}
}
