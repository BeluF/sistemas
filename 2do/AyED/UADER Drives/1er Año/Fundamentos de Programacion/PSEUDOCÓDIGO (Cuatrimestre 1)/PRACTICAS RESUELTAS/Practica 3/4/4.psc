Algoritmo ej4
	//Realice un algoritmo que solicite el ingreso de 2 números A y B. Donde A debe ser menor
	//que B. Luego liste los números comprendidos entre A y B, incluyéndolos.
	Definir a, b, aux Como Entero;
	
	//metemos en un repetir como método de verificación de que A sea menor que B.
	Repetir
		Escribir "Ingrese números A y B, A debe ser menor que B.";
		Leer a,b;
	Hasta Que a<b
	
	//iniciamos en A y que vaya aumentando de 1 en un 1 hasta alcanzar a B.
	aux=a;
	Escribir "Números comprendidos entre A y B:";
	Mientras aux<=b Hacer
		Escribir aux;
		aux=aux+1;
	FinMientras
FinAlgoritmo
