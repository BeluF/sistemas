Algoritmo ejercicio3B
	// Realice un algoritmo que solicite el ingreso de un n�mero (entero positivo) e informe su
	// tabla de multiplicar (del 1 al 10).
	
	//Version B -> Usando el Mientras 
	Definir i, num Como Entero;
	
	Escribir "Ingrese un n�mero entero positivo";
	Leer num;
	i<-1;
	
	Mientras num>=0 y i<=10 Hacer
		Escribir "Tabla del ",i,": ",num*i;
		i<-i+1;
	FinMientras
	
FinAlgoritmo