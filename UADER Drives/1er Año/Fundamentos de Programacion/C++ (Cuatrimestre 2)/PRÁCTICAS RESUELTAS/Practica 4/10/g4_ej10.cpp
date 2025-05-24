#include <iostream>
#include <string>

using namespace std;

/* 
Ingresar una cadena de caracteres que represente una dirección de correo electrónico. Se
desea validar la dirección para lo cual debe terminar en “.com”, debe tener una @ entre la
segunda posición y al menos una antes de “.com”. Y no debe tener espacios en blanco.
*/

int main(int argc, char *argv[]) {
	string correo;
	
	cout << "Ingrese correo electrónico: ";
	getline (cin,correo);
	
	// Si no encuentra un espacio (-1) pasamos a evaluar lo demás.
	if (correo.find(" ")==-1){
		
		// Ubicamos donde está el arroba, a partir de la 2da posición.
		int pos=correo.find("@",1);
		
		// Si hay un arroba (!-1) procedemos a buscar el .com
		if (pos!=-1)
		{
			// Utilizamos la posición donde se encontró el arroba para apartir de ahí buscar el .com, ya que teoricamente va dsps del @
			if (correo.find(".com",pos)!=-1)
			{
				cout << "Correo válido";
			}
			else cout << "El correo no posee \".com\"";
		}
		else cout << "El correo no posee \"@\"";
	}
	else cout << "Correo inválido.";
	
	return 0;
}

