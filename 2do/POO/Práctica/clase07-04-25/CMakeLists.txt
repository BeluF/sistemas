cmake_minimum_required(VERSION 3.16)

project(clase07-04-25 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clase07-04-25 main.cpp
    alumno.h alumno.cpp
)

include(GNUInstallDirs)
install(TARGETS clase07-04-25
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
