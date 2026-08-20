Ej. zoológico:

# MR:

Empleado(legajo(PK), nombre, direccion, telefono, fechaIngreso)
Cuidador(legajo(PK)(FK))
Guia(legajo(PK)(FK))
Itinerario(codigoItinerario)(PK), duracion, longitud, cantVisitantes
Zona(codigoZona(PK), nombre, extension)
Especie(codigoEspecie(PK), nombre, nombreCientifico, descripcion, codigoZona(FK)) R3

## R1: Guías acompañan a los visitantes en un Itinerario
ItinerarioGuia(codigoItinerario(PK)(FK), legajo(PK)(FK), hora)

## R2: Cuidador tiene asignada una o más especies.
CuidadorEspecie(codigoEspecie(PK)(FK), legajo(PK)(FK), fechaDesde)

## R4: Zonas que se visitan por itinerario
ZonasItinerario(codigoZona(PK)(FK), codigoItinerario(PK)(FK))

# CREAR TABLAS (con CONSTRAINT):

*Empleado:*
```sql
CREATE TABLE Empleado
        (legajo INTEGER NOT NULL, nombre VARCHAR (100) NOT NULL, direccion VARCHAR (150) NOT NULL,
            telefono VARCHAR (20), fechaIngreso DATE NOT NULL,
        CONSTRAINT PK_Empleado PRIMARY KEY CLUSTERED (legajo));
```

*Cuidador:*
```sql
CREATE TABLE Cuidador
        (legajo INTEGER NOT NULL,
		CONSTRAINT PK_Cuidador PRIMARY KEY CLUSTERED (legajo),
		CONSTRAINT FK_Cuidador_Empleado FOREIGN KEY (legajo) REFERENCES Empleado(legajo));
```

*Guia:*
```sql
CREATE TABLE Guia
        (legajo INTEGER NOT NULL,
		CONSTRAINT PK_Guia PRIMARY KEY CLUSTERED (legajo),
		CONSTRAINT FK_Guia_Empleado FOREIGN KEY (legajo) REFERENCES Empleado(legajo));
```

*Itinerario:*
```sql
CREATE TABLE Itinerario
        (codigoItinerario INTEGER NOT NULL, duracion INTEGER NOT NULL,
            longitud DECIMAL (10, 2) NOT NULL, cantVisitantes INTEGER NOT NULL,
		CONSTRAINT PK_Itinerario PRIMARY KEY CLUSTERED (codigoItinerario));
```

*Zona:*
```sql
CREATE TABLE Zona
        (codigoZona INTEGER NOT NULL, nombre VARCHAR (100) NOT NULL,
            extension DECIMAL (10, 2) NOT NULL,
		CONSTRAINT PK_Zona PRIMARY KEY (codigoZona));
```

*Especie:*
```sql
CREATE TABLE Especie
        (codigoEspecie INTEGER NOT NULL, nombre VARCHAR (100) NOT NULL,
            nombreCientifico VARCHAR (100) NOT NULL, descripcion VARCHAR (150) NOT NULL,
                codigoZona INTEGER NOT NULL,
		CONSTRAINT PK_Especie PRIMARY KEY CLUSTERED (codigoEspecie),
		CONSTRAINT FK_ZonaEspecie FOREIGN KEY (codigoZona) REFERENCES Zona(codigoZona));
```

*CuidadorEspecie:*
```sql
CREATE TABLE CuidadorEspecie(
		codigoEspecie INTEGER NOT NULL,
		legajo INTEGER NOT NULL,
		fechaDesde DATE NOT NULL,

		CONSTRAINT PK_Cuidador_Especie PRIMARY KEY CLUSTERED (codigoEspecie, legajo),
		CONSTRAINT FK_Cuidador_CE FOREIGN KEY (legajo) REFERENCES Cuidador(legajo),
		CONSTRAINT FK_Especie_CE FOREIGN KEY (codigoEspecie) REFERENCES Especie(codigoEspecie)
		);
```

*ItinerarioGuia:*
```sql
CREATE TABLE ItinerarioGuia(
		codigoItinerario INTEGER NOT NULL,
		legajo INTEGER NOT NULL,
		hora TIME,
		CONSTRAINT PK_Itinerario_Guia PRIMARY KEY CLUSTERED (codigoItinerario, legajo),
		CONSTRAINT FK_Itinerario_IG FOREIGN KEY (codigoItinerario) REFERENCES Itinerario(codigoItinerario),
		CONSTRAINT FK_Guia_IG FOREIGN KEY (legajo) REFERENCES Guia(legajo)
		);
```

