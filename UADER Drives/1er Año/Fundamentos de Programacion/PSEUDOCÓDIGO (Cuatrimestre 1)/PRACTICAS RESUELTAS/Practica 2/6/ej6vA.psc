Algoritmo ejercicio6versionA		//Versi�n m�s avanzada del ejercio; utilizaremos subcadenas que luego se convertiran en n�meros.
	Definir fechanacimiento, fechavoto Como Caracter; 
	Escribir Sin Saltar "Ingrese fecha de nacimiento en formato DDMMAAAA ";
	Leer fechanacimiento;
	Escribir Sin Saltar "Ingrese fecha de votaci�n en formato DDMMAAAA ";
	Leer fechavoto;
	Si ((ConvertirANumero(Subcadena(fechavoto,5,8)))-(ConvertirANumero(Subcadena(fechanacimiento,5,8)))>=19) Entonces
		Escribir "El usuario puede votar";
	SiNo
		Si ((ConvertirANumero(Subcadena(fechavoto,5,8)))-(ConvertirANumero(Subcadena(fechanacimiento,5,8)))>=18) Entonces
			si (ConvertirANumero(Subcadena(fechavoto,3,4)))<=(ConvertirANumero(Subcadena(fechanacimiento,3,4))) Entonces
				si (ConvertirANumero(Subcadena(fechavoto,1,2)))<=(ConvertirANumero(Subcadena(fechanacimiento,1,2))) Entonces
					Escribir "El usuario puede votar";
				SiNo
					Escribir "El usuario es menor, por lo tanto no puede votar.";
				FinSi
			SiNo
				Escribir "El usuario es menor, por lo tanto no puede votar.";
			FinSi
		SiNo
			Escribir "El usuario es menor, por lo tanto no puede votar.";
		FinSi
	FinSi
	
FinAlgoritmo
