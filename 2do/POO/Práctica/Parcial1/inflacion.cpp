/*
3. (15) Argumente qué ventajas y desventajas tiene la herencia y la composición. ¿Cuál usaría en el ejercicio anterior?

Ambas son técnicas de reutilización de código.
- Herencia:
    - Ventajas: permite utilizar jerarquía de clases y polimorfismo (la herencia en C++ se implementa con polimorfismo).
    - Desventajas: se genera un acoplamiento fijo y peor que en composición, esto produce "necesidad".
                    Ej.: si la función A necesita de la función B para funcionar, A está acoplada a B.
- Composición:
    - Ventajas: a partir de una clase contenedora se puede crear clases contenidas, donde la contenedora puede utilizar los métodos de la contenida. Pero para que sea
                al revés la contenedora debe pasarse por referencia o ser declarada como friend.
    - Desventajas: Produce acoplamiento fuerte. Se genera una dependencia de existencia ya que las clases contenidas se crean y destruyen junto con la contenedora.

4. (15) Indique cuales es el resultado ejecutando la función b para los parámetros 4, 7 y 5:
4: 0; 7: 1; 5: 1.
La función determina paridad (b) o imparidad (a)

int b(int n);

int a(int n){
    if (n == 0)
        return 1;
    return b(n - 1);}

int b(int n){
    if (n == 0)
        return 0;
    return a(n - 1);}

Describa qué hace la función

Software que permita actualizar sus precios con la inflación
Una empresa de productos lo contrata para realizar un software que le permita actualizar sus precios con la inflación. Existen 3 tipos de productos:
● Nacionales, los cuales aumentan un % ingresado por parámetros.
● Extranjeros, los cuales cotizan en dólares, por lo tanto se debe ingresar la cotización anterior del dólar y la actual.
                Y con estas cotizaciones se calcula el precio. precio actual = (precio anterior / cotización anterior) * cotización actual
● Ofertas, son un conjunto de productos los cuales están formados por productos y su precio es la suma del precio de los productos que lo componen menos un 10%.
            Las Ofertas no pueden contener productos de tipo oferta. Este producto debe permitir agregar productos que lo componen, como eliminarlos.
La empresa no cuenta con más de 100 productos.

1.(50) Realice el diseño e implementación que permita cargar los productos y actualizar sus precios.

2. (20) Realice una función que muestre todos los productos. Para ello sobreescriba el operador << . Y muestre el aumento total de los productos.

*/
#include <iostream>
using namespace std;

class Producto
{
protected:
    int ID;
    double precio, precioAnterior;
    static int proximoId;

public:
    Producto(int precio)
    {
        this->ID = proximoId++;
        this->precio = precio;
        this->precioAnterior = precio;
    }

    ~Producto() {}

    virtual void actualizarPrecio() = 0;

    int getID() const  { return ID; }
    double getPrecioAnterior() const  { return precioAnterior; }
    double getPrecio() const { return precio; }
};
int Producto::proximoId = 1;

ostream &operator<<(ostream &os, const Producto &p)
{
    os << "ID: " << p.getID();
    os << "Aumento: " << (p.getPrecio() - p.getPrecioAnterior());
    return os;
}

/*aumentan un % ingresado por parámetros.*/
class Nacional : public Producto
{
private:
    double aumento;

public:
    Nacional(double precio, double aumento) : Producto(precio), aumento(aumento) {}
    ~Nacional() {}

    void actualizarPrecio()
    {
        precioAnterior = precio;
        precio += (precio * aumento) / 100;
    }
};

/* cotizan en dólares, por lo tanto se debe ingresar la cotización anterior del dólar y la actual.
                Y con estas cotizaciones se calcula el precio. precio actual = (precio anterior / cotización anterior) * cotización actual*/