*ZonasItinerario:*
```sql
CREATE TABLE ZonasItinerario (
	codigoZona INTEGER NOT NULL,
	codigoItinerario INTEGER NOT NULL,
	CONSTRAINT PK_Zonas_Itinerario PRIMARY KEY CLUSTERED (codigoZona, codigoItinerario),
	CONSTRAINT FK_Zona_ZI FOREIGN KEY (codigoZona) REFERENCES Zona(codigoZona),
	CONSTRAINT FK_Itinerario_ZI FOREIGN KEY (codigoItinerario) REFERENCES Itinerario(codigoItinerario)
);
```


# CONSULTAS SQL:
1. Listado completo de especies:
```sql
SELECT * FROM especie;
```

2. Listado de especies ubicadas en una zona dada:
```sql
SELECT e.nombre, z.nombre FROM Especie e JOIN Zona z ON e.codigoZona = z.codigoZona WHERE z.codigoZona = 5;
```

3. Nombre y teléfono de los cuidados a cargo de una especie dada:
```sql
SELECT em.nombre, em.telefono, es.nombre FROM Empleado em LEFT JOIN CuidadorEspecie ce ON em.legajo = ce.legajo
	LEFT JOIN Especie es ON es.codigoEspecie = ce.codigoEspecie;
```

4. Listado de todos los empleados del parque indicando quienes son guías y quienes cuidadores:
```sql
SELECT e.nombre FROM Empleado e RIGHT JOIN Cuidador c ON e.legajo = c.legajo;
SELECT e.nombre FROM Empleado e RIGHT JOIN Guia g ON e.legajo = g.legajo;

SELECT e.nombre, 
	CASE
		WHEN g.legajo IS NOT NULL AND c.legajo IS NOT NULL
			THEN 'Guia y cuidador'
		WHEN g.legajo IS NOT NULL
			THEN 'Guia'
		WHEN c.legajo IS NOT NULL
			THEN 'Cuidador'
		ELSE 'Ninguno'
	END AS rol
FROM Empleado e
	LEFT JOIN Cuidador c ON e.legajo = c.legajo
	LEFT JOIN Guia g ON e.legajo = g.legajo;
```

5. Listado de guias definidos para un itinerario ordenados por hora:
```sql
SELECT e.nombre, ig.hora, i.codigoItinerario FROM Empleado e
    RIGHT JOIN ItinerarioGuia ig ON e.legajo = ig.legajo
	LEFT JOIN Itinerario i ON i.codigoItinerario = ig.codigoItinerario
    ORDER BY ig.hora;
```

6. Detalle de cada zona, extensión y cantidad de especies que aloja:
```sql
SELECT z.nombre, z.extension, COUNT(e.codigoEspecie) cantidadEspecies FROM Zona z
	LEFT JOIN Especie e ON z.codigoZona = e.codigoZona
	GROUP BY z.codigoZona, z.nombre, z.extension
	ORDER BY z.nombre;
    /* z.codigoZona se agrega en el GRUPO BY para que "una" zonas de igual nombre y extensión, si hubiera. */
```

7. Guías que entraron a trabajar en el último mes:
```sql
SELECT e.nombre
	FROM Empleado e
	INNER JOIN Guia g ON e.legajo = g.legajo
	WHERE DATEDIFF(DAY, e.fechaIngreso, GETDATE()) = 30;
```

8. Empleados con más de 10 años de antigüedad:
```sql
SELECT e.nombre
	FROM Empleado e
	WHERE fechaIngreso < DATEADD(YEAR, -10, GETDATE());

    /*DATEADD(tipoFecha, cantidad, fecha) suma o resta una cantidad de tiempo a una fecha */
```

9. Nombre de la especie y fecha en la que se hizo cargo de la misma cada cuidador:
```sql
SELECT es.nombre, ce.fechaDesde, em.nombre FROM Empleado em
	INNER JOIN CuidadorEspecie ce ON em.legajo = ce.legajo
	INNER JOIN Especie es ON es.codigoEspecie = ce.codigoEspecie
	ORDER BY es.nombre;
```

10. Promedio de duración de todos los itinerarios:
```sql
SELECT AVG (duracion) 'Promedio de duración' FROM Itinerario;
```

