#include "alumno.h"

Alumno::Alumno(int DNI) {
    this->DNI = DNI;
    //this es un puntero a la instancia actual y a su vez es un puntero a sí mismo
    //
}

int Alumno::getDNI() const //clase:: es el nombre de la clase
{
    return DNI;
}

int Alumno::getNota1() const
{
    return nota1;
}

void Alumno::setNota1(int newNota1)
{
    nota1 = newNota1;
}

int Alumno::getNota2() const
{
    return nota2;
}

void Alumno::setNota2(int newNota2)
{
    nota2 = newNota2;
}

char *Alumno::getNombre() const
{
    return nombre;
}

void Alumno::setNombre(char *newNombre)
{
    nombre = newNombre;
}

double Alumno::promedio()
{
    return ((this->nota1+nota2)/2.0);
}
