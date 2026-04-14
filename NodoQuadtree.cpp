//
// Created by martin-sanmiguel on 4/13/26.
//

#include "NodoQuadtree.h"
#include "Punto.h"

using namespace std;

template <class T>
NodoQuadtree<T> NodoQuadtree(){
    this->desc.clear();
}

template <class T>
NodoQuadtree<T> ~NodoQuadtree(){
    T list<NodoQuadtree<T>*> iterator it;
    for(it = this->desc.begin(); it != this->desc.end(); it++){
        delete *it;
    }
    this->desc.clear();
}

template <class T>
    T& NodoQuadtree<T> obtenerDato(){
    return this->datoPadre;
}

template <class T>
void NodoQuadtree<T> fijarDato(T& val){
    this->datoPadre = val;
}

template <class T>
void NodoQuadtree<T> limpiarHijos(){
    this->datoNW.clear();
    this->datoNE.clear();
    this->datoSW.clear();
    this->datoSE.clear();
}

template <class T>
void NodoQuadtree<T>::adicionarDesc(T& val){
    NodoQuadtree<T>* nodo = new NodoQuadtree<T>;
    if(){

    }
    nodo->fijarDato(val);
    this->desc.push_back(nodo);
}

template <class T>
bool NodoQuadtree<T> eliminarDesc(T& val){
    T list<NodoQuadtree<T>*>::iterator it;
    NodoQuadtree<T>* aux;
    bool eliminado = false;

    for(it = this->desc.begin(); it != this->desc.end(); it++){
        aux = *it;
        if(aux->obtenerDato() == val)
            break;
    }
    if(it != this->desc.end()){
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }
    return eliminado;
}

template <class T>
bool NodoQuadtree<T> esHoja(){
    return this->desc.size() == 0;
}

template <class T>
int NodoQuadtree<T>::altura(){
    int alt = -1;
    if(this->esHoja()){
        alt = 0;
    } else {
        int alth;
        T list<NodoQuadtree<T>*>::iterator it;
        for(it = this->desc.begin(); it != this->desc.end(); it++){
            alth = (*it)->altura();
            if(alt < alth + 1)
                alt = alth + 1;
        }
    }
    return alt;
}

//falta impolementar
template <class T>
void NodoQuadtree<T> inOrden(){
    T std::list<NodoGeneral<T>*> iterator it;
    for(it = this->desc.begin(); it != this->desc.end(); it++){
        (*it)->posOrden();
    }
    std::cout << this->dato << " ";
}