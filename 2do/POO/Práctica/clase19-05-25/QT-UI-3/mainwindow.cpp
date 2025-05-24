#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->r1 = new rotor(6);
    this->r2 = new rotor(6);
    this->r3 = new rotor(6);

    this->t1 = new QTimer(this);
    this->t2 = new QTimer(this);
    this->t3 = new QTimer(this);

    QObject::connect(this->t1, SIGNAL(timeout()), this, SLOT(girarR1));
    QObject::connect(this->t2, SIGNAL(timeout()), this, SLOT(girarR2));
    QObject::connect(this->t3, SIGNAL(timeout()), this, SLOT(girarR3));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int n1 = rand () % 6;
    srand(time(NULL));

    int n2 = rand () % 6;
    srand(time(NULL));

    int n3 = rand () % 5;
    srand(time(NULL));
    this->t1->start(100 * n1);
    this->t2->start(100 * n2);
    this->t3->start(200 * n3);
}

void MainWindow::girarR1()
{
    this->ui->lcdNumber->display(r1->next());
}

void MainWindow::girarR2()
{
    this->ui->lcdNumber_2->display(r2->next());
}

void MainWindow::girarR3()
{
    this->ui->lcdNumber_3->display(r3->next());
}


