#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/*
	Final 30-11-2023
	Resolucion by Chotawer
*/

using namespace std;

/// Struct
struct ALUMNO{
	string DNI;
	string NyA; // Nombre y Apellido
	string fecha_Inicio;
	int tipo_entrenamiento; // 1,2,3,4,5
	string situacion = "Alta";
	int antiguedad; // En meses
	bool NoParticipa = false; 
};

/// Funciones
int obtenerAntiguedad(string fecha_inscripcion);
void ordenar(ALUMNO alumnos[], int MAX);
int alumnoRepetido(string DNI, ALUMNO a[], int cantidad);

int main(int argc, char *argv[]) {
	/// Variables
	const int MAX = 500;
	int cant_alumnos = 0; // Cantidad de alumnos
	ALUMNO alumnos[MAX];
	string DNI;
	
	/// Lectura de datos
	ifstream archivo; archivo.open("./ALUMNOS.txt");
	if (archivo.fail())
		return 1;
	else 
		while(getline(archivo,alumnos[cant_alumnos].DNI)){
			getline(archivo,alumnos[cant_alumnos].NyA);
			archivo >> alumnos[cant_alumnos].fecha_Inicio 
				>> alumnos[cant_alumnos].tipo_entrenamiento;
			archivo.ignore();
			
			cant_alumnos++;
		}
	archivo.close(); 
	
	archivo.open("./ACTUALIZACION.txt");
	if (archivo.fail())
		return 1;
	else 
		while(getline(archivo,DNI)){
			int pos = alumnoRepetido(DNI,alumnos, cant_alumnos);
			if (pos == -1)		// Si el alumno no esta repetido, lo cargamos en una posición nueva.
				pos = cant_alumnos;
			
			alumnos[pos].DNI = DNI;
			getline(archivo,alumnos[pos].NyA);
			archivo >> alumnos[pos].tipo_entrenamiento
				>> alumnos[pos].fecha_Inicio
				>> alumnos[pos].situacion;
			archivo.ignore();
			
			if (pos == cant_alumnos)
				cant_alumnos++;
		}
	archivo.close(); 
		
	/// Antiguedad
	for (int i = 0; i < cant_alumnos; i++)
		alumnos[i].antiguedad = obtenerAntiguedad(alumnos[i].fecha_Inicio);
	
	cout << "\nANTIGUEDAD DEL MALDITO NASHE: " << alumnos[0].antiguedad;
	
	/// Punto A
	ordenar(alumnos,cant_alumnos);
	cout << "\nDNI" << setw(30) << "Nombre y Apellido" << setw(16) <<"  Antigüedad" << endl;
	for (int i = 0; i < cant_alumnos; i++)
		if ((alumnos[i].antiguedad >= 6) && (alumnos[i].situacion == "Alta"))
			cout << alumnos[i].DNI << setw(25) << alumnos[i].NyA << setw(12) << alumnos[i].antiguedad << " meses\n";
		else
			alumnos[i].NoParticipa = true;
	cout << endl;
	
	/// Punto B
	int MatrizB[5][5] = {0};
	for (int i = 0; i < cant_alumnos; i++){
		int indice = alumnos[i].tipo_entrenamiento -1;
		if (alumnos[i].situacion == "Alta")
			if (alumnos[i].antiguedad >= 31)
				MatrizB[indice][4]++;
			else if (alumnos[i].antiguedad >= 25)
				MatrizB[indice][3]++;
			else if (alumnos[i].antiguedad >= 19)
				MatrizB[indice][2]++;
			else if (alumnos[i].antiguedad >= 13)
				MatrizB[indice][1]++;
			else if (alumnos[i].antiguedad >= 6)
				MatrizB[indice][0]++;
		}
				
	cout << setw(78)<< "6 a 12     13 a 18     19 a 24     25 a 30     31 a 36\n"; 
	string entrenamiento[]{"Semipersonalizado","Personalizado","Funcional","Crossfit","Calistenia"};
	for (int i = 0; i < 5; i++){
		cout << setw(20) << entrenamiento[i] << setw(9);
		for (int j = 0; j < 5; j++)
			cout << MatrizB[i][j] << setw(12);
		cout << endl;	
	}	

	/// Punto C
	ofstream no_participan; no_participan.open("./ALUMNOS-QUE-NO-PARTICIPAN.txt");
	for (int i = 0; i < cant_alumnos; i++){
		if (alumnos[i].NoParticipa){
			no_participan << alumnos[i].DNI << " | " << alumnos[i].NyA << " | ";
			if (alumnos[i].situacion == "Baja")
				no_participan << "Baja" << endl;
			else 
				no_participan << "Antiguedad insuficiente" << endl;
		}
	}
	no_participan.close();
	
	return 0;
}

int obtenerAntiguedad(string fi){
	int antiguedad, 
		mes_actual = 10,
		anio_actual = 2023;
	int anio_ingreso = stoi(fi.substr(0,4));	// AAAA
	int mes_ingreso = stoi(fi.substr(4,2));		// MM
	/*
		Solo vamos a utilizar los meses para simplificar el calculo; 
		La forma de saber la antiguedad es simple, en caso de haber ingresado un año anterior
		a 2023, calculamos la cantidad de años de antiguedad y multiplicamos por 12 para
		obtener directamente los meses, y luego le sumamos la cantidad de meses de antiguedad.
		Notese que si entro en un mes posterior a 10 se descontarán meses.
	*/
	
	if (anio_ingreso < 2023){
		antiguedad = (anio_actual - anio_ingreso) * 12;
		antiguedad += (mes_actual - mes_ingreso);
	} else 
		antiguedad = mes_actual - mes_ingreso;
	
	return antiguedad;
}
	
void ordenar(ALUMNO a[], int MAX){
	for (int i = 0; i < MAX-1; i++)
		for (int j = i+1; j < MAX; j++)
			if (a[i].antiguedad < a[j].antiguedad){
				ALUMNO aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
}

int alumnoRepetido(string DNI, ALUMNO a[], int cantidad){
	for (int i = 0; i < cantidad; i++)
		if (a[i].DNI == DNI)
			return i;
	return -1;
}
