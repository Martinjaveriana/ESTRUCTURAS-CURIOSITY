#ifndef ENTREGA_0_1_FUNCIONES_CONSOLA_H
#define ENTREGA_0_1_FUNCIONES_CONSOLA_H

#include <vector>
#include <string>
#include <queue>
#include "Elemento.h"
#include "KDTree.h"
#include "Comando.h"
#include "Utilities.h"
#include "Grafo.h"

using namespace std;

class Curiosity {
protected:
    vector<Elemento>* elementos;
    queue<Comando*>* comandos;
    KDTree* arbolElementos;
    Grafo<Elemento,float>* grafo;
public:
    Curiosity();
    ~Curiosity();
    vector<Elemento>& obtenerElementos();
    void fijarElementos(vector<Elemento>* elementos);
    queue<Comando*>& obtenerComandos();
    void fijarComandos(queue<Comando*>* comandos);
    KDTree& obtenerArbolElementos();
    void fijarArbolElementos(KDTree* tree);
    Grafo<Elemento,float>& obtenerGrafo();
    void fijarGrafo(Grafo<Elemento,float>* grafo);

    void agregarMovimiento(vector<string>& args);
    void agregarAnalisis(vector<string>& args, string comentario);
    void limpiarComandos();

    void cargar_comandos(vector<string>& args);
    void cargar_elementos(vector<string>& args);
    void agregar_movimiento(vector<string>& args, bool imprimir);
    void agregar_analisis(vector<string>& args, bool imprimir);
    void agregar_elemento(vector<string>& args, bool imprimir);
    void guardar(vector<string>& args);
    void simular_comandos(vector<string>& args);
    void ubicar_elementos();
    void en_cuadrante(vector<string>& args);
    void crear_mapa(vector<string>& args);
    void ruta_mas_larga();
};

#include "Curiosity.hxx"

#endif //ENTREGA_0_1_FUNCIONES_CONSOLA_H

