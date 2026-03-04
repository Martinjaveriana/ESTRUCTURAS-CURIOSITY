//
// Created by martin-sanmiguel on 3/3/26.
//

#include <iostream>
#include <fstream>
#include "Elemento.h"

using namespace std;

Elemento::Elemento(const string& n_tipo, double n_tamano, const string& n_unidad, float n_cord_x, float n_cord_y) {
    tipo_comp = n_tipo;
    tamano = n_tamano;
    unidad = n_unidad;
    cord_x = n_cord_x;
    cord_y = n_cord_y;
}

//=====================
//Getters
//=====================



const string& Elemento::obtenerTipo_comp() const{
    return tipo_comp;
}

double Elemento::obtenerTamano() {
    return tamano;
}

const string& Elemento::obtenerUnidad() const {
    return unidad;
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

void Elemento::fijarTipo_comp(const string& n_tipo) {
    tipo_comp = n_tipo;
}

void Elemento::fijarTamano( double n_tamano) {
    tamano = n_tamano;
}

void Elemento::fijarUnidad(const string& n_unidad) {
    unidad = n_unidad;
}

void Elemento::fijarCord_x( float n_cord_x) {
    cord_x = n_cord_x;
}

void Elemento::fijarCord_y( float n_cord_y) {
    cord_y = n_cord_y;
}
