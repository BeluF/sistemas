Algoritmo ejercicio8A
	//Usando el TRUNC
	//Para que un a�o sea biciesto debe: (multiplo de 4 & no ser multiplo de 100) | (multiplo de 100 & multiplo de 400)
	Definir year Como Entero;
	
	//carga de datos
	Escribir Sin Saltar "Ingrese el a�o: ";
	Leer year;
	
	//decision
	si (year/2=trunc(year/2) y year/100<>trunc(year/100)) o (year/100=trunc(year/100) y year/400=trunc(year/400)) Entonces
		Escribir "El a�o es bisiesto";
	SiNo
		Escribir "El a�o no es bisiesto";
	FinSi
FinAlgoritmo