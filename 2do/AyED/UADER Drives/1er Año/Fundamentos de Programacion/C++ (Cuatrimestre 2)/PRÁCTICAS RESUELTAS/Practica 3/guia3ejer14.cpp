#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*14) La barra brava de un club decide realizar un control estadístico de la cantidad de veces
	que han estado detenidos sus integrantes. Para ello se ingresa por cada integrantre su apodo
	y la cantidad de veces que estuvo detenido.
	Informar de acuerdo al siguiente informe:
	
	Cantidad de Detenciones Cantidad de integrantes
	
	1 XXXX
	2 – 4 XXXX
	5 – 10 XXXX
	más de 10 XXXX
	
	Cantidad de integrantes encuestados: XXXX
	Desean conocer además el apodo del integrante que más detenciones tiene.
	El final de datos se determina con apodo igual a “ZZZ”.
	Nota: Todos los integrantes han sido detenidos por lo menos una vez.*/
	string apodo,apodomas;
	int cantdeten,det1=0,det2=0,det5=0,det10=0,masdeten=0;
	cout<<"Ingrese apodo: "<<endl;
	getline(cin,apodo);
	while (apodo != "ZZZ") {
		cout<<"Ingrese cantidad de detenciones"<<endl;
		cin>>cantdeten;
		cin.ignore();
		if (cantdeten==1){
			
			det1++;
		}
		else if ((cantdeten>=2) && (cantdeten<=4)){
			det2++;
		}
		else if ((cantdeten>=5) && (cantdeten<=10)){
			det5++;
		}
		else if (cantdeten>10){
			det10++;
		}
		if (cantdeten>masdeten){
			masdeten=cantdeten;
			apodomas=apodo;
		}
		cout<<"Ingrese apodo: "<<endl;
		getline(cin,apodo);
	}
	cout<<"Cantidad de Detenciones 	|	|	Cantidad de integrantes"<<endl;
	cout<<"1                        	|   |    "<<det1<<endl;
	cout<<"2-4                      	|   |    "<<det2<<endl;
	cout<<"5-10                     	|   |    "<<det5<<endl;
	cout<<"10 o mas                 	|   |    "<<det10<<endl;
	cout<<"Apodo del que mas detenciones tiene: "<<apodomas;
	return 0;
}

