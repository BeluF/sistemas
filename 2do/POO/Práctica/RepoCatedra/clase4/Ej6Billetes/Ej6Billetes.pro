TEMPLATE = app
CONFIG += console c++11

# Archivos fuente
SOURCES += main.cpp \
           Cambio.cpp

# Archivos de cabecera
HEADERS += cambio.h

# Opciones de compilación
INCLUDEPATH += .

# Configuración de salida
DESTDIR = ./bin
