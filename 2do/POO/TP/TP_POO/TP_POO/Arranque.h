#ifndef ARRANQUE_H
#define ARRANQUE_H

#include <QMainWindow>
#include "mainwindow.h"

// --- CLASE Inicio ---
// Representa la ventana de inicio del juego.
//Opciones: Recuperar juego, iniciar juego nuevo y ver las reglas.

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();
    void setValor(int valor);
    int getValor();

private slots:
    void on_BotonJugar_clicked();
    void mostrarReglas();

private:
    int ValorSpinBox;
    Ui::Inicio *ui;
    MainWindow *ventanaJuego;
};

#endif // ARRANQUE_H
