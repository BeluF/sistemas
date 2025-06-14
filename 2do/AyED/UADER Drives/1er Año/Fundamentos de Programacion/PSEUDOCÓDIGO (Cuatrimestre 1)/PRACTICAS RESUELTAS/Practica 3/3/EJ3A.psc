Algoritmo ejercicio3A
	// Realice un algoritmo que solicite el ingreso de un número (entero positivo) e informe su
	// tabla de multiplicar (del 1 al 10).
	
	//Version A -> Usando el PARA
	Definir i, num Como Entero;
	
	Escribir "Ingrese un número entero positivo";
	Leer num;
	
	si num>=0 Entonces
		para i<-1 hasta 10 con paso 1 Hacer
			Escribir "Tabla del ",i,": ",num*i;
		FinPara
	sino 
		Escribir "El número ingresado no es un entero positivo";
	FinSi
	
FinAlgoritmo
