#include "fraccion.h"

//Mayor común divisor
int MCD(int num, int denom){
    if ((num%denom)==0) return denom;
    return MCD(denom, num%denom);
}

int Fraccion::getNum() const
{
    return num;
}

int Fraccion::getDenom() const
{
    return denom;
}

//SUMAR
Fraccion Fraccion::suma(Fraccion f2)
{
    //Numerador nuevo
    int nuevoNum = this->num * f2.getDenom() +
                   f2.getNum() * this->denom;

    //Denominador nuevo
    int nuevoDenom = this->denom * f2.getDenom();

    return Fraccion(nuevoNum, nuevoDenom);
}

//RESTAR
Fraccion Fraccion::resta(Fraccion f2)
{
    //Numerador nuevo
    int nuevoNum = this->num * f2.getDenom() -
                   f2.getNum() * this->denom;

    //Denominador nuevo
    int nuevoDenom = this->denom * f2.getDenom();

    return Fraccion(nuevoNum, nuevoDenom);
}

//MULTIPLICAR
Fraccion Fraccion::mult(Fraccion f2)
{
    //Numerador nuevo
    int nuevoNum = this->num * f2.getNum();

    //Denominador nuevo
    int nuevoDenom = this->denom * f2.getDenom();

    return Fraccion(nuevoNum, nuevoDenom);
}

//DIVIDIR
Fraccion Fraccion::div(Fraccion f2)
{
    //Numerador nuevo
    int nuevoNum = this->num * f2.getDenom();

    //Denominador nuevo
    int nuevoDenom = this->denom * f2.getDenom();

    return Fraccion(nuevoNum, nuevoDenom);
}

Fraccion::Fraccion(int num) {
    this->num = num;
}


