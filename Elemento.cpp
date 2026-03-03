//
// Created by martin-sanmiguel on 3/3/26.
//

#include <iostream>
#include <fstream>
#include "Elemento.h"

using namespace std;

Elemento::Elemento(string n_tipo, double n_tamano, string n_unidad_medida, float n_cord_x, float n_cord_y) {
    tipo_comp = n_tipo;
    tamano = n_tamano;
    unidad_med = n_unidad_medida;
    cord_x = n_cord_x;
    cord_y = n_cord_y;
}

//=====================
//Getters
//=====================



string Elemento::obtenerTipo_comp() {
    return tipo_comp;
}

double Elemento::obtenerTamano() {
    return tamano;
}

string Elemento::obtenerUnidad_med() {
    return unidad_med;
}

float Elemento::obtenerCord_x() {
    return cord_x;
}

float Elemento::obtenerCord_y() {
    return cord_y;
}



//=====================
//Setters
//=====================

void Elemento::fijarTipo_comp(string n_tipo) {
    tipo_comp = n_tipo;
}

void Elemento::fijarTamano(double n_tamano) {
    tamano = n_tamano;
}

void Elemento::fijarUnidad_med(string n_unidad_medida) {
    unidad_med = n_unidad_medida;
}

void Elemento::fijarCord_x(float n_cord_x) {
    cord_x = n_cord_x;
}

void Elemento::fijarCord_y(float n_cord_y) {
    cord_y = n_cord_y;
}
