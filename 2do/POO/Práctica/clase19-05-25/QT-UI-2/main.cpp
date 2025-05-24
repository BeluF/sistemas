#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //Setea la ventana inicial (vacía)
    w.show(); //Muestra la ventana
    return a.exec();
}
