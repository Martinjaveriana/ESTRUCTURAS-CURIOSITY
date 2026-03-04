//
// Created by martin-sanmiguel on 3/3/26.
//

#include "CAnalisis.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

CAnalisis(string nTipoAn, string nObj, string nCom) {
    tipo_analisis = nTipoAn;
    objeto = nObj;
    comentario = nCom;
}

string obTipoAn() {
    return tipo_analisis;
}

void fijTipoAn(string nTipoAn) {
    tipo_analisis = nTipoAn;
}

string obObj() {
    return objeto;
}

void fijObj(string nObj) {
    objeto = nObj;
}

string obCom() {
    return comentario;
}

void fijCom(string nCom) {
    comentario = nCom;
}