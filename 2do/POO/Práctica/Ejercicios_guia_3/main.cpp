#include <iostream>
#include <cstring>

using namespace std;

//EJERCICIO 10: Realice una funcion que dado un vector de cstring devuelva un vector con las palabras
//que comiencen con una letra ingresada por parametros.

//Buscar cantidad de ocurrencias
int count (char* frase, char find){
    int tam = strlen(frase);
    int cant = 0;
    for (int i = 0; i < tam - 2; i++){
        if (frase[i] == find){
            cant++;
        }
    }

    return cant;
}

char** cut(char* frase, char c = ' '){ //Doble asterisco para devolver una matriz (c/palabra es un array)
    int tam = strlen(frase); //tamaño
    int count = count(frase, c);
    char ** aux = new char* [count + 1];
    int indice = 0;

    for (int i = 0; i < tam; i++){
        if (frase[i] == find){
            cant++;
        }
        while (frase[i] != )
    }
}


int main(int argc, char *argv[])
{


    return 0;
}
