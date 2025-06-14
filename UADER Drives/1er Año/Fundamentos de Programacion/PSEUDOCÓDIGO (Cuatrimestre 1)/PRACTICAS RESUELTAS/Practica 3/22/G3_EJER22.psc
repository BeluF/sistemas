Algoritmo G3_EJER22
	//Una empresa de acopio de cereales recibe varios camiones durante el día.
	//Por cada camión que descarga cereal se registran los siguientes datos: patente del camión,
	//apellido y nombre del remitente, tipo de cereal (?MAIZ?, ?SOJA?, ?GIRASOL?, etc.) y cantidad de
	//toneladas.
	//Los datos se ingresan sin orden alguno y el fin de datos ocurre cuando se ingresa una patente
	//igual a ?XYZ 123?.
	//Se desea informar:
	//? Cuantos camiones descargaron cereal durante el día.
	//? Cuantas toneladas de SOJA se acopiaron durante el día.
	//? Total de toneladas acopiadas durante el día.
	Definir nya,patente,tipocereal Como Caracter;
	definir canttone,cantsoja,totaltoneladas Como Real;
	definir c Como entero;
	
	c=0; totaltoneladas=0;
	Repetir
		Escribir "Ingrese Patente del camión | Fin de datos: XYZ 123";
		leer patente;
		Si patente<>"XYZ 123" hacer
			Escribir "Ingrese Nombre y apellido";
			leer nya;
			Escribir "Ingrese el tipo de cereal a descargar MAIZ,SOJA O GIRASOL";
			leer tipocereal;
			Escribir "Ingrese la cantidad de cereal descargada (en toneladas)";
			leer canttone;
			SI tipocereal=="SOJA" Entonces
				cantsoja=cantsoja+canttone;
			FinSi
			totaltoneladas=totaltoneladas+canttone;
			c=c+1;
		FinSi
	Hasta Que patente<>"XYZ 123"
	
	Escribir "Cantidad de camiones que descargaron: ",c;
	Escribir "Cantidad de toneladas de soja acopiadas: ",cantsoja;
	Escribir "Cantidad de toneladas acopiadas durante el dia: ",totaltoneladas;
FinAlgoritmo
