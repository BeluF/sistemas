#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	int a,b,d;
	string c;
	cout<<"Ingrese 3 numeros"<<endl;
	cin>>a>>b>>d;
	cout<<endl<<"Los numeros ingresados fueron "<<a<<" y "<<b<<endl<<endl;
	if (a>b&&a==d)
		cout<<a<<" es el numero mas grande"<<endl;
	else if (a<b)
		cout<<b<<" es el numero mas grande";
	else cout<<"Los 2 numeros  ingresados son iguales";
	//CONCATERNACION DE 2 STRINGS USANDO <SSTREAM>
	cout<<endl;
	cin>>c;
	ostringstream casa;
	casa<<c[1]<<c[0];
//	c=casa.str();
	cout<<endl<<casa.str();
	
}
