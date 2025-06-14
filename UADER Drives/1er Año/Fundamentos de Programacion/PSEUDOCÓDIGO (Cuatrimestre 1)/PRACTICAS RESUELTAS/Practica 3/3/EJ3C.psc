Algoritmo ejercicio3C
	// Realice un algoritmo que solicite el ingreso de un número (entero positivo) e informe su
	// tabla de multiplicar (del 1 al 10).

	//Version C -> Usando el PARA, mientras, y variable lógica para comprobar que el número es un entero positivo.
	definir num como real;
	Definir i Como Entero;
	Definir intpos Como Logico;
	
	Escribir "Ingrese un número entero positivo";
	Leer num;
	
	i<-1;	//iniciamos el contador
	Repetir 						
		intpos= num/i==trunc(num/i);	//intpos significa "entero positivo", y al ser una variable lógica puede tener 2 estados, verdadero o falso
		i<-i+1;							//si la división truncada es igual a la sin truncar, significa que el número es entero.
	Hasta Que intpos o i==10			//el bucle se rompe al ser positivo intpos o al llegar a la tabla del 10.
		
	si num>=0 & intpos Entonces
		para i<-1 hasta 10 con paso 1 Hacer
			Escribir "Tabla del ",i,": ",num*i;
		FinPara
	sino 
		Escribir "El número ingresado no es un entero positivo";
	FinSi
	
	
FinAlgoritmo
