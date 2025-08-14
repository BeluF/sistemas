/*
Realice un software que dado un monto en dinero retorne un vector de los billetes y monedas que debe retornar.
El software debe dar prioridad a billetes con mayor denominación. Los billetes son de 1000, 500, 200, 100, 50, 20, 10
y monedas de 5, 2, 1. Por ejemplo dado el monto 545 el software debe retornar el vector con los billetes [ 500, 20, 20, 5] 
*/

#include <iostream>
#include "cambio.h"

using namespace std;

int main() {
    int monto;
    cout << "Ingrese el monto: ";
    cin >> monto;

    Cambio cambio(monto); 
    cambio.calcular();

    int* resultado = cambio.getRes();
    int cantidad = cambio.getCant();

    cout << "Billetes/monedas devueltos: ";
    for (int i = 0; i < cantidad; i++) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    return 0;
}
