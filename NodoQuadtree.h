//
// Created by martin-sanmiguel on 4/13/26.
//

#ifndef ESTRUCTURAS_CURIOSITY_NODOQUADTREEPUNTOS_H
#define ESTRUCTURAS_CURIOSITY_NODOQUADTREEPUNTOS_H

using namespace std;


template <class T>
class NodoQuadtree {
    protected:
    T dato_NW;
    T dato_NE;
    T dato_SW;
    T dato_SE;
    list<NodoQuadtree<T>*> desc;
public:
    NodoQuadtree();
    ~NodoQuadtree();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& val);
    bool eliminarDesc(T& val);
    bool esHoja();
    int altura();
    int inOrden();
    list<NodoQuadtree<T>*>& obtenerDesc();

};



#endif //ESTRUCTURAS_CURIOSITY_NODOQUADTREEPUNTOS_H
