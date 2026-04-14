//
// Created by Ana on 13-Apr-26.
//

#include "Punto.h"

using namespace std;

Punto::Punto(T x, T y){
    this.valorx = x;
    this.valory = y;
}

template <class T>
T Punto::obtenerX(){
    return this->valorX;
}

template <class T>
T Punto::obtenerY(){
    return this->valorY;
}

template <class T>
void  Punto::fijarX(T val){
    this->valorX = val;
}

template <class T>
void Punto<T>::fijarY(T val){
    this->valorY = val;
}