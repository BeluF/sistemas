Algoritmo ejercicio2
	Definir n1 Como Real;
	Escribir "Ingrese el número: "; Leer n1; 
	//Punto A
	Si n1>0 Entonces 							
		Escribir "El número es positivo";
	SiNo
		Si n1<0 Entonces
			Escribir "El número es negativo";
		SiNo
			Escribir "El número es cero";
		FinSi
	FinSi
	//Punto B
	Si (n1%2=0) Entonces
		Escribir "El número es par";
	SiNo
		Escribir "El número no es par";
	FinSi
	//Punto C
	Si (n1%5=0) y (n1%3=0) Entonces
		Escribir "El número es múltiplo de 5 y 3 a la vez";
	FinSi
FinAlgoritmo
