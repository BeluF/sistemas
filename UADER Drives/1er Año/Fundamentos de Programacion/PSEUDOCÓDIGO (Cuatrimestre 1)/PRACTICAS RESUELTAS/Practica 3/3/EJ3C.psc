Algoritmo ejercicio3C
	// Realice un algoritmo que solicite el ingreso de un n�mero (entero positivo) e informe su
	// tabla de multiplicar (del 1 al 10).

	//Version C -> Usando el PARA, mientras, y variable l�gica para comprobar que el n�mero es un entero positivo.
	definir num como real;
	Definir i Como Entero;
	Definir intpos Como Logico;
	
	Escribir "Ingrese un n�mero entero positivo";
	Leer num;
	
	i<-1;	//iniciamos el contador
	Repetir 						
		intpos= num/i==trunc(num/i);	//intpos significa "entero positivo", y al ser una variable l�gica puede tener 2 estados, verdadero o falso
		i<-i+1;							//si la divisi�n truncada es igual a la sin truncar, significa que el n�mero es entero.
	Hasta Que intpos o i==10			//el bucle se rompe al ser positivo intpos o al llegar a la tabla del 10.
		
	si num>=0 & intpos Entonces
		para i<-1 hasta 10 con paso 1 Hacer
			Escribir "Tabla del ",i,": ",num*i;
		FinPara
	sino 
		Escribir "El n�mero ingresado no es un entero positivo";
	FinSi
	
	
FinAlgoritmo
