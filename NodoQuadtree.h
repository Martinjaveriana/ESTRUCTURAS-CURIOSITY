//
// Created by martin-sanmiguel on 4/13/26.
//

#ifndef ESTRUCTURAS_CURIOSITY_NODOQUADTREEPUNTOS_H
#define ESTRUCTURAS_CURIOSITY_NODOQUADTREEPUNTOS_H

#include <list>
#include "Punto.h
using namespace std;


template <class T>
class NodoQuadtree {
 protected:
    T datoPadre;
    T datoNW;
    T datoNE;
    T datoSW;
    T datoSE;

 public:
    NodoQuadtree();
    ~NodoQuadtree();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarHijos();
    void adicionarDesc(T& val);
    bool eliminarDesc(T& val);
    bool esHoja();
    int altura();
    int inOrden();
    list<NodoQuadtree<T>*>& obtenerDesc();

};



#endif //ESTRUCTURAS_CURIOSITY_NODOQUADTREE_H
