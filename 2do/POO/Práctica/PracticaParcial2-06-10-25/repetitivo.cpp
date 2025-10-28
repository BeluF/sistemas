#include "repetitivo.h"

Repetitivo::Repetitivo(Agenda *agenda) {
    this->agenda = agenda;
}

char Repetitivo::getTipo()
{
    return 'R';
}

void Repetitivo::notificar()
{
    std::cout << this->descripcion;
    Repetitivo nuevaTarea (this->agenda); // Crear la nueva tarea

    nuevaTarea.descripcion = this->descripcion;
    nuevaTarea.duracion = this->duracion;
    nuevaTarea.hora = this->hora;
    //@TODO: Aumentar la fecha en 1 día
    nuevaTarea.fecha = this->fecha;
    this->agenda->addTarea(&nuevaTarea);
}
