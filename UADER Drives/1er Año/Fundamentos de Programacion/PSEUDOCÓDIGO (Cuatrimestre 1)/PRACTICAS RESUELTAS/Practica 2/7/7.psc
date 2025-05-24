Algoritmo ejercicio7
	Definir ch,m, he, me Como Real; //ch= cantidad de horas trabajadas; m= costo x hora; he= horas extra; me= monto extra (50% más)
	//carga de datos
	Escribir Sin Saltar "Ingrese la monto por hora -";
	Leer m;
	Escribir Sin Saltar "Ingrese cantidad de horas trabajadas -";
	Leer ch;
	//toma de decisiones
	si ch=40 Entonces
		Escribir "Al trabajador le corresponde una paga de $", ch*m;
	SiNo
		si ch>40 Entonces
			he=ch-40;
			me= m*1.5;
			Escribir "Al trabajador le corresponde una paga de $", (40*m)+(he*me);
		SiNo
			Escribir "El trabajador no alcanzó las 40 horas semanales, por lo tanto no le corresponde una paga.";
		FinSi
	FinSi
FinAlgoritmo
