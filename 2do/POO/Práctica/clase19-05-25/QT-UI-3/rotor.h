#ifndef ROTOR_H
#define ROTOR_H

class rotor
{
private:
    int cant, indice = 0;
    int* elementos;
public:
    rotor(int cant);
    int next();
};

#endif // ROTOR_H
