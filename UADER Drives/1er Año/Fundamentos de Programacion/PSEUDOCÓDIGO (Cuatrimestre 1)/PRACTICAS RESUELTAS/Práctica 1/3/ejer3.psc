Algoritmo ejercicio3
	Definir patente Como Caracter;
	Definir m1,s1,m2,s2 Como Entero;
	Definir h1,h2 Como Real;
	Escribir Sin Saltar "Patente -"; 
	Leer patente;
	Escribir "Primer comisar�a";
	Escribir Sin Saltar "Hora -";
	Leer h1;
	Escribir Sin Saltar "Minutos -";
	Leer m1;
	Escribir Sin Saltar "Segundos -";
	Leer s1;
	Escribir "Segunda comisar�a";
	Escribir Sin Saltar "Hora -";
	Leer h2;
	Escribir Sin Saltar "Minutos -";
	Leer m2;
	Escribir Sin Saltar "Segundos -";
	Leer s2;
	h1<-h1+(m1/60)+(s1/3600);
	h2<-h2+(m2/60)+(s2/3600);
	Escribir "El veh�culo con patente ", patente," va a una velocidad promedio de: ", REDON(7.5/(h2-h1))," km/h";
	
FinAlgoritmo
