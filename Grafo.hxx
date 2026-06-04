//
// Created by ago on 6/05/26.
//

#include "Grafo.h"

using namespace std;

template <class V, class C>
// lo dio gemini
struct MenorPorSegundo {
    bool operator()(const pair<V, C>& a, const pair<V, C>& b) {
        return a.second < b.second;
    }
};

template <class V, class C>
Grafo<V, C>::Grafo() {
    this->vertices = new vector<V>;
    this->aristas = new list< list <pair<int,C> >* >;
}

template <class V, class C>
Grafo<V, C>::~Grafo() = default;

template <class V, class C>
vector<V>& Grafo<V, C>::getVertices() {
    return *this->vertices;
}

template <class V, class C>
list< list< pair<int,C > >* >& Grafo<V, C>::getAristas() {
    return *this->aristas;
}

template <class V, class C>
int Grafo<V, C>::cantidadVertices() {
    return this->vertices->size();
}

template <class V, class C>
int Grafo<V, C>::cantidadAristas() {
    edgesIterator it;
    int cantidad = 0;

    for (it = this->aristas->begin(); it != this->aristas->end(); ++it) {
        cantidad += (*it)->size();
    }

    return cantidad;
}

template <class V, class C>
int Grafo<V, C>::buscarVertice(V vertice) {
    int indice = 0;

    for (V v : *this->vertices) {
        if (v == vertice) return indice;
        indice ++;
    }

    return -1;
}

template <class V, class C>
void Grafo<V, C>::insertarVertice(V vertice) {
    if (this->buscarVertice(vertice) == -1) {
        this->vertices->push_back(vertice);
        list< pair<int,C> >* nLista = new list <pair<int,C> >;
        this->aristas->push_back(nLista);
    }
}

template <class V, class C>
void Grafo<V, C>::insertarArista(V vOri, V vDes, C cost) {
    // obtiene el indice de cada vertice
    int iOri = this->buscarVertice(vOri), iDes = this->buscarVertice(vDes);

    // declara el iterador para recorrer la lista del vector de origen
    edgesIterator vecOri;
    vecOri = this->aristas->begin();
    advance(vecOri, iOri);

    // 1. Verificar que el vértice origen y el vértice destino están en el grafo (buscar vértice).
    if (iOri != -1 && iDes != -1) {
        //2. Con el índice del vértice origen, extraer la lista correspondiente.
        list< pair<int,C> >* verOri = *vecOri;

        //3. Verificar que el vértice destino no está en la lista de aristas del vertice origen.
        bool des = false;
        for (pair<int,C> ari : *verOri) {
            if (iDes == ari.first) des = true;
        }

        //4. Agregar un nuevo par a la lista, el par tiene el índice del vértice destino y el costo de la conexión.
        if (!des) {
            pair<int,C> n;
            n.first = iDes;
            n.second = cost;
            verOri->push_back(n);
        }
    }
}

template <class V, class C>
C Grafo<V, C>::buscarArista(V vOri, V vDes) {
    // obtiene el indice de cada vertice
    int iOri = this->buscarVertice(vOri), iDes = this->buscarVertice(vDes);

    // declara el iterador para recorrer la lista del vector de origen
    edgesIterator vecOri;
    vecOri = this->aristas->begin();
    advance(vecOri, iOri);

    // 1. Verificar que el vértice origen y el vértice destino están en el grafo (buscar vértice).
    if (iOri != -1 && iDes != -1) {
        //2. Con el índice del vértice origen, extraer la lista correspondiente.
        list< pair<int,C> >* verOri = *vecOri;

        //3. Verificar que el vértice destino está en la lista de aristas del vertice origen.
        bool dest = false;
        pair<int,C> verticeDestino;
        for (pair<int,C> ari : *verOri) {
            if (iDes == ari.first) {
                dest = true;
                verticeDestino = ari;
            }
        }

        //4. Devuelve el costo de la arista
        if (dest) return verticeDestino.second;
    }

    return -1;
}

