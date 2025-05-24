//8) Una empresa de seguros realiza mensualmente una evaluación de sus vendedores. Para
//ello primero ingresa el porcentaje a pagar de comisión en los tres tramos de ventas: para
//	menos de 10 pólizas vendidas, para menos de 50 polizas vendidas y para 50 o más pólizas vendidas.
//  Luego se procede a la carga de las ventas ingresando por cada vendedor: su código y
//  cantidad de pólizas vendidas. Luego por cada póliza vendida se ingresa: capital asegurado y
//	cuota mensual a pagar. Un código de vendedor igual a 0 indica el fin de datos. Los datos se
//	ingresan ordenados por código de vendedor.
//  Se desea saber: 
//	- Cantidad total de pólizas vendidas, total de capital asegurado y total a pagar en concepto de
//	comisión.
//	- Código del vendedor que más pólizas vendió y código del que más comisión recibió.
//	Nota: La comisión se calcula como el procentaje sobre el total de cuotas mensuales
//		correspondientes al vendedor.

Algoritmo ej28B		//comprobando que los datos estén ordenados de menor a mayor
	Definir p1,p2,p3, capital, cuota, totalcapital, totalcomision, maxcomision, comisionvendedor  como real; //porcentaje de polizas
	Definir codigovendedor, polizas, c, totalpolizas , codvendedor, codcomision, maxpolizas, anterior como entero;
	
	totalcapital=0; totalpolizas=0; totalcomision=0; maxpolizas=0; maxcomision=0; anterior=0;
	
	Escribir "Ingrese porcentaje a pagar de comisión en los tres tramos de ventas:";
	Escribir Sin Saltar "Para menos de 10 polizas vendidas: ";	Leer p1;
	Escribir Sin Saltar "Para menos de 50 polizas vendidas: ";	Leer p2;
	Escribir Sin Saltar "Para más de 50 polizas vendidas: ";	Leer p3;
	
	Repetir
		Escribir "================================================";
		Escribir Sin Saltar "Ingrese código del vendedor:"; Leer codigovendedor;
		Escribir "================================================";
		si codigovendedor<>0 y anterior<codigovendedor Entonces
			comisionvendedor=0;
			Escribir Sin Saltar"Ingrese cantidad de polizas vendidas:";
			c=1;
			leer polizas;
			mientras c<=polizas Hacer
				Escribir Sin Saltar"Ingrese capital asegurado"; Leer capital;
				Escribir Sin Saltar"Ingrese cuota mensual a pagar"; leer cuota;
				totalcapital= totalcapital+capital;
				comisionvendedor=comisionvendedor+cuota;
				c=c+1;
			FinMientras
			
			si maxpolizas<polizas Entonces		// saber que vendedor consiguio el máximo de polizas
				codvendedor=codigovendedor;
			FinSi
			
			totalpolizas=totalpolizas+polizas;
			si polizas<10 Entonces				// calcular comision del vendedor
				comisionvendedor= (p1*comisionvendedor/100);
			SiNo
				si polizas <50 Entonces
					comisionvendedor= (p2*comisionvendedor/100);
				SiNo
					comisionvendedor= (p3*comisionvendedor/100);
				FinSi
			FinSi
			
			si maxcomision<comisionvendedor Entonces	//vendedor con más comisiones
				codcomision=codvendedor;
			FinSi
			totalcomision=totalcomision+comisionvendedor;
		SiNo
			si anterior>codigovendedor Entonces
				Escribir "Código ingresado anteriormente, carge otro código mayor";
			FinSi
		FinSi
		anterior=codigovendedor;
	Hasta Que codigovendedor==0;
	
	Escribir "Cantidad de polizas vendidas: ",totalpolizas," | Total de capital asegurado: ", totalcapital, " | Total a pagar en concepto de comisión: ", totalcomision;
	Escribir "Código del vendedor con más pólizas vendidas: ", codvendedor, " | Código de vendedor con más comisión: ", codcomision;
	
	
FinAlgoritmo