class Extranjero : public Producto
{
private:
    double cotizacionAnterior, cotizacionActual;

public:
    Extranjero(double precio, double cotizacionAnterior, double cotizacionActual) : Producto(precio) {
        this->cotizacionAnterior = cotizacionAnterior;
    this->cotizacionActual = cotizacionActual;
    }
    ~Extranjero() {}

    void actualizarPrecio()
    {
        precioAnterior = precio;
        precio = (precioAnterior / cotizacionAnterior) * cotizacionActual;
    }
};

/*  son un conjunto de productos los cuales están formados por productos y su precio es la suma del precio de los productos que lo componen menos un 10%.
            Las Ofertas no pueden contener productos de tipo oferta. Este producto debe permitir agregar productos que lo componen, como eliminarlos. */
class Oferta : public Producto
{
private:
    static const int MAX_PRODUCTOS = 100;
    const float porcentaje = 10;
    Producto* productos[100]; // Array de punteros a Producto
    int numProductos;

public:
    Oferta() : Producto(0) {numProductos = 0;}
    ~Oferta() {numProductos = 0;}

    void actualizarPrecio()
    {
        precioAnterior = precio;
        precio += (precio * porcentaje) / 100;
    }

    void agregarProducto(Producto *producto)
    {
        if(dynamic_cast<Oferta*>(producto) != nullptr){
            cout << "No se pueden agregar ofertas dentro de una oferta." << endl;
            return;
        }
        if(numProductos < MAX_PRODUCTOS){
            productos[numProductos++] = producto;
        }
        else {
            cout << "No se pueden agregar más productos a la oferta." << endl;
        }
    }
};

class Inventario{
    private:
        static const int MAX_PRODUCTOS = 100;
        Producto* inventario [MAX_PRODUCTOS];
        int cantidadProductos;

    public:
        Inventario() {    cantidadProductos = 0;
}
        ~Inventario() {
            for (int i = 0; i < cantidadProductos; i++) {
                delete inventario[i];
            }
        }

        void agregarProducto(Producto* producto){
            if (cantidadProductos < MAX_PRODUCTOS){
                inventario[cantidadProductos++] = producto;
            } else {
                cout << "No se pueden agregar más productos al inventario." << endl;
            }
        }

        Producto* getProducto(int id){
            for (int i = 0; i < cantidadProductos; i++){
                if (inventario[i]->getID() == id){
                    return inventario[i];
                }
            }
            return nullptr; // Producto no encontrado
        }

        void actualizarPrecios(){
            for (int i = 0; i < cantidadProductos; i++){
                inventario[i]->actualizarPrecio();
            }
        }

        void mostrarInventario() const {
            for (int i = 0; i < cantidadProductos; i++){
                cout << *(inventario[i]) << endl;
            }
        }

};

// --- FUNCIÓN MAIN ---
// (No necesita cambios, ya que interactúa con la interfaz pública del gestor)
int main() {
    Inventario gestor;

    // Carga de productos
    gestor.agregarProducto(new Nacional(100.0, 15.0)); // ID: 1
    gestor.agregarProducto(new Nacional(250.0, 20.0)); // ID: 2
    gestor.agregarProducto(new Extranjero(500.0, 850.0, 950.0)); // ID: 3
    
    // Crear una oferta
    Oferta* oferta1 = new Oferta(); // ID: 4
    oferta1->agregarProducto(gestor.getProducto(1)); // Agrega el producto con ID 1
    oferta1->agregarProducto(gestor.getProducto(3)); // Agrega el producto con ID 3
    gestor.agregarProducto(oferta1);
    
    std::cout << "--- Inventario Inicial ---";
    gestor.mostrarInventario();

    // Actualizar precios
    gestor.actualizarPrecios();
    
    // Mostrar resultados
    gestor.mostrarInventario();
    
    std::cout << "\n=============================================" << std::endl;
    // Poner precisión para mostrar 2 decimales en el output
    
    std::cout << "=============================================" << std::endl;

    return 0; // El destructor de 'gestor' se llamará automáticamente aquí.
}