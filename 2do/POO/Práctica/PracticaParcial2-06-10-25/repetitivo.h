#ifndef REPETITIVO_H
#define REPETITIVO_H

#include "tarea.h"
#include "string.h"
#include "agenda.h"

class Repetitivo : public Tarea
{
private:
    Agenda* agenda; //Va con puntero para que aounte a nada y funcione cuando setea la agenda (?
public:
    Repetitivo(Agenda* agenda);

    char getTipo();
    void notificar();
};

#endif // REPETITIVO_H
