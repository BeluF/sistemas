/********************************************************************************
** Form generated from reading UI file 'Arranque.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARRANQUE_H
#define UI_ARRANQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QLabel *label;
    QPushButton *BotonRecuperarJuego;
    QPushButton *BotonJugar;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *BotonReglas;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Inicio)
    {
        if (Inicio->objectName().isEmpty())
            Inicio->setObjectName("Inicio");
        Inicio->resize(1437, 738);
        centralwidget = new QWidget(Inicio);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 220, 800, 70));
        label->setMaximumSize(QSize(800, 70));
        label->setStyleSheet(QString::fromUtf8("font: 700 italic 11pt \"Cantarell\"; text-align:center; font-size: 50px"));
        BotonRecuperarJuego = new QPushButton(widget);
        BotonRecuperarJuego->setObjectName("BotonRecuperarJuego");
        BotonRecuperarJuego->setGeometry(QRect(500, 310, 500, 40));
        BotonRecuperarJuego->setMaximumSize(QSize(500, 40));
        BotonJugar = new QPushButton(widget);
        BotonJugar->setObjectName("BotonJugar");
        BotonJugar->setGeometry(QRect(500, 370, 500, 40));
        BotonJugar->setMaximumSize(QSize(500, 40));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 420, 589, 27));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(950, 420, 50, 27));
        spinBox->setMaximumSize(QSize(50, 16777215));
        BotonReglas = new QPushButton(widget);
        BotonReglas->setObjectName("BotonReglas");
        BotonReglas->setGeometry(QRect(500, 460, 500, 40));
        BotonReglas->setMaximumSize(QSize(500, 40));

        gridLayout->addWidget(widget, 1, 1, 1, 1);

        Inicio->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Inicio);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1437, 25));
        Inicio->setMenuBar(menubar);
        statusbar = new QStatusBar(Inicio);
        statusbar->setObjectName("statusbar");
        Inicio->setStatusBar(statusbar);

        retranslateUi(Inicio);

        QMetaObject::connectSlotsByName(Inicio);
    } // setupUi

    void retranslateUi(QMainWindow *Inicio)
    {
        Inicio->setWindowTitle(QCoreApplication::translate("Inicio", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Inicio", "Bienvenido al Juego de la Oca", nullptr));
        BotonRecuperarJuego->setText(QCoreApplication::translate("Inicio", "Recuperar juego", nullptr));
        BotonJugar->setText(QCoreApplication::translate("Inicio", "Iniciar juego nuevo", nullptr));
        label_2->setText(QCoreApplication::translate("Inicio", "Cantidad de jugadores", nullptr));
        BotonReglas->setText(QCoreApplication::translate("Inicio", "Reglas del juego", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio: public Ui_Inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARRANQUE_H
