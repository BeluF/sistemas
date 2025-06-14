#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	/*Los docentes de la c�tedra Programaci�n desean contar con un programa que ingresada
	la nota de los 3 parciales rendidos por un alumno y los valores m�nimos de promedios para
	promocionar y regularizar, determine la condici�n del alumno en la materia (Libre, Regular o
	Promocionado).
	Solo si promociona debe informar adem�s la nota correspondiente para la libreta y el
	concepto para el acta de cierre.
	La Nota se obtiene aplicando la sig. f�rmula:
	Nota = Redondeo( (Promedio - A ) *6 / ( 100 � A ) + 4 )
	A= l�mite para promoci�n
	Tenga en cuenta la siguiente tabla para determinar el concepto del alumno:
	Nota Concepto
	4 � 5 Aprobado
	6 � 7 Bueno
	8 � 9 Distinguido
	10 Sobresaliente
	Observaciones: Las notas de los parciales y los valores m�nimos son valores entre 0 y 100.*/
	float n1,n2,n3;
	int regular,promocion;
	string concepto,condicion;
	cout<<"Ingrese los valores para promocionar y luego para regularizar"<<endl;
	cin>>promocion>>regular;
	cout<<"Ingrese la nota de los 3 parciales (del 1 al 100)"<<endl;
	cin>>n1>>n2>>n3;
	float promedio=(n1+n2+n3)/3; 
	int nota=((promedio-promocion)*6) /(100-promocion)+4;
	if ((nota==4) ||(nota==5))
	{
	concepto="aprobado";
	}
	else if ((nota==6) || (nota==7))
	{
	concepto="Bueno";
	}
	else if ((nota==8) || (nota==9))
	{
	concepto="Distinguido";
	}
	else concepto="Sobresaliente";
	if (nota>=promocion) 
	{
	condicion="Promocionado";
	}
	else if (nota>regular)
	{
	condicion="Regular";
	}
	else condicion="Libre";
	if (condicion=="Promocionado")
	{
	cout<<"El alumno se encuentra en la condici�n de: "<<condicion<<" Teniendo una nota para su libreta de: "<<nota<<" , con un concepto: "<<concepto<<endl;
	}
	else cout<<"El alumno se encuentra en la condici�n de: "<<condicion;
	return 0;
}

