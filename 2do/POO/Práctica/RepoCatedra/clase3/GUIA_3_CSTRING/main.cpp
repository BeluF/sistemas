#include <iostream>
#include <cstring>


using namespace std;

//1. Realice una función que dado un vector de cstring retorne el mismo cstring en mayúscula.
//ASCII 65 - 90
void may (char* v){
    for (int i = 0; v[i] != '\0'; i++){
        if (v[i] >= 'a' && v[i] <= 'z'){
            v[i] = v[i] - 32;
        }
    }
}

//2. Realice una función que dado un vector de cstring retorne el mismo cstring en minúscula.
void min (char* v){
    for (int i = 0; v[i] != '\0'; i++){
        if (v[i] >= 'A' && v[i] <= 'Z'){
            v[i] = v[i] + 32;
        }
    }
}

//3. Realice una función que dado un vector de ctring y un carácter agregue dicho carácter al
//final vector cstring.
void add(char* &v, char n){
    // Longitud
    int longt = 0;
    while (v[longt] != '\0') {
        longt++;
    }

    // Crear nuevo arreglo
    char* v2 = new char[longt + 2];

    // Copiar
    for (int i = 0; i < longt; i++) {
        v2[i] = v[i];
    }

    v2[longt] = n;
    v2[longt + 1] = '\0';

    delete[] v;
    v = v2;
}

//4. Realice una función que dado un vector de ctring y un carácter agregue dicho carácter al
//principio del vector cstring.
void add_start(char* &v, char n){
    // Longitud
    int longt = 0;
    while (v[longt] != '\0') {
        longt++;
    }

    // Crear nuevo arreglo
    char* v2 = new char[longt + 2];

    v2[0] = n;
    // Copiar
    for (int i = 0; i < longt; i++) {
        v2[i+1] = v[i];
    }

    v2[longt+1] = '\0';

    delete[] v;
    v = v2;
}

//5. Realice una función que dado un vector de ctring y un carácter elimine la primer ocurrencia.
void remove_first(char* &v, char c){
    // Longitud
    int longt = 0, pos = -1;
    while (v[longt] != '\0') {
        if(pos == -1 && v[longt] == c){
            pos = longt;
        }
        longt++;
    }
    // Si no se encontró el carácter, salir
    if (pos == -1) return;

    // Crear nuevo arreglo
    char* v2 = new char[longt];

    // Copiar hasta la pos a eliminar
    for (int i = 0; i < pos; i++) {
        v2[i] = v[i];
    }

    // Copiar lo restante
    for (int i = pos; i < longt; i++) {
        v2[i] = v[i+1];
    }


    delete[] v;
    v = v2;
}

//6. Realice una función que dado un vector de ctring y un carácter elimine todas las ocurrencias.
void remove_all(char* &v, char c){
    // Longitud
    int longt = 0;
    while (v[longt] != '\0') {
        longt++;
    }

    int cont = 0;

    //Recorro para saber cuantas ocurrencias hay
    for (int i = 0; i < longt; i++){
        if(v[i] == c){
            cont++;
        }
    }

    if (cont == 0) return;

    char* v2 = new char [longt-cont];

    // Copiar elementos que no coinciden
    int j = 0; // Índice para el nuevo arreglo
    for (int i = 0; i < longt; i++) {
        if (v[i] != c) {
            v2[j] = v[i];
            j++;
        }
    }

    // Actualizar vector original
    delete[] v;
    v = v2;
}

//7. Realice una función que dado un vector de ctring y un entero retorne la subcadena que esta
//formada por desde el entero pasado por parámetros hasta el fin de la cadena .

void subc(char* &v, int n){
    int longt = 0;
    while(v[longt] != '\0'){
        longt++;
    }

    if (n < 0 || n >= longt) return; // Posición inválida

    char* v2 = new char [longt-(n+1)];
    for (int i = n; i < longt; i++){
        v2[i-n] = v[i]; //La cadena nueva debe iniciar en 0 y la vieja en n
    }

    delete[] v;
    v = v2;
}

//8. Realice una función que dado un vector de ctring y dos enteros retorne la subcadena que esta
//formada por desde el primer entero pasado por parámetros hasta el segundo.
void subc2(char* &v, int n1, int n2){
    int longt = 0;
    while(v[longt] != '\0'){
        longt++;
    }

    if (n1 > n2 || n1 < 0 || n2 > longt) return; // Posición inválida

    char* v2 = new char [n2 - n1 + 2];

    for (int i = 0; i <= (n2-n1); i++){
        v2[i] = v[i+n1]; //La cadena nueva debe iniciar en 0 y la vieja en n1
    }

    v2[n2 - n1 + 1] = '\0'; // Asegurar terminación nula

    delete[] v;
    v = v2;
}

//9. Realice una función que dado un vector de ctring y un carácter retorne el indice donde se
//encotro la primera ocurrencia, de no ser encontrado se debe retornar -1
int find_first(char* v, char c){
    // Longitud
    int longt = 0, pos = -1;
    while (v[longt] != '\0') {
        if(pos == -1 && v[longt] == c){
            pos = longt;
        }
        longt++;
    }
    // Si no se encontró el carácter, salir
    if (pos == -1) return -1;
    else return 1;

    return 0;
}

//10. Realice una función que dado un vector de cstring devuelva un vector con las palabras que
//comiencen con una letra ingresada por parámetros.
void devolver(char** v, char c, int longt){

    bool find = false;
    int cont = 0;

    for (int i = 0; i < longt; i++){
        if(v[i][0] == c){
            find = true;
            cont++;
        }
    }

    if(find == false) return; //Ninguna palabra comienza con esa letra

    char* v2 = new char[cont];
    cont = 0;
    for (int i = 0; i < longt; i++){
        if(v[i][0] == c){
            v2[cont] == v[i];
            cont++;
        }
    }

    delete[] v;
    v = v2;
}



int main()
{
    char str [] = "hola mundo";
    may(str);
    min(str);
    char* str2 = new char[11];

    // Copiar
    const char* temp = "hola mundo";
    int i = 0;
    while (temp[i] != '\0') {
        str2[i] = temp[i];
        i++;
    }
    str2[i] = '\0';

    add(str2, '!');
    cout << str2 << endl;

    add_start(str2, '#');
    cout << str2 << endl;

    remove_first(str2, '#');
    cout << str2 << endl;

    remove_all(str2, 'o');
    cout << str2 << endl;

    subc(str2, 4);
    cout << str2 << endl;

    subc2(str2, 0, 1);
    cout << str2 << endl;

    int res = find_first(str2, 'm');
    try{
        if(res == 1) throw "Hallado";
        else if (res == -1) throw "Error: no encontrado";
        else throw "Error desconocido";
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    delete[] str2;

    const char* str3[] = {'Banana', 'Manzana', 'Pera', 'Naranja', 'Mandarina'};
    cout << devolver(str3, 'B', 5) << endl;
    delete[] str3;

    return 0;
}
