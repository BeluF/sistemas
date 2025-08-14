#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno
{
private:
    int DNI;
    char* nom, ap;
    float notas[4];
public:
    //Constructor con lo mínimo
    Alumno(int DNI);
};

#endif // ALUMNO_H
