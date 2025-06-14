#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

/*
3. Se desea, a partir de los archivos NATACION.TXT, CARRETA.TXT y BICICLETA.TXT, obtener
el código del participante ganador del triatlón (participante que realizó menor tiempo).
*/
const int n=3;

int main(int argc, char **argv){
	float mintiempo=0; int ganador, atleta;
	//apertura de archivos
	ifstream dp[n]; dp[0].open("./NATACION.txt"); dp[1].open("./CARRETA.txt"); dp[2].open("./BICICLETA.txt");
	if (!dp[0].fail()&&!dp[1].fail()&&!dp[2].fail()){
		while (!dp[0].eof()){
			float tiempotot=0; string linea; 
			for (int i=0; i<n; i++){
				getline(dp[i],linea);
				if (linea=="") break;
				int pos= linea.find(" ");
				atleta= stoi(linea.substr(0,pos));
				float tiempo= stof(linea.substr(pos+1));
				tiempotot=tiempotot+tiempo;
			}
			if (linea=="") break;
			if (tiempotot<mintiempo|| mintiempo==0){
				mintiempo=tiempotot;
				ganador=atleta;
			}
		}
		
	cout<<"Ganador: "<<ganador;
	}
	else cout<<"Error al abrir los archivos requeridos para que el programa funcione";
	
	//cerrar archivos
	for (int i=0;i<n;i++){
		dp[i].close();
	}
	return 0;
}
