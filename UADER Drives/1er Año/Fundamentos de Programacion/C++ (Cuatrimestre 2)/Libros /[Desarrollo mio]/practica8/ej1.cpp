#include <iostream>
#include <string>

using namespace std;

const int n=5,m=2;

struct ficha_alumno {
	string nya;
	string mataprob[n];
	string matcurs[n];
	int nma[n]; //Notas Materias Aprobadas
	int parciales[n][m];
	char ape[12];
};

int main(){
	ficha_alumno x,y,z;
	cin>>x.ape;	//char solamente se puede usar en cin
	cin.ignore(100,'\n');
	getline(cin,x.nya);	//string usado en getline
	cout<<x.nya<<endl;
	cout<<x.ape;
}
