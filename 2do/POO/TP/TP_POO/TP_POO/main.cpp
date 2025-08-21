#include "mainwindow.h"
#include "Arranque.h"
#include "juego.h"
#include <iostream>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego juego;

    Inicio ventanaInicial;
    ventanaInicial.show();

    return a.exec();
}
