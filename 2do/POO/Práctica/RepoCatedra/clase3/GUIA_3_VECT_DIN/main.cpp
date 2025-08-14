#include <iostream>

using namespace std;

//1. Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor pasado
//por parámetro en la ultima posición

void add(int* &v, int &t, int n){
    int* v2 = new int [t+1];
    for (int i = 0; i < t; i++){
        v2[i] = v[i];
    }
    v2[t] = n;
    delete[] v;
    v = v2;
    t++;
}

//2. Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor pasado
//por parámetro en la primera posición.
void add_start(int* &v, int &t, int n){
    int* v2 = new int [t+1];
    v2[0] = n;
    for (int i = 0; i < t; i++){
        v2[i+1] = v[i];
    }
    delete[] v;
    v = v2;
    t++;
}

//3. Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor pasado
//por parámetro en una posición pasada por parámetros.
void add_pos(int* &v, int &t, int n, int pos){
    int* v2 = new int [t+1];
    //Copio los elementos hasta la posición dada
    for (int i = 0; i < pos; i++) {
        v2[i] = v[i];
    }

    // Agrego el nuevo elemento
    v2[pos] = n;

    // Copio el resto de elementos desplazándolos
    for (int i = pos; i < t; i++) {
        v2[i+1] = v[i];
    }
    delete[] v;
    v = v2;
    t++;
}

//4. Realice una función que dado un vector dinámico de enteros, remueva el elemento que se
//encuentra en una posición pasada por parámetro. Si la posición es mayor a la cantidad de
//elementos, la función no debe remover ningún elemento.
int remove_pos(int* &v, int &t, int pos){
    if (pos > t) return 0; //0: la posición dada excede el tamaño
    int* v2 = new int [t-1];
    //Copio los elementos hasta la posición dada
    for (int i = 0; i < pos; i++) {
        v2[i] = v[i];
    }

    // Copio el resto de elementos desplazándolos
    for (int i = pos; i < t; i++) {
        v2[i-1] = v[i];
    }
    delete[] v;
    v = v2;
    t--;
    return 1; //1: Se eliminó correctamente
}

//5. Realice una función que dado un vector dinámico de enteros, remueva la primera
//coincidencia de un elemento pasado por parámetro
int remove_first (int* &v, int &t, int n)
{
    int pos = -1;

    //Recorro para saber la posición del elemento a eliminar
    while (pos < t && v[pos] != n) {
        pos++;
    }

    //Si la posición se mantiene en -1 el elemento no está en el vector
    if (pos == -1) return 0; //0: el elemento no está en el vector

    int* v2 = new int [t-1];

    //Copio los elementos hasta la posición a eliminar
    for (int i = 0; i < pos; i++){
        v2[i] = v[i];
    }

    //Copio el resto de elementos desplzándolos
    for (int i = pos+1; i< t; i++){
        v2[i-1] = v[i];
    }

    delete[] v;
    v = v2;
    t--;
    return 1; //1: se eliminó correctamente
}

//6. Realice una función que dado un vector dinámico de enteros, remueva un elemento pasado por parámetro.
int remove_all(int* &v, int &t, int n){
    int cont = 0;

    //Recorro para saber cuantas ocurrencias hay
    for (int i = 0; i < t; i++){
        if(v[i] == n){
            cont++;
        }
    }

    if (cont == 0) return 0; //0: el elemento no está en el vector

    int* v2 = new int [t-cont];

    // Copiar elementos que no coinciden
    int j = 0; // Índice para el nuevo arreglo
    for (int i = 0; i < t; i++) {
        if (v[i] != n) {
            v2[j] = v[i];
            j++;
        }
    }

    // Actualizar vector original
    delete[] v;
    v = v2;
    t = t - cont;
    return 1; //1: se eliminó correctamente
}

//7. Realice una función que dado un vector dinámico de enteros, remueva una cantidad de
//elementos pasados por parámetros. Dicha función debe comenzar a eliminar elementos desde el final
int remove_c(int* &v, int &t, int c){

    if (c > t) return 0; //0: la cantidad excede el tamaño
    if (c <+ 0) return 2; //2: cantidad negativa o 0
    if (c == t){
        delete[] v;
        v = nullptr;
        t = 0;
        return 3; //3: vacío el array
    }

    int* v2 = new int [t-c];

    for (int i = 0; i < c; i++) {
        v2[i] = v[i];
    }

    // Actualizar vector original
    delete[] v;
    v = v2;
    t = t - c;
    return 1; //1: se eliminó correctamente

}

