#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

string extrae_tipopat(string codi);
int busca_DNI(string s_pac[][8], string doc, int cnew);
void extrae_anionac(string fec_nac, int &a_nac);
void busca_patologia(string s_pat[][2], string cod, int cant, int & fila);

int main(int argc, char *argv[]) {
	///DATOS ARCHIVO PACIENTES
	string s_pacientes [200][8]; ///DNI|Apellido|Nombres|Fecha Nac| OS|Descri. OS |cod. pat.|tipo enfer.
	//en la col 6, guardare las letras del cod.pat para facilitar tareas
	///DATOS ARCHIVO PATOLOGIAS RESPIRATORIAS
	string s_patologias [200][2]; ///cod. pat.|Descrip.

	int anioactual= 2023;
	int cant_pac=0;///CANTIDAD TOTAL DE PACIENTES
	int cant_pato=0; ///CANTIDAD TOTAL DE PATOLOGIAS
	int cant_new; ///CANTIDAD DE PACIENTES TOTALES (CON LOS NUEVOS AGREGADOS)
	string DNI; ///dni paciente. 
	string cod_pat; ///codigo patologia
	int dia; ///dia del mes
	string cod_auxi; ///auxiliar para codigo de patologia
	float porc60cr; ///porcentaje mayores de 60 con enf.cronicas
	int may60cr; ///contador mayores de 60 y con enf. cronicas
	int anio_nac; ///auxiliar para anio nacimiento del paciente
	int edad; ///auxiliar para calculo de edad del paciente
	int matpuntob[200][2]; ///cuenta patologias segun quincena 0: 1-15 |1: 16-31
	int posi; ///auxiliar para determinar fila de un elemento
	int fila_pat; ///auxiliar para determinar posici�n de codigo de patologia
	
	//Extracción de datos de pacientes
	ifstream pac;
	pac.open ("PACIENTES.TXT");
	if ( pac.fail() ){
		cout << "Error en la apertura del archivo";
	}
	else {
		while ( !pac.eof() ) {
			for (int k=0; k<7; k++){
				getline(pac,s_pacientes[cant_pac][k]);
			}
			s_pacientes[cant_pac][7]= extrae_tipopat(s_pacientes[cant_pac][6]);
			cant_pac++;
		}
	}
	pac.close();
		
	//Extracción de datos de patologías.	
	ifstream pato;  
	pato.open ("PAT_RESPI.TXT");
	if ( pato.fail() ){
		cout << "Error en la apertura del archivo";
	}
	else {
		while ( !pato.eof() ) {		
			getline(pato,s_patologias[cant_pato][0]);	
			//incrementamos el contador usando el ++, ya que lo hace dsps de la instrucción
			getline(pato,s_patologias[cant_pato++][1]);
		}
	}
	pato.close();
	
	//poner contadores en 0.
	for(int i=0; i<200; i++)
		for(int j=0; j<2; j++)
			matpuntob[i][j]=0;
	

	///CARGA DE DATOS...	
	cant_new= cant_pac;
	cout<<"\nIngrese dia: ";
	cin>>dia;
	while (dia != 99)
	{
		cin.get();
		cout<<"Ingrese DNI: ";
		getline(cin, DNI);
		//posi adquiere un numero distinto de 999 en caso de encontrar al paciente.
		posi=busca_DNI(s_pacientes, DNI, cant_new);
		if (posi != 999)
		{
			cout<<"Ingrese codigo de patologia: ";
			getline(cin,cod_pat);
			cod_auxi=extrae_tipopat(cod_pat);
			if(s_pacientes[posi][6] == "VR")
				s_pacientes[posi][6]= cod_pat;
		}
		else {
			cout<<endl<<"PACIENTE NUEVO..."<<endl;
			s_pacientes[cant_new][0]= DNI;
			cout<<"Apellido: ";
			getline(cin, s_pacientes[cant_new][1]);
			cout<<"Nombres: ";
			getline(cin, s_pacientes[cant_new][2]);
			cout<<"Fecha Nacimiento (AAAAMMDD): ";
			getline(cin, s_pacientes[cant_new][3]);
			cout<<"Tiene Obra Social S o N: ";
			getline(cin, s_pacientes[cant_new][4]);
			if (s_pacientes[cant_new][3] == "S")
			{
				cout<< "Ingrese Descripcion: ";
				getline(cin, s_pacientes[cant_new][5]);
			}
			else s_pacientes[cant_new][5]= "---";
			cout<<"Codigo Patologia (EN MAYUSCULAS): ";
			getline(cin, s_pacientes[cant_new][6]);
			s_pacientes[cant_new][7]= extrae_tipopat(s_pacientes[cant_new][6]);
			cod_pat=s_pacientes[cant_new][6];//esto es para el punto b y que coincida cuando el pac. ya existe
			cant_new++;
		}
		busca_patologia(s_patologias, cod_pat, cant_pato, fila_pat);
		if(dia <=15)
			matpuntob[fila_pat][0]++;
		else matpuntob[fila_pat][1]++;
		
		cout<<"Ingrese dia: ";
		cin>>dia;
	}
			
	
			
	///verificar edad y enfermedad y contar.
	for(int i=0; i<cant_new; i++)
	{
		extrae_anionac(s_pacientes[i][3], anio_nac);
		edad= anioactual-anio_nac;
		if((edad > 60) && (s_pacientes[i][7] != "VR"))
			may60cr++;
	}
	porc60cr= (may60cr * 100) / cant_new;
	///PRIMER INFORME
	cout<<endl<<"Porcentaje de pacientes mayores de 60 anios que padecen enf. cronicas: "<<porc60cr<<endl<<endl;
			
		
	///SEGUNDO INFORME
	/*b) Listado con cantidades de pacientes atendidos por tipo de patología y quincena del mes con el siguiente formato:
	Código     Descripción	1º Quincena        2º Quincena
	xxxx		xxxxx			99		99*/
	
	cout<<endl<<"Cantidad de pacientes por patologia atendidos en enero 2023"<<endl;
	cout<<"Codigo  Descripcion                    1ra Quinc.    2da Quinc."<<endl;
	for (int i=0;i<cant_pato;i++)
		cout<<s_patologias[i][0]<<"  "<<s_patologias[i][1]<<"  "<<matpuntob[i][0]<<"  "<<matpuntob[i][1]<<endl;
	
	
	cout<<"---------------------------------------------------"<<endl;
		
	
	
    ///SOLO LIBRES
	cout<<"****- Creando archivo. Espere....... -****"<<endl;
		 
	ofstream archi;	
	archi.open("PACIENTES_NEW.TXT"); 
	
	if (archi.fail() ) 
		{
			cout << "Error en la creacion del archivo.";
		}
	else 
		{
			for( int i=0; i<cant_new; i++)
			{
				archi<<s_pacientes[i][0]<<endl;
				archi<<s_pacientes[i][1]<<endl;
				archi<<s_pacientes[i][2]<<endl;
				archi<<s_pacientes[i][3]<<endl;
				archi<<s_pacientes[i][4]<<endl;
				archi<<s_pacientes[i][5]<<endl;
				archi<<s_pacientes[i][6]<<endl;				
			}			
	    }
	archi.close();	
	cout<<endl<<"****- Archivo creado -****"<<endl;
	
	return 0;
}
	

string extrae_tipopat(string codi)
{
	string aux=codi.substr(0,2);
	return aux;
}
	

void extrae_anionac(string fec_nac, int &a_nac)
{
	string aux= fec_nac.substr(0,4);
	a_nac=stoi(aux);
}


int busca_DNI(string s_pac[][8], string doc, int cnew)
{
	int p= 999; ///valor absurdo para determinar si existe o no
	for(int f=0; f<cnew; f++)
	{
		if(doc == s_pac[f][0])
		{
			p=f;
			f=cnew;
		}		
	}
	return p;
}


void busca_patologia(string s_pat[][2], string cod, int cant, int & fila)
{
	for(int fi=0; fi<cant; fi++)
	{
		if(cod == s_pat[fi][0])
		{
			fila=fi;
			fi=cant;
		}		
	}
}


