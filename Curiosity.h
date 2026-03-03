//
// Curiosity.h
//

#ifndef CURIOSITY_H
#define CURIOSITY_H

#include <vector>
#include <string>

#include "Elemento.h"
#include "Comando.h"
#include "CAnalisis.h"
#include "CMovimiento.h"

using namespace std;
class Curiosity {

private:
    vector<Elemento> elementos_C;
    //vector<string> comandos;

public:
    Curiosity();

    // Metodo principal: el main solo llama este
    void procesar(const string& entrada);

private:

//getter y setters de las listas de elementos y comandos

    //comandos del doc
    void cargar_comandos(vector<string>& args);
    void cargar_elementos(vector<string>& args);
    void agregar_movimiento(vector<string>& args);
    void agregar_analisis(vector<string>& args);
    void agregar_elemento(vector<string>& args);
    void guardar(vector<string>& args);
    void simular_comandos(vector<string>& args);
    void ubicar_elementos();
    void en_cuadrante(vector<string>& args);
    void crear_mapa(vector<string>& args);
    void ruta_mas_larga();

    //ayudas
    void funcionAyuda();
    void ayudaA();
    void cargarComandosA();
    void cargarElementosA();
    void agregarMovimientoA();
    void agregarAnalisisA();
    void agregarElementoA();
    void guardarA();
    void simularComandosA();
    void ubicarElementoA();
    void enCuadranteA();
    void crearMapaA();
    void rutaMasLargaA();
    void salirA();

    //ayudas para interpretar comandos
    std::vector<std::string> obtenerArgumentos(const std::string& entrada);
    bool verificador(const std::string& cadena, int opcion);
};

#endif // CURIOSITY_H