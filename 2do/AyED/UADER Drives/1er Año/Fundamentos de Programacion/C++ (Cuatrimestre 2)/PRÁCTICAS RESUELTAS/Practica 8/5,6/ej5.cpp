#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

/*5. 
Se necesita generar un archivo con los nombres de las 24 provincias. De acuerdo al orden de
ingreso se les asigna un código (entre 0 y 23).
En el archivo PROVINCIAS.TXT se almacena, por renglón, código y nombre separados por espacio
en blanco.
*/
using namespace std;

int main(int argc, char *argv[] ){
	ofstream provincias; provincias.open("./PROVINCIAS.txt");
	if (provincias.fail()) cout<<"Error al abrir el archivo PROVINCIAS.txt";
	else {
		int c=0; string nombre;
		do{
			cout<<"Ingrese nombre de la provincia: "; getline(cin,nombre);
			provincias<<c<<" "<<nombre<<endl;
			c++;
		}while(c<24);
	}
	provincias.close();
	return 0;
}
