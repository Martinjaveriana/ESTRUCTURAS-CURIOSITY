//
// Created by martin-sanmiguel on 3/3/26.
//

#include "CMovimiento.h"
#include <string>

CMovimiento(string nTipoMov, float nMag, string nUni) {
    tipo_mov = nTipoMov;
    mag = nMag;
    unidad = nUni;
}

string obTipoMov() {
    return tipo_mov;
}

void fijTipoMov(string nTipoMov) {
    tipo_mov = nTipoMov;
}

float getMag() {
    return mag;
}

void fijMag(float nMag) {
    mag = nMag;
}

string getUni() {
    return unidad;
}

void fijUni(string nUni) {
    unidad = nUni;
}