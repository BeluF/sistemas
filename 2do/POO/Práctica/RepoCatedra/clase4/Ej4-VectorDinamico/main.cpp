#include <iostream>
#include "vectordinamico.h"

using namespace std;

int main() {
    VectorDinamico v;

    v.add(10);
    v.add(25);
    v.add(5);
    v.add(20);
    v.add(10);

    cout << "Vector: ";
    v.show();

    cout << "Cantidad: " << v.getCant() << endl;

    cout << "Promedio: " << v.prom() << endl;
    cout << "Mayor: " << v.may() << endl;
    cout << "Menor: " << v.min() << endl;

    v.remove(10);
    cout << "Después de remover 10: ";
    v.show();

    return 0;
}
