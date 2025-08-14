cmake_minimum_required(VERSION 3.16)

project(Ej4-VectorDinamico LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ej4-VectorDinamico main.cpp
    vectordinamico.h vectordinamico.cpp)

include(GNUInstallDirs)
install(TARGETS Ej4-VectorDinamico
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
