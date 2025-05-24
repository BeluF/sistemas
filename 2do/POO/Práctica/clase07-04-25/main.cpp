#include <iostream>
#include "alumno.h"

using namespace std;

int main()
{
    Alumno primero (54622159); // defino en que clase trabajo, nombro a mi variable
                                //y paso el parámetro mínimo e indispensable (DNI)

    primero.setNombre("Belén"); //Con el . llamo a los métodos
    primero.setNota1(80);
    primero.setNota2(100);

    Alumno* pointerAlumno = new Alumno(45698745);
    pointerAlumno->getDNI();

    cout << primero.promedio() << endl;
    return 0;
}
