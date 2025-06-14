Algoritmo ejercicio3
	Definir n1,n2,n3 Como Caracter;
	Escribir "Ingrese nombre1, nombre2, nombre3: ";
	Leer n1,n2,n3;
	Si (n1<n2) y (n1<n3) y (n2<n3) Entonces Escribir "[1 SI]"; //PSeint le da valor de menor a la primer letra del abecedario (A) y valor mayor a la última (Z)
		Escribir n1;
		Escribir n2;
		Escribir n3;
	SiNo
		Si (n1<n2) y (n1<n3) y (n3<n2) Entonces Escribir "[2 SI]";
			Escribir n1;
			Escribir n3;
			Escribir n2;
		SiNo
			Si (n2<n1) y (n2<n3) y (n1<n3) Entonces Escribir "[3 SI]";
				Escribir n2;
				Escribir n1;
				Escribir n3;
			SiNo
				Si (n2<n3) y (n2<n1) y (n3<n1) Entonces Escribir "[4 SI]";
					Escribir n2;
					Escribir n3;
					Escribir n1;
				SiNo
					Si (n3<n2) y (n3<n1) y (n2<n1) Entonces Escribir "[5 SI]";
						Escribir n3;
						Escribir n2;
						Escribir n1;
					SiNo	Escribir "[6 SI]";
						Escribir n3;
						Escribir n1;
						Escribir n2;
					finsi
				FinSi
			FinSi
		FinSi
	FinSi
	
FinAlgoritmo
