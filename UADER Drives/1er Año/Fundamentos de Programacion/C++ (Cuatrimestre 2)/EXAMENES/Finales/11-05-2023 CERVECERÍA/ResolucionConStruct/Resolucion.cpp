// version corregida por mi y mas especifica
// no uso acentos en todos los comentarios porque los IDEs se confunden.
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>	//para usar getch
#include <cmath>	//para usar trunc
using namespace std;

/// ---------------------------------[STRUCTS]--------------------------------------------
struct c{							//Concursantes
	string cod, nombre;
	int tot=0, prod=0, prof=0, inv=0;
};
struct a{							//Asistentes
	string dni, nya, curso;
	char part='0';
};

/// ---------------------------------[FUNCIONES]--------------------------------------------
	
int funcionb(c cur[], char &pt, string &codcur, int ct);	//funcion del punto B

bool busqueda(a as[], string dni, int &pos, int at);

bool busqueda(c cu[], string curso, int &pos2, int ct);

/// ==========================[Main]==========================
int main(int argc, char** argv){
	const int MAX = 500; 			/// Cantidad m�xima del indice de los arrays
	c cursos[MAX]; a assist[MAX];	/// assist = asistentes
	int i=0;
	
	//Array con las direcciones de los archivos que queremos abrir	
	string archivo[]={"./cursos.txt","./asistentes.txt"};	
	//Array de variables tipo fichero									
	ifstream f[2]; 
	//Recorremos el array de ficheros y los abrimos dándoles una dirección.
	for (int k=0; k<2; k++) 
		f[k].open(archivo[k]);
	
	/// =======[Extraccion de datos de cursos]=======	
	// Variable con el tamanio maximo del registro de concursos
	int ct = 0;	
	// En caso de no fallar, invocamos a tamanio y obtenemos el tamanio.
	if (!f[0].fail()) 
		while (getline(f[0],cursos[ct].cod))
			//"++" incrementa el valor de la variable despues de ejecutar la instruccion, por lo que cuando termine leer el dato se incrementara sola.
			getline(f[0],cursos[ct++].nombre);		
	else {
		cout<<"Error de apertura";
		return 1;
	}

	/// =======[Extraccion de datos de asistentes]=======	
	// Variable con el tamanio maximo del registro de asistentes
	int at = 0;											
	if (!f[1].fail()) 
		while (getline(f[1],assist[at].dni))
			getline(f[1],assist[at++].nya);		
	else {
		cout<<"Error de apertura";
		return 1;
	}
	
	/// Cerramos los archivos recorriendo el array de ficheros.
	for (int k=0; k<2; k++) 
		f[k].close();

	/// =======[Carga de datos]=======
	// pos indica la posicion en el registro asistentes, pos2 el de cursos.
	string dni, curso; int pos=0,pos2=0;	
	do{
		cout<<"Ingrese DNI: ";
		cin>>dni;
		//Si el DNI es distinto de 0 y la busqueda encuentra el DNI, pedimos datos del curso.
		if (dni!="0" && busqueda(assist,dni,pos,at)){	
			cout<<"Ingrese codigo de curso: ";
			cin>> curso;
			//Si el curso existe, le damos ese curso al asistente.
			if (busqueda(cursos,curso,pos2,ct)){	
				assist[pos].curso=curso;
				//Cargar caracter de participacion
				bool bucle=true;		
				cout<<"Ingrese caracter de participacion [0. Ninguna | 1. Investigadores | 2. Profesionales | 3. Productores]\n";
				//Comprobar que se ingresa el caracter de participacion correcto
				while (bucle){			
					//Lee el caracter de participacion directamente del teclado					
					assist[pos].part=getch();		
					//Si el caracter ingresado esta en la lista, se incrementa el contador de ese tipo de caracter participacion y se termina el bucle.		
					switch (assist[pos].part){
					case '0': bucle=false;
						break;	
					case '1': cursos[pos2].inv++; bucle=false;	
						break;
					case '2': cursos[pos2].prof++; bucle=false;  
						break;
					case '3': cursos[pos2].prod++; bucle=false;  
						break;
					}
				}
				//Se incrementa el contador del total de asistentes de ese curso.
				cursos[pos2].tot++;	
			}
			else cout<<"Codigo no encontrado\n";
		}
		else cout<<"El participante no ha sido cargado\n";
	}while (dni!="0");	
	
	/// ---------------------------------[Punto A]--------------------------------------------
	//Ordenamiento de los cursos segun el total de participantes.
	for (int i=0; i<ct; i++)				
		for (int j=i+1; j<ct; j++)
			//Si el total en la posicion i es inferior a la posicion j, los cambiamos de lugar.
			if (cursos[i].tot<cursos[j].tot){
				c aux=cursos[i];
				cursos[i]=cursos[j];
				cursos[j]=aux;
			}
		
	
	
	/// Mostrar como indica la consigna A.
	cout<<"Cod. curso   Nombre Curso  Cant Investigadores   Cant. Profesionales   Cant. Productores  Cant. Total\n";
	for (int i=0; i<ct;i++){
		cout<<cursos[i].cod<<"    "<<cursos[i].nombre<<"    "<<cursos[i].inv<<"    "<<cursos[i].prod<<"    "<<cursos[i].tot<<endl;
	}
	
	/// ---------------------------------[Punto B]--------------------------------------------
	//part se quedara con el caracter de paritipacion prominente.
	char part;
	//funcionb le asigna a int el maximo de asistentes, y de paso por referencia le da el valor al caracter de participacion y a los cursos.
	int max= funcionb(cursos,part,curso,ct);
	cout<<"\nEl curso "<<curso<<" fue el que tuvo mayor caracter de participacion, con participacion tipo "<< part<<" y un maximo de "<<max<<".";

	/// ---------------------------------[Punto C]--------------------------------------------
	ofstream noa; noa.open("./no_asistentes.txt");
	for (int i=0; i<at; i++){
		if (assist[i].part=='0') {
			//Respetamos el formato del documento con el que trabajamos inicialmente.
			noa<<assist[i].dni<<endl<<assist[i].nya<<endl;
		}
	}
	noa.close();
	/// ---------------------------------[fin del examen]--------------------------------------------
	return 0;
}

///Busca el DNI del asistente
bool busqueda(a as[], string dni, int &pos, int at){	
	for (int i=0; i<at; i++)
		//Si encuentra el DNI, la pos se queda con la posicion donde se encontro.
		if (as[i].dni==dni){
			pos=i;
			return true;
		}
		
	return false;
}	
	
///Busca el codigo de curso
bool busqueda(c cu[], string curso, int &pos2, int ct){
	for (int i=0; i<ct; i++)
		if (cu[i].cod==curso){
			//Si encuentra el curso, la pos se queda con la posicion donde se encontro.
			pos2= i;
			return true;
		}
		
	return false;
}
	
/// Obtiene el maximo caracter de participacion.
int funcionb(c cur[], char &pt, string &codcur, int ct){		
	int max=0;					
	for (int i=0; i < ct; i++){
		//Se queda con el valor maximo del caracter de partipacian, el tipo y de paso guarda del nombre del curso.
		if (max<cur[i].inv) {
			max=cur[i].inv;
			codcur= cur[i].nombre;
			pt='1';
		}
		if (max<cur[i].prod){
			max=cur[i].prod;
			codcur= cur[i].nombre;
			pt='3';
		}
		if (max<cur[i].prof){
			max=cur[i].prof;
			codcur= cur[i].nombre;
			pt='2';
		}
	}
	return max;	
}
