#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Se desea obtener la cuota a pagar por un cr�dito solicitado. Se ingresa la
	informaci�n de: Capital solicitado, Raz�n (tasa anual), plazo (en meses).
	El c�lculo de inter�s simple se realiza con la f�rmula: (Capital x raz�n x tiempo) /
	(100 x 12).
	El monto que se obtenga (capital + inter�s) dividido el plazo da como resultado el
	valor de la cuota.*/
	float capitalsol,tasaan,interes,cuota;
	int plazo;
	cout<<"Ingrese el capital solicitado, luego la tasa anual y por �ltimo el plazo"<<endl;
	cin>>capitalsol>>tasaan>>plazo;
	interes=(capitalsol*tasaan*plazo)/(100*12);
	cuota=(capitalsol+interes)/plazo;
	cout<<"Las cuotas tendr�n un valor de: $"<<cuota;
	return 0;
}

