#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
3. Se desea, a partir de los archivos NATACION.TXT, CARRETA.TXT y BICICLETA.TXT, obtener
el código del participante ganador del triatlón (participante que realizó menor tiempo).
*/
const int n=3;

int main(int argc, char **argv){
	int mintiempo[n]={0,0,0}, ganador[n];
	//apertura de archivos
	ifstream dp[n]; dp[0].open("./NATACION.txt"); dp[1].open("./CARRETA.txt"); dp[2].open("./BICICLETA.txt");
	for (int i=0; i<n; i++){
		string linea;
		while (!dp[i].eof()){
			int atleta; float tiempo;
			dp[i]>>atleta;
			dp[i]>>tiempo;
			if (tiempo<mintiempo[i] || mintiempo[i]==0){
				mintiempo[i]=tiempo;
				ganador[i]=atleta;
			}
		}
	}
	string texto[]={"NATACION: ","CARRETA: ","BICICLETA: "};
	for (int i=0;i<n;i++){
		cout<<texto[i]<<"Competidor "<<ganador[i]<<" con "<<mintiempo[i]<<" segundos"<<endl;
	}
	
	//cerrar archivos
	for (int i=0;i<n;i++){
		dp[i].close();
	}
	return 0;
}
