#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


void busca_diaMayor(float matI2[][29], int mayor[][2], int col);
void ordenar(float prod[][2], string tamb[]);

int main(int argc, char *argv[]) {
	///DATOS ARCHIVO TAMBO
	string tambos[11]; ///Nombre del tambo
	
	///DATOS ARCHIVOS PRODUCCION 
	int tipoPast[11];
	float litros22,litros23; 	
	
	///MATRICES QUE USO PARA LEVANTAR PARTE DE LOS DATOS DE ARCHIVO PARA INFORME 1
	float produccion [11][6]; 
	float Informe3[11][2];
	string tamboInf3[11];
	///         cant. vacas22 | cant. vacas23 |litros producidos acumulados22 |litros producidos acumulados23 | productividad22 | productividad23
	///tambo        0                 1                 2                             3                              4                 5
	///     1      xx                 xx               xxx                           xxx                            xxx               xxx
	///     2      xx                 xx               xxx                           xxx                            xxx               xxx
	/// ....       ....             .....             ........                      .....                        ......             ........
	///    10      xx                 xx               xxx                           xxx                            xxx               xxx
		
	///MATRICES INFORME 2
	float matI2_2022[11][29];
	float matI2_2023[11][29];
	///      dia  1  2  3 ........ 28
	///tambo
	///1          x  x  x .........x 
	///2          x  x  x .........x 
	///...        x  x  x .........x 
	///10         x  x  x .........x 
	int matInforme2[11][2]; ///busco en las matrices matI2_2022 y matI2_2023 y guardo dias mayores por tambo en matInforme2
	///             dia mayor prod 22      dia mayor prod 23
	///        col          0                       1
	///fila/tambo
	///1          			x  						x  
	///2          			x  						x  
	///...          		x  						x   
	///10            		x  						x  
	
	///VECTOR INFORME 3
	///float vecI3[11];
	
	///VARIABLES SIMPLES NECESARIAS
	int nroT, cont_tambo=0, contReg=0;
	int dia, nT;
	
	///PONGO EN CERO MATRICES CONTADORAS/ACUMULADORAS
	for(int i=1; i<11; i++)
	{
		matInforme2[i][0]=0; 
		matInforme2[i][1]=0; 				
		for(int j=0; j<4; j++)
		{
			produccion[i][j]=0;
			
		}
	
	}
   for (int f=1;f<11;f++){
	   for (int c=1;c<29;c++){
	       matI2_2022[f][c]=0;
	       matI2_2023[f][c]=0;
	   }
	}
	ifstream tambo;
	tambo.open ("tambos.txt");
	if ( tambo.fail() ){
		cout << "Error en la apertura del archivo Tambos";
	}
	else {
		tambo >> nroT;		
		while ( !tambo.eof() ) {
			tambo.ignore();
			getline(tambo,tambos[nroT]);
			cont_tambo++;
			tambo >> nroT;
		}
	}
	tambo.close();
	
	/*PRUEBA LECTURA DE DATOS*/
	cout<<"---------------------------------------------------"<<endl;
	cout << "Veo si cargue bien los datos del archivo tambos"<<endl;
	cout << "Nro Tambo        Nombre"<<endl;
	for(int i=1; i<cont_tambo+1; i++)
		cout<<i<<"               "<<tambos[i]<<endl;
	cout<<endl<<"Total TAMBOS: "<<cont_tambo<<endl;
	cout<<"---------------------------------------------------"<<endl;
	
	ifstream prod;  
	prod.open ("produccion.txt");
	if ( prod.fail() ){
		cout << "Error en la apertura del archivo";
	}
	else {
		prod >> dia;	
		while ( !prod.eof() ) {		
			prod >> nT;	
			prod >> tipoPast[nT];
			prod >> litros22;	
			prod >> litros23;
			///PARA INFORME 1
			produccion[nT][2]=produccion[nT][2]+litros22;	
			produccion[nT][3]=produccion[nT][3]+litros23;	
			
			///PARA INFORME 2 YA litros leidos en fila tambo, columna dia una matriz por año
			matI2_2022[nT][dia]=litros22;					
			matI2_2023[nT][dia]=litros23;					
			
			contReg++;
			prod>> dia;	
		}
	}
	prod.close();
		
	///PRUEBA LECTURA DE DATOS	
	cout<<"PROBANDO HABER CARGADO BIEN LOS DATOS DEL ARCHIVO PRODUCCION"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"tambo     litros22       litros23    tipo pastura"<<endl;
	for(int i=1; i<11; i++)
	{
		cout<<i<<"          "<<produccion[i][2]<<"            "<<produccion[i][3]<<"        "<<tipoPast[i]<<endl;	
	}
	cout<<"---------------------------------------------------"<<endl;
	
	///CARGA DATOS VACAS
	cout<<endl<<"Carga de cantidad de vacas por tambo y por anio..."<<endl;
	for(int i=0; i<10; i++)
	{
		cout<<"Nro. de Tambo (1-10): ";
		cin>>nT;
		cout<<"Cant. Vacas 02/2022: ";
		cin>>produccion[nT][0];
		cout<<"Cant. Vacas 02/2023: ";
		cin>>produccion[nT][1];		
	}
	
	///CALCULO LA PRODUCTIVIDAD
	for (int i=1;i<11;i++)
	{
		produccion[i][4]= (produccion[i][2]/produccion[i][0])*28;
		produccion[i][5]= (produccion[i][3]/produccion[i][1])*28;
	}
	
	///INFORME 1
	cout<<endl<<"Febrero 2022"<<endl;
	cout<<"Nro Tambo    Cant Vacas      Lts de Leche Prod.   Productividad"<<endl;
	for (int i=1;i<11;i++)
	{
		cout<<i<<"       "<<produccion[i][0]<<"         "<<produccion[i][2]<<"          "<<produccion[i][4]<<endl;			
	}
	cout<<"---------------------------------------------------"<<endl;
	
	cout<<endl<<endl<<"Febrero 2023"<<endl;
	cout<<"Nro Tambo    Cant Vacas      Lts de Leche Prod.   Productividad"<<endl;
	for (int i=1;i<11;i++)
	{
		cout<<i<<"          "<<produccion[i][1]<<"          "<<produccion[i][3]<<"           "<<produccion[i][5]<<endl;			
	}
		
	cout<<"---------------------------------------------------"<<endl;
	
	///Informe 2
	busca_diaMayor(matI2_2022, matInforme2, 0);
	busca_diaMayor(matI2_2023, matInforme2, 1);
	cout<<"---------------------------------------------------"<<endl;
	cout<<endl<<endl<<"Nombre del Tambo  Dia Mayor Prod. 2022     Dia Mayor Prod. del 2023"<<endl;
	for (int i=1;i<11;i++)
	{
		cout<<tambos[i]<<"                   "<<matInforme2[i][0]<<"                 "<<matInforme2[i][1]<<endl;			
	}
	cout<<"---------------------------------------------------"<<endl;
	///PASOS PARA GENERAR LO NECESARIO PARA EL INFORME 3
	for (int i=1; i<11;i++)
	{
		Informe3[i][0]=tipoPast[i];
		Informe3[i][1]=produccion[i][5];
		tamboInf3[i]=tambos[i];
	}
	ordenar(Informe3, tamboInf3);
	
	///INFORME 3
	cout<<"---------------------------------------------------"<<endl;
	cout<<"****- Creando archivo. Espere....... -****"<<endl;
	
	ofstream file;	
	file.open("productividad_tambera2023.txt"); 
	string pastura;
	if (file.fail() ) 
	{
		cout << "Error en la creacion del archivo.";
	}
	else 
	{
		for (int r=1; r<11;r++)
		{
			if (Informe3[r][0]=1)
				pastura="Pasto Ovillo";
			else pastura="Alfalfa";
			
			file<<tamboInf3[r]<<pastura<<Informe3[r][1]<<endl;	
		}
	}
	file.close();	
	cout<<endl<<"****- Archivo creado -****"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	
    ///SOLO LIBRES
	cout<<"---------------------------------------------------"<<endl;
	cout<<"****- Creando archivo de LIBRES. Espere....... -****"<<endl;
	ofstream file2;	
	file2.open("menor_productividad.txt"); 
	
	if (file2.fail() ) 
	{
		cout << "Error en la creacion del archivo.";
	}
	else 
	{
		for (int i=1; i<11;i++)
		{
			if (produccion[i][5]<produccion[i][4])
                file2<<tambos[i]<<tipoPast[i]<<produccion[i][5]<<endl;	
		}
	}
	file.close();	
	cout<<endl<<"****- Archivo de LIBRES creado -****"<<endl;	 
	cout<<"---------------------------------------------------"<<endl;
	
	return 0;
}


void busca_diaMayor(float matI2[][29], int mayor[][2], int col)
{
	float may1=0, auxd;
	for(int f=1; f<11; f++)
	{
		for (int c=1;c<29;c++)
		{
		
		if(matI2[f][c] > may1)
		{
			may1=matI2[f][c];
			auxd=c;
			
		}	
		mayor[f][col]=auxd;///agregue la columna
		}
	}
	
}


void ordenar(float prod[][2], string tamb[])
{
	string aux;
	int aux1;
	
	for(int a=1; a<11-1; a++)
		for(int b=a+1; b<11; b++)
	{
		if (prod[a][2] > prod[b][2])
		{
			for(int k=0; k<2; k++)
			{
				aux1= prod[a][k];
				prod[a][k]= prod[b][k];
				prod[b][k]= aux1;			
				
			}
			
			aux= tamb[a];
			tamb[a]=  tamb[b];
			tamb[b]= aux;
		}
	}
}




