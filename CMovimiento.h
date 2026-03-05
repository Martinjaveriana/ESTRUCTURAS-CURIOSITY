//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_CMOVIMIENTO_H
#define INTERFAZ_DE_USUARIO_CMOVIMIENTO_H
#include <string>

using namespace std;

class CMovimiento {
private:
    string tipo_mov;
    float mag;
    string unidad;
public:
    CMovimiento(string nTipoMov, float nMag, string nUni);
    const string& obTipoMov() const;
    void fijTipoMov(const string& nTipoMov);
    float obMag() const;
    void fijMag(float nMag);
    const string& obUni() const;
    void fijUni(const string& nUni);
};


#endif //INTERFAZ_DE_USUARIO_CMOVIMIENTO_H