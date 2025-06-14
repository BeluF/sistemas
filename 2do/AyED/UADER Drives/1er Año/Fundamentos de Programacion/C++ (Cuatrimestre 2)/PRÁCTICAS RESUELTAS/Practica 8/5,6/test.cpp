#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file; file.open("./PROVINCIAS.txt");
	string prueba;
	file>>prueba;
	cout<<prueba;
	file>>prueba;
	cout<<prueba<<endl;
	file>>prueba;	
	cout<<prueba;
	file.close();
	return 0;
}
