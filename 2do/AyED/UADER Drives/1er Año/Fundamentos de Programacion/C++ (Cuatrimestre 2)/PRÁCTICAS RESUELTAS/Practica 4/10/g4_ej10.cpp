#include <iostream>
#include <string>

using namespace std;

/* 
Ingresar una cadena de caracteres que represente una direcci�n de correo electr�nico. Se
desea validar la direcci�n para lo cual debe terminar en �.com�, debe tener una @ entre la
segunda posici�n y al menos una antes de �.com�. Y no debe tener espacios en blanco.
*/

int main(int argc, char *argv[]) {
	string correo;
	
	cout << "Ingrese correo electr�nico: ";
	getline (cin,correo);
	
	// Si no encuentra un espacio (-1) pasamos a evaluar lo dem�s.
	if (correo.find(" ")==-1){
		
		// Ubicamos donde est� el arroba, a partir de la 2da posici�n.
		int pos=correo.find("@",1);
		
		// Si hay un arroba (!-1) procedemos a buscar el .com
		if (pos!=-1)
		{
			// Utilizamos la posici�n donde se encontr� el arroba para apartir de ah� buscar el .com, ya que teoricamente va dsps del @
			if (correo.find(".com",pos)!=-1)
			{
				cout << "Correo v�lido";
			}
			else cout << "El correo no posee \".com\"";
		}
		else cout << "El correo no posee \"@\"";
	}
	else cout << "Correo inv�lido.";
	
	return 0;
}

