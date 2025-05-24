#include <iostream>
#include <string>
using namespace std;

// Practica Cadenas
// 1) Dadas 3 cadenas de caracteres, ordenarlas de acuerdo a su orden alfabético.

int main(int argc, char *argv[]) 
{
	string uno,dos,tres;
	
	getline(cin,uno);
	getline(cin,dos);
	getline(cin,tres);
	
	cout << "\nCadenas ordenadas:\n";
	
	// Detectar cual es la primer palabra a ordenar
	
	if ((uno < dos) && (uno < tres))
		cout << uno << endl;
	else 
		if ((dos < uno) && (dos < tres))
			cout << dos << endl;
		else 
			cout << tres << endl;
	
	// Detectar cual es la segunda palabra a ordenar
	
	if (((uno > dos) && (uno < tres)) || ((uno < dos) && (uno > tres)))
		cout << uno << endl;
	else 
		if ((dos > uno) && (dos < tres))
			cout << dos << endl;
		else 
			cout << tres << endl;
	
	// Detectar cual es la tercera palabra a ordenar
	
	if ((uno > tres) && (uno > dos))
		cout << uno << endl;
	else 
		if ((dos > uno) && (dos > tres))
			cout << dos << endl;
		else 
			cout << tres << endl;
	
	return 0;
}

