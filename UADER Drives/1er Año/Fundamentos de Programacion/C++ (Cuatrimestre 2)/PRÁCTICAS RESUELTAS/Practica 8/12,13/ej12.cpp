#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
12. En un triatlón participaron N competidores y por cada uno de ellos se tienen: el número de
competidor y los 3 pares de datos con la siguiente información:
  - Código de Deporte (1= natación, 2=carrera, 3=bicicleta)
  - Tiempo que hizo en ese deporte (en minutos)
Los pares de datos no vienen ordenados por código de deporte.
La cantidad N de participantes se ingresa como primer dato.
Se desea generar 3 archivos: NATACION.TXT, CARRETA.TXT y BICICLETA.TXT. Los archivos
tienen la misma estructura: Cod de competidor (0..N-1), espacio en blanco y Tiempo (en minutos).
Nota: Todos los competidores completaron las 3 pruebas.
*/

int main(int argc, char **argv){	
	int n,c=0;  
	cout<<"Cantidad de atletas: ";cin>>n;
	float dp[n][4];
	for (int i=0; i<n; i++){
		for (int j=0; j<4; j++ ){
			dp[i][j]=0;
		}
	}
	
	while(c++<n){
		int m;
		do{
			cout<<"Numero de competidor: "; cin>>m;
		}while (!(m<n)||!(0<m));
		dp[m-1][0]= m;
		while (dp[m][1]==0 || dp[m][2]==0 || dp[m][3]==0){
			int j; float i;
			do{
				cout<<"Código de deporte: [1= natacion, 2=carrera, 3=bicicleta] "; cin>>j;
			}while (j>3||1>j);
			cout<<"Tiempo en el que hizo el deporte (en minutos)"; cin>>i;
			dp[m][j]= i;
		}
	}
	//carga de datos a los archivos de text
	ofstream file[3]; file[0].open("./NATACION.txt"); file[1].open("./CARRETA.txt"); file[2].open("./BICICLETA.txt");
	for (int i=0;i<3;i++){
		for (int j=0;j<n;j++)
			file[i]<<dp[j][0]<<" "<<dp[j][i+1]<<endl;
	}
	//cerrar archivos
	for (int i=0;i<3;i++){
		file[i].close();
	}
}