template <class V, class C>
bool Grafo<V, C>::eliminarVertice(V vertice) {
    // obtiene el indice del vertice a eliminar
    int iVerAEliminar = this->buscarVertice(vertice);

    if (iVerAEliminar != -1) {
        // declara el iterador de la lista del vector de origen
        edgesIterator aristasVerE;
        aristasVerE = this->aristas->begin();
        advance(aristasVerE, iVerAEliminar);

        verticesIterator verticeAEliminar;
        verticeAEliminar = this->vertices->begin() + iVerAEliminar;

        // declara el iterador para recorrer la lista de aristas
        edgesIterator multiIt;
        vectorEdgesIterator ariIt;

        for (multiIt = this->aristas->begin(); multiIt != this->aristas->end(); ++multiIt) {
            for (ariIt = (*multiIt)->begin(); ariIt != (*multiIt)->end(); ++ariIt) {
                if (ariIt->first == iVerAEliminar) (*multiIt)->erase(ariIt);
            }
        }

        this->aristas->erase(aristasVerE);
        this->vertices->erase(verticeAEliminar);

        return true;
    }

    return false;
}

template <class V, class C>
bool Grafo<V, C>::eliminarArista(V vOri, V vDes) {
    // obtiene el indice de cada vertice
    int iOri = this->buscarVertice(vOri), iDes = this->buscarVertice(vDes);

    // declara el iterador para recorrer la lista del vector de origen
    edgesIterator aristasVerOri;
    aristasVerOri = this->aristas->begin();
    advance(aristasVerOri, iOri);

    // 1. Verificar que el vértice origen y el vértice destino están en el grafo (buscar vértice).
    if (iOri != -1 && iDes != -1) {
        //2. Con el índice del vértice origen, extraer la lista correspondiente.
        list< pair<int,C> >* verOri = *aristasVerOri;

        vectorEdgesIterator ariIt;
        //3. Verificar que el vértice destino está en la lista de aristas del vertice origen.
        for (ariIt = (*aristasVerOri)->begin(); ariIt != (*aristasVerOri)->end(); ++ariIt) {
            if (iDes == ariIt->first) {
                verOri->erase(ariIt);
                return true;
            }
        }

        return false;
    }

    return false;
}

template <class V, class C>
vector<V> Grafo<V, C>::recorridoPlano() {
    return this->getVertices();
}

template <class V, class C>
vector<V> Grafo<V, C>::recorridoDFS(V vertice) {      //recorrido Depth-first search
    vector<V> verVisit = vector<V>();
    //marco vertice como visitado
    verVisit.push_back(vertice);

    int iVerOriDFS = this->buscarVertice(vertice);

    edgesIterator ariIt;
    ariIt = this->aristas->begin();
    advance(ariIt, iVerOriDFS);

    vectorEdgesIterator vecAriIt;

    for (vecAriIt = (*ariIt)->begin(); vecAriIt != (*ariIt)->end(); ++vecAriIt) {
        V verW = this->vertices->at(vecAriIt->first);

        //si el vertice *vecAriIt no ha sido visitado
        if (!this->aristaVisitada(verVisit, verW)) {
            this->recorridoDFS(verVisit, verW);
        }
    }

    return verVisit;
}

template <class V, class C>
void Grafo<V, C>::recorridoDFS(vector<V>& verVisit, V& vertice) {
    //marco vertice como visitado
    verVisit.push_back(vertice);

    int iVerOriDFS = this->buscarVertice(vertice);

    edgesIterator ariIt;
    ariIt = this->aristas->begin();
    advance(ariIt, iVerOriDFS);

    vectorEdgesIterator vecAriIt;

    for (vecAriIt = (*ariIt)->begin(); vecAriIt != (*ariIt)->end(); ++vecAriIt) {
        V verW = this->vertices->at(vecAriIt->first);

        //si el vertice *vecAriIt no ha sido visitado
        if (!this->aristaVisitada(verVisit, verW)) {
            this->recorridoDFS(verVisit, verW);
        }
    }
}

