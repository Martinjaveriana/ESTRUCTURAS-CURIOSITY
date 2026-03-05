//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_CANALISIS_H
#define INTERFAZ_DE_USUARIO_CANALISIS_H
#include <string>

using namespace std;


class CAnalisis {
private:
    string tipo_analisis;
    string objeto;
    string comentario;
public:
    CAnalisis(string nTipoAn, string nObj, string nCom);
    const string& obTipoAn() const;
    void fijTipoAn(const string& nTipoAn);
    const string& obObj() const;
    void fijObj(const string& nObj);
    const string& obCom() const;
    void fijCom(const string& nCom);
};


#endif //INTERFAZ_DE_USUARIO_CANALISIS_H