cmake_minimum_required(VERSION 3.16)

project(Ej2Guia4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ej2Guia4 main.cpp
    fraccion.h fraccion.cpp)

include(GNUInstallDirs)
install(TARGETS Ej2Guia4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
