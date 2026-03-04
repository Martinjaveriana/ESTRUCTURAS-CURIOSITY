//
// Created by martin-sanmiguel on 3/3/26.
//

#include "CMovimiento.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

CMovimiento::CMovimiento(string nTipoMov, float nMag, string nUni) {
    tipo_mov = nTipoMov;
    mag = nMag;
    unidad = nUni;
}

string CMovimiento::obTipoMov() {
    return tipo_mov;
}

void CMovimiento::fijTipoMov(string nTipoMov) {
    tipo_mov = nTipoMov;
}

float CMovimiento::getMag() {
    return mag;
}

void CMovimiento::fijMag(float nMag) {
    mag = nMag;
}

string CMovimiento::getUni() {
    return unidad;
}

void CMovimiento::fijUni(string nUni) {
    unidad = nUni;
}