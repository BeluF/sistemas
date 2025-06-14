#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	# Resolución de parcial 3_1 por mi
	# Asumimos que el orden de los datos en los archivos está 
	  colocado de manera descendente
*/

/// Funciones:
bool obtenerDatos(string Direccion_del_Archivo, string Array_con_Datos[][4], int &contador_del_archivo);
int busqueda(string Dato_a_buscar, string Array_donde_buscar[][4], int Tope, int Columna_a_buscar);
void ordenar(float array_a_ordenar[][2], string Segundo_Array_a_ordenar[][4], int Tope_array);

/// Main
int main(int argc, char **argv)
{
	const int N = 999;
	int max_cursos = 0, max_alumnos = 0;
	float montodescuento = 0;
	float inscript_recaudado[N][2] = {0}; // Total de inscriptos[0] y recaudado[1]
	string cursos[N][4]; //  [0]NRO CURSO | [1]DESCRIPCION | [2]NOMBRE DOCENTE | [3]COSTO
	string alumnos[N][4]; // [0]DNI | [1]NyA | [2]FECHA DE NACIMIENTO | [3]CANTIDAD DE CURSOS PREVIOS
	string DNI, NyA, fecha, NCurso;
	
	/// Lectura de datos
	
	// Funcion que lee los archivos, pasada una direccion, un array, y un maximo
	// el operador ! niega el resultado, como es una funcion booleana, retorna true si logro leer todo bien.
	// En este caso estamos diciendo si NO pudo obtener los datos, retornamos 1 (ERROR)
	if (!obtenerDatos("./cursos_docen.txt", cursos, max_cursos))
		return 1;
	if (!obtenerDatos("./old_alumnos.txt", alumnos, max_alumnos))
		return 1;
	
	/// Carga de datos
	
	cout << "Ingrese DNI Alumno: "; 
	cin >> DNI; 
	while (DNI != "0"){
		int pos = busqueda(DNI,alumnos,max_alumnos,0);
		if (pos == -1){			/// En caso de no encontrar el dato
			pos = max_alumnos;
			alumnos[pos][0] = DNI;
			cout << "Ingrese apellido y nombre: "; 
			getline(cin,NyA);
			alumnos[pos][1] = NyA;
			cout << "Ingrese fecha de nacimiento: ";
			cin >> fecha;
			alumnos[pos][2] = fecha;
			alumnos[pos][3] = "0";
			max_alumnos++;
		}
		
		bool descuento = (alumnos[pos][3] != "0"); // Si realizó un curso, se activa el descuento
		
		cout<< "Numero de curso: "; 
		cin >> NCurso;
		pos = busqueda(NCurso,cursos,max_cursos,0);
		if (pos != -1){
			float desc = 1;						// Porcentaje de descuento
			float precio = stof(cursos[pos][3]);
			
			inscript_recaudado[pos][0]++;		// Aumentar cantidad de inscriptos
			if (descuento){
				desc = 0.85;					// 15% de Descuento
				montodescuento += precio * 0.15;
			}
			
			inscript_recaudado[pos][1] += precio * desc;
		}
		
		cout << "Ingrese DNI Alumno: "; 
		cin >> DNI;
	}
	
	/// Informe A
	ordenar(inscript_recaudado,cursos,max_cursos);
	cout << "Nro. Curso    Descripción    Docente    Total inscriptos    Recaudación";	for (int i = 0; i < max_cursos; i++)
		cout << cursos[i][0] <<"  "<< cursos[i][1] <<"  "<< cursos[i][2] <<"  "<< inscript_recaudado[i][0] <<"  "<< inscript_recaudado[i][1] << endl;
	
	/// Informe B
	float montototal = 0;
	for (int i = 0; i < max_cursos; i++)
		montototal += inscript_recaudado[i][1];
			
	cout << "Monto total a recaudar:" << montototal << "\nMonto total de descuentos: " << montodescuento;
	
	/// Consigna C
	ofstream recaudacion; recaudacion.open("./recaudacion.txt");
	for (int i = 0; i < max_cursos; i++)
		recaudacion << cursos[i][0] << endl << cursos[i][1] << endl << cursos[i][2] << endl << inscript_recaudado[i][0] << endl << inscript_recaudado[i][1] << endl;
	
	return 0;
}

bool obtenerDatos(string direccion, string data[][4], int &max)
{
	ifstream archivo; archivo.open(direccion);
	if (archivo.fail()){
		cout << "No se pudo abrir archivo en la direccion: " << direccion;
		return false; 
	}
	
	while(getline(archivo,data[max][0])){
		getline(archivo,data[max][1]);
		getline(archivo,data[max][2]);
		getline(archivo,data[max][3]);	
		max++;
	}
	
	return true;
}

int busqueda(string dato, string array[][4], int max, int C){
	for (int i = 0; i < max; i++)
		if (dato == array[i][C])
			return i; 	/// Dato encontrado
	
	return -1;	/// Dato no encontrado
}

void ordenar(float array1[][2], string array2[][4], int max){
	for (int i = 0; i < max-1; i++)
		for (int j = i+1; j < max; j++)
			if (array1[i] < array1[j]){
				for (int k = 0; k < 2; k++){
					float aux = array1[i][k];
					array1[i][k] = array1[j][k];
					array1[j][k] = aux;
				}
				for (int k = 0; k < 4; k++){
					string auxS = array2[i][k];
					array2[i][k] = array2[j][k];
					array2[j][k] = auxS;
				}
			}
}
