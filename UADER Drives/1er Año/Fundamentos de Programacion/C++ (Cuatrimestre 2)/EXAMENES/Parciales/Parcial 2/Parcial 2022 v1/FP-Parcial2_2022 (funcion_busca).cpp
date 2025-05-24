#include <iostream>
#include <string>
using namespace std;
/*La Direccion de Transito de Oro Verde, necesita implementar medidas de seguridad vial. Para ello, relevara cierta informacion
de las motos registradas en dicha localidad.
Al inicio se ingresan los datos de las 1550 motos registradas: patente (alfanumerico), nro de carnet de conducir del propietario, 
cantidad de multas, cantidad de acarreos.
Luego se ingresan los datos de las multas efectuadas en los meses de mayo a agosto inclusive del corriente a√±o: patente (alfanumerico), 
tipo de multa (1: exceso de velocidad, 2: documentacion vencida, 3: conducir sin licencia, 4: conducir sin casco, 5: conducir 
alcoholizado), dia y mes de la multa (en variables numericas por separado). El fin de datos esta dado por Patente = 'x'. 
Una misma moto pudo ser multada mas de una vez en el periodo y por diferentes motivos. Ademas, debe considerarse que, si la multa es 
de tipo 3, 4 o 5, se retiene la moto, lo cual implica un acarreo.

Se desea obtener los siguientes informes: 
1) Listado ordenado decreciente por cantidad de multas, con todos los valores actualizados, segun el siguiente formato:
PATENTE	CANT. MULTAS		CANT. ACARREOS
XXXXX		        XXX	 	     XXX

2) Listado por patente y por mes (puede incluir valores 0), solamente con los acarreos efectuados en el periodo evaluado:
PATENTE	MAYO	JUNIO	JULIO	AGOSTO
XXXX		XX	XX	XX	XX
XXX		XX	XX	XX	XX
...

3) Listado con totales segun tipo de multa en el periodo de tiempo considerado:
TIPO (*)		TOTAL MULTAS		%
xxxxxx		xx			xx
...
TOTALES 	XXX			100%

(*) OBS: Debe listarse la descripcion de la multa, no el numero.
*/

int busca( string dato, string pat[], int cant);
void ordenar(int hm[][2], string p[], int pm[][4], int c);

