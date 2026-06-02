#include <vector>
#include <limits>
#include <algorithm>


#include "Grafo.h"

template <class V, class C>

Grafo<V, C>::Grafo(){}

template <class V, class C>
// TODO # 3: Insertar un vértice y hacer crecer la matriz
void Grafo<V, C>::InsertarVertice(const V& vertice) {
    vertices.push_back(vertice);
    int n = vertices.size();

    // Redimensionamos la matriz para el nuevo tamaño n x n
    matriz.resize(n);
    for (int i = 0; i < n; ++i) {
        // Llenamos los espacios nuevos con -1 (indicando que no hay arista)
        matriz[i].resize(n, -1);
    }
}

template <class V, class C>
// Método necesario para obtener un vértice y calcular su distancia (TODO # 4)
V Grafo<V, C>::ObtenerVertice(int indice) const {
    return vertices[indice];
}

template <class V, class C>
// TODO # 4: Insertar la arista con su costo
void Grafo<V, C>::InsertarArista(int origen, int destino, C costo) {
    matriz[origen][destino] = costo;
}

template <class V, class C>
// TODO # 5 y # 7: Saber cuántos vértices hay para los bucles
unsigned int Grafo<V, C>::NumeroVertices() const {
    return vertices.size();
}

template <class V, class C>
// TODO # 7: Obtener el costo entre dos nodos para imprimir el informe
C Grafo<V, C>::ObtenerCosto(int origen, int destino) const {
    return matriz[origen][destino];
}