//
// Created by martin-sanmiguel on 3/3/26.
//

#include "CMovimiento.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

CMovimiento::CMovimiento(string nTipoMov, float nMag, string nUni) {
    tipo_mov = nTipoMov;
    mag = nMag;
    unidad = nUni;
}

const string& CMovimiento::obTipoMov() const {
    return tipo_mov;
}

void CMovimiento::fijTipoMov(const string& nTipoMov) {
    tipo_mov = nTipoMov;
}

float CMovimiento::obMag() const{
    return mag;
}

void CMovimiento::fijMag(float nMag) {
    mag = nMag;
}

const string& CMovimiento::obUni() const{
    return unidad;
}

void CMovimiento::fijUni(const string& nUni) {
    unidad = nUni;
}