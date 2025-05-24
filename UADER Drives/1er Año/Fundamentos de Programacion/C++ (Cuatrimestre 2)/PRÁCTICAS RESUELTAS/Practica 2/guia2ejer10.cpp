#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*Una empresa desea calcular el sueldo de un empleado sabiendo que el sueldo básico
		depende de la categoría. Además, se le paga un adicional por antigüedad.
		La determinación del básico se realiza según el siguiente detalle:
		
		Categoría Sueldo Básico
		1 $ 60.000,00.-
		2 $ 50.000,00.-
		3 $ 40.000,00.-
		4 $ 30.000,00.-
		
		La antigüedad se calcula en base a la siguiente tabla:
		Antigüedad Porcentaje
		0-10 años 20%
		11-15 años 50%
		16-20 años 80 %
		más de 20 años 100%
		
		Para ello se ingresan los datos de un empleado en el siguiente orden: Apellido y nombre,
		categoría (1 a 4) y antigüedad.
		Informar con el siguiente formato:
		Apunte elaborado por la cátedra Fundamentos de Programación – Sede Oro Verde Pág. Nro. 3
		
		APELLIDO Y NOMBRE: ..........................................................
		CATEGORÍA: ...... SUELDO BÁSICO: $ ......................
		ANTIGÜEDAD: ........ AÑOS MONTO ANTIGÜEDAD: $.................
		SUELDO TOTAL: $ ................................*/
	int cat,antiguedad;
	string nya;
	float sueldo,sueldoant;
	cout<<"Ingrese nombre y apellido del empleado"<<endl;
	getline(cin,nya);
	cout<<"Ingrese la categoria a la que pertenece (1,2,3 o 4)"<<endl;
	cin>>cat;
	cout<<"Ingrese los años de antiguedad"<<endl;
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
	cout<<"Categoría: "<<cat<<"      "<<"Sueldo básico: $"<<sueldo<<endl;
	cout<<"Antiguedad: $"<<antiguedad<<"     "<<"Años monto antiguedad: $"<<sueldoant<<endl;
	cout<<"Sueldo total: $"<<sueldo+sueldoant<<endl;
	
	return 0;
}