//8. Realice una función que dado un vector dinámico de enteros, retorne un vector con el doble
//de elementos y los nuevos elementos deben ser una copia de los anteriores
void add_double(int *&v, int &t){
    int* v2 = new int [t*2];
    for (int i = 0; i < t; i++){
        v2[i] = v[i];
    }
    for (int i = 0; i < t; i++){
        v2[i+t] = v[i];
    }

    // Actualizar vector original
    delete[] v;
    v = v2;
    t = t*2;
}

//9. Realice una función que dado un vector dinámico de enteros, retorne una matriz que
//contenga en una fila el número y el número de repeticiones de dicho número.
int** matriz(int* v, int t, int& filas) {

    // Matriz temporal para almacenar resultados
    int** m2 = new int*[t];
    for (int i = 0; i < t; i++) {
        m2[i] = new int[2];
    }

    filas = 0;

    // Contar ocurrencias cada elemento del vector
    for (int i = 0; i < t; i++) {
        int num = v[i];
        bool find = false;

        // Buscar si el número ya está en m2
        for (int j = 0; j < filas; j++) {
            if (m2[j][0] == num) {
                m2[j][1]++; // Incrementar el valor de la columna repeticiones
                find = true;
                break;
            }
        }

        // Si no se encontró, agregar el nuevo número
        if (!find) {
            m2[filas][0] = num;
            m2[filas][1] = 1; //Primer ocurrencia
            filas++; //Paso a la sgte fila
        }
    }

    // Matriz de resultados
    int** res = new int*[filas];

    for (int i = 0; i < filas; i++) {
        res[i] = new int[2];
        res[i][0] = m2[i][0];
        res[i][1] = m2[i][1];
    }

    // LIberar memoria
    for (int i = 0; i < t; i++) {
        delete[] m2[i];
    }
    delete[] m2;

    return res;
}

// Función para imprimir matriz
void imprimirMatriz(int** matriz, int filas) {
    cout << "Número\tRepeticiones" << endl;
    for (int i = 0; i < filas; i++) {
        cout << matriz[i][0] << "\t" << matriz[i][1] << endl;
    }
}

// Función para liberar memoria
void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}



int main()
{
    int t = 5;
    int* v = new int[t];

    for (int i = 0; i < t; i++){
        v[i] = i;
    }

    add(v, t, 5); //t=6
    add_start(v, t, 10); //t=7
    add_pos(v, t, 15, 2); //t=8

    // for (int i = 0; i < t; i++){
    //     cout << v[i] << endl;
    // }
    // cout << endl;

    int res = remove_pos(v, t, 2); //t=7

    try{
        if (res == 1){
            throw "Se removió el elemento de la posición 2 correctamente";
        }
        else if(res == 0){
            throw "Error: posición fuera de rango";
        }
        else
        {
            throw "Error desconocido al insertar";
        }
    }

    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    // for (int i = 0; i < t; i++){
    //     cout << v[i] << endl;
    // }
    // cout << endl;

    res = remove_first(v, t, 15); //t=6
    try{
        if (res == 1){
            throw "Se removió el elemento 15 correctamente";
        }
        else if(res == 0){
            throw "Error: el elemento no se encuentra";
        }
        else
        {
            throw "Error desconocido al insertar";
        }
    }

    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    for (int i = 0; i < t; i++){
       cout << v[i] << endl;
    }
    cout << endl;

    res = remove_all(v, t, 1); //t=5
    try{
        if (res == 1){
            throw "Se removió el elemento 1 correctamente";
        }
        else if(res == 0){
            throw "Error: el elemento no se encuentra";
        }
        else
        {
            throw "Error desconocido al insertar";
        }
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    cout << endl;
    for (int i = 0; i < t; i++){
        cout << v[i] << endl;
    }

    res = remove_c(v, t, 3); //t=5
    try{
        if (res == 0){
            throw "Error: la cantidad ingresada excede el tamaño del array";
        }
        else if(res == 2){
            throw "Error: la cantidad ingresada debe ser mayor o igual a 1";
        }
        else if(res == 3){
            throw "Se vació el array";
        }
        else if(res == 1){
            throw "Se eliminaron 3 elementos del array";
        }
        else
        {
            throw "Error desconocido al insertar";
        }
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    add_double(v, t);
    cout << endl;
    for (int i = 0; i < t; i++){
        cout << v[i] << endl;
    }

    delete[] v;

    int t2 = 10;
    int* v2 = new int[tamaño]{2, 5, 2, 8, 5, 5, 2, 8, 2, 9};

    int filas;
    int** res = matriz(v2, t2, filas);

    imprimirMatriz(res, filas);

    liberarMatriz(res, filas);

    return 0;
}
