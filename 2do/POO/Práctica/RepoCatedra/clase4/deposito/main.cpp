/*
Crear un sistema que permita registrar productos en un depósito y mostrar su información. Cada producto tiene nombre, código y precio.
*/

#include <iostream>
#include <string>

using namespace std;

class Producto
{
private:
    string nombre;
    int codigo;
    float precio;

public:
    // Constructor
    Producto(string nom, int cod, float pre)
    {
        nombre = nom;
        codigo = cod;
        precio = pre;
    }

    // Métodos
    string getNombre()
    {
        return nombre;
    }
    int getCodigo()
    {
        return codigo;
    }
    float getPrecio()
    {
        return precio;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << ", Codigo: " << codigo << ", Precio: " << precio << endl;
    }
};

class Deposito
{
private:
    Producto **listaProductos;
    int cant;
    int capacidad;

public:
    // Constructor
    Deposito(int cap)
    {
        capacidad = cap;
        cant = 0;
        listaProductos = new Producto *[capacidad];
    }
    // Destructor
    ~Deposito()
    {
        for (int i = 0; i < capacidad; i++)
        {
            delete listaProductos[i];
        }
        delete[] listaProductos;
    }
    // Métodos
    void addProd(string nom, int cod, float pre)
    {
        if (cant < capacidad)
        {
            listaProductos[cant++] = new Producto(nom, cod, pre);
        }
        else
        {
            cout << "No hay espacio en el deposito" << endl;
        }
    }

    void removeProd(int cod)
    {
        for (int i = 0; i < cant; i++)
        {
            if (listaProductos[i]->getCodigo() == cod)
            {
                delete listaProductos[i];
                for (int j = i; j < cant - 1; j++)
                {
                    listaProductos[j] = listaProductos[j + 1];
                }
                cant--;
                return;
            }
        }
    }

    void mostrar()
    {
        for (int i = 0; i < cant; i++)
        {
            listaProductos[i]->mostrar();
        }
    }

    void buscarProd(int cod)
    {
        for (int i = 0; i < cant; i++)
        {
            if (listaProductos[i]->getCodigo() == cod)
            {
                listaProductos[i]->mostrar();
                return;
            }
        }
        cout << "No se encontro el producto" << endl;

    }
};
int main()
{
    Deposito d(10);
   
    d.addProd("Producto1", 1, 10.5);
    d.addProd("Producto2", 2, 20.5);
    d.addProd("Producto3", 3, 30.5);


    cout << "Lista de productos:" << endl;
    d.mostrar();
    d.removeProd(1);
    cout << "Lista de productos luego de eliminar el producto 1:" << endl;
    d.mostrar();
    cout << "Buscando producto con codigo 2:" << endl;
    d.buscarProd(2);
    cout << "Buscando producto con codigo 100:" << endl;
    d.buscarProd(100);

    return 0;
}