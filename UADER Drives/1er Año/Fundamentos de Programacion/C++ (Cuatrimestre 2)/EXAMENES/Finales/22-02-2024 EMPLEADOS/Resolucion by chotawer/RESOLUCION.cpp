#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Resolucion by chotawer v1

/// Structs
struct empleado{
	string ID;
	string apellido;
	string nombre;
	string fecha_asignacion;
	int nivel_Exp;
	string codigo_proyecto;
};
struct proyecto{
	string codigo;
	string nombre;
	string area_esp;
	int quincena1 = 0;
	int quincena2 = 0;
};

/// Funciones
int buscar(empleado e[], int max, string dato );
int buscar(proyecto p[], int max, string dato );
int ErrorCode(string direccion);

int main(int argc, char *argv[]) {
	/// Variables
	empleado e[999];
	proyecto p[999];
	int contador_e = 0;
	int contador_p = 0;
	int dia;
	string id_empleado;
	ifstream archivo;
	ofstream archivo_Salida;

	/// Lectura
	archivo.open("./EMPLEADOS.TXT");
	if (archivo.fail())
		return ErrorCode("./EMPLEADOS.TXT");
	while (getline(archivo,e[contador_e].ID)){
		getline(archivo,e[contador_e].apellido);
		getline(archivo,e[contador_e].nombre);
		archivo >> e[contador_e].fecha_asignacion 
				>> e[contador_e].nivel_Exp 
				>> e[contador_e].codigo_proyecto;
		archivo.ignore();
		contador_e++;
	}
	archivo.close();
	archivo.open("./PROYECTOS.TXT");
	if (archivo.fail())
		return ErrorCode("./PROYECTOS.TXT");
	while (getline(archivo,p[contador_p].codigo)){
		getline(archivo,p[contador_p].nombre);
		getline(archivo,p[contador_p].area_esp);
		contador_p++;
	}
	archivo.close();
	
	/// Punto A
	cout << "Carga de empleados del mes de enero de 2024"
		 << "\nIngrese dia de asignacion: ";
	cin >> dia;
	cout << "Ingrese ID del empleado: ";
	cin >> id_empleado;
	
	while(id_empleado != "0"){
		int pos = buscar(e,contador_e,id_empleado);
		if (pos == -1){
			cin.ignore();
			e[contador_e].ID = id_empleado;
			cout << "Ingrese apellido del empleado: ";
			getline(cin,e[contador_e].apellido);
			cout << "Ingrese nombre del empleado: ";
			getline(cin,e[contador_e].nombre);
			cout << "Ingrese nivel de experiencia del empleado: ";
			cin >> e[contador_e].nivel_Exp;
			pos = contador_e;
			contador_e++;
		}
		
		cout << "Ingrese codigo de proyecto, y fecha de asignacion del mismo: ";
		cin >> e[pos].codigo_proyecto 
			>> e[pos].fecha_asignacion;
		
		pos = buscar(p,contador_p,e[pos].codigo_proyecto);
		if (pos == -1)
			cout << "Codigo de proyecto no encontrado.";
		else
			if (dia < 16)
				p[pos].quincena1++;
			else p[pos].quincena2++;
		

		cout << "Carga de empleados del mes de enero de 2024"
			 << "\nIngrese dia de asignacion: ";
		cin >> dia;
		cout << "Ingrese ID del empleado: ";
		cin >> id_empleado;
	}
	/// Punto B
	int empleados_req = 0;
	for (int i = 0; i < contador_e; i++){
		string codigo = e[i].codigo_proyecto;
		if (e[i].nivel_Exp > 3 && (codigo.find("PRJDIU") != -1))
			empleados_req++;
	}
	float porcentaje = (empleados_req*100) / contador_e;
	cout << "\nPorcentaje de empleados con +3 años de exp: " << porcentaje;
	/// Punto C
	cout << setw(20) <<"\nCod. Proyecto"<< setw(40) << "Area de especialización"<< setw(20) << "Quincena 1"<< setw(15) << "Quincena 2" << endl;
	for (int i = 0; i < contador_p; i++)
		cout << setw(10)<< p[i].codigo<< setw(50) << p[i].area_esp<< setw(7) << p[i].quincena1<< setw(18) << p[i].quincena2 << endl;
	
	/// Punto D
	archivo_Salida.open("./EMPLEADOS_PROYECTOS.TXT");
	for (int i = 0; i < contador_e; i++){
		int pos = buscar(p,contador_p,e[i].codigo_proyecto);
		archivo_Salida  << e[i].ID << endl
						<< e[i].codigo_proyecto << endl
						<< p[pos].area_esp << endl;
		}
	archivo_Salida.close();
	return 0;
}

int ErrorCode(string direc){
	cout <<"======================================================================================\n" 
		<< "Error al abrir "<< direc <<", puede no estar en la carpeta donde se encuentra el programa\n"
		<< "======================================================================================\n";
	return 404;
}

int buscar(empleado e[], int max, string dato ){
	for (int i = 0; i < max; i++)
		if (e[i].ID == dato)
			return i;
	return -1;
}
	
int buscar(proyecto p[], int max, string dato ){
	for (int i = 0; i < max; i++)
		if (p[i].codigo == dato)
			return i;
	return -1;
}
