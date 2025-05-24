Algoritmo ejercicio13
	Definir p1, p2, p3, p4, p5, venttotal1, venttotal2, venttotal3, venttotal4, venttotal5, ventcliente, suma, clientemontomayor Como real;
	Definir nombre, nombreclientemontomayor Como Caracter;
	Definir cp, art Como Entero;
	Escribir "Ingrese el precio del artículos 1";
	Leer p1;
	Escribir "Ingrese el precio del artículos 2";
	Leer p2;
	Escribir "Ingrese el precio del artículos 3";
	Leer p3;
	Escribir "Ingrese el precio del artículos 4";
	Leer p4;
	Escribir "Ingrese el precio del artículos 5";
	Leer p5;
	venttotal1=0; venttotal2=0; venttotal3=0; venttotal4=0; venttotal5=0; suma=0; clientemontomayor=0;
	Repetir
		Escribir "Ingrese el nombre del cliente";
		Leer nombre;
		si nombre<>"zzz" Entonces
			Escribir "Cantidad comprada del cliente";
			Leer cp;
			Escribir "Código de artículo";
			Leer art;
			Segun art Hacer
				1:ventcliente=p1*cp; venttotal1=venttotal1+ventcliente;
				2:ventcliente=p2*cp; venttotal2=venttotal2+ventcliente;
				3:ventcliente=p3*cp; venttotal3=venttotal3+ventcliente;
				4:ventcliente=p4*cp; venttotal4=venttotal4+ventcliente;
				5:ventcliente=p5*cp; venttotal5=venttotal5+ventcliente;
			FinSegun
		FinSi
		si ventcliente>clientemontomayor Entonces
			clientemontomayor=ventcliente;
			nombreclientemontomayor=nombre;
		FinSi
		suma=suma+cp;
	Hasta Que nombre=="zzz"
	Escribir "Venta total artículo 1: ", venttotal1;
	Escribir "Venta total artículo 2: ", venttotal2;
	Escribir "Venta total artículo 3: ", venttotal3;
	Escribir "Venta total artículo 4: ", venttotal4;
	Escribir "Venta total artículo 5: ", venttotal5;
	Escribir "Cantidad de ventas realizadas: ", suma;
	Escribir "Monto total de ventas: ", venttotal1+venttotal2+venttotal3+venttotal4+venttotal5;
	Escribir "Cliente con mayor monto de venta: ", nombreclientemontomayor;
FinAlgoritmo
