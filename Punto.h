//
// Created by Ana on 13-Apr-26.
//

#ifndef ESTRUCTURAS_CURIOSITY_PUNTO_H
#define ESTRUCTURAS_CURIOSITY_PUNTO_H

template<class T>
class Punto
{
    private:
    T valorX;
    T valorY;

    public:
    Punto(T x, T y);
    T obtenerX();
    T obtenerY();
    void fijarX(val T);
    void fijarY(val T);
};



#endif //ESTRUCTURAS_CURIOSITY_PUNTO_H