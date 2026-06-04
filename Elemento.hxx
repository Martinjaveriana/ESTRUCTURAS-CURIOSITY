#include <cmath>
using namespace std;

inline Elemento::Elemento() {
    this->tipo = "";
    this->tamano = 0.0;
    this->unidad = "";
    this->coordX = 0.0;
    this->coordY = 0.0;
}

inline Elemento::Elemento(string& nTipo, double& nTamano, string& nUnidad, float& nCoordX, float& nCoordY) {
    this->tipo = nTipo;
    this->tamano = nTamano;
    this->unidad = nUnidad;
    this->coordX = nCoordX;
    this->coordY = nCoordY;
}

inline Elemento::~Elemento() = default;

inline string& Elemento::obtenerTipo() {
    return this->tipo;
}

inline double& Elemento::obtenerTamano() {
    return this->tamano;
}

inline string& Elemento::obtenerUnidad() {
    return this->unidad;
}

inline float& Elemento::obtenerCoordX() {
    return this->coordX;
}

inline float& Elemento::obtenerCoordY() {
    return this->coordY;
}

inline void Elemento::fijarTipo(string &nTipo) {
    this->tipo = nTipo;
}

inline void Elemento::fijarTamano(double &nTamano) {
    this->tamano = nTamano;
}

inline void Elemento::fijarUnidad(string &nUnidad) {
    this->unidad = nUnidad;
}

inline void Elemento::fijarCoordX(float &nCoordX) {
    this->coordX = nCoordX;
}

inline void Elemento::fijarCoordY(float &nCoordY) {
    this->coordY = nCoordY;
}

inline float Elemento::distancia(Elemento &e1) {
    float x = coordX - e1.coordX;
    float y = coordY - e1.coordY;
    return( std::sqrt( ( x * x ) + ( y * y ) ) );
}