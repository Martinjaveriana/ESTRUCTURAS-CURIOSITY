//
// Created by ago on 21/04/26.
//

#include "NodoKD.h"

using namespace std;

inline NodoKD::NodoKD() : elemento() {
    this->hijoDer = nullptr;
    this->hijoIzq = nullptr;
}

inline NodoKD::NodoKD(Elemento &val)
{
    this->elemento = val;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

inline NodoKD::~NodoKD()
= default;

inline Elemento& NodoKD::obtenerElemento()
{
    return this->elemento;
}

inline void NodoKD::fijarElemento(Elemento& val)
{
    this->elemento = val;
}

inline NodoKD* NodoKD::obtenerHijoIzq()
{
    return this->hijoIzq;
}

inline NodoKD* NodoKD::obtenerHijoDer()
{
    return this->hijoDer;
}

inline void NodoKD::fijarHijoIzq(NodoKD *hijo)
{
    this->hijoIzq = hijo;
}

inline void NodoKD::fijarHijoDer(NodoKD *hijo)
{
    this->hijoDer = hijo;
}

inline bool NodoKD::esHoja() {
    if (this->hijoIzq == nullptr && this->hijoDer == nullptr) return true;
    return false;
}