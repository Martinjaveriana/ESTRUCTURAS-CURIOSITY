cmake_minimum_required(VERSION 3.20)
project(ProyectoCuriosity)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
        "*.cpp" "*.cxx" "*.h" "*.hpp" "*.hxx"
        "src/*.cxx" "src/*.cpp"
        "Include/Cabeceras/*.h" "Include/Cabeceras/*.hpp" "Include/Cabeceras/*.hxx"
)

add_executable(curiosity ${SOURCES})

# 1. Creamos una lista vacía para las rutas cortas
set(SOURCES_RELATIVAS "")

# 2. Convertimos cada ruta larga en una corta respecto al proyecto
foreach(FILA ${SOURCES})
    file(RELATIVE_PATH RUTA_CORTA ${CMAKE_CURRENT_SOURCE_DIR} ${FILA})
    list(APPEND SOURCES_RELATIVAS ${RUTA_CORTA})
endforeach()

# 3. Imprimimos la lista limpia
message(STATUS "Archivos del proyecto: ${SOURCES_RELATIVAS}")