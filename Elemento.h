//
// Created by ago on 13/04/26.
//

#ifndef PROYECTOCURIOSITY_ELEMENTO_H
#define PROYECTOCURIOSITY_ELEMENTO_H

#include <string>

using namespace std;

class Elemento {
private:
    string tipo; //roca, crater, etc
    double tamano; //12, 13.21, 1
    string unidad; //cm, dm, m, km
    float coordX; //12, 13.21, 1
    float coordY; //12, 13.21, 1

public:
    //contructor
    Elemento();
    Elemento(string &nTipo, double &nTamano, string &nUnidad, float &nCoordX, float &nCoordY);
    ~Elemento();
    //getters
    string& obtenerTipo();
    double& obtenerTamano();
    string& obtenerUnidad();
    float& obtenerCoordX();
    float& obtenerCoordY();
    //setters
    void fijarTipo(string &nTipo);
    void fijarTamano(double &nTamano);
    void fijarUnidad(string &nUnidad);
    void fijarCoordX(float &nCoordX);
    void fijarCoordY(float &nCoordY);
    //operadores
    bool operator==(const Elemento& otro) const {
        return this->coordX == otro.coordX && this->coordY == otro.coordY
        && this->tamano == otro.tamano && this->unidad == otro.unidad
        && this->tipo == otro.tipo;
    }
    bool operator!=(const Elemento& otro) const {
        return this->coordX != otro.coordX || this->coordY != otro.coordY
        || this->tamano != otro.tamano || this->unidad != otro.unidad
        || this->tipo != otro.tipo;
    }
    //Operacion
    float distancia(Elemento &e1);
    void imprimirElemento();
};

#include "Elemento.hxx"

#endif //PROYECTOCURIOSITY_ELEMENTO_H
