#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
	ifstream archi;

	string nombre[51];
	int i, c, codi;
	
	c=0;
	archi.open ("./CIUDADES.TXT");
	if ( archi.fail() ) {
		cout << "Error en la apertura del archivo.";
	}
	else {	
		archi>>codi;
		while (!archi.eof())
		{
			
			archi.ignore();
			getline(archi,nombre[codi]);
			c++;
			archi>>codi;
			
		}
	}	
	archi.close ();
	
	for (int i=1; i<c+1; i++) {
		cout << i<<" "<<nombre[i]<<endl;
		
	}
	return 0;
}

