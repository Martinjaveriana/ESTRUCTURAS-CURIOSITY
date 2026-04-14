//
// Created by martin-sanmiguel on 4/13/26.
//

#include "ArbolQuadtree.h"
#include <queue>
#include <iostream>

using namespace std;


template <class T>
ArbolGeneral<T>::ArbolGeneral(){
    this->raiz = NULL;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T val){
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
}

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this->raiz;
    this->raiz = NULL;
}

template <class T>
bool ArbolGeneral<T>::esVacio(){
    return this->raiz == NULL;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz(){
    return this->raiz;
}

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz){
    this->raiz = nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarRec(NodoGeneral<T>* nodo, T padre, T n){
    if(nodo == NULL)
     return false;
    if(nodo->obtenerDato() == padre){
        nodo->adicionarDesc(n);
        return true;
    }
    typename std::list<NodoGeneral<T>*>::iterator it;
    for(it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
        if(insertarRec(*it, padre, n))
     return true;
    }
    return false;
}

template <class T>
std::list<NodoGeneral<T>*>& NodoGeneral<T>::obtenerDesc(){
    return this->desc;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    if(this->esVacio())
    return false;
    return insertarRec(this->raiz, padre, n);
}

template <class T>
bool ArbolGeneral<T>::eliminarRec(NodoGeneral<T>* nodo, T n){
    if(nodo == NULL)
    return false;
    typename std::list<NodoGeneral<T>*>::iterator it;
    for(it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
        if((*it)->obtenerDato() == n){
            nodo->eliminarDesc(n);
            return true;
        }
        if(eliminarRec(*it, n))
        return true;
    }
    return false;
}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
    if(this->esVacio()) return false;
    return eliminarRec(this->raiz, n);
}

template <class T>
bool ArbolGeneral<T>::buscarRec(NodoGeneral<T>* nodo, T n){
    if(nodo == NULL)
    return false;
    if(nodo->obtenerDato() == n)
    return true;
    typename std::list<NodoGeneral<T>*>::iterator it;
    for(it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
        if(buscarRec(*it, n))
        return true;
    }
    return false;
}

template <class T>
bool ArbolGeneral<T>::buscar(T n){
    if(this->esVacio())
    return false;
    return buscarRec(this->raiz, n);
}

template <class T>
int ArbolGeneral<T>::altura(){
    if(this->esVacio())
    return -1;
    return (this->raiz)->altura();
}

template <class T>
unsigned int ArbolGeneral<T>::tamanoRec(NodoGeneral<T>* nodo){
    if(nodo == NULL)
    return 0;
    unsigned int contador = 1;
    typename std::list<NodoGeneral<T>*>::iterator it;
    for(it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
        contador += tamanoRec(*it);
    }
    return contador;
}

template <class T>
unsigned int ArbolGeneral<T>::tamano(){
    if(this->esVacio())
    return 0;
    return tamanoRec(this->raiz);
}
