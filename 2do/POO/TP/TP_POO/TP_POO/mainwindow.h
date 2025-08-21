#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>

#include <QPixmap>
#include "juego.h"
#include "jugador.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int numJugadores, QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void continuarTurno();
public slots:
    void mostrarMensajePopUp(const QString& mensaje)
    {
        if (mensaje.isEmpty())
            return;

        QMessageBox::information(this, "Casilla especial", mensaje);
        emit continuarTurno();
    }
private slots:
    void on_BotonTirarDado_clicked();
    void configurarPanelesJugadores(int numJugadores);
    void actualizarDado(int valorDado);
    void moverFichaUI(int jugadorIndex, int casillaOrigen, int casillaDestino);
    void mostrarGanador(const QString &nombreGanador);
    void actualizarPanelesJugadores();


private:
    void crearTableroUI();
    void inicializarPeones(int numJugadores);

    Ui::MainWindow *ui;
    Juego miJuego;
    QVector<QLabel*> vectorCasillas; // Contendrá las casillas creadas
    QVector<QLabel*> peonesLabels;   // Contendrá los peones creados
    QList<Jugador*> jugadoresUI;

};
#endif // MAINWINDOW_H
