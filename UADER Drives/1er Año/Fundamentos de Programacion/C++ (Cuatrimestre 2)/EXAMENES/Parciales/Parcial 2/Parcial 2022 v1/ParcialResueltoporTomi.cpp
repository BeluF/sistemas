#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	const int N = 1550;
	string patentex[N], patente; 
	int dato[N][3]; // 0: Nro carnet | 1: Cant. multas | 2: Cant. acarreos
	int tipo_, tipo[5] = {0}, dia, mes;
	int acarreos[N][4] = {0}; // 0: Mayo, 1: Julio .....
	
	/// Primer carga de datos
	
	for (int i = 0; i < N; i++){
		cout << "Ingrese patente: ";
		cin >> patentex[i];
		cout << "Ingrese nro de conducir, cantidad de multas, y cantidad de acarreos: ";
		cin >> dato[i][0] >> dato[i][1] >> dato[i][2];
	}
	
	/// Segunda carga de datos
	cout << "Ingrese patente: ";
	cin >> patente;
	while (patente != "x"){
		int pos, i = 0, band = 0;
		while (i < N) {
			if (patente == patentex[i])
			{
				pos = i;
			    i = N;
				band = 1;
			}
			i++;
		}
		if (band == 0) 
			cout << "Patente no encontrada\n";
		else {
			cout << "Ingrese TIPO DE MULTA (1: EXCESO DE VELOCIDAD, 2: DOCUMENTACIoN VENCIDA, 3:CONDUCIR SIN LICENCIA, 4: CONDUCIR SIN CASCO, 5: CONDUCIR ALCOHOLIZADO)\n";
			cin >> tipo_;
			tipo[tipo_ - 1]++;
			
			cout << "Ingrese dia y mes por separado\n";
			cin >> dia >> mes;
			
			dato[pos][1]++;	// Sumamos una multa a esa moto
			if (tipo_ > 2)	// Acarreo
			{
				dato[pos][2]++; 	// Sumamos un acarreo a esa moto
				acarreos[pos][mes-5]++;	 // Sumamos un acarreo al mes correspondiente con la patente
			}
		}
		
		cout << "Ingrese patente: ";
		cin >> patente;
	}
	
	/// Ordenamiento
	
	for (int i = 0; i < N-1; i++)
		for (int j = i + 1; j < N; j++)
			if (dato[i][1] < dato[j][1])
			{
				string aux = patentex[i];
				patentex[i] = patentex[j];
				patentex[j] = aux;
				
				for (int k = 0; k < 3; k++)
				{
					int aux = dato[i][k];
					dato[i][k] = dato[j][k];
					dato[j][k] = aux;
				}
				
				for (int k = 0; k < 4; k++)
				{
					int aux = acarreos[i][k];
					acarreos[i][k] = acarreos[j][k];
					acarreos[j][k] = aux;
				}
			}
	
	/// Informe 1:
		cout << "PATENTE           CANT. MULTAS           CANT. ACARREOS\n";
		for (int i = 0; i < N; i++)
			cout << patentex[i] << "         " << dato[i][1] << "         " << dato[i][2] << endl;
			
	/// Informe 2:
		cout << "PATENTE    MAYO    JUNIO    JULIO      AGOSTO\n";
		for (int i = 0; i < N; i++)
			cout << patentex[i] <<setw(10)<< acarreos[i][0] <<setw(10)<< acarreos[i][1] <<setw(10)<< acarreos[i][2] <<setw(10)<< acarreos[i][3] << endl;
			
	/// Informe 3:
		long int total = 0;
		string desc[] = {"1: EXCESO DE VELOCIDAD", "2: DOCUMENTACIoN VENCIDA", "3: CONDUCIR SIN LICENCIA", "4: CONDUCIR SIN CASCO", "5: CONDUCIR ALCOHOLIZADO"};
		for (int i = 0; i < 5; i++)
			total += tipo[i];
		
		cout << "TIPO    TOTAL MULTAS      %" << endl;
		for (int i = 0; i < 5; i++)
		{
			float porcentaje = (tipo[i] * 100) / total;
			cout << desc[i] << setw(10) << tipo[i] << setw(10) << porcentaje << endl;
		}
		cout << "TOTALES  " << total << "    100%";
	return 0;
}

