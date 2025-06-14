Algoritmo g3_ejer27
	//27) Una empresa deposita en un banco el sueldo de sus empleados, los cuales pueden retirar
	//el dinero a través de cajeros automáticos.
	//Cada empleado puede realizar diversas extracciones a lo largo del mes. Si la operación se
	//realiza en cajeros de bancos en los que la empresa no ha hecho contrato, se le cobra en cada
	//extracción 2% de recargo sobre el monto retirado.
	//Por cada empleado se ingresa: número de documento, nombre y apellido, monto del sueldo
	//depositado por la empresa y cantidad de extracciones realizadas en el mes y luego, por cada
	//extracción se ingresa: día, monto retirado y cajero (?C?: Contratado, ?NC?: No contratado).
	//Al inicio se lee la cantidad de empleados a los que la empresa deposita el sueldo en el banco.
	//Se desea informar:
	//a) Por cada empleado:
	//NOMBRE Y APELLIDO: ............................................ DNI: .......................................
	//MONTO TOTAL RETIRADO: $ .......................
	//MONTO TOTAL DE RECARGO: $................... (*1)
	//SALDO DE LA CUENTA: $ ........................
	//Observaciones: (*1) Si corresponde aplicar recargo, caso contrario, mostrar valor cero
	Definir dni,nya,cajero,dia Como Caracter;
	definir montosueldo,montoretirado,totalretirado,recargo Como Real;
	definir cantempleados,extraccionesrealizadas,c,n Como Entero;
	Escribir "Ingrese la cantidad de empleados a los que se le va a depositar su sueldo en el banco";
	leer cantempleados;
	c=0;  totalretirado=0;  montoretirado=0;
	Repetir
		n=0; recargo=0;
		Escribir "Ingrese nombre y apellido";
		leer nya;
		Escribir "Ingrese su Número de documento";
		leer dni;
		Escribir "Ingrese monto depositado por la empresa:";
		leer montosueldo;
		Escribir "Ingrese cantidad de extracciones realizadas durante el mes";
		leer extraccionesrealizadas;
		si extraccionesrealizadas>0 Entonces
			Repetir
				Escribir "Ingrese día de la extracción";
				leer dia;
				Escribir "Ingrese monto retirado";
				leer montoretirado;
				Escribir "Ingrese si el cajero esta bajo contrato C o no NC";
				leer cajero;
				n=n+1;
				totalretirado=totalretirado+montoretirado;
				si cajero=="NC" Entonces
					recargo=recargo+(montoretirado*0.02);
				FinSi
			Hasta Que n==extraccionesrealizadas
		FinSi
		c=c+1;
		Escribir "Nombre y apellido: ",nya,"                    DNI: " ,dni;
		Escribir "Monto total retirado: $",totalretirado;
		Escribir "Monto total de recargo: $",recargo;
		Escribir "Saldo de la cuenta: $",montosueldo-totalretirado-recargo;
	Hasta Que c==cantempleados
	
FinAlgoritmo
