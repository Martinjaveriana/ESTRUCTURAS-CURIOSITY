//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_ELEMENTO_H
#define INTERFAZ_DE_USUARIO_ELEMENTO_H


class Elemento {
    private:
    std::string tipo_comp; //roca, crater, etc
    double tamano; //12, 13.21, 1
    std::string unidad_med; //cm, dm, m, km
    float cord_x; //12, 13.21, 1
    float cord_y; //12, 13.21, 1

    public:
    //contructor
    Elemento(std::string n_tipo, double n_tamano, std::string n_unidad_medida, float n_cord_x, float n_cord_y);

    //getters
    std::string obtenerTipo_comp();
    double obtenerTamano();
    std::string obtenerUnidad_med();
    float obtenerCord_x();
    float obtenerCord_y();

    //setters
    void fijarTipo_comp(std::string n_tipo);
    void fijarTamano(double n_tamano);
    void fijarUnidad_med(std::string n_unidad_medida);
    void fijarCord_x(float n_cord_x);
    void fijarCord_y(float n_cord_y);
};


#endif //INTERFAZ_DE_USUARIO_ELEMENTO_H