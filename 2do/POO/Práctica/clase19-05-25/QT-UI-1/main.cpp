#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window -> setWindowTitle("Example button!!!");
    QPushButton *button = new QPushButton("Quit");
    //QT trabaja con eventos: cada componente puede expresar una señal (SIGNAL) que es atrapada por un SLOT.
    //Pueden tenerse diferentes SLOT para una señal.
    //Connect es la forma de compunicar SIGNAL con SLOT (son macros).
    //Parámetros de Connect-> componente, señal que quiero lanzar, el componenete que recibe la señal
    //y la función que se ejecuta al recibir la señal.
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);

    QSpinBox *spinbox = new QSpinBox();
    spinbox->setRange(0, 130);

    QObject::connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    QObject::connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));


    QHBoxLayout *layout = new QHBoxLayout;
    layout -> addWidget(spinbox);
    layout -> addWidget(slider);
    layout -> addWidget(button);
    window->setLayout(layout);
    window->show();
    return app.exec();//Ejecución en bucle

    //QWidget -> padre de cualquier componente visual.
    //SpinBox -> Input number con flechas p cambiar el valor
    //Slider -> Input number en forma de barra


}
