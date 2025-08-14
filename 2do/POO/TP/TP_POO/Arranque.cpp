#include "Arranque.h"
#include "ui_Arranque.h"
#include "mainwindow.h"

//Constructor
Inicio::Inicio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inicio)
{
    ui->setupUi(this);
    connect(ui->BotonReglas, &QPushButton::clicked, this, &Inicio::mostrarReglas);

    ui->spinBox->setMinimum(2);
    ui->spinBox->setMaximum(4);
    ui->spinBox->setValue(2); //Que inicie con el valor 2
}

//Destructor
Inicio::~Inicio()
{
    delete ui;
}

//Obtiene el valor de la spinbox (cantidad de jugadores)
void Inicio::setValor(int valor)
{
    ValorSpinBox=valor;
}

//Devuelve el valor de la spinbox (cantidad de jugadores)
int Inicio::getValor()
{
    return ValorSpinBox;
}

//Slot que se ejecuta al pulsar el boton Jugar
void Inicio::on_BotonJugar_clicked()//boton jugar
{
    int numeroDeJugadores = ui->spinBox->value();
    setValor(ui->spinBox->value());
    ui->label->setText(QString :: number(getValor()));//cuando se pulsa el boton jugar el numero de la spinbox se almacena en valorspinbox

    MainWindow *ventanaPrincipal = new MainWindow(numeroDeJugadores);
    ventanaPrincipal->show();

    this->close();
}

void Inicio::mostrarReglas()
{
    QString reglas = "REGLAS DEL JUEGO DE LA OCA:\n\n"
                     "1. Cada jugador lanza el dado en su turno.\n"
                     "2. Si cae en una casilla especial, sigue las instrucciones indicadas:\n"
                     "   - Oca: avanza automáticamente a la próxima oca.\n"
                     "   - Puente: avanza a la casilla 12.\n"
                     "   - Posada: pierde un turno.\n"
                     "   - Pozo: no puede moverse hasta que otro jugador caiga en la misma casilla.\n"
                     "   - Laberinto: retrocede hasta la casilla 30.\n"
                     "   - Cárcel: pierde dos turnos.\n"
                     "   - Calavera: vuelve a la casilla 1.\n"
                     "   - Jardín de la Oca: gana el juego.\n"
                     "3. Gana el primero que llegue exactamente a la casilla 63 (Jardín de la Oca).\n"
                     "4. Si saca más puntos de los necesarios debe retroceder la diferencia.";

    QMessageBox::information(this, "Reglas del Juego", reglas);
}
