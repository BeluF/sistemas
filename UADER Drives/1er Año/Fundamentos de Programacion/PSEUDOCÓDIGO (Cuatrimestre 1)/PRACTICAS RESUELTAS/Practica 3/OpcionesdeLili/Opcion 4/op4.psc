Algoritmo opcion4
	definir ncomision, anterior, comisiones, alumnos  como entero;
	definir totalpromedios, totalnota, nota, promedio como real;
//	Opción 4
//	Luego del examen parcial, se desean conocer los promedios obtenidos por cada comisión
//	Para ello, por cada comisión se conoce: el número de la misma y la nota de cada uno de
//	sus alumnos. Los datos vienen ordenados por número de comisión y puede venir más de
//	un alumno por comisión. Determinar e informar el promedio de cada comisión y el
	//	promedio total. Los datos finalizan con número de comisión = 999.
	Escribir "Nº comision: ";
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
			Escribir "Nº comision: ";
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
