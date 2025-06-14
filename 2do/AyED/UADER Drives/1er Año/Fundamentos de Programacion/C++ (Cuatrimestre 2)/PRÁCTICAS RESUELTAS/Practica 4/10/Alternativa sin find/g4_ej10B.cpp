#include <iostream>
using namespace std;

/* 
Ingresar una cadena de caracteres que represente una dirección de correo electrónico. Se
desea validar la dirección para lo cual debe terminar en “.com”, debe tener una @ entre la
segunda posición y al menos una antes de “.com”. Y no debe tener espacios en blanco.
*/

int main(int argc, char *argv[]) {
	string correo;
	bool tienearroba = false, tienecom = false;
	
	cout << "Ingrese correo electrónico: ";
	getline (cin, correo);
	
	int i = 0; int pos = -1; int longitud = correo.size();
	while ((correo[i]!=' ' && i<longitud) && (!tienearroba || !tienecom))
	{
		if ((!tienearroba) && (correo[i]=='@' && i>0))
		{
			tienearroba=true;
			pos=i;
		}
		if ((i>=pos && i+3 <= longitud) && (correo[i]=='.' && correo[i+1]=='c' && correo[i+2]=='o' && correo[i+3]=='m' ))
		{
			tienecom = true;
		}
		
		++i;
	}
	
	if (tienearroba && tienecom) cout << "Correo válido.";
	else 
	{
		cout << "Correo inválido";
		if (!tienearroba) 
			cout << "\nFalta \"@\"";
		if (!tienecom) 
			cout << "\nFalta \".com\"";
	}
	
	return 0;
}

