#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/*
	Resolución by chotawer
	Final 14.12.2023
*/

struct pelicula{
	string codigo;
	string titulo;
	int cantidad_comentarios = 0;
	float calificacion_maxima = 0, calificacion_minima = 6;
	float calificacion_promedio;
};

struct comentario{
	string codigo;
	float puntuacion;
	string texto;
};

int contar_palabras(string texto, string dato); 
float calcular_calificacion(comentario c[999], int contador_comentarios, pelicula &p);

int main(int argc, char *argv[]) {
	const int N = 999;
	int cp = 0;	// contador peliculas
	int cc = 0; // contador comentarios
	int indice_pelicula_mas_comentarios = 0; // Indice donde está la pelicula con mayor cantidad de comentarios
	int mayor_cantidad_comentarios = 0;
	int miedo = 0, terror = 0, suspenso = 0;
	
	float max = 0;
	float min = 6;
	
	string titulo_pelicula_maxima;
	string titulo_pelicula_minima;
	
	ifstream archivo;
	ofstream analisis;
	
	pelicula p[N];	// peliculas
	comentario c[N];	// comentarios
	
	/// Lectura de datos;
	// Lectura hecha asumiendo que los datos estan separados por un enter, debido a que no poseo el archivo original.
	
	archivo.open("./peliculas.txt"); 
	if (archivo.fail())
		return 1;
	while(archivo >> p[cp].codigo){
		archivo.ignore();
		getline(archivo,p[cp].titulo);
		cp++;
	}
	archivo.close();
	
	archivo.open("./comentarios.txt"); 
	if (archivo.fail())
		return 1;
	while(archivo >> c[cc].codigo >> c[cc].puntuacion){
		archivo.ignore();
		getline(archivo,c[cc].texto);
		cc++;
	}
	archivo.close();
	
	/// Calificacion
	
	for (int i = 0; i < cp; i++){
		p[i].calificacion_promedio = calcular_calificacion(c,cc,p[i]);
		if (p[i].calificacion_promedio <  min){
			min = p[i].calificacion_promedio;
			titulo_pelicula_minima = p[i].titulo;
		}
		if (p[i].calificacion_promedio > max){
			max = p[i].calificacion_promedio;
			titulo_pelicula_maxima = p[i].titulo;
		}
	}
	
	/// Ordenamiento
	
	for (int i = 0; i < cp-1; i++)
		for (int j = i+1; j < cp; j++)
			if (p[i].codigo < p[j].codigo)
			{
				pelicula aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
	
	/// Obtener pelicula con mayor cantidad de comentarios post ordenamiento
			
	for (int i = 0; i < cp; i++)
		if (p[i].cantidad_comentarios > mayor_cantidad_comentarios){
			mayor_cantidad_comentarios = p[i].cantidad_comentarios;
			indice_pelicula_mas_comentarios = i;
		}
	
	/// Informe
	
	for (int i = 0; i < cp; i++){
		cout << "Codigo de pelicula: " << p[i].codigo 
			<< "\nTitulo: " << p[i].titulo
			<< "\nCantidad de reseñas: " << p[i].cantidad_comentarios
			<< "\nCalificacion promedio: " << p[i].calificacion_promedio
			<< "\nCalificacion minima: " << p[i].calificacion_minima << "  Calificacion maxima:" << p[i].calificacion_maxima
			<< "\n*******************************\n";
	}
	cout << "PELICULA MEJOR CALIFICADA : " << titulo_pelicula_maxima
		 << "\nPELICULA PEOR CALIFICADA : " << titulo_pelicula_minima;
	
	/// Archivo con analisis
	
	string direccion= "./analisis_[";
	direccion = direccion + p[indice_pelicula_mas_comentarios].codigo + "].txt";
	analisis.open(direccion);
	
	for (int i = 0; i < cc; i++)
		if (c[i].codigo == p[indice_pelicula_mas_comentarios].codigo){
			analisis << c[i].puntuacion;
			if (c[i].puntuacion > 3)
				analisis << "\nSI\n";
			else
				analisis << "\nNO\n";
			analisis << c[i].texto.length() << endl;
			analisis << c[i].texto << endl;
			miedo = contar_palabras(c[i].texto,"miedo");
			terror = contar_palabras(c[i].texto,"terror");
			suspenso = contar_palabras(c[i].texto,"suspenso");
			analisis << "Cantidad de veces que aparecen las palabras:"
				<< "\nmiedo = " << miedo
				<< "\nterror = " << terror
				<< "\nsuspenso = " << suspenso << endl;
			analisis << "*************************************\n";
		}
	
	analisis.close();
	return 0;
}

int contar_palabras(string texto, string dato){
	int total = 0;
	int pos = 0;
	int palabra_Encontrada = texto.find(dato);
	while (palabra_Encontrada != -1){
		total++;
		pos =  palabra_Encontrada;
		palabra_Encontrada = texto.find(dato,pos+1);
	}
	return total;
}
	

float calcular_calificacion(comentario c[999], int cc, pelicula &p){
	float promedio = 0;
	
	for (int i = 0; i < cc; i++){
		if (c[i].codigo == p.codigo){
			promedio += c[i].puntuacion;
			p.cantidad_comentarios++;
			if (c[i].puntuacion > p.calificacion_maxima)
				p.calificacion_maxima = c[i].puntuacion;
			if (c[i].puntuacion < p.calificacion_minima)
				p.calificacion_minima = c[i].puntuacion;
		}
	}
		
	return promedio/p.cantidad_comentarios;
}
