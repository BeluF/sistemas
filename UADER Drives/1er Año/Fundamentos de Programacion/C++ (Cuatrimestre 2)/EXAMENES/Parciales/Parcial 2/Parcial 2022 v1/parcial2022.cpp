#include <iostream>
#include <string>
#include <iomanip> 


using namespace std;

int main(int argc, char *argv[]) {
	const int N = 5; // Cantidad de motos
	string patente[N];
	int motos[N][3]; // 0: Nro carnet | 1: Cantidad de multas | 2: Cantidad de acarreos.
	int tipo[5] = {0}; // tipo de multas
	int total_acarreos[N][4] = {0};
	string patentex;
	int tip, dia, mes;
	
	// Ingreso de datos de las 1550 motos
	for (int i = 0; i < N; i++)
	{
		cout << "Ingrese patente del vehiculo: \n";
		cin >> patente[i];
		
		cout << "Ingrese nro de carnet, cantidad de multas y cantidad de acarreos por separado:\n";
		for (int j = 0; j < 3; j++)
			cin >> motos[i][j];
	}
	
	cout << "Ingrese numero de patente: \n";
	cin >> patentex;
	while (patentex != "x")
	{
		int i;
		for (i = 0; (i < N) && (patentex != patente[i]); i++)
			;
		
		if (i == N)
			cout << "Moto no registrada\n";
		else {
			cout << "TIPO DE MULTA (1: EXCESO DE VELOCIDAD, 2: DOCUMENTACIóN VENCIDA, 3: CONDUCIR SIN LICENCIA, 4: CONDUCIR SIN CASCO, 5: CONDUCIR ALCOHOLIZADO)\n";
			cin >> tip;
			tipo[tip-1]++; // Sumamos uno a el contador de tipo de multa
			motos[i][1]++; // Sumamos uno al contador de multas
			
			cout << "Dia y mes de la multa por separado:\n";
			cin >> dia >> mes;	// No se usa en ningun informe asi que no lo guardamos en ningún lado.
			
			if (tip > 2 && tip <6)
				total_acarreos[i][mes-5]++; // Actualizar cantidad de acarreos
		}	
		
		cout << "Ingrese numero de patente: \n";
		cin >> patentex;
	}
	
	/// Ordenamiento
	for (int i = 0; i < N-1; i++)
		for (int j = i+1; j < N; j++)
			if (motos[i][1] > motos[j][1])
			{
				for (int k = 0; k < 3; k++){
					int aux = motos[i][k];
					motos[i][k] = motos[j][k];
					motos[j][k] = aux;
				}
				
				string aux = patente[i];
				patente[i] = patente[j];
				patente[j] = aux;
				
				for (int k = 0; k < 4; k++) {
					int aux1 = total_acarreos[i][k];
					total_acarreos[i][k] = total_acarreos[j][k];
					total_acarreos[j][k] = aux1; 
				}
			}
			
	/// Informe 1
	cout << setw(10) << "PATENTE" << setw(20) << "CANT. MULTAS" << setw(20) << "CANT. ACARREOS\n";
	for (int i = 0; i < N; i++)
		cout << setw(10) << patente[i] << setw(20) << motos[i][1] << setw(19) << motos[i][2] << endl << endl;
	
	/// Informe 2
		cout << setw(10) << "PATENTE" << setw(10) << "MAYO" << setw(10) << "JUNIO" << setw(10) << "JULIO" << setw(11) << "AGOSTO\n";
		for (int i = 0; i < N; i++){
			cout << setw(10) << patente[i];
			for (int j = 0; j < 4; j++)
				cout << setw(10) << total_acarreos[i][j];
			cout << endl << endl;
		}
		
	/// Informe 3 
		string tipol[] = {"1: Exceso de velocidad", "2: Documentación vencidad", "3: Conducir sin licencia", "4. Conducir sin casco", "5. Conducir alcoholizado"};
		long int total = 0;
		for (int i = 0; i < 5; i++)
			total += tipo[i];
		
		cout << setw(15) << "TIPO" << setw(25) << "TOTAL MULTAS" << setw(15) << "%" << endl;
		for (int i = 0; i < 5; i++){
			float porcentaje = (tipo[i] * 100)/total;
			cout << setw(25) << tipol[i] << setw(10) << tipo[i] << setw(20) << porcentaje << endl;
		}
		
	return 0;
}

