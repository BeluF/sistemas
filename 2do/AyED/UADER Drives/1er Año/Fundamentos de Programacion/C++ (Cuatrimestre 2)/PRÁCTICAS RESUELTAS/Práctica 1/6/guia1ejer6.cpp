#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string nya1,nya2;
	float kmr1,kmr2,sueldo1,sueldo2;
	cout<<"Ingrese nombre 1 y luego nombre 2 "<<endl;
	getline(cin,nya1);
	getline(cin,nya2);
	cout<<"Ingrese sueldo basico del chofer 1 y luego del chofer 2"<<endl;
	cin>>sueldo1>>sueldo2;
	cout<<"Ingrese los km recorridos del chofer 1 y luego del chofer 2"<<endl;
	cin>>kmr1>>kmr2;
	float tot1=sueldo1+(kmr1*50), tot2=sueldo2+(kmr2*50);
	float totgral=tot1+tot2;
	cout<<"LIQUIDACION MENSUAL CHOFERES"<<endl<<"nombre chofer 1: "<<nya1<<"		total a cobrar: $"<<sueldo1<<endl<<"nombre chofer 2: "<<nya2<<" 		total a cobrar: $"<<tot2<<endl<<"Total general: $"<<totgral;
	
	return 0;
}

