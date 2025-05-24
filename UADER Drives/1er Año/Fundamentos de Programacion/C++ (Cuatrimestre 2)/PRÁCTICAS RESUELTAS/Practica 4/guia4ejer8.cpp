#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string cadena;
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cadena);

    int primerp = cadena.find(' ');
    if (primerp == -1) {
        cout << "La cadena solo tiene una palabra." << endl;
    } else {
        int segundap = cadena.find(' ', primerp + 1);
            string segundaPalabra = cadena.substr(primerp + 1, segundap - primerp - 1);
            cout << "La segunda palabra es: " << segundaPalabra << endl;
        }
    

    return 0;
}
