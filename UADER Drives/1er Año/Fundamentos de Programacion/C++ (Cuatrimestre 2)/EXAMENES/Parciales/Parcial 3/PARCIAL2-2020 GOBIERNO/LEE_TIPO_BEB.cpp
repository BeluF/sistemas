#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
	ifstream archi;

	string descr[8];
	int tipob[8];
	int i, c, codb;
	
	c=0;
	archi.open ("./TIPOS_DE_BEBIDA.TXT");
	if ( archi.fail() ) {
		cout << "Error en la apertura del archivo.";
	}
	else {	
		archi>>codb;
		while (!archi.eof())
		{
			archi>>tipob[codb];
			archi.ignore();
			getline(archi,descr[codb]);
			c++;
			archi>>codb;
			
		}
	}	
	archi.close ();
	
	for (int i=1; i<c+1; i++) {
		cout << i<<" "<<tipob[i]<<" "<<descr[i]<<endl;
	}
	return 0;
}

