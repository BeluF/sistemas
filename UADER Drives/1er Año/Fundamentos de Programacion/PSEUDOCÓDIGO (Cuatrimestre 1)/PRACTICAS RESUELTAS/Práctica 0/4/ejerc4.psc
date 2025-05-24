Algoritmo ejercicio4
	Definir hhmmss,v1,v2,v3 como Entero;
	Escribir "Ingrese tiempo en formato hhmmss";
	Leer hhmmss;
	v1<-TRUNC((hhmmss)/10000);
	v2<-TRUNC((hhmmss-(v1*10000))/100);
	v3<-TRUNC((hhmmss-(v1*10000)-(v2*100)));
	Escribir "La cantidad de segundos totales es: ", v1*3600+v2*60+v3;
FinAlgoritmo
