#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
/*
4. El club del ejercicio anterior decide realizar un control estadístico de la cantidad de veces que han
estado detenidos sus integrantes. Para ello use el archivo BARRAS.TXT generado en el ejercicio
anterior.
Informar de acuerdo al siguiente informe:
Cantidad de Detenciones Cantidad de integrantes
1 						XXXX
2 – 4 						XXXX
5 – 10 						XXXX
más de 10 					XXXX
Cantidad de integrantes de la barra: XXXX
Desean conocer además el apodo del integrante que más detenciones ostenta.
*/

int main(int argc, char *argv[]){
	ifstream fichero; 
	fichero.open("./BARRAS.txt");
	
	if (!fichero.fail()){
		string linea,apodo;
		int contadores[]={0,0,0,0};
		int max=0; 
		int detenciones;
		string picante;	// Quien ostenta mas detenciones
		
		getline(fichero,apodo,'|');
		while (!fichero.eof()){
			fichero >> detenciones;
			fichero.ignore();
			
			///	Comprobar datos para mostrar luego
			if (detenciones==1)
				contadores[0]++;
			else if(detenciones>=2 && detenciones<=4)
				contadores[1]++;
			else if(detenciones>=5 && detenciones<=10)
				contadores[2]++;
			else 
				contadores[3]++;
			
			/// Comprobar quien mas ostenta
			if (max<detenciones) {
				max=detenciones;
				picante=apodo;
			}
			
			getline(fichero,apodo,'|');
		}
		//Mostrar datos
		cout<<"Cantidad de Detenciones Cantidad de integrantes"<<endl;
		cout<<"1		  		"<<contadores[0]<<endl;
		cout<<"2 a 4    			"<<contadores[1]<<endl;
		cout<<"5 a 10    			"<<contadores[2]<<endl;
		cout<<"+10    				"<<contadores[3]<<endl;
		cout<<"Criminal con más detenciones: "<<picante<<" con "<<max;
	}	
	else 
					  cout<<"error al abrir el archivo BARRAS";
	
	fichero.close();
	return 0;
}
	
		
