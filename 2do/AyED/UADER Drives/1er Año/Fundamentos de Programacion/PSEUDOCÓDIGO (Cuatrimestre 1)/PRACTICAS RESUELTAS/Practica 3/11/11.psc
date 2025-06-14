Algoritmo ej11
	definir N, contador Como Entero;
	definir peso, altura, maximaaltura, minpeso Como Real;
	definir nya, altonya, minnya como caracter;
//	11) Un jardín de infantes tiene N alumnos y desea hacer un control de los mismos. Por cada
//	alumno se ingresa Nombre y Apellido, Peso y Altura. Informar cuál es el alumno más alto y
	//	cuál es el de menor peso. El Valor N se ingresa como primer dato.
	Escribir "Ingrese cantidad de alumnos";
	leer N; 
	contador=0; maximaaltura=0; minpeso=99999;
	Mientras contador<N Hacer
		Escribir "Valor de N: ", n, " Valor del contador: ", contador;
		Escribir "Ingrese Nombre y apellido, peso, y altura";
		leer nya,peso,altura;
		si maximaaltura<altura Entonces
			maximaaltura=altura;
			altonya=nya;
		FinSi
		si minpeso>peso Entonces
			minpeso= peso;
			minnya= nya;
		FinSi
		contador=contador+1;
	FinMientras
	
	Escribir "El alumno con altura maxima es ",altonya, " con ", maximaaltura;
	Escribir "El alumno con mínimo peso es ", minnya, " con ", minpeso," kg.";
	
//	Mientras contador<N Hacer
		
//		contador=contador+1;
//	FinMientras
	
FinAlgoritmo
