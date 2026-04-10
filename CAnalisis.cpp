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

const string& CAnalisis::obTipoAn() const{
    return tipo_analisis;
}

void CAnalisis::fijTipoAn(const string& nTipoAn) {
    tipo_analisis = nTipoAn;
}

const string& CAnalisis::obObj() const {
    return objeto;
}

void CAnalisis::fijObj(const string& nObj) {
    objeto = nObj;
}

const string& CAnalisis::obCom() const{
    return comentario;
}

void CAnalisis::fijCom(const string& nCom) {
    comentario = nCom;
}