Algoritmo ejercicio2B
	//version con TRUNC
	Definir n1 Como Entero;
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
	Si n1/2=trunc(n1/2) Entonces
		Escribir "El número es par";
	SiNo
		Escribir "El número no es par";
	FinSi
	//Punto C
	Si n1/5=trunc(n1/5) y n1/3=trunc(n1/3) Entonces
		Escribir "El número es múltiplo de 5 y 3 a la vez";
	FinSi
FinAlgoritmo
