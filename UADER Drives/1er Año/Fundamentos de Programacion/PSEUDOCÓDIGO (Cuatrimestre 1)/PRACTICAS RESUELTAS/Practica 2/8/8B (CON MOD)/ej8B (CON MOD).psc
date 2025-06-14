Algoritmo ejercicio8B
	//Usando el MOD (%) 
	//Para que un año sea biciesto debe: (multiplo de 4 & no ser multiplo de 100) | (multiplo de 100 & multiplo de 400)
	Definir year Como Entero;
	
	//carga de datos
	Escribir Sin Saltar "Ingrese el año: ";
	Leer year;
	
	//decision
	si (year%4=0 y year%100<>0) o (year%100=0 y year%400=0) Entonces
		Escribir "El año es bisiesto";
	SiNo
		Escribir "El año no es bisiesto";
	FinSi
FinAlgoritmo

