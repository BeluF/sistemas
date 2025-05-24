#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Se desea obtener la cuota a pagar por un crédito solicitado. Se ingresa la
	información de: Capital solicitado, Razón (tasa anual), plazo (en meses).
	El cálculo de interés simple se realiza con la fórmula: (Capital x razón x tiempo) /
	(100 x 12).
	El monto que se obtenga (capital + interés) dividido el plazo da como resultado el
	valor de la cuota.*/
	float capitalsol,tasaan,interes,cuota;
	int plazo;
	cout<<"Ingrese el capital solicitado, luego la tasa anual y por último el plazo"<<endl;
	cin>>capitalsol>>tasaan>>plazo;
	interes=(capitalsol*tasaan*plazo)/(100*12);
	cuota=(capitalsol+interes)/plazo;
	cout<<"Las cuotas tendrán un valor de: $"<<cuota;
	return 0;
}

