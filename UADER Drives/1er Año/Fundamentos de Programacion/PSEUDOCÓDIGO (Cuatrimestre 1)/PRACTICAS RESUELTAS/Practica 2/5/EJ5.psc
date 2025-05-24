Algoritmo Ejercicio5
	Definir peso,altura,imc Como Real;
	Escribir "Ingrese Peso y Altura";
	Leer peso,altura;
	imc<-peso/(altura^2);
	si (imc>0) y (imc<18.5) Entonces
		Escribir "Debajo del normal";
	SiNo
		si (imc>18.5) y (imc<25) Entonces
			Escribir "Normal";
		SiNo
			si (imc>25) y (imc<30) Entonces
				Escribir "Sobrepeso";
			SiNo
				Escribir "Obesidad";
			FinSi
		FinSi
	FinSi
	
	
FinAlgoritmo
