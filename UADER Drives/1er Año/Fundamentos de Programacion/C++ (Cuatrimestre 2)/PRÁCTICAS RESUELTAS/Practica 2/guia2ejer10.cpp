#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*Una empresa desea calcular el sueldo de un empleado sabiendo que el sueldo b�sico
		depende de la categor�a. Adem�s, se le paga un adicional por antig�edad.
		La determinaci�n del b�sico se realiza seg�n el siguiente detalle:
		
		Categor�a Sueldo B�sico
		1 $ 60.000,00.-
		2 $ 50.000,00.-
		3 $ 40.000,00.-
		4 $ 30.000,00.-
		
		La antig�edad se calcula en base a la siguiente tabla:
		Antig�edad Porcentaje
		0-10 a�os 20%
		11-15 a�os 50%
		16-20 a�os 80 %
		m�s de 20 a�os 100%
		
		Para ello se ingresan los datos de un empleado en el siguiente orden: Apellido y nombre,
		categor�a (1 a 4) y antig�edad.
		Informar con el siguiente formato:
		Apunte elaborado por la c�tedra Fundamentos de Programaci�n � Sede Oro Verde P�g. Nro. 3
		
		APELLIDO Y NOMBRE: ..........................................................
		CATEGOR�A: ...... SUELDO B�SICO: $ ......................
		ANTIG�EDAD: ........ A�OS MONTO ANTIG�EDAD: $.................
		SUELDO TOTAL: $ ................................*/
	int cat,antiguedad;
	string nya;
	float sueldo,sueldoant;
	cout<<"Ingrese nombre y apellido del empleado"<<endl;
	getline(cin,nya);
	cout<<"Ingrese la categoria a la que pertenece (1,2,3 o 4)"<<endl;
	cin>>cat;
	cout<<"Ingrese los a�os de antiguedad"<<endl;
	cin>>antiguedad;
	switch (cat) 
	{
	case 1: sueldo=60000;
	break;
	case 2: sueldo=50000;
	break;
	case 3: sueldo=40000;
	break;
	case 4: sueldo= 30000;
	break;	
	}
	if (antiguedad <= 10)
	{
		sueldoant= (sueldo*0.20);
	}
	else if ((antiguedad > 11) && (antiguedad <= 15))
	{
		sueldoant= (sueldo*0.5);
	}
	else if ((antiguedad > 16) && (antiguedad <= 20))
	{
		sueldoant= (sueldo*0.8);
	}
	else sueldoant= sueldo;
	cout<<"Apellido y Nombre: "<<nya<<endl;
	cout<<"Categor�a: "<<cat<<"      "<<"Sueldo b�sico: $"<<sueldo<<endl;
	cout<<"Antiguedad: $"<<antiguedad<<"     "<<"A�os monto antiguedad: $"<<sueldoant<<endl;
	cout<<"Sueldo total: $"<<sueldo+sueldoant<<endl;
	
	return 0;
}

