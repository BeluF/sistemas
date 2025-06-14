#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
	Final 15/12/2022 resuelto por tomás chotawer
*/

/// Structs
struct productos{
	string codigo_barra;	// Código de barra en formato string
	long int cod_barra;		// Código de barra en formato int
	string fecha_hora;		// Fecha y hora
	int tiempo_validez;  	// En meses
	bool nacional;
	bool vence2024;
};

/// Funciones
int check_vencimiento(string fecha, int &mes, int &dia);
void FuncionInutilPuntoA(string &CodigoDePaisQueNoVamosAUSAR);
bool CheckearSiEsNacional(string Codigo_de_Barra);
int ObtenerDatos(productos Producto[], string Direccion);
void Ordenar(productos P[], int max_contador);		// HACER
string DigitoDeControl(string codigo_De_barra);	// HACER

int main(int argc, char *argv[]) {
	/// Declaración de Datos 
	const int N = 500; // Volumen de datos
	int max_productos; // Contador de productos
	productos prod[N];
	int productos_que_vencen_2024[31][12] = {0};
	
	/// Lectura de datos
	max_productos = ObtenerDatos(prod,"./produc.txt");
	if (max_productos == -1)
		return -1;
	
	/// Informe A
	
	/*
		Este informe se resuelve usando la FuncionInutilPuntoA, debido a que deberiamos llamar 
		a la función para que nos devuelva el código nacional, y checkear mediante un if si es 
		nacional el producto o no dentro del for que verás a continuación.
		Yo la hice dentro de la carga de datos como un bool que nos dice directamente si es o no naciona,
		pero de todas formas el procedimiento no cambia mucho.
	*/
	
	int cantidad_importados = 0, cantidad_nacionales = 0;
	for (int i = 0; i < max_productos; i++)
		if (prod[i].nacional)
			cantidad_nacionales++;
		else
			cantidad_importados++;
	
	cout << "Cantidad de productos nacionales: " << cantidad_nacionales << " | Cantidad de productos importados: " << cantidad_importados << endl;
	
	/// Informe B
	int anio = 0, mes = 0, dia = 0;
	for (int i = 0; i < max_productos; i++){
		anio = check_vencimiento(prod[i].fecha_hora,mes,dia);
		int tiempo = prod[i].tiempo_validez;
		
		if (mes + tiempo > 12){
			int tiempo_vencimiento = (mes+tiempo)/12;
			anio += tiempo_vencimiento;
			mes = (mes + tiempo) - (12*tiempo_vencimiento);
		} else 
			mes += tiempo;
		
		if ((anio + tiempo) == 2024){
			productos_que_vencen_2024[dia-1][mes-1]++;	// Restamos 1 porque los arrays arrancan en 0.
			prod[i].vence2024 = true;
		}
	}
	
	cout << setw(4) << " ";			// Armar parte de los meses
	for (int i = 1; i < 13; i++)
		cout << setw(4) << i;
	
	cout << endl;					// Parte de los dias
	for (int dia = 0; dia < 31; dia++){
		cout << setw(4) << dia+1;
		for (int mes = 0; mes < 12; mes++)
			cout << setw(4) << productos_que_vencen_2024[dia][mes];
		cout << endl;
	}
	
	/// Informe C
	// Calcular digito de control
	for (int i = 0; i < max_productos; i++)
		prod[i].codigo_barra = DigitoDeControl(prod[i].codigo_barra);
	
	Ordenar(prod,max_productos);
	
	cout << "\nProductos ordenados por código de barras completo: \n";
	for (int i = 0; i < max_productos; i++)
		cout << setw(13) << prod[i].codigo_barra << setw(20) << prod[i].fecha_hora << setw(10) << prod[i].tiempo_validez << " meses" <<endl;
	
	/// Consigna D
	ofstream productos_new; productos_new.open("./productos_new.txt");
	for (int i = 0; i < max_productos; i++) 
		if (prod[i].vence2024)
			productos_new << prod[i].codigo_barra << endl;
	
	productos_new.close();
	return 0;
}

void Ordenar(productos p[], int max_contador){
	for (int i = 0; i < max_contador-1; i++)
		for (int j = i+1; j < max_contador; j++)
			if (p[i].codigo_barra > p[j].codigo_barra){ // Ascendiente
				productos aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
}

string DigitoDeControl(string cod){
	int max = cod.length();					// longitud del string
	int sumatoria = 0;
	for (int i = max-1; i >= 0 ; i--)
		if (i%2 == 0) 						// posición par
			sumatoria += cod[i] - 48;		// al restar 48 obtenemos el valor original del número, ya que 0 es 48 en ASCII
		else 
			sumatoria += (cod[i] - 48) * 3;
	
	// Calcular decena superior
	int decena;
	for (decena = sumatoria; decena%10 != 0; decena++)
		;									// frena al alcanzar la decena superior

	//Calcular digito de control
	int digito = decena - sumatoria;
	cod += digito + 48; 					// similar al if, al ser 48 el valor del 0 en ASCII, le sumamos eso para obtener el caracter.

	return cod;						
}

int check_vencimiento(string fecha,int &mes, int &dia){
	dia = stoi(fecha.substr(0,2));
	mes = stoi(fecha.substr(3,2));
	return stoi(fecha.substr(6,4)); // Devolver anio
}

bool CheckearSiEsNacional(string cb){
	cb = cb.substr(0,3); // Obtenemos los 3 primeros números del código de barras
	if (cb == "779")
		return true;
	else
		return false;
}

int ObtenerDatos(productos p[], string d){
	int contador = 0;
	string linea;
	ifstream archivo; archivo.open(d);
	if (archivo.fail())
		return -1;
	else {
		archivo >> p[contador].codigo_barra;
		while (!archivo.eof()){
			archivo >> p[contador].fecha_hora >> p[contador].tiempo_validez;
			p[contador].nacional = CheckearSiEsNacional(p[contador].codigo_barra);
			contador++;
			archivo >> p[contador].codigo_barra;
		}
	}
	
	return contador;
}
