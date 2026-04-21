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
    inline Elemento(string &nTipo, double &nTamano, string &nUnidad, float &nCoordX, float &nCoordY);
    inline ~Elemento();
    //getters
    inline string& obtenerTipo();
    inline double& obtenerTamano();
    inline string& obtenerUnidad();
    inline float& obtenerCoordX();
    inline float& obtenerCoordY();
    //setters
    inline void fijarTipo(string &nTipo);
    inline void fijarTamano(double &nTamano);
    inline void fijarUnidad(string &nUnidad);
    inline void fijarCoordX(float &nCoordX);
    inline void fijarCoordY(float &nCoordY);
};

#include "Elemento.hxx"

#endif //PROYECTOCURIOSITY_ELEMENTO_H
