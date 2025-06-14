#include <iostream>

void imprimir_arreglo(int (*arreglo)[4], int numero_de_filas, int numero_de_columnas) {
    for (int i = 0; i < numero_de_filas; i++) {
        for (int j = 0; j < numero_de_columnas; j++) {
            std::cout << arreglo[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int FILAS = 3;
    const int COLUMNAS = 4;

    int mi_arreglo[FILAS][COLUMNAS] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    int (*mi_puntero)[COLUMNAS] = mi_arreglo;

    // Llamar a la función para imprimir el arreglo utilizando el puntero
    imprimir_arreglo(mi_puntero, FILAS, COLUMNAS);

    return 0;
}
