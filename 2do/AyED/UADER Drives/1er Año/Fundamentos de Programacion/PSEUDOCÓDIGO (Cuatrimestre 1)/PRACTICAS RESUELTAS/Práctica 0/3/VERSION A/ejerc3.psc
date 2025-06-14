Algoritmo ejercicio3
	Definir Fecha Como Cadena;
	Escribir "Ingrese fecha en formato MMDDAA: ";
	Leer Fecha;
	Fecha<-Concatenar(Concatenar(Subcadena(Fecha,3,4),Subcadena(Fecha,1,2)),Subcadena(Fecha,5,6));
	Escribir "fecha actual en formato DDMMAA: ", Fecha;
FinAlgoritmo
