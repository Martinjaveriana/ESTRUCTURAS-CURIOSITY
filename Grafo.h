//
// Created by ago on 6/05/26.
//

#ifndef EJERCICIOS_DE_CLASE_GRAFO_H
#define EJERCICIOS_DE_CLASE_GRAFO_H
#define NOCONECTADO -1

#include <vector>
#include <list>
#include <utility>
#include <iterator>

template <class V, class C>
class Grafo {
private:
    std::vector<V>* vertices;
    std::list< std::list< std::pair<int,C > >* >* aristas;

    static C INFINITO() { return std::numeric_limits<C>::max(); }
    using edgesIterator = std::list< std::list <std::pair<int,C> >* >::iterator;
    using verticesIterator = std::vector<V>::iterator;
    using vectorEdgesIterator = std::list< std::pair<int,C> >::iterator;

    bool aristaVisitada(std::vector<V>& visitados, V& vertice);
    int menorCola(std::vector<int>& cola, std::vector<C>& distanciaVer);
public:
    Grafo();
    ~Grafo();
    std::vector<V>& getVertices();
    std::list< std::list< std::pair<int,C > >* >& getAristas();
    int cantidadVertices();
    int cantidadAristas();
    int buscarVertice(V vertice);
    C buscarArista(V vOri, V vDes);
    void insertarVertice(V vertice);
    void insertarArista(V vOri, V vDes, C cost);
    bool eliminarVertice(V vertice);
    bool eliminarArista(V vOri, V vDes);
    std::vector<V> recorridoPlano();
    std::vector<V> recorridoDFS(V vertice);
    void recorridoDFS(std::vector<V>& verVisit, V& vertice);
    std::vector<V> recorridoBFS(V vertice);
    std::pair<std::vector<V>,std::vector<C>> dijkstra(int indiceVerticeInicio);
    //en pair<int,int> el primero es el valor del vertice,
    //el segundo es el costo para llegar a el desde un vector en especifico, ej. u
    bool vacio();
    std::vector<V> construirCamino(V origen, V destino, std::vector<V> predecesores);
};

#include "Grafo.hxx"

#endif //EJERCICIOS_DE_CLASE_GRAFO_H
