QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += resources.qrc

SOURCES += \
    Arranque.cpp \
    casilla.cpp \
    casillacastigo.cpp \
    casillanormal.cpp \
    casillaoca.cpp \
    casillapuente.cpp \
    dado.cpp \
    juego.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    tablero.cpp \


HEADERS += \
    Arranque.h \
    casilla.h \
    casillacastigo.h \
    casillanormal.h \
    casillaoca.h \
    casillapuente.h \
    dado.h \
    estadoJugador.h \
    juego.h \
    jugador.h \
    mainwindow.h \
    tablero.h \

FORMS += \
    Arranque.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
