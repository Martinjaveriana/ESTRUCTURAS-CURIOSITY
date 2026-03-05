//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_ELEMENTO_H
#define INTERFAZ_DE_USUARIO_ELEMENTO_H

using namespace std;
class Elemento {
private:
    string tipo_comp; //roca, crater, etc
    double tamano; //12, 13.21, 1
    string unidad; //cm, dm, m, km
    float cord_x; //12, 13.21, 1
    float cord_y; //12, 13.21, 1

public:
    //contructor
    Elemento(const string& n_tipo, double n_tamano, const string& n_unidad, float n_cord_x, float n_cord_y);

    //getters
    const string& obtenerTipo_comp() const;
    double obtenerTamano();
    const string& obtenerUnidad() const;
    float obtenerCord_x();
    float obtenerCord_y();

    //setters
    void fijarTipo_comp(const string& n_tipo);
    void fijarTamano(double n_tamano);
    void fijarUnidad(const string& n_unidad);
    void fijarCord_x(float n_cord_x);
    void fijarCord_y(float n_cord_y);
};


#endif //INTERFAZ_DE_USUARIO_ELEMENTO_H