#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
	Generador de archivos by chotawer
	Version 1
*/

int main(int argc, char *argv[]) {
	int registros, cantidad, contador_datos;
	string linea, nombre_archivo, nombre_cpp;
	
	cout << "Ingrese cantidad de archivos a generar: ";
	cin >> cantidad;
	cin.ignore();
	
	for (int i = 0; i < cantidad; i++){
		contador_datos = 1;
		cout << "Ingrese nombre del archivo generador: ";
		getline(cin, nombre_cpp);
		nombre_archivo = "\"./" + nombre_cpp + ".txt\"";
		nombre_cpp = "./generador_" + nombre_cpp + ".cpp";
		cout << "Ruta establecida como: " << nombre_cpp << endl;
//		cout << "Ingrese nombre del archivo txt que generará: ";
//		getline(cin, nombre_archivo);
		
		
		ofstream genera_cpp; genera_cpp.open(nombre_cpp);
		genera_cpp << "#include <iostream>\n#include <fstream>\n#include <string>\n" 
			<< "using namespace std;\nint main (int argc, char *argv[]) {\n"
			<< "\tofstream archivo; archivo.open(" << nombre_archivo << ");\n\n";
		
		cout << "Ingrese tamaño de registros por archivo (Cantidad de renglones que ocupa un solo conjunto de datos): ";
		cin >> registros;
		cin.ignore();
		cout << "######################################\nComienze a escribir los datos [FIN: Fin de datos]: \n";
		cout << "Conjunto de datos número: " << contador_datos << endl;
		getline(cin,linea);
		while (linea != "FIN"){
			genera_cpp << "\tarchivo << \"" << linea << "\" << endl";
			for (int i = 1; i < registros; i++){
				getline(cin,linea);
				genera_cpp << " << \"" << linea << "\" << endl";
			} genera_cpp <<";"<< endl;
			
			contador_datos++;
			cout << "Conjunto de datos número: " << contador_datos << endl;
			
			getline(cin,linea);
		}
		genera_cpp << "\n\tarchivo.close();\n\treturn 0;\n}";
		genera_cpp.close();
	}
	
	return 0;
}

