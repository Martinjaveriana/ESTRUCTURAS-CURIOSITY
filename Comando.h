#ifndef PROYECTOCURIOSITY_COMANDO_H
#define PROYECTOCURIOSITY_COMANDO_H

#include <string>

using namespace std;

class Comando{
protected:
    string tipoAccion;
public:
    inline Comando();
    inline virtual ~Comando();
    inline void fijarTipoAccion(string &tipoAccion);
    inline string& obtenerTipoAccion();
};

#include "Comando.hxx"

#endif //PROYECTOCURIOSITY_COMANDO_H
