/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcd_dado;
    QWidget *boardContainer;
    QGridLayout *gridLayout;
    QPushButton *BotonTirarDado;
    QWidget *widget;
    QFormLayout *formLayout;
    QGroupBox *groupBox_j1;
    QGroupBox *groupBox_j2;
    QGroupBox *groupBox_j3;
    QGroupBox *groupBox_j4;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menupausa;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1399, 667);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        lcd_dado = new QLCDNumber(centralwidget);
        lcd_dado->setObjectName("lcd_dado");
        lcd_dado->setAutoFillBackground(true);
        lcd_dado->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout_2->addWidget(lcd_dado, 13, 22, 1, 1);

        boardContainer = new QWidget(centralwidget);
        boardContainer->setObjectName("boardContainer");
        boardContainer->setEnabled(true);
        gridLayout = new QGridLayout(boardContainer);
        gridLayout->setObjectName("gridLayout");

        gridLayout_2->addWidget(boardContainer, 0, 0, 15, 1);

        BotonTirarDado = new QPushButton(centralwidget);
        BotonTirarDado->setObjectName("BotonTirarDado");

        gridLayout_2->addWidget(BotonTirarDado, 14, 22, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        groupBox_j1 = new QGroupBox(widget);
        groupBox_j1->setObjectName("groupBox_j1");
        groupBox_j1->setMaximumSize(QSize(1000, 20));
        groupBox_j1->setStyleSheet(QString::fromUtf8("font: 800 11pt \"Cantarell\";color: black;"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, groupBox_j1);

        groupBox_j2 = new QGroupBox(widget);
        groupBox_j2->setObjectName("groupBox_j2");
        groupBox_j2->setMaximumSize(QSize(1000, 20));
        groupBox_j2->setStyleSheet(QString::fromUtf8("font: 800 11pt \"Cantarell\";color: black;"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, groupBox_j2);

        groupBox_j3 = new QGroupBox(widget);
        groupBox_j3->setObjectName("groupBox_j3");
        groupBox_j3->setMaximumSize(QSize(1000, 20));
        groupBox_j3->setStyleSheet(QString::fromUtf8("font: 800 11pt \"Cantarell\";color: black;"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, groupBox_j3);

        groupBox_j4 = new QGroupBox(widget);
        groupBox_j4->setObjectName("groupBox_j4");
        groupBox_j4->setMaximumSize(QSize(100, 20));
        groupBox_j4->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 800 11pt \"Cantarell\";"));

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, groupBox_j4);


        gridLayout_2->addWidget(widget, 8, 22, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1399, 25));
        menupausa = new QMenu(menubar);
        menupausa->setObjectName("menupausa");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menupausa->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BotonTirarDado->setText(QCoreApplication::translate("MainWindow", "Tirar Dado", nullptr));
        groupBox_j1->setTitle(QCoreApplication::translate("MainWindow", "Jugador 1", nullptr));
        groupBox_j2->setTitle(QCoreApplication::translate("MainWindow", "Jugador 2", nullptr));
        groupBox_j3->setTitle(QCoreApplication::translate("MainWindow", "Jugador 3", nullptr));
        groupBox_j4->setTitle(QCoreApplication::translate("MainWindow", "Jugador 4", nullptr));
        menupausa->setTitle(QCoreApplication::translate("MainWindow", "Men\303\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
