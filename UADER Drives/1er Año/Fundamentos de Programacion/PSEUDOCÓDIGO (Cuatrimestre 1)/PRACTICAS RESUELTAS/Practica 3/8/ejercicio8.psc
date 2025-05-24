Algoritmo ejercicio8
	
	definir nombre, auxiliar Como Caracter;
	Definir contador Como Entero;
	
	Leer nombre;
	contador=1;
	
	Repetir
		auxiliar=nombre;
		Leer nombre;
		contador=contador+1;
	Hasta Que nombre=auxiliar;
	
	//La lógica empleada es que: Se lee en nombre fuera del bucle y se inicializa el contador, luego 
	//el Repetir se inicia y asigna a la variable auxiliar el nombre, luego pedimos al usuario ingresar
	//un nombre y que el contador se incremente en uno (para este momento tendríamos 2 nombres ingresados)
	//ahí es cuando llegamos al fin del bloque, y se evalua la condición, en caso de ser falsa, se vuelve
	//a ejecutar el bucle y el nombre se asigna a la variable auxiliar, para volver a iniciar el proceso
	//hasta que el nombre actual sea igual al anterior (auxiliar).
	
	Escribir "La cantidad de nombres ingresados fue ", contador;
FinAlgoritmo
