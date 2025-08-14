cmake_minimum_required(VERSION 3.16)

project(Ej5-Alumnos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ej5-Alumnos main.cpp
    alumno.h alumno.cpp
    curso.h curso.cpp)

include(GNUInstallDirs)
install(TARGETS Ej5-Alumnos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
