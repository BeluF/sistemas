#include <iostream>

using namespace std;

//Definir el struct
struct nodo_cola{
    int dato;
    struct nodo_cola* link;
};

typedef nodo_cola NCola;

//Preguntar si está vacía
bool isEmpty (NCola* frente){ //Al tener doble acceso con que cualquiera de los dos (frente o fondo) esté vacío significa que la cola también lo está
    bool b = (frente == NULL) ? true : false;
    return b;
}

//Push -- agregar
void agregar(NCola* &fondo, NCola* &frente, int n){ //Necesito el fondo porque desde allí se agrega, pero también necesito el frente por si la cola esta vacía
    NCola* aux = new (NCola); //Creo un nuevo nodo
    aux -> dato = n; //Agrego el valor al nuevo nodo
    aux -> link = NULL; //Al ser el último elemento apuntará a NULL
    if (fondo != NULL) fondo -> link = aux; // Si fondo != NULL significa que apunta a algo (la cola no está vacía), por lo que el nodo al que apunta fondo debe apuntar al nuevo nodo
    fondo = aux; //Luego, el fondo debe apuntar al nuevo nodo
    if (frente == NULL) frente = aux; //Si el frente es NULL la cola está vacía, por lo que debo apuntar frente al nuevo nodo
}

//Get -- obtener
int obtener(NCola* &frente){ //Para sacar solo se necesita el frente
    bool b = isEmpty(frente); //Evalúo que la cola esté vacía
    if (b) return -1; //Si lo está retorno -1 (para manejo de errores)
    int aux = frente -> dato; //Obtengo el dato a mostrar
    NCola* cola_aux = frente; //Creo un puntero auxiliar que apunte al mismo lugar que frente, es decir, al 1er nodo.
    frente = frente -> link; //Hago que frente apunte al siguiente nodo
    delete cola_aux; //Al ser de acceso destructivo debo eliminar el nodo que obtengo
    return aux;
}


int main(void)
{
    NCola *cola_frente = NULL, *cola_fondo = NULL;
}
