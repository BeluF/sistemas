Algoritmo diasdelmes
	definir mes Como entero;
	leer mes;
	Si mes>=1 & mes<=12 entonces
		Si mes=1 o mes=3 o mes=5 o mes=7 o mes=8 o mes=10 o mes=12 entonces
			escribir "El mes tiene 31 días"; 
		Sino
			si mes=4 o mes=5 o mes=9 o mes=11 Entonces
				Escribir "El mes tiene 30 días";
			Sino
				Escribir "El mes tiene 28 días";
			FinSi
		FinSi
	FinSi
FinAlgoritmo
