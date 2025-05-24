Algoritmo ejercicio8A
	//Usando el TRUNC
	//Para que un año sea biciesto debe: (multiplo de 4 & no ser multiplo de 100) | (multiplo de 100 & multiplo de 400)
	Definir year Como Entero;
	
	//carga de datos
	Escribir Sin Saltar "Ingrese el año: ";
	Leer year;
	
	//decision
	si (year/2=trunc(year/2) y year/100<>trunc(year/100)) o (year/100=trunc(year/100) y year/400=trunc(year/400)) Entonces
		Escribir "El año es bisiesto";
	SiNo
		Escribir "El año no es bisiesto";
	FinSi
FinAlgoritmo