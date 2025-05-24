Algoritmo Ejercicio11
	Definir nsocio Como Entero;
	Definir valorbase como real;
	Definir club, nya, tipo Como Caracter;
	Escribir "Ingrese valor base de la cuota";
	Leer valorbase;
	Escribir "Ingrese el nombre del club";
	Leer club;
	Escribir "Ingrese datos del socio: Número de socio, nombre, apellido, y tipo (activo, familiar, cadete.)";
	Leer nsocio, nya, tipo;
	si tipo="familiar" Entonces
		valorbase= valorbase*1.5;
		Escribir "CLUB: ", club;
		Escribir "NRO. DE SOCIO: ", nsocio," | NOMBRE DEL SOCIO: ", nya;
		Escribir "TIPO DE SOCIO: ", tipo, " | TOTAL A PAGAR: ", valorbase;
	SiNo
		si tipo="cadete" Entonces
			valorbase= valorbase*0.80;
			Escribir "CLUB: ", club;
			Escribir "NRO. DE SOCIO: ", nsocio," | NOMBRE DEL SOCIO: ", nya;
			Escribir "TIPO DE SOCIO: ", tipo, " | TOTAL A PAGAR: ", valorbase;
		sino 
			si tipo="activo" Entonces
				Escribir "CLUB: ", club;
				Escribir "NRO. DE SOCIO: ", nsocio," | NOMBRE DEL SOCIO: ", nya;
				Escribir "TIPO DE SOCIO: ", tipo, " | TOTAL A PAGAR: ", valorbase;
			SiNo
				Escribir "El tipo ingresado no corresponde al cargado en el programa";
			FinSi
		FinSi
	FinSi
	//mostrar los datos
FinAlgoritmo
