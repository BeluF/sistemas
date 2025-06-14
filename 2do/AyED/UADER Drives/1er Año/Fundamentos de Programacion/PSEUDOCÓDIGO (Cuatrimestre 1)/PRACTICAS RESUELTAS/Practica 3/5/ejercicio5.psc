Algoritmo ejercicio5
	Definir a,b,c,x,i,min,max,RA,RB Como Entero;
	Escribir "ax^2+bx+c";
	Leer a,b,c;
	Escribir "Rango A, B:";
	Leer RA,RB;
	si RA<RB entonces
		min=RA;max=RB;
	SiNo
		max=RB;min=RB;
	FinSi
	Escribir "X | Y";
	Escribir "-----";
	Para x<-min hasta max con paso 1 Hacer
		Escribir X," | ", (a*x^2)+(b*x)+c;
	FinPara
	
	
FinAlgoritmo
