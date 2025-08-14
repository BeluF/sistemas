cmake_minimum_required(VERSION 3.16)

project(Clase-14-04-25 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Clase-14-04-25 main.cpp
    vectordinamico.h vectordinamico.cpp)

include(GNUInstallDirs)
install(TARGETS Clase-14-04-25
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
