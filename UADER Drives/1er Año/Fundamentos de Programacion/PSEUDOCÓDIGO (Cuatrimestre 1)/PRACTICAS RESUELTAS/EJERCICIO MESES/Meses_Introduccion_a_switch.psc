Algoritmo Meses
Definir fecha Como Entero;
	Escribir ("Ingrese el Mes:");
	leer fecha;
	Si 1<=fecha & fecha<=12	Entonces
		Segun(fecha) hacer
			1,3,5,7,8,10,12:
				Escribir("El mes tiene 31 d�as");
			4,5,9,11:
				Escribir ("El mes tiene 30 d�as");
			De Otro Modo:
				Escribir ("El mes tiene 28 d�as");
		FINSEGUN;
	Sino 
		Escribir ("El n�mero ingresado no corresponde a un mes.");
	FinSi	
FinAlgoritmo
