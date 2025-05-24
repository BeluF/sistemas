#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
ofstream archivo; //archivo, es el nombre de la varible logica
 //ofstream ABRE ARCHIVO PARA SALIDA
archivo.open ("./prueba.txt"); //vinculacion con archivo físico
if ( archivo.fail() ){
cout << "Error en la apertura del archivo.";
}
else {
string cadena;
getline(cin,cadena);
archivo << cadena; //envía al archivo la cadena
}
archivo.close ();
return 0;
}
