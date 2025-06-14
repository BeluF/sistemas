#include <iostream>
using namespace std;

int main(void) {
	float montoxhora;
	int horastrabajadas;
	
	cout << "Ingrese monto";
	cin >> montoxhora;
	
	cout << "Ingrese horas trabajadas: ";
	cin >> horastrabajadas;
	
	if (horastrabajadas <= 40) 
	{
		float salario = horastrabajadas * montoxhora;
		cout << "El salario del trabajador es de " << salario;
	}
	else if (horastrabajadas > 40) 
	{
		int aux = horastrabajadas - 40;
		float salario = 40 * montoxhora;
		float extra = aux * (montoxhora * 1.5);
		
		cout << "El salario del trabajador es de " << salario + extra;
	}
	
	return 0;
}

