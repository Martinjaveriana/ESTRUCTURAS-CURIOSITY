#include <string>

inline CMovimiento::CMovimiento(string &nTipoMovimiento, float &nMagnitud, string &nUnidad) {
    Comando::tipoAccion = nTipoMovimiento;
    this->magnitud = nMagnitud;
    this->unidad = nUnidad;
}

inline CMovimiento::~CMovimiento() = default;

inline string& CMovimiento::obtenerTipoMovimiento(){
    return Comando::tipoAccion;
}

inline void CMovimiento::fijarTipoMovimiento(string &nTipoMovimiento) {
    Comando::tipoAccion = nTipoMovimiento;
}

inline float& CMovimiento::obtenerMagnitud() {
    return this->magnitud;
}

inline void CMovimiento::fijarMagnitud(float &nMagnitud) {
    this->magnitud = nMagnitud;
}

inline string& CMovimiento::obtenerUnidad(){
    return this->unidad;
}

inline void CMovimiento::fijarUnidad(string &nUnidad) {
    this->unidad = nUnidad;
}