#include <iostream>
#include <fstream>
#include <string>

/*
	Resolución FINAL 16-02-23
	by chotawer
*/

using namespace std;

/// Structs
struct paciente{
	string DNI;
	string Apellido;
	string Nombres;
	string FechaNacimiento;
	char ObraSocial;
	string descripcion;
	string codigo_patologia;
	int edad;
};

struct patologia{
	string codigo;
	string descripcion;
	int quincena1 = 0, quincena2 = 0;
}; 

/// Funciones
int ObtenerEdad(string FechaPaciente);
string ExtraccionCaracteres(string Texto, int longitud);
int Busqueda(string dato, paciente p[], int max);
int Busqueda(string dato, patologia p[], int max);

int main(int argc, char *argv[]) {
	/// Variables
	paciente pacientes[999];
	patologia patologias[25];
	int contador_pacientes = 0, contador_patologias = 0;
	
	/// Alta de datos
	ifstream archivo; archivo.open("./PACIENTES.txt");
	if (archivo.fail())
		return 1;
	while (getline(archivo,pacientes[contador_pacientes].DNI)){
		getline(archivo,pacientes[contador_pacientes].Apellido);
		getline(archivo,pacientes[contador_pacientes].Nombres);
		archivo >> pacientes[contador_pacientes].FechaNacimiento 
			>> pacientes[contador_pacientes].ObraSocial
			>> pacientes[contador_pacientes].descripcion
			>> pacientes[contador_pacientes].codigo_patologia;
		archivo.ignore();
		pacientes[contador_pacientes].edad = ObtenerEdad(pacientes[contador_pacientes].FechaNacimiento);
		contador_pacientes++;
	}
	archivo.close(); 
	archivo.open("./PAT_RESPI.txt");
	if (archivo.fail())
		return 1;
	while (getline(archivo,patologias[contador_patologias].codigo)){
		getline(archivo,patologias[contador_patologias].descripcion);
		contador_patologias++;
	}
	archivo.close();
	/// Carga de datos
	int dia;
	string DNI;
	string codigo_patologia;
	cout << "Ingrese dia: ";
	cin >> dia;
	while(dia != 99){
		cout << "Ingrese DNI: ";
		cin >> DNI;
		int pos = Busqueda(DNI,pacientes,contador_pacientes);
		if (pos == -1){
			pacientes[contador_pacientes].DNI = DNI;
			getline(cin,pacientes[contador_pacientes].Apellido);
			getline(cin,pacientes[contador_pacientes].Nombres);
			cin >> pacientes[contador_pacientes].FechaNacimiento 
				>> pacientes[contador_pacientes].ObraSocial
				>> pacientes[contador_pacientes].descripcion
				>> pacientes[contador_pacientes].codigo_patologia;
			cin.ignore();
			codigo_patologia = pacientes[contador_pacientes].codigo_patologia;
			pacientes[contador_pacientes].edad = ObtenerEdad(pacientes[contador_pacientes].FechaNacimiento);
			contador_pacientes++;
		} else {
			cout << "Ingrese codigo de patologia: ";
			cin >> codigo_patologia;
			if (ExtraccionCaracteres(pacientes[pos].codigo_patologia,2) == "VR")
				pacientes[pos].codigo_patologia = codigo_patologia;
		}
		
		pos = Busqueda(codigo_patologia,patologias,contador_patologias);
		if (dia < 16)
			patologias[pos].quincena1++;
		else 
			patologias[pos].quincena2++;
		
		cout << "Ingrese dia: ";
		cin >> dia;
	}
	/// Informes
	// Informe a;
	int pacientes_60 = 0;
	int paciente_cronico = 0;
	for (int i = 0; i < contador_pacientes; i++){
		if (pacientes[i].edad > 60)
			pacientes_60++;
		if (pacientes[i].edad > 60 && (ExtraccionCaracteres(pacientes[i].codigo_patologia,2) != "VR"))
			paciente_cronico++;
	}
	cout << "Porcentaje de pacientes +60 años con enfermedad cronica: " << (paciente_cronico*100)/pacientes_60 << "%\n";
	// Informe b;
	cout << "Codigo    Descripcion     1º Quincena     2ºQuincena";
	for (int i = 0; i < contador_patologias; i++)
		cout <<patologias[i].codigo << "   "<<patologias[i].descripcion << "   "<<patologias[i].quincena1 << "   "<<patologias[i].quincena2 << endl;
	
	// Actividad c;
	ofstream archi; archi.open("./PACIENTES_NEW.txt");
	for (int i = 0; i < contador_pacientes; i++) 
		archi << pacientes[i].DNI << endl 
			<< pacientes[i].Apellido<< endl 
			<< pacientes[i].Nombres<< endl 
			<< pacientes[i].FechaNacimiento<< endl 
			<< pacientes[i].ObraSocial<< endl 
			<< pacientes[i].descripcion<< endl 
			<< pacientes[i].codigo_patologia << endl;
	archi.close();
	return 0;
}

int ObtenerEdad(string FechaPaciente){
	int edad;
	int anio_actual = 2023;
	int anio_nacimiento = stoi(FechaPaciente.substr(0,4));
	
	edad = anio_actual - anio_nacimiento;
	
	return edad;
}
string ExtraccionCaracteres(string Texto, int longitud){
	string caracteres = "";
	for (int  i = 0; i < longitud; i++)
		caracteres += Texto[i];
	return caracteres;
}
	
int Busqueda(string dato, paciente p[], int max){
	for (int i = 0; i < max; i++)
		if (dato == p[i].DNI)
			return i;
	return -1;
}
int Busqueda(string dato, patologia p[], int max){
	for (int i = 0; i < max; i++)
		if (dato == p[i].codigo)
			return i;
	return -1;
}
	
