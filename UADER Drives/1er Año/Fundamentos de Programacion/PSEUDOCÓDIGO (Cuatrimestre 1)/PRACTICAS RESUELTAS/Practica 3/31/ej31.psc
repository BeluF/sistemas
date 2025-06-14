Algoritmo ej31a
	definir escuela, Sueldo, c, max, DNI, ant Como Entero;
	Definir ayp, mes Como Caracter;
	definir total Como Real;
	
	total=0; max=0; c=0;
	Escribir Sin Saltar"Ingrese mes: "; Leer mes;
	Repetir
		Escribir Sin Saltar"Ingrese codigo de escuela: "; Leer escuela;
		ant=escuela;
		Mientras ant==escuela Hacer
			si escuela>0 y escuela<>999 Entonces
				Escribir Sin Saltar "DNI: "; Leer DNI;
				Escribir Sin Saltar "Apellido y Nombre: "; Leer ayp;
				Escribir Sin Saltar "Sueldo: "; Leer Sueldo;
				c=c+1; total=total+Sueldo; 
				si sueldo>10000 Entonces
					max=max+1;
				FinSi
			FinSi
			Escribir Sin Saltar"Ingrese codigo de escuela: "; Leer escuela;
		FinMientras
	Escribir "Liquidación del mes de ", mes;
	Escribir "Escuela: ", ant;
	Escribir "Total a  pagar en todas las escuelas $", total;
	Escribir "Cantidad de docentes que cobran más de $10000: ", max;
	Hasta Que escuela==999;
	//Mostrar datos
	
	Escribir "Liquidación del mes de ", mes;
	Escribir "Cantidad de docentes procesados ", c;
	Escribir "Total a  pagar en todas las escuelas $", total;
	Escribir "Cantidad de docentes que cobran más de $10000: ", max;
	
FinAlgoritmo
