Algoritmo EJERCICIO8
	Definir Monto1,Monto2,total,bono Como real;
	Definir empleado Como Entero;
	Escribir "Sucursal I";
	Escribir Sin Saltar "Ingrese cantidad de empleados -";
	Leer empleado;
	Escribir Sin Saltar "Ingrese monto total del primer semestre -";
	Leer Monto1;
	Escribir Sin Saltar "Ingrese monto total del segundo semestre -";
	Leer Monto2;
	total<- monto1+monto2;
	bono<- 20*(total/100);
	Escribir "El total de ventas de la primer sucursal es: ", total,"$";
	Escribir "El bono que se repartió a cada empleado es de ", bono/empleado,"$";
	/////////////////////////////////////////////////////////////////////////////////// SUCURSAL 2
	Escribir "Sucursal II";
	Escribir Sin Saltar "Ingrese cantidad de empleados -";
	Leer empleado;
	Escribir Sin Saltar "Ingrese monto total del primer semestre -";
	Leer Monto1;
	Escribir Sin Saltar "Ingrese monto total del segundo semestre -";
	Leer Monto2;
	total<- monto1+monto2;
	bono<- 20*(total/100);
	Escribir "El total de ventas de la segunda sucursal es: ", total,"$";
	Escribir "El bono que se repartió a cada empleado es de ", bono/empleado,"$";
	
	
FinAlgoritmo
