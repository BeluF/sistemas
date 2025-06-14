Algoritmo EJERCICIO8b
	Definir Monto1,Monto2,total,totaltotal,bonoa,bonob Como real;
	Definir empleado Como Entero;
	Escribir "Sucursal I";
	Escribir Sin Saltar "Ingrese cantidad de empleados -";
	Leer empleado;
	Escribir Sin Saltar "Ingrese monto total del primer semestre -";
	Leer Monto1;
	Escribir Sin Saltar "Ingrese monto total del segundo semestre -";
	Leer Monto2;
	total<- monto1+monto2;
	totaltotal<- total;
	bonoa<- 20*(total/100);
	Escribir "El total de ventas de la primer sucursal es: ", total,"$";
	Escribir "El bono que se repartió a cada empleado es de ", bonoa/empleado,"$";
	///////////////////////////     SUCURSAL 2        ////////////////////////////////////
	Escribir "Sucursal II";
	Escribir Sin Saltar "Ingrese cantidad de empleados -";
	Leer empleado;
	Escribir Sin Saltar "Ingrese monto total del primer semestre -";
	Leer Monto1;
	Escribir Sin Saltar "Ingrese monto total del segundo semestre -";
	Leer Monto2;
	total<- monto1+monto2;
	totaltotal<-totaltotal+total;
	bonob<- 20*(total/100);
	Escribir "El total de ventas de la segunda sucursal es: ", total,"$";
	Escribir "El bono que se repartió a cada empleado es de ", bonob/empleado,"$";
	///////////////////////////     ÁMBAS SUCURSALES      ////////////////////////////////////
	Escribir "Estadisticas Sucursal I y Sucursal II";
	Escribir "El total de ventas de las dos sucursales fue de ", totaltotal,"$";
	Escribir "El bono promedio que se pago a cada empleado entre ambas sucursales fue: ", (bono+bonob)/2,"$";
FinAlgoritmo
