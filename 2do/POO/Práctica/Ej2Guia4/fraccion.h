#ifndef FRACCION_H
#define FRACCION_H

class Fraccion
{
private:
    int num, denom = 1;

public:
    //Constructor que define lo mínimo
    Fraccion(int num);
    //
    Fraccion(int num, int denom);
    int getNum() const;
    int getDenom() const;

    Fraccion suma(Fraccion f2);
    Fraccion resta(Fraccion f2);
    Fraccion mult(Fraccion f2);
    Fraccion div(Fraccion f2);
};

#endif // FRACCION_H
