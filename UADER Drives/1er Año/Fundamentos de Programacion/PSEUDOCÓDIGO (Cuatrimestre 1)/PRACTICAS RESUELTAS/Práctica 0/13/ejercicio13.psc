Algoritmo Examenes
	Definir P1,P2,TP Como Entero;
	Escribir "Ingrese nota del primer exámen parcial, luego del segundo parcial y posteriormente la calificación del trabajo práctico.";
	Leer P1,P2,TP;
	Si 100>=P1 & P1>=0 & 100>=P2 & 0<=P2 & 100>=TP & 0<=TP Entonces
		Escribir "La nota final es ",((((P1+P2)/2)*80)/100)+((TP*20)/100);
	SiNo
		Escribir "Uno de lo valores ingresados no es correcto.";
	FinSi
FinAlgoritmo
