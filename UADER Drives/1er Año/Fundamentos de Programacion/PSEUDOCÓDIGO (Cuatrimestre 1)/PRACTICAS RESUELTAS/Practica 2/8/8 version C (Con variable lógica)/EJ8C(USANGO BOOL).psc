Algoritmo ejercicio8c
	//Usando el MOD (%) y usando una variable l�gica
	
	//Las variables L�GICAS solo pueden adquirir 2 valores, verdadero o falso.
	
	//Para que un a�o sea biciesto debe: (multiplo de 4 & no ser multiplo de 100) | (multiplo de 100 & multiplo de 400)
 	Definir year Como Entero;
	Definir bisiesto Como Logico;
	//carga de datos
	Escribir Sin Saltar "Ingrese el a�o: ";
	Leer year;
	//procesamiento de datos
	bisiesto=(year%4=0 y year%100<>0) o (year%100=0 y year%400=0);
	//decision
	si bisiesto Entonces
		Escribir "El a�o es bisiesto";
	SiNo
		Escribir "El a�o no es bisiesto";
	FinSi
FinAlgoritmo
