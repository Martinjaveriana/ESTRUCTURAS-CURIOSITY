cmake_minimum_required(VERSION 4.2)
project(Proyecto_Curiosity)

# Exigir de forma estricta el estándar C++20
set(CMAKE_CXX_STANDARD 20)

# Incluir el directorio actual para la resolución de rutas de cabeceras
include_directories(.)

# Declarar el ejecutable mapeando de forma explícita toda tu arquitectura de archivos
add_executable(Proyecto_Curiosity
        # --- Archivos Fuente Principales (.cxx) ---
        interfazUsuario.cxx

        # --- Cabeceras y Archivos de Plantillas (.h y .hxx) ---
        CAnalisis.h
        CAnalisis.hxx
        CMovimiento.h
        CMovimiento.hxx
        Comando.h
        Comando.hxx
        Curiosity.h
        Curiosity.hxx
        Elemento.h
        Elemento.hxx
        Grafo.h
        Grafo.hxx
        KDTree.h
        KDTree.hxx
        NodoKD.h
        NodoKD.hxx
        Utilities.h
        Utilities.hxx
)