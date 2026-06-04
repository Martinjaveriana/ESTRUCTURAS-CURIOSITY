//
// Created by ago on 13/04/26.
//

#ifndef PROYECTOCURIOSITY_AYUDA_H
#define PROYECTOCURIOSITY_AYUDA_H

#include "CMovimiento.h"
#include <vector>

class Utilities {
public:
    inline static void funcionAyuda();
    inline static void cargarComandosA();
    inline static void cargarElementosA();
    inline static void agregarMovimientoA();
    inline static void agregarAnalisisA();
    inline static void agregarElementoA();
    inline static void guardarA();
    inline static void simularComandosA();
    inline static void ubicarElementoA();
    inline static void enCuadranteA();
    inline static void crearMapaA();
    inline static void rutaMasLargaA();

    inline static vector<string> obtenerArgumentos(string &entrada);
    inline static bool verificador(string &cadena, int opcion);
    inline static float calcularDistancia(CMovimiento &c);
    inline static string comentario(vector<string>& args);
};

#include "Utilities.hxx"

#endif //PROYECTOCURIOSITY_AYUDA_H
