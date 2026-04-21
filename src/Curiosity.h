#ifndef ENTREGA_0_1_FUNCIONES_CONSOLA_H
#define ENTREGA_0_1_FUNCIONES_CONSOLA_H

#include <vector>
#include <string>
#include <queue>
#include "Elementos/Elemento.h"
#include "Comandos/Comando.h"
#include "Utilites/Utilities.h"

using namespace std;

class Curiosity {
protected:
    vector<Elemento*>* elementos;
    queue<Comando*>* comandos;
public:
    inline Curiosity();
    inline ~Curiosity();
    inline vector<Elemento*>* obtenerElementos();
    inline void fijarElementos(vector<Elemento*>* elementos);
    inline queue<Comando*>* obtenerComandos();
    inline void fijarComandos(queue<Comando*>* comandos);

    inline void agregarMovimiento(vector<string>* args);
    inline void agregarAnalisis(vector<string>* args, string comentario);
    inline void limpiarComandos();

    inline void cargar_comandos(vector<string>* args);
    inline void cargar_elementos(vector<string>* args);
    inline void agregar_movimiento(vector<string>* args, bool imprimir);
    inline void agregar_analisis(vector<string>* args, bool imprimir);
    inline void agregar_elemento(vector<string>* args, bool imprimir);
    inline void guardar(vector<string>* args);
    inline void simular_comandos(vector<string>* args);
    inline void ubicar_elementos();
    inline void en_cuadrante(vector<string>* args);
    inline void crear_mapa(vector<string>* args);
    inline void ruta_mas_larga();
};

#include "Curiosity.hxx"

#endif //ENTREGA_0_1_FUNCIONES_CONSOLA_H

