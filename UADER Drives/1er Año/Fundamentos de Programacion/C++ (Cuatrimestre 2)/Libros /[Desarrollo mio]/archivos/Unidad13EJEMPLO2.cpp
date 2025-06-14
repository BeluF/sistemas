// Ejemplo 2.
// Este programa lee de un archivo una cadena de texto.
// El archivo debe existir previamente y llamarse prueba.txt
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]) {
ifstream archivo; //archivo, es el nombre de la varible logica
 //ifstream ABRE ARCHIVO PARA ENTRADA
archivo.open ("./prueba.txt"); //vinculacion con archivo físico
if ( archivo.fail() ){
cout << "Error en la apertura del archivo.";
}
else {
int linea2;
string linea;
archivo>>linea2; //LEE DESDE EL ARCHIVO
cout << "La cadena leida es:" << endl;
cout << linea;
}
archivo.close ();
return 0;
}

