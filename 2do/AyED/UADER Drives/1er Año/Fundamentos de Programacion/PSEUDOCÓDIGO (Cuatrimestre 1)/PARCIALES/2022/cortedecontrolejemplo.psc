Algoritmo cortedecontrol	//no sabemos cuantos empleados puede llegar a tener la empresa
	leer empresa;
	mientras empresa<>"xx" Hacer
		//<datos de la empresa>
		anterior=empresa;
		mientras anterior=empresa Hacer
			//<datos de empleados>
			leer empresa;
		FinMientras
		//<estadisticas de esa empresa>
	FinMientras
FinAlgoritmo
