#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno
{
private:
    int DNI = 0;
    int nota1 = 0;
    int nota2 = 0;
    char* nombre;
public:
    Alumno(int DNI); //Constructor: defino lo mínimo e indispensable para instanciar mi clase Alumno

    //Acceder al elemento: GET
    //Modif el elemento: SET

    int getDNI() const;
    int getNota1() const;
    void setNota1(int newNota1);
    int getNota2() const;
    void setNota2(int newNota2);
    char *getNombre() const;
    void setNombre(char *newNombre);

    double promedio(); //Método
};

#endif // ALUMNO_H

/*
class Facu {
    void Inscribir (Alumno* a)
}

class Alumno {
    void seInscribe (Facultad f)
    {
        f.Inscribir(this); DE ESTA FORMA NO ESCRIBO DOS VECES EL CÓDIGO PARA UNA MISMA ACCIÓN (Inscribir y seInscribe)
    }
}

*/
