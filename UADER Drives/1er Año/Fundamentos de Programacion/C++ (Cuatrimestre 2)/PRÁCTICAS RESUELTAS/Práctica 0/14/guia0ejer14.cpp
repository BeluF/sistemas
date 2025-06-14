#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Un abuelo desea repartir el 15% de sus ingresos entre sus tres nietos en forma
		proporcional a la edad de ellos. Se ingresa el sueldo cobrado por el abuelo y las
		edades de sus nietos. Informar el total a repartir y lo que le corresponde a cada uno
		de los nietos.*/
	float porcentaje,sueldo;
	int edad1,edad2,edad3;
	cout<<"Ingrese la edad del primer, luego del segundo y por ultimo del tercer nieto"<<endl;
	cin>>edad1>>edad2>>edad3;
	cout<<"Ingrese Sueldo"<<endl;
	cin>>sueldo;
	porcentaje=(15*sueldo)/100;
	cout<<"El total a repartir es de: $"<<porcentaje<<endl;
	cout<<"Al nieto de "<<edad1<< "años le corresponde: $"<<(porcentaje*edad1)/(edad1+edad2+edad3)<<endl;
	cout<<"Al nieto de "<<edad2<< "años le corresponde: $"<<(porcentaje*edad2)/(edad1+edad2+edad3)<<endl;
	cout<<"Al nieto de "<<edad3<< "años le corresponde: $"<<(porcentaje*edad3)/(edad1+edad2+edad3)<<endl;
	return 0;
}

