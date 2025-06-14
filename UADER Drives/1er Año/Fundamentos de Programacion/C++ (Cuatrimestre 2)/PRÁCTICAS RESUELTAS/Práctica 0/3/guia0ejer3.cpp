#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	int dia,mes,anio,fecha;
	cout<<"Ingrese fecha en formato MM/DD/AAAA"<<endl;
	cin>>fecha;
	mes=(fecha/10000);
	fecha=fecha-(mes*10000);
	dia=(fecha/100);
	anio=fecha-(dia*100);
	cout<<dia<<"/"<<mes<<"/"<<anio;
	
		return 0;
}

