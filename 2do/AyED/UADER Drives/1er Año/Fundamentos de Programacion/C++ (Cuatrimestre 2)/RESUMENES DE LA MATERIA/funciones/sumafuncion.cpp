#include <iostream>
using namespace std;

float multiplicacion(int n, int mult = 2)
{		
	return n * mult;
}

int main(int argc, char *argv[]) {
	int numero1 = 5;
	
	float numero2 = multiplicacion(numero1,3);
	
	cout << "Multiplicacion del numero1: " << numero2;
	return 0;
}



