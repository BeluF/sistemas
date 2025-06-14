//version mia del parcial para practicar, usando todos los temas e incluso creando un archivo.
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
//estructura que contiene la info de c/atleta
struct at{
    int DNI, Edad, Puesto;
};

//estructura que contiene la info de la provincia	
struct provincias{
    string provincia;
	string deporte;
    int catletas;
    at *atletas;
    int puestos[4]={0,0,0,0};
    int DNIMenor;
};

int main(int argc, char *argv[]){
	provincias p[24]; int i=0;
	do{
		string dummy;	int young=0;
	//procesar datos de provincia
		cout<<"\nbucle: "<<i<<endl;
		cout<<"Ingrese nombre de provincia: ";getline(cin,dummy);
		if (dummy=="xx" || dummy=="XX") break;	//romper proceso en caso de ingresar fin de datos
		p[i].provincia=dummy;
    	cout<<"Ingrese nombre del deporte: ";getline(cin,p[i].deporte);
    	cout<<"Ingrese cantidad de atletas: ";cin>>p[i].catletas;
		p[i].atletas= new at[p[i].catletas];
	//procesar datos por cada atleta
		int c=0;
		cout<<"\n valor de c: "<<c;
		while (p[i].provincia!="xx" && c<p[i].catletas){
			cout<<"Ingrese DNI del atleta: ";cin>>p[i].atletas[c].DNI;
			cout<<"Ingrese Edad del atleta: ";cin>>p[i].atletas[c].Edad;
			cout<<"Ingrese Puesto del atleta: ";cin>>p[i].atletas[c].Puesto;
			//incrementar cantidad de puestos
			if (p[i].atletas[c].Puesto>0 && p[i].atletas[c].Puesto<4){p[i].puestos[p[i].atletas[c].Puesto]++;} 
			else if (p[i].atletas[c].Puesto>=4 && p[i].atletas[c].Puesto<=5){ p[i].puestos[0]++;}
			//verificar menor
			if (p[i].atletas[c].Edad<young || young==0){
				young=p[i].atletas[c].Edad;
				p[i].DNIMenor=p[i].atletas[c].DNI;
			}
			//contador
			c++;
			}
		i++;
		cin.ignore();
	}while(i<24);
    	
    //escupir datos
    for (int j=0;j<i;j++){
    	cout<<"================================================================"<<endl;
    	cout<<"JUEGOS EVITA"<<endl<<"Provincia: "<<p[j].provincia<<"			Deporte: "<<p[j].deporte;
    	cout<<"\nDNI		Edad		Puesto";
    	for (int n=0;n<p[j].catletas;n++){
    		cout<<endl<<p[j].atletas[n].DNI<<"		"<<p[j].atletas[n].Edad<<"		"<<p[j].atletas[n].Puesto;
		}
		cout<<"\nCantidad total de: [1 Puesto]: "<<p[j].puestos[1]<<" | [2 Puesto:] "<<p[j].puestos[2]<<" | [3 Puesto]: "<<p[j].puestos[3]<<" | [4 y 5 Puestos:] "<<p[j].puestos[0];
		cout<<"\nDNI del atleta más joven: "<<p[j].DNIMenor;
		cout<<endl<<"================================================================"<<endl;
	}
	
	//imprimir datos
	ofstream archivo;
	archivo.open("./PARCIAL.txt",ios::app);
	for (int j=0;j<i;j++){
    	archivo<<"================================================================"<<endl;
    	archivo<<"JUEGOS EVITA"<<endl<<"Provincia: "<<p[j].provincia<<"			Deporte: "<<p[j].deporte;
    	archivo<<"\nDNI		Edad		Puesto";
    	for (int n=0;n<p[j].catletas;n++){
    		archivo<<endl<<p[j].atletas[n].DNI<<"		"<<p[j].atletas[n].Edad<<"		"<<p[j].atletas[n].Puesto;
		}
		archivo<<"\nCantidad total de: [1 Puesto]: "<<p[j].puestos[1]<<" | [2 Puesto:] "<<p[j].puestos[2]<<" | [3 Puesto]: "<<p[j].puestos[3]<<" | [4 y 5 Puestos:] "<<p[j].puestos[0];
		archivo<<"\nDNI del atleta más joven: "<<p[j].DNIMenor;
		archivo<<endl<<"================================================================"<<endl;
	}
	archivo.close();
	
    //liberar datos y terminar el programa
    for (int k=0;k<24;k++)
    	delete[] p[i].atletas;
    return 0;
}
