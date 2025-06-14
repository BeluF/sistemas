Algoritmo CaF
	definir temp Como Real;
	definir menu Como Caracter;
	Escribir "Ingrese escala de temperatura a utilizar";
	Escribir "C para Celsius o F para Farenheit";
	leer menu;
	si menu="C" Entonces
		Escribir "Ingrese la temperatura a convertir";
		leer temp;
		Escribir temp, "ºC equivale a: ", (temp*9/5) + 32,"ºF";
	FinSi
	si menu="F" Entonces
		Escribir "Ingrese la temperatura a convertir";
		leer temp;
		Escribir temp, "ºF equivale a: ", (temp-32) * 5/9,"ºC";
	FinSi
FinAlgoritmo
