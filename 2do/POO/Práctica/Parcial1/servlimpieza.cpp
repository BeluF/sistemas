// Una empresa la cual se encarga de ofrecer servicios de limpieza, le solicita como programador, realizar un Software que permita el cobro mensual, sobre su actual cartera de Clientes.
// Dichos servicios son provistos para un segmento de viviendas que poseen una tipología tipo media familiar. Los formatos de cálculo de la facturación son los siguientes:
// ● Mediante horas de servicio: se cobra un monto fijo por la cantidad de horas semanales empleadas en el servicio.
// ● Mensual: se cobra un abono fijo por mes.
// ● A solicitud del cliente: se cobra un monto por servicio.
// Como parte de una promoción vigente, existe una opción PROMO, la cual a partir del precio de las 3 posibles tarifas anteriores, se cobre la más barata con un 15% de descuento.
// El software debe permitir cargar los valores iniciales, monto por una hora, monto fijo mensual y monto por servicio. Y luego registrar los servicios que están formados por :
// número de cliente, tipo de servicio y según el servicio, las horas utilizadas o las solicitudes de servicio.

// 1 (65).El software debe calcular el monto total a cobrar y imprimir por pantalla un detalle de todos los clientes con una deuda mayor a un valor ingresado.
// 2 (15). Para implementar polimorfismo en c++, ¿es necesario que la clase padre tenga un método abstracto? Justifique. Indique las diferencias entre clase y objeto.
// 3 (20). Indique cual es el resultado del siguiente algoritmo con los siguientes valores :
// 1522, 645, 876.
// int XXX(int n) {
// if(n < 10)
// return n;
// return n%10+XXX(n/10)
// }

// Indique qué hace el algoritmo.

// 2. Para implementar polimorfismo en C++ no es estrictamente necesario que la calse padre tenga un método abstracto o sea abstracta, pero si tiene que tener al menos un método virtual.
// 3. Para 1522 la salida es 10, para 645 la salida es 15 y para 876 al salida es 21. El algoritmo devuelve la suma de los números que componen el número entero n.

// 1.
// Facturación:
//- Por hora
//- Por mes
//- Por servicio
//- Promo: 15% dcto

// Maquetación:
//- Cliente
//- Servicio
//- Tipo de servicio
//- Monto

#include <iostream>
using namespace std;

class Cliente
{
private:
    int nroCliente;
    double deuda;

public:
    // Contructor: solo necesita nroCliente
    Cliente(int nro) : nroCliente(nro), deuda(0.0) {}

    // Desrtuctor
    ~Cliente() {}

    // Getters
    int getNroCliente() const { return nroCliente; }
    double getDeuda() const { return deuda; }

    // Setters
    void setDeuda(double monto) { deuda += monto;}
};

class Monto
{
private:
    double porHora, porMes, promo;
    // Monto por servicio
    double *porServicio;     // Array dinámico
    char **nombresServicios; // Array dinámico
    int cantServ;

public:
    // Construtor: inicializa los montos
    Monto(double hora, double mes, const char *nombres[], double *montos, int numServicios)
    {
        porHora = hora;
        porMes = mes;
        cantServ = numServicios;

        // Reservar memoria p los nombres
        nombresServicios = new char *[cantServ];
        for (int i = 0; i < cantServ; i++)
        {
            int len = 0;
            while (nombres[i][len] != '\0')
                len++;                               // Calcular longitud del nombre
            nombresServicios[i] = new char[len + 1]; // +1 para el carácter nulo
            for (int j = 0; j < len; j++)
            {
                nombresServicios[i][j] = nombres[i][j];
            }
        }

        // Reservar memoria p montos
        porServicio = new double[cantServ];
        for (int i = 0; i < cantServ; i++)
        {
            porServicio[i] = montos[i];
        }
    };

    // Destructor
    ~Monto()
    {
        for (int i = 0; i < cantServ; ++i)
        {
            delete[] nombresServicios[i];
        }
        delete[] nombresServicios;
        delete[] porServicio;
    }

    // Getters
    double getPorHora() const { return porHora; }
    double getPorMes() const { return porMes; }
    double getPorServicio(int i) const { return porServicio[i]; }
    const char *getNombreServicio(int i) const { return nombresServicios[i]; }
    int getCantServicios() const { return cantServ; }
    double getPromo() const { return promo; }

    // Setters
    void setPromo(double servicio) { promo = servicio - (servicio * 0.15); }
};

class Servicio
{
private:
    Cliente *cliente;
    Monto *monto;
    int tipoGeneral;  // 0 = por hora, 1 = por mes, 2 = a solicitud
    int tipoServicio; // Indice
    int cantidad;     // Horas o cant de solicitudes, segun el tipo

public:
    // Constructor: recibe cliente, monto, tipo de servicio y cantidad
    Servicio(Cliente *c, Monto *m, int tipoGen, int cant, int tipoSpec = -1) : cliente(c), monto(m), tipoGeneral(tipoGen), cantidad(cant), tipoServicio(tipoSpec) {}

    // Destructor
    ~Servicio() {}

    int getCantidad() const { return cantidad; }

    double calcularMonto() const
    {
        if (tipoGeneral == 0) // Por hora
            return monto->getPorHora() * cantidad;
        else if (tipoGeneral == 1) // Por mes
            return monto->getPorMes();
        else if (tipoGeneral == 2) // A solicitud
            return monto->getPorServicio(tipoServicio) * cantidad;
        return 0.0; // Si no es ninguno de los anteriores
    }

    const char *getNombreServicio() const
    {
        if (tipoGeneral == 2 && tipoServicio >= 0) // A solicitud
            return monto->getNombreServicio(tipoServicio);
        else if (tipoGeneral == 0) // Por hora
            return "Por Hora";
        else if (tipoGeneral == 1) // Por mes
            return "Por Mes";
        return "Desconocido"; // Si no es ninguno de los anteriores
    }
};
int main()
{

    const int numClientes = 2;
    Cliente **clientes = new Cliente *[numClientes]; // Array de punteros a Cliente
    clientes[0] = new Cliente(101);
    clientes[1] = new Cliente(102);

    double umbralDeuda;
    cout << "Ingrese el monto de deuda: ";
    cin >> umbralDeuda;

    int clientesConDeuda = 0;
    cout << "\nClientes con deuda mayor a $" << umbralDeuda << ":" << endl;
    for (int i = 0; i < numClientes; i++)
    {
        if (clientes[i]->getDeuda() > umbralDeuda)
        {
            cout << "- Cliente Nro: " << clientes[i]->getNroCliente() << ", Deuda Total: $" << clientes[i]->getDeuda() << endl;
            clientesConDeuda++;
        }
    }

    if (clientesConDeuda == 0)
    {
        cout << "No se encontraron clientes que superen ese umbral de deuda." << endl;
    }

    // Liberar memoria
    for (int i = 0; i < numClientes; i++)
    {
        delete clientes[i]; // Libera cada objeto Cliente
    }
    delete[] clientes; // Libera el array de punteros
    clientes = NULL;   // Evitar punteros colgantes

    return 0;
}