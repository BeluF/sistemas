#include "archtxt.h"
#include <fstream>
#include <iostream>

ArchTxt::ArchTxt() {}

char ArchTxt::getTipo()
{
    return 'A';
}

void ArchTxt::notificar()
{
    std::ofstream arch("dato.txt");

    if (arch.is_open()){
        arch << "Se ejecutó " << this->descripcion << std::endl;
        arch.close();
    }
}
