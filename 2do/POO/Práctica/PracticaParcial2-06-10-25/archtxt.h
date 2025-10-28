#ifndef ARCHTXT_H
#define ARCHTXT_H

#include <tarea.h>

class ArchTxt: public Tarea
{
public:
    ArchTxt();

    char getTipo();
    void notificar();
};

#endif // ARCHTXT_H
