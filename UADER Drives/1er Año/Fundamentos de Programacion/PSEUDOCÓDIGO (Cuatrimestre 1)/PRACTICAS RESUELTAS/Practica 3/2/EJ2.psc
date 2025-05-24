Algoritmo EJ2
Definir N,Ult,Ant,Aux Como Entero;
Ult=1;
N=3; Ant=1;
Escribir '1 | ', Ant;
Escribir '2 | ', Ult;
Repetir
	Aux=Ult;
	Ult=Ult+Ant;
	Ant=Aux;
	Escribir N," | ",Ult;
	N=N+1;
Hasta que N>10 y Ant > 34
FinAlgoritmo
