//
// Created by martin-sanmiguel on 4/13/26.
//

#ifndef ESTRUCTURAS_CURIOSITY_QUADTREE_H
#define ESTRUCTURAS_CURIOSITY_QUADTREE_H

using namespace std;

template <class T>
class ArbolQuadtree {
    private:
    ArbolQuadtree* nodoRaiz;

    public:
    ArbolQuadtree();
    ArbolQuadtree(T val);
    ~ArbolQuadtree();
    bool esVacio();
    NodoQuadtree<T>* obtenerRaiz();
    void fijarRaiz(NodoQuadtree<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);
    int altura();
    unsigned int tamano();
    int inOrden();
};



#endif //ESTRUCTURAS_CURIOSITY_QUADTREE_H
