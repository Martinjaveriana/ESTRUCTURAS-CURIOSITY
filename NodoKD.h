//
// Created by ago on 21/04/26.
//

#ifndef PROYECTOCURIOSITY_NODOKD_H
#define PROYECTOCURIOSITY_NODOKD_H

#include "Elemento.h"

class NodoKD {
protected:
    Elemento elemento;
    NodoKD* hijoIzq;
    NodoKD* hijoDer;
public:
    inline NodoKD();
    inline NodoKD(Elemento &val);
    inline ~NodoKD();
    inline Elemento& obtenerElemento();
    inline void fijarElemento(Elemento &val);
    inline NodoKD* obtenerHijoIzq();
    inline NodoKD* obtenerHijoDer();
    inline void fijarHijoIzq(NodoKD *hijo);
    inline void fijarHijoDer(NodoKD *hijo);
    inline bool esHoja();
};

#include "NodoKD.hxx"

#endif //PROYECTOCURIOSITY_NODOKD_H