int main() {
	string patente[4]; //patente (alfanumerico)
	string nrocarnet; //nro carnet de conducir
	int historico_multas[4][2];//0: cantidad de multas, 1: cantidad de acarreos
	int patente_mes[4][4]; //matriz contadora por patente y por mes del periodo
	int tipo_multa[6]; //vector para contar multas segun tipo
	string paten; //auxiliar para carga de datos
	int tipomul, dia, mes, pos; //tipo de multa, dia y mes de la misma, posicion de la patente
	string mensaje[6]; //guarda la descripcion de cada tipo de multa
	
	
	//inicializo arreglos contadores
	for(int i=0; i<6; i++)
		tipo_multa[i]=0;
	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			patente_mes[i][j]=0;
		}
	}
	
	mensaje[1]= "Exceso de velocidad";
	mensaje[2]= "Documentacion vencida";
	mensaje[3]= "Conducir sin licencia";
	mensaje[4]= "Conducir sin casco";
	mensaje[5]= "Conducir alcoholizado";
	
	/*Al inicio se ingresan los datos de las 4 motos registradas: patente (alfanumerico), nro de carnet de conducir del propietario, 
	cantidad de multas, cantidad de acarreos.*/
	cout<<"Datos de las motos registradas: "<<endl;
	for(int i=0; i<4; i++){
		cout<<"Patente: ";
		getline(cin,patente[i]);
		cout<<"Nto Carnet de conducir: ";
		getline(cin,nrocarnet);
		cout<<"Cantidad de multas: ";
		cin>>historico_multas[i][0];
		cout<<"Cantidad de acarreos: ";
		cin>>historico_multas[i][1];
		cin.get();
	}
	
	/*Luego se ingresan los datos de las multas efectuadas en los meses de mayo a agosto inclusive del corriente anio: patente (alfanumerico), 
	tipo de multa (1: exceso de velocidad, 2: documentacion vencida, 3: conducir sin licencia, 4: conducir sin casco, 5: conducir 
	alcoholizado), dia y mes de la multa (en variables numericas por separado). El fin de datos esta dado por Patente = 'x'. 
	Una misma moto pudo ser multada mas de una vez en el periodo y por diferentes motivos. Ademas, debe considerarse que, si la multa es 
	de tipo 3, 4 o 5, se retiene la moto, lo cual implica un acarreo.
	*/
	
	cout<<endl<<endl;
	cout<<"Datos de las multas efectuadas..."<<endl;
	cout<<"Ingrese PATENTE: ";
	getline(cin, paten);
	
	while(paten!="x"){
		cout<<"Tipo de multa (1 a 5): ";
		cin>>tipomul; 
		cout<<"Dia: ";
		cin>>dia;
		cout<<"Mes (1 a 12): ";
		cin>>mes; 
		pos= busca(paten, patente, 4);
		historico_multas[pos][0]++; //para item a)
		
		if(tipomul >= 3)
		{
			patente_mes[pos][mes-5]++;//para Ìtem b)
			historico_multas[pos][1]++;//para item a)
		}
			
			tipo_multa[tipomul]++;
			
			cin.get();
			cout<<"Ingrese PATENTE: ";
			getline(cin, paten);
	}
	
	//ORDENAR POR CANTIDAD DE MULTAS
	ordenar(historico_multas, patente, patente_mes, 4);
		
		cout<<endl;
		//1) Listado ordenado decreciente por cantidad de multas, con todos los valores actualizados, segun el siguiente formato:
		cout<<"PATENTE	    CANT. MULTAS		CANT. ACARREOS"<<endl;
		for(int i=0; i<4; i++)
			cout<<patente[i]<<"    "<<historico_multas[i][0]<<"   "<<historico_multas[i][1]<<endl;
			
			cout<<endl;
			//2) Listado por patente y por mes (puede incluir valores 0), solamente con los acarreos efectuados en el periodo evaluado:
			cout<<"PATENTE		MAYO	JUNIO	JULIO	AGOSTO"<<endl;
			for(int i=0; i<4; i++)
			{
				cout<<patente[i]<<"     ";
				for(int j=0; j<4; j++)
				{
					cout<<patente_mes[i][j]<<"   ";
				}
				cout<<endl;
			}
			cout<<endl;
			//3) Listado con totales segun tipo de multa en el periodo de tiempo considerado:
			int total=0; //para contar total de multas;
			for(int i=1; i<6; i++)
				total= total + tipo_multa[i];
			
			float porc; //para calcular los porcentajes y mostrar
			cout<<"TIPO			TOTAL MULTAS		%"<<endl;
			for(int i=1; i<6; i++)
			{
				porc= (tipo_multa[i]*100)/total;
				cout<<mensaje[i]<<"    "<<tipo_multa[i]<<"    "<<porc<<endl;
			}
			cout<<"             TOTALES "<< total<<"   100%"<<endl;
			
	return 0;
}

int busca( string dato, string pat[], int cant)
{
	int p;
	for (int i=0; i<cant; i++)
	{
		if(dato==pat[i])
		{
			p=i;
			i=cant;
		}			
	}
	return p;
}

void ordenar(int hm[][2], string p[], int pm[][4], int c)
{	
	string saux;
	int naux;
	for(int i=0; i<3; i++)
	for(int j=i+1; j<4; j++)
{
	if(hm[i][0] < hm[j][1])
	{
		saux= p[i];
		p[i]= p[j];
		p[j]=saux;
		
		for(int k=0; k<2; k++)
		{
			naux=hm[i][k];
			hm[i][k]= hm[j][k];
			hm[j][k]=naux;
		}
		//ordeno el arreglo del item b para no perder vinculacion con patente
		for(int k=0; k<4; k++)
		{
			naux=pm[i][k];
			pm[i][k]= pm[j][k];
			pm[j][k]=naux;
		}
	}
}
}
