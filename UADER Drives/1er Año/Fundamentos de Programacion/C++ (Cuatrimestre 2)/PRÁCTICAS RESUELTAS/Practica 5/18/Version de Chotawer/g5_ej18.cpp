#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* 
	18. Ingrese una lista de N palabras y almacénelas en un arreglo. Luego genere una matriz de
	Nx3 donde se almacenará lo siguiente: en la columna 1 el largo de la palabra, en la columna 2
	la cantidad de consonantes, en la 3 la cantidad de vocales.
	Luego de finalizada la carga, realizar el siguiente informe:
	Palabra Largo Consonantes Vocales Otros Caracteres 
	xxxxxxx  999     999         999       999
	xxxxxxx  999     999         999       999
	xxxxxxx  999     999         999       999
	El valor N se ingresa como primer dato.     
	
	Video explicando el ejercicio:
		https://youtu.be/oiomaVNxkdk
*/

int main()
{	
    string palabras[999];
    int N, matriz[999][3] = {0};  //0 = Largo; 1 = Consonantes; 2 = Vocal

    cout << "Ingrese cantidad de palabras: ";
    cin >> N;
    cin.ignore();

    int i;
    
    for (i = 0; i < N; i++) {
        cout << "Ingrese las palabras | Cantidad restante: " << N-i << endl;
        getline(cin,palabras[i]);

        // vamos preparando la matriz
        matriz[i][0] = palabras[i].size();
    }

    for (i = 0; i < N; i++) 
        for (int j = 0; j < matriz[i][0]; j++)
            if ((palabras[i][j] > 64 && palabras[i][j] < 91) || (palabras[i][j] > 97 && palabras[i][j] < 122))
            {
				bool vocalMayuscula = (palabras[i][j] == 'A' || palabras[i][j] == 'E' || palabras[i][j] == 'I' || palabras[i][j] == 'O' || palabras[i][j] == 'U');
				bool vocalMinuscula = (palabras[i][j] == 'a' || palabras[i][j] == 'e' || palabras[i][j] == 'i' || palabras[i][j] == 'o' || palabras[i][j] == 'u');
				
            	if (vocalMayuscula || vocalMinuscula)
                    matriz[i][2]++;
                else 
                    matriz[i][1]++;
			}
                

    cout << "Palabra" << setw(10) << "Largo" << setw(20) << "Consonantes" << setw(10) << "Vocales" << setw(20) << "Otros Caracteres\n";
    int Otros;
    
    for (i = 0; i < N; i++) {
        Otros = matriz[i][0] - (matriz[i][1] + matriz[i][2]);
        cout << palabras[i] << setw(10) << matriz[i][0] << setw(20) << matriz[i][1] << setw(10) << matriz[i][2] << setw(20) << Otros << endl;
    }

    return 0;
}
