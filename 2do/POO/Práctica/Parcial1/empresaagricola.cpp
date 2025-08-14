/*3. (20) Conteste :
Indique cómo la programación orientada a objeto contribuye a la reutilización de código. Liste y describa técnicas que proveen dicho beneficio.
¿Qué ventajas tiene la utilización de template? ¿Por qué estas se utilizan en los lenguajes de tipado estático?*/
/* POO para reutilización de código:
    - Herencia (en C++ se implementa con polimorfismo): es un mecanismo que permite crear una clase hija a partir de una clase padre, ya existente, y permitiendo que la primera herede los métodos y atributos de la segunda.
            La clase padre es general y describe comportamientos y atributos comunes para que la clase hija puedas reutilizarlos, ampliándolos o redefiniéndolos, si lo necesita.
            Para que las hijas puedan sobreescribir un método, este debe ser virtual en la clase padre. Puede, o no, ser virtual pura: esto obliga a la hija a implementar el método.
            Si la lcase padre define métodos o atributos como public, son accesibles desde cualquier parte del código; si son protected, son accesibles desde las hijas o friens, y si son private solo son accesibles desde la propia clase.

    - Composición:Es una relación donde una clase tiene otras clases como miembros. Las clases contenidas se crean y destruyen con la principal. La contenedora puede utilizar todos los métodos de la clase contenida,
            pero si se quiere que sea al revés, la contenedora debe ser pasada como referencia o declararse como friend.
            Es de propiedad fuerte, implica dependencia de existencia: la clase contenida no tiene sentido sin la contenedora.
    - Polimorfismo: es la capacidad de un objeto de comportarse de diferentes formas según el tipo real. Se implementa con punteros (debe referenciar a la clase, no ser parte de ella)
            Se utiliza virtual, para que se comporte según el tipo real del objeto y herencia.
    - Constructor: define las propiedades o atributos mínimos e indispensables para inicializar una clase. Existen los constructores de copia, con los que se puede crear un objeto a partir de otro existente.*/

/*
1. (50) Una empresa agrícola especializada en legumbres, oleaginosas y cereales te ha contratado para desarrollar un sistema que permita calcular la productividad de sus cultivos.
La información sobre la cosecha se ingresará por consola con la siguiente estructura:
nombre del cultivo : char[30]
kilogramos cosechados : int
tipo de cultivo : char[1] // L: legumbre, O: oleaginosa, C: cereal

El sistema debe calcular la productividad de cada tipo de cultivo según las siguientes reglas:
Legumbre: 1.2 * kilogramos cosechados
Oleaginosa: 1.5 * kilogramos cosechados
Cereal: 1.1 * kilogramos cosechados

Tener en cuenta que un cultivo puede tener múltiples registros de cosecha.

Diseñe y programe las clases necesarias para calcular la productividad acumulada de cada tipo de cultivo.

Sobrecargue el operador << para mostrar la productividad total de cada cultivo en el siguiente formato: "nombre_cultivo ........ productividad_total"
*/

#include <iostream>
#include <cstring>
using namespace std;

class Cultivo
{
protected:
    int kgCosechados;
    char tipoDeCultivo; // L: legumbre, O: oleaginosa, C: cereal
public:
    char nombreDelCultivo[30];

    Cultivo(const char *nombre, int kg, char tipo)
    {
        strncpy(nombreDelCultivo, nombre, 30);
        kgCosechados = kg;
        tipoDeCultivo = tipo;
    }

    // Destructor
    virtual ~Cultivo() {}

    const char *getNombre() const
    {
        return this->nombreDelCultivo;
    }

    void getKgCosechados(int &kg) const
    {
        kg = kgCosechados;
    }

    // Método para sumar cosecha a un cultivo existente
    void agregarCosecha(int kg)
    {
        this->kgCosechados += kg;
    }

    virtual double calcularProductividad() const = 0; // Método virtual puro: las hijas deben implementarlo
};

