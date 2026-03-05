//
// Created by martin-sanmiguel on 3/3/26.
//

#include "CAnalisis.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

CAnalisis::CAnalisis(string nTipoAn, string nObj, string nCom) {
    tipo_analisis = nTipoAn;
    objeto = nObj;
    comentario = nCom;
}

string CAnalisis::obTipoAn() {
    return tipo_analisis;
}

void CAnalisis::fijTipoAn(string nTipoAn) {
    tipo_analisis = nTipoAn;
}

string CAnalisis::obObj() {
    return objeto;
}

void CAnalisis::fijObj(string nObj) {
    objeto = nObj;
}

string CAnalisis::obCom() {
    return comentario;
}

void CAnalisis::fijCom(string nCom) {
    comentario = nCom;
}