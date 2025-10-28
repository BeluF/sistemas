#ifndef AGENDA_H
#define AGENDA_H

#include "tarea.h"
#include <vector>

class Agenda
{
private:
    std::vector<Tarea*> tareas;
public:
    Agenda();
    Agenda(const std::vector<Tarea *> &tareas);

    void addTarea(Tarea* t);
    void leer();
    void guardar();

    std::vector<Tarea*> mayorDuracion();
    std::string diaConMasTareas();
};

#endif // AGENDA_H
