Algoritmo opcion3
	definir contador, ncomision, alumnos como entero;
	definir nota, promedio como real;

//	Opci�n 3
//	Luego del examen parcial, se desean conocer los promedios obtenidos por cada una de las
//	15 comisiones.
//	Para ello, por cada comisi�n se conoce: el n�mero de la misma y, de cada uno de sus
//	alumnos, la nota obtenida. La carga de notas de los alumnos de una comisi�n culmina con
//	nota = -1.
//	Determinar e informar el promedio de cada comisi�n y el promedio total.

	contador=0; promediototal=0;
	
	Repetir		//BUCLE DE COMISIONES
		totalnotas=0; alumnos=0;
		leer ncomision;
		leer nota;
		mientras nota<>-1 Hacer	//BUCLE DE ALUMNOS
			alumnos= alumnos+1;
			totalnotas= totalnotas+nota;
			leer nota;
		FinMientras
		promedio= totalnotas/alumnos;
		promediototal= promediototal+promedio;
		Escribir "El promedio de la comisi�n ", ncomision, " es: ", promedio; 
		contador=contador+1;
	Hasta Que contador=15
	
	Escribir "El promedio de todas las comisiones fue ", promediototal/15;
	
FinAlgoritmo