/*Cereal: 1.1 * kilogramos cosechados*/
class Cereal : public Cultivo
{
public:
    Cereal(const char *nombre, int kg) : Cultivo(nombre, kg, 'L')
    {
        strncpy(nombreDelCultivo, nombre, 30);
        kgCosechados = kg;
    }

    // Destructor
    ~Cereal() {}

    double calcularProductividad () const 
    {
        double resultado = 1.1 * kgCosechados;
        return resultado;
    }
};

/*Oleaginosa: 1.5 * kilogramos cosechados */
class Oleaginosa : public Cultivo
{
public:
    Oleaginosa(const char *nombre, int kg) : Cultivo(nombre, kg, 'O')
    {
        strncpy(nombreDelCultivo, nombre, 30);
        kgCosechados = kg;
    }

    // Destructor
    ~Oleaginosa() {}

    double calcularProductividad() const 
    {
        double resultado = 1.5 * kgCosechados;
        return resultado;
    }
};

/*Legumbre: 1.2 * kilogramos cosechados*/
class Legumbre : public Cultivo
{
public:
    Legumbre(const char *nombre, int kg) : Cultivo(nombre, kg, 'L')
    {
        strncpy(nombreDelCultivo, nombre, 30);
        kgCosechados = kg;
    }

    // Destructor
    ~Legumbre() {}

    double calcularProductividad() const 
    {
        double resultado = 1.2 * kgCosechados;
        return resultado;
    }
};

// Sobrecarga del operador <<
ostream &operator<<(ostream &os, const Cultivo &cultivo)
{
    os << cultivo.getNombre() << " ........ " << cultivo.calcularProductividad();
    return os;
}

int main()
{
    // La cantidad de cultivos a ingresar debe ser gestionado con punteros y memoria dinámica.
    int cantidadCultivos;
    cout << "Ingrese la cantidad de cultivos: ";
    cin >> cantidadCultivos;

    Cultivo **cultivos = new Cultivo *[cantidadCultivos]; // Array de punteros a Cultivo
    int cultivosUnicos = 0;                               // Contador para cultivos distintos

    for (int i = 0; i < cantidadCultivos; i++)
    {
        char nombre[30];
        int kgCosechados;
        char tipo;

        cout << "Ingrese el nombre del cultivo: ";
        cin >> nombre;

        cout << "Ingrese los kilogramos cosechados: ";
        cin >> kgCosechados;

        cout << "Ingrese el tipo de cultivo (L: legumbre, O: oleaginosa, C: cereal): ";
        cin >> tipo;

        bool encontrado = false;

        for (int j = 0; j < cultivosUnicos; j++)
        {
            if (strcmp(cultivos[j]->getNombre(), nombre) == 0)
            {
                // Si el cultivo ya existe, sumar la cosecha
                cultivos[j]->agregarCosecha(kgCosechados);
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            // Crear el cultivo según el tipo
            if (tipo == 'L')
            {
                cultivos[i] = new Legumbre(nombre, kgCosechados);
            }
            else if (tipo == 'O')
            {
                cultivos[i] = new Oleaginosa(nombre, kgCosechados);
            }
            else if (tipo == 'C')
            {
                cultivos[i] = new Cereal(nombre, kgCosechados);
            }
            else
                continue;
            cultivosUnicos++;
        }
    }

    
    // --- Mostrar resultados ---
    cout << "\n\n--- Productividad Total por Cultivo ---\n";
    // Iteramos SÓLO sobre los cultivos únicos que creamos
    for (int i = 0; i < cultivosUnicos; i++) {
        cout << *(cultivos[i]) << endl;
    }

    // Liberar memoria de los cultivos únicos
    for (int i = 0; i < cultivosUnicos; i++)
    {
        delete cultivos[i];
    }
    // Liberar el array de punteros creado con 'new[]'
    delete[] cultivos;

    system("pause"); // Para que la consola no se cierre inmediatamente
    return 0;
}

