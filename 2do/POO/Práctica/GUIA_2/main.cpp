#include <iostream>

using namespace std;

//1. Realice un método que retorne el acumulado de un vector de 10 enteros. Utilice recursividad.
int acum(int v[], int t){
    //Caso base
    if (t == 0){
        return 0;
    }
    return v[t-1] + acum(v, t-1);
}

//2. Realice un método que retorne el promedio de un vector de 10 enteros
double prom(int v[], int t){
    double p = 0.0;
    p = v[t-1] + acum(v, t-1);
    return p/t;
}

//3. Realice un método que retorne el mayor elemento de un vector de 10 enteros. Utilice recursividad.
int mayor(int v[], int t){
    //Caso base: solo hay 1 elem
    if (t == 1){
        return v[0];
    }
    int m = mayor (v+1, t-1);
    return (v[0] > m) ? v[0] : m;
}

//4. Realice un método que retorne el menor elemento de un vector de 10 enteros. Utilice recursividad.
int menor (int v[], int t){
    //Caso base: solo hay 1 elem
    if (t == 1){
        return v[0];
    }
    int m = menor (v+1, t-1);
    return (v[0] < m) ? v[0] : m;
}

//5. Realice un método que retorne el valor del triangulo de pascal en la posición determinada por
parámetros.


int main()
{
    int v [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Acumulador: " << acum (v, 10) << endl;
    cout << "Promedio:" << prom (v, 10) << endl;
    cout << "Mayor: " << mayor (v, 10) << endl;
    cout << "Menor: " << menor (v,10) << endl;
    return 0;
}
