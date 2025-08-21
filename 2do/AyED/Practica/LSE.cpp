#include <iostream>

using namespace std;

//Defino el struct
struct nodo_lista_se{
    int dato;
    struct nodo_lista_se* link;
};

typedef nodo_lista_se NListaSE;

bool isEmpty(NListaSE* LSE){
    return (LSE == NULL) ? true : false;
}


//Imprimir todos los elementos de la lista
void imprimir(NListaSE* LSE){ //Paso por parámetro el puntero al primer elemento de la lista
    NListaSE* LSE_aux = LSE; //Creo un puntero auxiliar para poder avanzar entre los nodos
    while (LSE_aux != NULL){ //Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        cout << (LSE_aux -> dato) << endl; //Imprimo el dato del nodo
        LSE_aux = LSE_aux -> link; //Me muevo al siguiente nodo
    }
}

//Agregar elemento al principio
void agregar_inicio(NListaSE* &LSE, int n){
    NListaSE* aux = new (NListaSE); //Creo el nuevo nodo
    aux -> dato = n; //Almaceno el dato
    aux -> link = LSE; //Hago que mi nuevo nodo apunte al primer nodo, es decir, a donde apunta LSE (puntero inicial)
    LSE = aux; //Hago que mi puntero inicial, LSE, apunte al nuevo nodo
}

//Agregar elemento al final
void agregar_final(NListaSE* &LSE, int n){
    NListaSE* aux = new (NListaSE); //Creo el nuevo nodo
    aux -> dato = n; //Almaceno el nuevo valor
    aux -> link = NULL; //Como lo agrego al final el nuevo nodo debe apuntar a NULL
    NListaSE* LSE_aux = LSE; //Puntero auxiliar para poder recorrer la lista
    //Evaluar si esta vacía
    isEmpty(LSE_aux);
    //Recorrer la lista hasta el último elemento
    while((LSE_aux -> link) != NULL){
        LSE_aux = LSE_aux -> link; //Avanzo hasta el último elemento
    }
    LSE_aux -> link = aux; //Hago que el último nodo de la lista apunte al nuevo nodo
}

//Agregar elemento al final forma 2: Utilizar dos punteros (actual y anterior)
void agregar_final_2 (NListaSE *&LSE, int n){
    NListaSE* aux = new(NListaSE); //Creo el nuevo nodo
    aux -> dato = n; //Almaceno el nuevo valor
    aux -> link = NULL; //Como lo agrego al final el nuevo nodo debe apuntar a NULL
    NListaSE* actual = LSE;
    NListaSE* anterior = NULL;
    //Evaluar si está vacía
    if (!isEmpty(LSE)){ //Si no está vacía
        //Recorrer la lista hasta el último elemento
        while ((actual != NULL)){
            anterior = actual; //Muevo anterior en una posición
            actual = actual -> link; //Muevo actual a la siguiente posición
        }
        anterior -> link = aux; //Hago que el último nodo de la lista apunte al nuevo nodo
    }
    else LSE = aux; //Si la lista está vacía LSE debe apuntar al nuevo nodo

}

//Eliminar primer coincidencia de un elemento de la lista (Rehacer haciendo el cambio del while)
void borrar(NListaSE* &LSE, int n){
    NListaSE* actual = LSE;
    NListaSE* anterior = NULL; //Puntero anterior atrasado en una posición con actual

    //Recorro la lista buscando el elemento
    while((actual != NULL) && ((actual -> dato) != n)){ //Mientras que actual sea != NULL aún recorro elementos de la lista, mientras que actual != n aún no encuentro el elemento
        anterior = actual; //Muevo anterior en una posición
        actual = actual -> link; //Muevo actual a la siguiente posición
    }
    //Al salir del while hay dos opciones:

    //1. El elemento buscado es el primer elemento
    if ((anterior == NULL) && (actual != NULL)){ //En este caso anterior no avanzó porque el elemento buscado es el primero y si actual != NULL es que seguimos dentro de la lista
        LSE = actual -> link; //Hago que mi puntero índice apunte al segundo nodo
        delete (actual); //Elimino el primer nodo, donde se halla el elemento buscado
    }

    //2. El elemento buscado no es el primer elemento
    else if((anterior != NULL) && (actual != NULL)){ //En este caso anterior deja de ser NULL, por lo que el elemento no está en la primera posición y si actual != NULL es que seguimos dentro de la lista
        anterior -> link = actual -> link; //Necesito que el nodo anterior al que voy a eliminar se conecte al nodo siguiente al que voy a eliminar
        delete (actual); //Elimino el nodo de interés
    }
}

//Agregar elementos a una lista vacía e ir ordenándolos de menor a mayor
void ordenar (NListaSE* &LSE){
    NListaSE* aux = new(NListaSE); //NUevo nodo


}

int main() {
    NListaSE* lista = NULL;
    agregar_final_2(lista, 10);  // Lista: [10]
    agregar_final_2(lista, 20);  // Lista: [10] -> [20]
    imprimir(lista);
    return 0;
}
