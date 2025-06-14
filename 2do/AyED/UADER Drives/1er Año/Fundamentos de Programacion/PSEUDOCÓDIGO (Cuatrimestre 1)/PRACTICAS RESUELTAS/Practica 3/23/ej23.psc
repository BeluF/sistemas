Algoritmo EJ23
	// Una empresa de colectivos tiene varios coches que durante el d�a hacen varios recorridos
	//y venden 3 tipos de boletos: estudiante, com�n y jubilado. 
	//El boleto estudiante es un 20 % m�s barato que el boleto com�n y el jubilado un 40 % m�s
	//barato que el com�n. El precio del boleto com�n se lee como primer dato.
	//Por cada recorrido se ingresa: Nro. de colectivo, cantidad de boletos estudiantes, cantidad de
	//boletos comunes y cantidad de boletos jubilados vendidos. 
	//La carga de datos finaliza con nro. de colectivo = 99. 
	//Se desea saber:
	//- Por cada recorrido, el total recaudado.
	//- Cantidad de boletos estudiantes vendidos durante el d�a.
	//- Total recaudado en todos los recorridos ingresados.
	//- El nro de colectivo que menos recaud� y el monto recaudado por el mismo.
	
	Definir pbc, mmr, total, mrc Como Real;	//pbc precio boleto comun; mr monto m�nimo recaudado
	Definir nc, be, bc, bj, nmr, tbe Como Entero;	//tbe= total boletos comunes
	tbe=0; total=0; mmr=999999999999; 
	
	Escribir Sin Saltar "Ingrese precio del boleto com�n";
	Leer pbc;
	Repetir
		Escribir Sin Saltar "Ingrese n�mero de colectivo";
		Leer nc;
		Si nc<>99 Entonces
			Escribir Sin Saltar "Cantidad de boletos estudiantiles:";
			Leer be;
			Escribir Sin Saltar "Cantidad de boletos comunes:";
			Leer bc;
			Escribir Sin Saltar "Cantidad de boletos jubilados:";
			Leer bj;
			//consigna 2
			tbe=tbe+be;	
			//consigna 3
			total=total+(be*(pbc*0.8))+(bj*(pbc*0.6))+(bc*pbc);
			//consigna 4
			mrc=(be*(pbc*0.8))+(bj*(pbc*0.6))+(bc*pbc);
			si mmr>mrc Entonces
				inicio=Falso;
				mmr=mrc;
				nmr=nc;
			FinSi
			Escribir "Total recaudado por ese recorrido: ", mrc;
		FinSi
	Hasta Que nc==99
	
	Escribir "Cantidad de boletos de estudiantes vendidos durante el d�a: ", tbe;
	Escribir "Total recaudado en todos los recorridos ingresados: ", total;
	Escribir "El c�digo del colectivo que menos recaud� fue ", nmr," y el monto recaudado por el mismo:",mmr;
	
	
FinAlgoritmo
