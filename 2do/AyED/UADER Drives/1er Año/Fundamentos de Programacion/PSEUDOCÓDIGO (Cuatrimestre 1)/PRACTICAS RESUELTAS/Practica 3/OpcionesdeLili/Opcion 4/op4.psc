Algoritmo opcion4
	definir ncomision, anterior, comisiones, alumnos  como entero;
	definir totalpromedios, totalnota, nota, promedio como real;
//	Opci�n 4
//	Luego del examen parcial, se desean conocer los promedios obtenidos por cada comisi�n
//	Para ello, por cada comisi�n se conoce: el n�mero de la misma y la nota de cada uno de
//	sus alumnos. Los datos vienen ordenados por n�mero de comisi�n y puede venir m�s de
//	un alumno por comisi�n. Determinar e informar el promedio de cada comisi�n y el
	//	promedio total. Los datos finalizan con n�mero de comisi�n = 999.
	Escribir "N� comision: ";
	Leer ncomision; 
	totalpromedios=0; comisiones=0;
	mientras ncomision<>999 Hacer		//BUCLE DE COMISIONES
		totalnota=0; alumnos=0; 
		anterior=ncomision;
		mientras anterior==ncomision Hacer		//BUCLE DE ALUMNOS
			Escribir "Nota: ";
			leer nota;
			totalnota= totalnota+ nota;
			alumnos=alumnos+1;
			Escribir "N� comision: ";
			leer ncomision;
		FinMientras
		promedio=totalnota/alumnos;
		totalpromedios= totalpromedios + promedio;
		Escribir "El promedio de la comision ", anterior," es de: ", promedio;
		comisiones= comisiones+1;
	FinMientras
	totalpromedios= totalpromedios/comisiones;
	Escribir "El promedio de todas las comisiones es: ", totalpromedios;
	
FinAlgoritmo
