cmake_minimum_required(VERSION 3.20)
project(ProyectoCuriosity)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
        "*.cpp" "*.cxx" "*.h" "*.hpp" "*.hxx"
        "src/*.cxx" "src/*.cpp"
        "src/*.h" "src/*.hpp" "src/*.hxx"
)

add_executable(curiosity ${SOURCES}
        src/Utilites/Utilities.hxx
        src/Utilites/Utilities.h
        src/Comandos/Comando.hxx
        src/Comandos/Comando.h
        src/Comandos/ComandoAnalisis/CAnalisis.hxx
        src/Comandos/ComandoAnalisis/CAnalisis.h
        src/Comandos/ComandoMovimiento/CMovimiento.hxx
        src/Comandos/ComandoMovimiento/CMovimiento.h
        src/Elementos/Elemento.hxx
        src/Elementos/Elemento.h)

# 1. Creamos una lista vacía para las rutas cortas
set(SOURCES_RELATIVAS "")

# 2. Convertimos cada ruta larga en una corta respecto al proyecto
foreach(FILA ${SOURCES})
    file(RELATIVE_PATH RUTA_CORTA ${CMAKE_CURRENT_SOURCE_DIR} ${FILA})
    list(APPEND SOURCES_RELATIVAS ${RUTA_CORTA})
endforeach()

# 3. Imprimimos la lista limpia
message(STATUS "Archivos del proyecto: ${SOURCES_RELATIVAS}")