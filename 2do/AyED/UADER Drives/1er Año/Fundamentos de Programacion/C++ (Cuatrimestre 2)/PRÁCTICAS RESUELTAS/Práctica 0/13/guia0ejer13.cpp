#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Una alumno ha rendido 2 ex�menes parciales y ha presentado un trabajo
	pr�ctico. Seg�n las calificaciones obtenidas, se determina la calificaci�n del
	alumno:
	El promedio de los parciales constituye el 80% de la calificaci�n final, el 20%
	restante es la correspondiente al trabajo pr�ctico. Tanto los parciales como el
	trabajo pr�ctico son calificados entre 0 y 100.
	Se ingresan las 3 notas obtenidas. Informar la nota final.*/
	int parc1,parc2,tp;
	float promedio;
	cout<<"Ingrese nota del primer parcial y luego del segundo"<<endl;
	cin>>parc1>>parc2;
	cout<<"Ingrese nota del TP"<<endl;
	cin>>tp;
	promedio=((((parc1+parc2)/2)*80)/100)+((tp*20)/100);
	cout<<"Su promedio es de: "<<promedio;
	return 0;
}

