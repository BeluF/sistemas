Algoritmo EJ7
	Definir n, aux  Como Entero;
	Definir k Como Real;
	//factorial => n! = n-1*n-2*...*n-k
	
	Escribir sin saltar"ingrese numero";
	leer n;
	aux=1;
	k=1;
	
	Mientras n>=aux Hacer
		k=k*aux;
		aux=aux+1;
	FinMientras
	
	Escribir "El factorial es: ", k ;
FinAlgoritmo
