Algoritmo ejercicio2
	Definir n1 Como Real;
	Escribir "Ingrese el n�mero: "; Leer n1; 
	//Punto A
	Si n1>0 Entonces 							
		Escribir "El n�mero es positivo";
	SiNo
		Si n1<0 Entonces
			Escribir "El n�mero es negativo";
		SiNo
			Escribir "El n�mero es cero";
		FinSi
	FinSi
	//Punto B
	Si (n1%2=0) Entonces
		Escribir "El n�mero es par";
	SiNo
		Escribir "El n�mero no es par";
	FinSi
	//Punto C
	Si (n1%5=0) y (n1%3=0) Entonces
		Escribir "El n�mero es m�ltiplo de 5 y 3 a la vez";
	FinSi
FinAlgoritmo
