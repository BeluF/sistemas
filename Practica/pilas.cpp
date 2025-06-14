#include <iostream>

using namespace std;

//Definición del struct
struct nodo_pila
{
    int dato;
    struct nodo_pila* link; //Al agregar un nuevo nodo se "anexa" a nodo_pila
};
typedef nodo_pila Npila; //Para referir al tipo de dato nodo_pila* se usará el sinónimo Npila

//Push -- agregar
void agregar(Npila* &pila, int n){ //Se pasa por referencia el puntero al inicio de la pila porque será modificado
    Npila* aux = new(Npila); //Genero un nuevo nodo de forma dinámica (new)
    aux -> dato = n; //Agrego el nuevo valor al campo "dato" de mi nuevo nodo
    aux -> link = pila; //Hago que mi nuevo nodo apunte a donde está apuntando el "índice" o "acceso" de la pila, es decir, al primer elemento
    pila = aux; //Ahora mi primer elemento es el nuevo nodo ya que se agrega "arriba" (LIFO), por lo que el "indice" o "acceso" de la pila debe apuntar al nuevo nodo

}

//Get -- obtener
int obtener (Npila* &pila){ //Pasamos el indice como referencia ya que al acceder a un dato este debe eliminarse
    int aux = pila -> dato; //Obtengo el último elemento almacenado en la pila
    Npila* pila_aux = pila; //Necesito una variable auxiliar que almacene temporalmente el valor de pila para no perder el nodo a eliminar
    pila = pila -> link; //Apunto el "índice" al siguiente nodo (nodo nro 2, al que apunta el nodo a eliminar)
    delete pila_aux; //Elimino el nodo que voy a mostrar ya que el acceso es detructivo
    return aux;

}

//Preguntar si está vacía
bool isEmpty(Npila* pila){
    bool b = (pila == NULL) ? true : false;
    return b;
}

int main(void)
{
    Npila* pila = NULL;
    int n = 5;
    agregar(pila, n);
    cout<<obtener(pila)<<endl;
    cout<<isEmpty(pila);
}
