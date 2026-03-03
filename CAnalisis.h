//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_CANALISIS_H
#define INTERFAZ_DE_USUARIO_CANALISIS_H
#include <string>


class CAnalisis {
protected:
    string tipo_analisis;
    string objeto;
    string comentario;
public:
    CAnalisis(string nTipoAn, string nObj, string nCom);
    string obTipoAn();
    void fijTipoAn(string nTipoAn);
    string obObj();
    void fijObj(string nObj);
    string obCom();
    void fijCom(string nCom);
};


#endif //INTERFAZ_DE_USUARIO_CANALISIS_H