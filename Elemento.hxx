#include <cmath>
using namespace std;

Elemento::Elemento() {
    this->tipo = "";
    this->tamano = 0.0;
    this->unidad = "";
    this->coordX = 0.0;
    this->coordY = 0.0;
}

Elemento::Elemento(string& nTipo, double& nTamano, string& nUnidad, float& nCoordX, float& nCoordY) {
    this->tipo = nTipo;
    this->tamano = nTamano;
    this->unidad = nUnidad;
    this->coordX = nCoordX;
    this->coordY = nCoordY;
}

Elemento::~Elemento() = default;

string& Elemento::obtenerTipo() {
    return this->tipo;
}

double& Elemento::obtenerTamano() {
    return this->tamano;
}

string& Elemento::obtenerUnidad() {
    return this->unidad;
}

float& Elemento::obtenerCoordX() {
    return this->coordX;
}

float& Elemento::obtenerCoordY() {
    return this->coordY;
}

void Elemento::fijarTipo(string &nTipo) {
    this->tipo = nTipo;
}

void Elemento::fijarTamano(double &nTamano) {
    this->tamano = nTamano;
}

void Elemento::fijarUnidad(string &nUnidad) {
    this->unidad = nUnidad;
}

void Elemento::fijarCoordX(float &nCoordX) {
    this->coordX = nCoordX;
}

void Elemento::fijarCoordY(float &nCoordY) {
    this->coordY = nCoordY;
}

float Elemento::distancia(Elemento &e1) {
    float x = coordX - e1.coordX;
    float y = coordY - e1.coordY;
    return( std::sqrt( ( x * x ) + ( y * y ) ) );
}

inline void Elemento::imprimirElemento() {
    cout << "tipo: " << this->obtenerTipo() << "\ttamaño: " << this->obtenerTamano()
        << "\tunidad: " << this->obtenerUnidad() << "\tcoordenada x:" << this->obtenerCoordX()
        << "\tcoordenada y: " << this->obtenerCoordY() << endl;
}
