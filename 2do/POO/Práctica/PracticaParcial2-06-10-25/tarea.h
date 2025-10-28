#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>

using namespace std;

struct TareaStr{
    string descripcion;
    string fecha;
    string hora;
    int duracion;
    char tipo;
};

class Tarea
{
public:
    Tarea();

    string getDescripcion() const;
    void setDescripcion(const string &newDescripcion);
    string getFecha() const;
    void setFecha(const string &newFecha);
    string getHora() const;
    void setHora(const string &newHora);
    int getDuracion() const;
    void setDuracion(int newDuracion);

    TareaStr getStr();
    void setStr(TareaStr str);

    virtual char getTipo() = 0;
    virtual void notificar() = 0;

protected:
    string descripcion;
    string fecha;
    string hora;
    int duracion;
};

#endif // TAREA_H
