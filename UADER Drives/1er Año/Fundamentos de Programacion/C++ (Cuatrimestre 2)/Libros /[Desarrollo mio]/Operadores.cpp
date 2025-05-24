#include <iostream>
using namespace std;

int main(){
	int a=2,b=2,c=3;
	cout<< a++<<endl;
	cout<<a<<"+"<<b<<"=";
	a+=b;
	cout<<a<<endl;
	a=b=c=10;
	cout<<c<<" y "<<b<<" son iguales.";
	return 0;
}
