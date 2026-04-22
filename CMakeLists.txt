cmake_minimum_required(VERSION 3.20)
project(ProyectoCuriosity)

set(CMAKE_CXX_STANDARD 20)

# Solo buscamos recursivamente DENTRO de la carpeta src/
file(GLOB_RECURSE SOURCES
        "src/*.cpp" "src/*.cxx"
        "src/*.h" "src/*.hpp" "src/*.hxx"
)

# Creamos el ejecutable uniendo el main principal y los archivos fuente de src/
add_executable(curiosity
        interfazUsuario.cxx
        ${SOURCES}
)

# 1. Creamos una lista vacía para las rutas cortas
set(SOURCES_RELATIVAS "")

# 2. Convertimos cada ruta larga en una corta respecto al proyecto
foreach(FILA ${SOURCES})
    file(RELATIVE_PATH RUTA_CORTA ${CMAKE_CURRENT_SOURCE_DIR} ${FILA})
    list(APPEND SOURCES_RELATIVAS ${RUTA_CORTA})
endforeach()

# 3. Imprimimos la lista limpia
message(STATUS "Archivos del proyecto: ${SOURCES_RELATIVAS}")