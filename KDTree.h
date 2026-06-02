//
// Created by ago on 21/04/26.
//

#ifndef PROYECTOCURIOSITY_KDTREE_H
#define PROYECTOCURIOSITY_KDTREE_H

#include "NodoKD.h"
#include "Elemento.h"

class KDTree {
protected:
    NodoKD* raiz;
public:
    inline KDTree();
    inline ~KDTree();
    inline bool esVacio();
    inline Elemento& obDatoRaiz();
    inline int altura();
    inline int altura(NodoKD *nodo);
    inline int tamano();
    inline int tamano(NodoKD *nodo);
    inline bool insertarNodo(Elemento &val);
    inline bool eliminarNodo(Elemento &val);
    inline NodoKD* buscarNodo(Elemento &val);
    inline std::vector<Elemento>* preOrden();
    inline void preOrden(NodoKD *nodo, std::vector<Elemento> &valores);
    inline std::vector<Elemento>* inOrden();
    inline void inOrden(NodoKD *nodo, std::vector<Elemento> &valores);
    inline std::vector<Elemento>* posOrden();
    inline void posOrden(NodoKD *nodo, std::vector<Elemento> &valores);
    inline std::vector<Elemento>* nivelOrden();

    inline NodoKD* encontrarPadreMayor(NodoKD *nodo);
    inline std::vector<Elemento>* enCuadrante(float x1, float y1, float x2, float y2);
    inline void enCuadrante(NodoKD* nodo, std::vector<Elemento>& elementos, float x1, float y1, float x2, float y2, int profundidad);
    inline void clear();
};

#include "KDTree.hxx"

#endif //PROYECTOCURIOSITY_KDTREE_H