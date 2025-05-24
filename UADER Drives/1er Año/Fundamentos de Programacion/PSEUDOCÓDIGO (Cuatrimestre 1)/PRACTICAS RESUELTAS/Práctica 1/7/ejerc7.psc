Algoritmo ejercicio7
	Definir Xa,Ya,Xb,Yb,Xc,Yc Como Real;			//Coordenadas pertinentes a cada punto
	Definir AB,BC,CA Como Real; 					//vamos usar estas variables como auxiliares para el punto B, pero no son necesarias.
	Escribir "Ingrese coordenadas del punto A:";	//entrada de datos del punto A
	Escribir Sin Saltar "X -";
	Leer Xa;
	Escribir Sin Saltar "Y -";
	Leer Ya;
	Escribir "Ingrese coordenadas del punto B:";	//entrada de datos del punto B
	Escribir Sin Saltar "X -";
	Leer Xb;
	Escribir Sin Saltar "Y -";
	Leer Yb;
	Escribir "Ingrese coordenadas del punto C:";	//entrada de datos del punto C
	Escribir Sin Saltar "X -";
	Leer Xc;
	Escribir Sin Saltar "Y -";
	Leer Yc;
	Escribir "=======================================================";		//línea decorativa para separar la carga de datos de los resultados que se mostrarán por pantalla.
	//https://www.youtube.com/watch?v=kDzTTOvv5dc&ab_channel=MatemáticasprofeAlex 	en este video se explica la distancia entre 2 puntos usando vectores, aunque la formula está al pie del ejercicio.
	AB<-((Xb-Xa)^2+(Yb-Ya)^2)^(1/2);	//Elevar a (1/2) es lo mismo que usar la funcion RAIZ/RC
	BC<-RAIZ((Xc-Xb)^2+(Yc-Yb)^2); //Lo mismo de antes pero hecho con raíz en ves de elevar
	CA<-RAIZ((Xa-Xc)^2+(Ya-Yc)^2);
	Escribir "La distancia entre A y B	es: ",AB,", La distancia entre B y C es: ",BC;
	Escribir "La distancia entre C y A es: ",CA;
	Escribir "La distancia total que debe recorrer el avión es: ",AB+BC+CA;	//sumatoria de distancias
FinAlgoritmo
