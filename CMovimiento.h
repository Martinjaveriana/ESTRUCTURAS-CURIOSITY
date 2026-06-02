#ifndef PROYECTOCURIOSITY_CMOVIMIENTO_H
#define PROYECTOCURIOSITY_CMOVIMIENTO_H

#include "Comando.h"

class CMovimiento : public Comando {
private:
    float magnitud;
    string unidad;
public:
    inline CMovimiento(string &nTipoMovimiento, float &nMagnitud, string &nUnidad);
    inline ~CMovimiento() override;
    inline string& obtenerTipoMovimiento();
    inline void fijarTipoMovimiento(string &nTipoMovimiento);
    inline float& obtenerMagnitud();
    inline void fijarMagnitud(float &nMagnitud);
    inline string& obtenerUnidad();
    inline void fijarUnidad(string &nUnidad);
};

#include "CMovimiento.hxx"

#endif //PROYECTOCURIOSITY_CMOVIMIENTO_H
