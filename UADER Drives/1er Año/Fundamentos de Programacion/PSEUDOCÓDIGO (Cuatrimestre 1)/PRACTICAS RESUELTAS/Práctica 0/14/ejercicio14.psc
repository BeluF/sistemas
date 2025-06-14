Algoritmo Jubilado
	Definir sueldo Como Entero;
	Definir porcentaje,edad1,edad2,edad3 Como Real;
	Escribir "Ingrese total del sueldo a repartir";
	Leer Sueldo;
	Escribir "Ingrese la edad por separado de sus 3 nietos";
	Leer edad1,edad2,edad3;
	porcentaje<-15*(sueldo/100);
	Escribir "El total a repartir es ",porcentaje,"$";
	Escribir "Lo que le corresponde al nieto de ",edad1," años es ",(porcentaje*edad1)/(edad1+edad2+edad3),"$";
	Escribir "Lo que le corresponde al nieto de ",edad2," años es ",(porcentaje*edad2)/(edad1+edad2+edad3),"$";
	Escribir "Lo que le corresponde al nieto de ",edad3," años es ",(porcentaje*edad3)/(edad1+edad2+edad3),"$";
FinAlgoritmo
