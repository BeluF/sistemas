Algoritmo ej9
	//9) Calcular la media de X cantidad de números, para lo cual se ingresarán valores enteros
	// reiteradamente, siendo el fin de la carga un valor igual a 0. Informar el valor medio y la
	// cantidad de datos ingresados.
	Definir num, total Como Entero;
	Definir sum Como Real;
	
	sum=0; total=-1;
	
	Repetir
		Escribir Sin Saltar "Ingrese número -";
		Leer num;
		sum=sum+num;
		total=total+1;
	Hasta Que num==0
	
	Escribir "Media: [",sum/total,"] | Cantidad de números ingresados: [", total,"]";
FinAlgoritmo
