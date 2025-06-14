#include <iostream>
#include <string>

using namespace std;

// ejercicio 7 guia 5
int main(int argc, char const *argv[])
{
	const int N = 7;
    string vector[] = {"uno","dos","tres","cuatro","cinco","seis","siete"};

    // Vector normal sin el ordenamiento.
    cout << "Vector: \n";
    for (int i = 0; i < N; i++)
        cout << i << " | " << vector[i] << endl;

    /* La formula a seguir sera algo como: N - i = n, siendo i la posicion inicial del array,
     N la ultima posicion del mismo (o el total) y n = N-i */
    for (int i = 0; i < N; i++)
    {
        // aux nos ayudara a intercambiar los valores.
        int n; string aux;
        n = (N-1) - i;  //N-1 porque arranca en 7, pero como los vectores en C++ arrancan desde el 0, el 6 seria nuestra ultima posicion.
        if (n > i) // Cortara cuando i (posicion inferior) supere a la n (posicion superior)
        {
            aux = vector[i];
            // le damos el valor de la posicion enesima a la posicion i
            vector[i] = vector[n];
            // aux contiene el valor de la posicion que estamos mirando, se la damos a la n asi efectuamos un intercambio
            vector[n] = aux;
        }
    }

    // Vector ordenado segun la formula 
    cout << "Vector reordenado: \n";
    for (int i = 0; i < N; i++)
        cout << i << " | " << vector[i] << endl;

    return 0;
}
