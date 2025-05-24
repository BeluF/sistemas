#include <iostream>

using namespace std;

bool funcionLoca(int vector[][2])
{
	cout << "Numeros que le llegaron a la función: \n";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++)
			cout << vector[i][j] << "\t";
		cout << endl;
	}
		
	return true;
}

int main()
{
	int arreglo[3][2] = {1,2,3,4,5,6};
	bool tomiestaloco = funcionLoca(arreglo);
	
	return 0;
}
