#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Ingrese el primer n�mero: ";
    cin >> num1;
    cout << "Ingrese el segundo n�mero: ";
    cin >> num2;

    if (num1 > num2) {
        cout << "El primer n�mero es mayor." << endl;
    } else if (num2 > num1) {
        cout << "El segundo n�mero es mayor." << endl;
    } else {
        cout << "Los n�meros son iguales." << endl;
    }

    return 0;
}