template <class V, class C>
vector<V> Grafo<V, C>::recorridoBFS(V vertice) {
    vector<V> verVisit = vector<V>();

    queue<V> cola;
    cola.push(vertice);

    while (!cola.empty()) {
        vertice = cola.front();
        cola.pop();

        if (!this->aristaVisitada(verVisit, vertice)) {
            verVisit.push_back(vertice);

            int iVerOriBFS = this->buscarVertice(vertice);

            edgesIterator ariIt;
            ariIt = this->aristas->begin();
            advance(ariIt, iVerOriBFS);

            vectorEdgesIterator vecAriIt;

            for (vecAriIt = (*ariIt)->begin(); vecAriIt != (*ariIt)->end(); ++vecAriIt) {
                V verW = this->vertices->at(vecAriIt->first);
                cola.push(verW);
            }
        }
    }

    return verVisit;
}

template <class V, class C>
bool Grafo<V, C>::aristaVisitada(vector<V>& visitados, V& vertice) {
    for (V visit : visitados) {
        if (visit == vertice) return true;
    }

    return false;
}

template <class V, class C>
pair<vector<V>,vector<C>> Grafo<V, C>::dijkstra(int indiceVerticeInicio) {
    vector<C> distanciaVer;
    vector<V> predecesores, visitados;
    vector<int> cola;

    predecesores.resize(this->vertices->size());
    distanciaVer.resize(this->vertices->size());
    cola.resize(this->vertices->size());

    //INICIALIZACION
    //la distancia del primer vertice es 0
    distanciaVer.at(indiceVerticeInicio) = 0;
    cola.at(indiceVerticeInicio) = indiceVerticeInicio;

    //la distancia del resto de los vertices es infinito y se añaden todos los vertices a la cola
    for (int i = 0; i < this->cantidadVertices(); i++) {
        if (i != indiceVerticeInicio) {
            distanciaVer.at(i) = INFINITO();
            cola.at(i) = i;
        }
    }

    //el predecesor del primer vertice es el mismo
    predecesores.at(indiceVerticeInicio) = this->vertices->at(indiceVerticeInicio);

    //INICIO DEL ALGORITMO
    for (int i = 0; i < cola.size(); i++) {
        int iU = this->menorCola(cola, distanciaVer);
        V u = this->vertices->at(iU);

        visitados.push_back(u);
        cola.at(iU) = -1;

        edgesIterator ariIt;
        ariIt = this->aristas->begin();
        advance(ariIt, iU);

        vectorEdgesIterator v;

        for (v = (*ariIt)->begin(); v != (*ariIt)->end(); ++v) {
            C nuevaDistancia = distanciaVer.at(iU) + v->second;
            if (distanciaVer.at(v->first) > nuevaDistancia) {
                distanciaVer.at(v->first) = nuevaDistancia;
                predecesores.at(v->first) = u;
            }
        }
    }

    return {predecesores,distanciaVer};
}

template <class V, class C>
int Grafo<V, C>::menorCola(vector<int>& cola, vector<C>& distanciaVer) {
    C costoMenor = 0;
    int iCostoMenor = -1;

    for (int i : cola) {
        if (i != -1) {
            costoMenor = distanciaVer.at(i);
            iCostoMenor = i;
            break;
        }
    }

    for (int iVerAEvaluar : cola) {
        if (iVerAEvaluar != -1) {
            if (distanciaVer.at(iVerAEvaluar) < costoMenor) {
                costoMenor = distanciaVer.at(iVerAEvaluar);
                iCostoMenor = iVerAEvaluar;
            }
        }
    }

    return iCostoMenor;
}

template <class V, class C>
bool Grafo<V, C>::vacio() {
    if (this->vertices->empty()) return true;
    else return false;
}
