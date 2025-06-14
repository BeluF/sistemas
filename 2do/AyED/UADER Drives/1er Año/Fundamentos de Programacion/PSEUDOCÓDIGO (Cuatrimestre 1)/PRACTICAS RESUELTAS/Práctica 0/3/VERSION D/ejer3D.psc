Algoritmo EJERC3D
	Definir	fecha, mes,dia,anio como entero;
	Escribir "Ingrese la fecha en formato mmddaa: ";
	Leer fechA;
	mes=trunc(FEcha/10000);
	fecha=fecha-(mes*10000);
	dia=trunc(fecha/100);
	anio= -(dia*100);
	Escribir dia,"/",mes,"/",anio;
FinAlgoritmo
