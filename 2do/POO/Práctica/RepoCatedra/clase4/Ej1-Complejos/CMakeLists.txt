cmake_minimum_required(VERSION 3.16)

project(Ej1-Complejos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ej1-Complejos main.cpp
    complejo.h complejo.cpp)

include(GNUInstallDirs)
install(TARGETS Ej1-Complejos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
