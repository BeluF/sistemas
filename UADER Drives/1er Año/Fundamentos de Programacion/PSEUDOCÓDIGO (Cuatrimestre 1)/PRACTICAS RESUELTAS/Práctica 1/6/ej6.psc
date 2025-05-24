Algoritmo ejercicio6
	Definir nombre1,nombre2 Como Caracter;
	Definir sueldobasico Como Entero;
	Definir km1,km2 como real;
	Escribir "Ingrese el sueldo básico";
	Leer sueldobasico;
	Escribir "Ingrese datos del primer chofer (Nombre, km)";
	Leer nombre1, km1;
	Escribir "Ingrese datos del segundo chofer (Nombre, km)";
	Leer nombre2, km2;
	Escribir "LIQUIDACIÓN MENSUAL DE CHOFERS";
	Escribir Sin Saltar "NOMBRE DEL CHOFER 1: ", nombre1;
	Escribir "          TOTAL A COBRAR $ ",km1*50+sueldobasico;
	Escribir Sin Saltar "NOMBRE DEL CHOFER 2: ", nombre2;
	Escribir "          TOTAL A COBRAR $ ",km2*50+sueldobasico;
	Escribir "TOTAL GRAL $",(km1*50+sueldobasico)+(km2*50+sueldobasico);
FinAlgoritmo
