#include "jugador.h"
#include <string>
using namespace std;


Jugador::Jugador() {

}

Jugador::Jugador(string nombre)
{
    this->nombre=nombre;  //creeria que el constructor le asigna un nombre al jugador, preguntar
}

string Jugador::getNombre()
{
    return nombre;
}

int Jugador::getPosicion(){
    return posicion;
}

void Jugador::mover(int cantidad)
{
    posicion+=cantidad;
}

void Jugador::resetEstado()
{
    estadoEspecial= normal;
}

bool Jugador::estaCastigado(){
    if (estadoEspecial == casitigado) return true;

    return false;
}

