Algoritmo Cuota
	Definir cap Como Real;
	Definir razon,plazo Como Entero;
	Escribir "Ingrese el capital solicitado, luego la raz�n (tasa anual, y por �ltimo el plazo (en meses)";
	Leer cap, razon, plazo;
	Escribir "La cuota a pagar es de ", (cap+((cap*razon*plazo)/(100*12)))/plazo,"$ por un plazo de ", plazo," meses."; 
FinAlgoritmo
