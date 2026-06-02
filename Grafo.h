#ifndef GRAFO_H
#define GRAFO_H

// V = Punto
// C = float

#define INFINITO std::numeric_limits<C>::max()
#define NOCONECTADO -1

template <class V, class C>
class Grafo {
private:
    // Guardamos los vértices reales (las coordenadas), generando una
    // lista de los vertices que hay
    std::vector<V> vertices;

    // Nuestra matriz de adyacencia de costos
    std::vector<std::vector<C>> matriz;

public:
    // Constructor
    Grafo();

    // TODO # 3: Insertar un vértice y hacer crecer la matriz
    void InsertarVertice(const V& vertice);

    // Método necesario para obtener un vértice y calcular su distancia (TODO # 4)
    V ObtenerVertice(int indice) const;

    // TODO # 4: Insertar la arista con su costo
    void InsertarArista(int origen, int destino, C costo);

    // TODO # 5 y # 7: Saber cuántos vértices hay para los bucles
    unsigned int NumeroVertices() const;

    // TODO # 7: Obtener el costo entre dos nodos para imprimir el informe
    C ObtenerCosto(int origen, int destino) const;

};

#include "Grafo.hxx"
#endif // GRAFO_H