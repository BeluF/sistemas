#include "tarea.h"
#include <iostream>
#include <string>

using namespace std;

Tarea::Tarea()
{
  /*  this->descripcion = descripcion;
    this->hora = hora;
    this->fecha = fecha;*/

}

string Tarea::getDescripcion() const
{
    return descripcion;
}

void Tarea::setDescripcion(const string &newDescripcion)
{
    descripcion = newDescripcion;
}

string Tarea::getFecha() const
{
    return fecha;
}

void Tarea::setFecha(const string &newFecha)
{
    fecha = newFecha;
}

string Tarea::getHora() const
{
    return hora;
}

void Tarea::setHora(const string &newHora)
{
    hora = newHora;
}

int Tarea::getDuracion() const
{
    return duracion;
}

void Tarea::setDuracion(int newDuracion)
{
    duracion = newDuracion;
}

TareaStr Tarea::getStr(){
    TareaStr str;

    str.duracion = this->duracion;
    str.descripcion = this->descripcion;
    str.fecha = this->fecha;
    str.hora = this->hora;
    str.tipo = this->getTipo();
}

void Tarea::setStr(TareaStr str){
    this->duracion = str.duracion;
    this->descripcion = str.descripcion;
    this->fecha = str.fecha;
    this->hora = str.hora;
}
