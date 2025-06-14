Algoritmo ej1
	Definir provincia, deporte, provt Como Caracter;
	Definir catletas,c,p1,p2,p3,p4y5,young, DNI, DNIjoven, Edad, Puesto, total, tenistas, podiototal Como Entero;	//catletas= cantidad te atletas
	total=0; tenistas=0; podiototal=0;
	Escribir "JUEGOS EVITA";
	leer provincia;
	Mientras provincia<>"xx" Hacer
		c=0; p1=0; p2=0; p3=0; p4y5=0; young=0;
		Leer deporte,catletas;	//Lectura de deporte y de cantidad de atletas
		Escribir "Provincia: ", provincia, "        Deporte: ", deporte;
		Escribir "DNI              Edad             Puesto";
		Mientras c<catletas Hacer
			Leer DNI, Edad,Puesto;
			si puesto>0 Entonces	//comprobar que puesto es mayor a 1
				c=c+1;
				Escribir DNI,"         ", Edad,"                  ",Puesto;
				segun puesto Hacer
					1: p1=p1+1; podiototal=podiototal+1;
					2: p2=p2+1; podiototal=podiototal+1;
					3: p3=p3+1; podiototal=podiototal+1;
					4,5: p4y5=p4y5+1; podiototal=podiototal+1;
				FinSegun
				si Edad<young o young==0 Entonces
					young=Edad;
					DNIJoven=DNI;
				FinSi
				total=total+1;
			FinSi
		FinMientras
		Si tenistas<c y deporte="TENIS" Entonces
			tenistas=c;
			provt= provincia;
		FinSi
		Escribir "Cantidad total de: 1º Puesto: ",p1," - 2º Puesto: ",p2," - 3º Puesto: ",p3,"- 4º y 5º Puestos: ",p4y5;
		Escribir "DNI del atleta más joven: ", DNIJoven;
		leer provincia;
	FinMientras
	Escribir "Cantidad total de atletas participantes:",total;
	Escribir "Porcentaje de podios sobre total de atletas:", (podiototal*100)/total;
	Escribir "Provincia con mayor cantidad de Tenistas:",provt;
FinAlgoritmo
