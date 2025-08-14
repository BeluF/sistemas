/*
7.Realice un software que permita mantener las fechas de cumpleaños de sus amistades.
El software debe permitir cargar un cumpleaños y listar los cumpleaños cargados. 
*/
#include <iostream>
#include <string>


using namespace std;

class Cumpleanos {
private:
    string nombre;
    int dia;
    int mes;
    int anio;
public:
    //Constructor
    Cumpleanos(string n, int d, int m, int a) {
        nombre = n;
        dia = d;
        mes = m;
        anio = a;
    }

    //Métodos
    string getNombre() {
        return nombre;
    }

    string getFecha() {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }

    void mostrar() {
        cout << "Nombre: " << nombre << ", Fecha: " << getFecha() << endl;
    }
};

class CumpleanosManager {
private:
    Cumpleanos** listaCumpleanos;
    int cantidad;
    int capacidad;
public:
    //Constructor
    CumpleanosManager(int cap) {
        capacidad = cap;
        cantidad = 0;
        listaCumpleanos = new Cumpleanos*[capacidad];
    }

    //Destructor
    ~CumpleanosManager() {
        for (int i = 0; i < cantidad; i++) {
            delete listaCumpleanos[i];
        }
        delete[] listaCumpleanos;
    }

    //Métodos
    void agregarCumpleanos(string nombre, int dia, int mes, int anio) {
        if (cantidad < capacidad) {
            listaCumpleanos[cantidad++] = new Cumpleanos(nombre, dia, mes, anio);
        } else {
            cout << "Capacidad maxima alcanzada." << endl;
        }
    }

    void listarCumpleanos() {
        for (int i = 0; i < cantidad; i++) {
            listaCumpleanos[i]->mostrar();
        }
    }
    void buscarCumpleanos(string nombre) {
        for (int i = 0; i < cantidad; i++) {
            if (listaCumpleanos[i]->getNombre() == nombre) {
                listaCumpleanos[i]->mostrar();
                return;
            }
        }
        cout << "Cumpleaños no encontrado." << endl;
    }

};




int main(){
    CumpleanosManager manager(10);
    int opcion;
    string nombre;
    int dia, mes, anio;

    do {
        cout << "1. Agregar cumpleaños" << endl;
        cout << "2. Listar cumpleaños" << endl;
        cout << "3. Buscar cumpleaños" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese dia: ";
                cin >> dia;
                cout << "Ingrese mes: ";
                cin >> mes;
                cout << "Ingrese anio: ";
                cin >> anio;
                manager.agregarCumpleanos(nombre, dia, mes, anio);
                break;
            case 2:
                manager.listarCumpleanos();
                break;
            case 3:
                cout << "Ingrese nombre a buscar: ";
                cin >> nombre;
                manager.buscarCumpleanos(nombre);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 4);

    return 0;

}