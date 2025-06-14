#include <iostream>
using namespace std;

/// Practica 7, Ejercicio 8, by chotawer
/*
	8. En distintas localidades de Buenos Aires, Entre Ríos y Tucumán se realiza el cultivo de
	arándanos. Se necesitan hacer algunos cálculos estadísticos generales de lo que sucede en
	las diferentes provincias y en Entre Ríos en particular sobre el incremento de su producción.
	Se ingresan los datos de las distintas localidades de las provincias de la siguiente forma:
	código de la provincia (1: Buenos Aires, 2: Entre Ríos y 3:Tucumán), cantidad de localidades
	que producen arándanos y luego, por cada una de esas localidades: código de localidad
	(1..N), superficie cosechada (en ha) y producción en toneladas en el año . 
	Luego, se ingresan sólo para las N localidades de Entre Ríos, lo producido en el año pasado,
	de la siguiente manera: código de localidad (1..N) y producción en toneladas en el año
	anterior.
	Se desea calcular e informar:
	a) El rendimiento en kg/ha de cada localidad. 
	b) El promedio de rendimiento entre las tres provincias 
	c) El nombre de la provincia con mejor rendimiento.
	d) De las localidades de la Provincia de Entre Ríos el promedio de producción de los dos
	últimos años
	Diseñar una función para cada punto. 
	Obs.: Rendimiento (kg/ha) = producción en tn/superficie cosechada * 1000
*/

float ObtenerRendimiento(float produccion, float hectareas);
float PromedioRendimiento(float rendimiento_Total, int cantidad_de_localidades);
string NombreProvinciaMejorRendimiento(float  array_Reloco[]);
float Zimbabwe(float rendimiento_Actual, float rendimiento_pasado);

int main(int argc, char *argv[]) {
	float datos[3][999][2]; // i = Provincias; j = Localidades; k = 0: Superficie cosechada, 1: Produccion en toneladas
	float entre_Rios[999], total_Rendimiento[3] = {0};
	int contador_localidades[3];
	int codigo_provincia;
	int codigo_localidad;
	float aux;

	for (int cantidad_provincias = 0; cantidad_provincias < 3; cantidad_provincias++){
		float aux1, aux2;
		cout << "Ingrese codigo de provincia: \n";
		cin >> codigo_provincia;
		codigo_provincia--;
		cout << "Ingrese cantidad de localidades: \n";
		cin >> contador_localidades[codigo_provincia];
		cout << "Ingrese codigo de localidad, superficie cosechada, y produccion de toneladas en el anio: \n";
		
		for (int i = 0; i < contador_localidades[codigo_provincia]; i++){
			cin >> codigo_localidad >> aux1	>> aux2;
			datos[codigo_provincia][codigo_localidad-1][0] = aux1;
			datos[codigo_provincia][codigo_localidad-1][1] = aux2;
		}
	}
	
	cout << "\n" << datos[0][0][1] << endl;
	
	cout << "Produccion del anio pasado en Entre Rios por localidad: \n";
	for (int i = 0; i < contador_localidades[1]; i++)
		cin >> codigo_localidad >> entre_Rios[codigo_localidad-1];

	// Obtener punto A:
	string localidades[]={"Buenos Aires", "Entre Rios", "Tucuman"};
	for (int i = 0; i < 3; i++){
		cout << "\nProduccion en " << localidades[i] << ":\n";
		for(int j = 0; j < contador_localidades[i]; j++){
			aux = ObtenerRendimiento(datos[i][j][1], datos[i][j][0]); 
			total_Rendimiento[i] += aux;
			cout << "Localidad: " << j+1 << " | Rendimiento de la localidad: " <<  aux << "kg/ha" << endl;
		}
	}		
	// Obtener punto B:
	for (int i = 0; i < 3; i++)
		total_Rendimiento[i] = PromedioRendimiento(total_Rendimiento[i], contador_localidades[i]);
	
	cout << "\nPromedio de la provincia de Buenos aires: " << total_Rendimiento[0]
		<< "\nPromedio de la provincia de Entre Rios: " << total_Rendimiento[1]
		<< "\nPromedio de la provincia de Tucuman: " << total_Rendimiento[2];

	// Obtener punto C:
	cout << "\n\nEl nombre de la provincia con el mejor rendimiento es: " << NombreProvinciaMejorRendimiento(total_Rendimiento);

	// Obtener punto D:
	for (int i = 0; i < contador_localidades[1]; i++)
		cout << "\n\nPromedio de rendimiento de la localidad " << i+1 << ": " << Zimbabwe(datos[1][i][1],entre_Rios[i]);

	return 0;
}

float ObtenerRendimiento(float produccion, float hectareas){
	return (produccion/hectareas) * 1000;
}

float PromedioRendimiento(float rendimiento_Total, int cantidad_de_localidades){
	return rendimiento_Total/cantidad_de_localidades;
}

string NombreProvinciaMejorRendimiento(float  array_Reloco[]){
	float max = 0;
	int indice = 0;

	for (int i = 0; i < 3; i++)
		if (max < array_Reloco[i]){
			max = array_Reloco[i];
			indice = i;
		}
	
	switch (indice){
		case 0: return "Buenos Aires";
		case 1: return "Entre Rios";
		case 2: return "La jungla";
	}
	
	return "Tengo que poner esto porque sino el compilador da error jaja re boludo el C++ quien programa en esto ajsdjkasjka";
}

float Zimbabwe(float rendimiento_Actual, float rendimiento_pasado){
	return (rendimiento_Actual+rendimiento_pasado) / 2;
}
