#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

/*
	Version B capaz de reconocer caraceteres acentuados.
	Video explicando el ejercicio:
		https://youtu.be/oiomaVNxkdk
*/ 

int main()
{
	string palabras[100];	//lista de palabras
	int matriz[100][3], N;		//matriz Nx3 , N cantidad de palabras.
	
	cout << "Ingrese cantidad de palabras:\n";
	cin >> N;
	cin.ignore();
	
	for (int i = 0; i < N; i++) 
	{
		printf("Ingrese palabra %d de %d:\n",i+1, N);
		getline(cin, palabras[i]);
		
		// Armando matriz
		matriz[i][0] = palabras[i].size();	
		matriz[i][1] = 0;
		matriz[i][2] = 0;
		
		// Revisando las letras
		for (int j = 0; j < matriz[i][0]; j++)	
			// miramos si es una letra
			if (isalpha(palabras[i][j]))	
		{
				//Checkeamos si es una vocal
				char letra = tolower(palabras[i][j]);
				bool esvocal = (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
				
				if (esvocal)
					matriz[i][2]++; // Se suma 1 al contador de vocales
				else
					matriz[i][1]++; // Se suma 1 al contador de consonantes
		}	
			else 
				{
				char letra = tolower(palabras[i][j]);
				bool esvocal = (letra == 'á' || letra == 'é' || letra == 'í' || letra == 'ó' || letra == 'ú');
				if (esvocal)
					matriz[i][2]++; // Se suma 1 al contador de vocales
				}
	}
	
	// Informe
	cout << setw(15) << "Palabra" << setw(10) << "Largo" << setw(15) << "Consonantes" << setw(10) << "Vocales" << setw(20) << "Otros Caracteres\n";	
	int otro; // otros caracteres
	
	for (int i = 0; i < N; i++) {
		otro = matriz[i][0] - (matriz[i][1] + matriz[i][2]);
		cout << setw(15) << palabras[i] << setw(9) << matriz[i][0] << setw(12) << matriz[i][1] << setw(12) << matriz[i][2] << setw(15) << otro << endl;
	}
	
	return 0;	
}
