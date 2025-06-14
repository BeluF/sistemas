Algoritmo Meses
Definir fecha Como Entero;
	Escribir ("Ingrese el Mes:");
	leer fecha;
	Si 1<=fecha & fecha<=12	Entonces
		Segun(fecha) hacer
			1,3,5,7,8,10,12:
				Escribir("El mes tiene 31 días");
			4,5,9,11:
				Escribir ("El mes tiene 30 días");
			De Otro Modo:
				Escribir ("El mes tiene 28 días");
		FINSEGUN;
	Sino 
		Escribir ("El número ingresado no corresponde a un mes.");
	FinSi	
FinAlgoritmo
