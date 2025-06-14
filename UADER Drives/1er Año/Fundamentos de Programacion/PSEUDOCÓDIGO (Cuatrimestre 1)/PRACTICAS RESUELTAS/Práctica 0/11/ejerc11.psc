Algoritmo Almacen
	Definir Nombre, Apellido Como Caracter;
	Definir Cantidad Como Entero;
	Definir Precio, Descuento Como Real;
	Escribir "Ingrese nombre y apellido del cliente:";
	Leer Nombre, Apellido;
	Escribir "Ingrese la cantidad del producto adquirida y el precio de cada unidad";
	Leer Cantidad, Precio; 
	Descuento <- 95*(precio/100);
	Escribir Nombre," ", Apellido," el total a pagar es: ", Descuento+(21*(Descuento/100));
FinAlgoritmo

//acá si uso otra variable, para no tener que calcular 2 veces lo mismo a diferencia del ejercicio 
//anterior, pero se puede hacer tranquilamente metiendo esa operación dentro del paréntesis