#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rotor.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void girarR1();
    void girarR3();
    void girarR2();

private:
    Ui::MainWindow *ui;
    rotor *r1, *r2, *r3;
    QTimer *t1, *t2, *t3;
};
#endif // MAINWINDOW_H