11. Nombre de la zona de mayor extensión:
```sql
SELECT nombre, extension FROM Zona WHERE extension = (SELECT MAX(extension) FROM Zona);

/*MAX() se utiliza en consultas, por lo que para utilizarlo en una cláusula WHERE debe haber una subquery dentro*/
```
12. Listado de itinerarios que recorren una zona dada:
```sql
SELECT i.codigoItinerario, z.nombre FROM Itinerario i
	INNER JOIN ZonasItinerario zi ON i.codigoItinerario = zi.codigoItinerario
	INNER JOIN Zona z ON z.codigoZona = zi.codigoZona
	WHERE z.codigoZona = 15;
```

13. Cantidad de itinerarios que visitan cada zona:
```sql
SELECT z.nombre, COUNT(zi.codigoItinerario) CantidadItinerariosPorZona FROM Zona z
	INNER JOIN ZonasItinerario zi ON z.codigoZona = zi.codigoZona
	GROUP BY z.nombre;
```

14. Indicar por cada itinerario la relación longitud sobre duración, ordenados de mayor a menor siendo los mayores los más exigentes:
```sql
SELECT codigoItinerario, (longitud/duracion) 'Longitud/Duracion' FROM Itinerario ORDER BY 'Longitud/Duracion' DESC;
```

15. Indicar los itinerarios cuya duración esté por encima del promedio:
```sql
SELECT codigoItinerario, duracion, (SELECT AVG(duracion) FROM Itinerario) AS duracionProm FROM Itinerario
	WHERE duracion > (SELECT AVG(duracion) FROM Itinerario)
	GROUP BY codigoItinerario, duracion
	ORDER BY 'duracionProm' ASC;

    /* Se debe hacer una subquery de selección dentro de la selección principal para que tome el AVG GENERAL,
    si simplemente se pone AVG(duracion) dentro del SELECT principal va a imprimir el AVG de duración de CADA itinerario. */
```

16. Listado de itinerarios que pueden visitar determinada especie:
```sql
SELECT i.codigoItinerario, es.nombre FROM Itinerario i
	JOIN ZonasItinerario zi ON i.codigoItinerario = zi.codigoItinerario
	JOIN Zona z ON z.codigoZona = zi.codigoZona
	JOIN Especie es ON es.codigoZona = zi.codigoZona
    WHERE es.codigoEspecie = 1;
```

17. Listado de empleados que no tengan especies a cargo ni lleven ningún itinerario:
```sql
SELECT em.nombre, em.legajo FROM Empleado em
	LEFT JOIN CuidadorEspecie ce ON em.legajo = ce.legajo
	LEFT JOIN ItinerarioGuia ig ON em.legajo = ig.legajo
	WHERE ce.legajo IS NULL AND ig.legajo IS NULL;
```

18. Listado de cuidadores y la cantidad de especies a cargo que tiene cada uno:
```sql
SELECT em.nombre, em.legajo, COUNT(ce.codigoEspecie) cantEspecies FROM Empleado em
	INNER JOIN CuidadorEspecie ce ON em.legajo = ce.legajo
	GROUP BY em.nombre, em.legajo
	ORDER BY cantEspecies DESC;
```

19. Cuidadores con más de 5 especies a cargo:
```sql
SELECT em.nombre, em.legajo, COUNT(ce.codigoEspecie) cantEspecies FROM Empleado em
	INNER JOIN CuidadorEspecie ce ON em.legajo = ce.legajo
	GROUP BY em.nombre, em.legajo
	HAVING COUNT(ce.codigoEspecie) > 5
	ORDER BY cantEspecies DESC;
```

20. Nombre de la especie con mayor número de cuidadores:
```sql
SELECT TOP (1) WITH TIES es.nombre, COUNT(ce.legajo) cantCuidadores FROM Especie es 
	JOIN CuidadorEspecie ce ON es.codigoEspecie = ce.codigoEspecie
	GROUP BY es.nombre
	ORDER BY cantCuidadores DESC;

/* CON MAX */
SELECT es.nombre, COUNT(ce.legajo) cantCuidadores FROM Especie es 
	JOIN CuidadorEspecie ce ON es.codigoEspecie = ce.codigoEspecie
	GROUP BY es.nombre
    HAVING COUNT(ce.legajo) = (
    SELECT MAX(cantidad)
    FROM
    (
        SELECT COUNT(ce2.legajo) AS cantidad
        FROM CuidadorEspecie AS ce2
        GROUP BY ce2.codigoEspecie
    ) AS cantidades
)
	ORDER BY cantCuidadores DESC;
```