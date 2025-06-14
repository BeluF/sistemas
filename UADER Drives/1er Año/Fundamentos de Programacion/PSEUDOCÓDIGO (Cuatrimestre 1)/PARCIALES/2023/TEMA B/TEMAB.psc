Algoritmo PARCIAL2023temaB
	//datos: la fabrica posee 34 rubros, conocemos el fin del bucle principal (rubros)
	definir RUBROS, contador, codproducto, cantprod, cantproductos, stocktotal Como Entero;
	definir incremento, costou, venta, stock, menor, mayor Como Real;
	definir desc, descprodct, descmenor, descmayor Como Caracter;	
	
	Escribir "DETALLE PRODUCCIÓN DE MAYO 2023 - ESTIMACIÓN DE PRECIOS";
	RUBROS= 34; contador=0; stocktotal=0; menor=9999; mayor= 0;
	Repetir
		cantproductos=0; stock=0;
		leer desc, incremento;
		Escribir "Descripción Rubro: ", desc, "    Incremento: ", incremento,"%";
		Escribir "Código      Descrip. Producto   Cant. Producida   Costo Unitario   Precio Sugerido Vta";
		leer codproducto;
		Mientras codproducto<>-1 Hacer
			leer descprodct, cantprod, costou;
			venta=costou+(costou*(incremento/100));
			Escribir codproducto,"   ",descprodct,"   ",cantprod,"   ",costou,"   ",venta;
			stock= stock + (costou*cantprod);
			cantproductos=cantproductos+1;
			//importante poner el contador antes de volver a leer el código para evitar cargar un producto extra
			leer codproducto;
		FinMientras
		
		//		obtener stock total
		stocktotal= stocktotal+stock;
		
		//ver cual es el rubro con menor % de incremento
		si menor>incremento Entonces
			menor=incremento;
			descmenor= desc;
		FinSi
		
		//ver cual es el rubro con más cantidad de productos;
		si mayor<cantproductos Entonces
			mayor=cantproductos;
			descmayor= desc;
		FinSi
		
		Escribir "Cantidad total de productos que componen el rubro: ", cantproductos;
		Escribir "Valor del Stock Ponderado del rubro: $", stock;
		contador=contador+1;
	Hasta Que contador==RUBROS;
	
	Escribir "Valor del Stock Ponderado de toda la produccion: $", stocktotal;
	Escribir "Descripción del rubro con menor % de incremento: ", descmenor;
	Escribir "Descripción del rubro con mayor cantidad de productos: ", descmayor;
FinAlgoritmo
