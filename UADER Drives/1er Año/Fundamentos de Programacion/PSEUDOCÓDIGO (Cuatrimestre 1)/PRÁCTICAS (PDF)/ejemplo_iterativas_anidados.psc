Algoritmo ejemplo
	Definir nombre,opcion Como Caracter;
	Definir edad Como Entero;
	definir continuar Como Logico;
	
	Repetir
		Escribir "Ingrese nombre del cliente:";
		Leer nombre;
		Repetir
			Escribir "Ingrese edad: ";
			Leer edad;
		Hasta Que edad>0;
		//decisión de continuar el bucle
		Escribir "Desea ingresar otro cliente? [si/	no]";
		Leer opcion;
		si opcion=="no" Entonces
			continuar=falso;
		SiNo
			continuar=Verdadero;
		FinSi
	Hasta Que continuar=Falso;
FinAlgoritmo
