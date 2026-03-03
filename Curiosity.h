//
// Curiosity.h
//

#ifndef CURIOSITY_H
#define CURIOSITY_H

#include <vector>
#include <string>

#include "Elemento.h"
// #include "Comando.h"

class Curiosity {

private:
    vector<std::Elemento> elementos_C;
    //std::vector<std::string> comandos;

public:
    Curiosity();

    // Metodo principal: el main solo llama este
    void procesar(const std::string& entrada);

private:

//getter y setters de las listas de elementos y comandos

    //comandos del doc
    void cargar_comandos(std::vector<std::string>& args);
    void cargar_elementos(std::vector<std::string>& args);
    void agregar_movimiento(std::vector<std::string>& args);
    void agregar_analisis(std::vector<std::string>& args);
    void agregar_elemento(std::vector<std::string>& args);
    void guardar(std::vector<std::string>& args);
    void simular_comandos(std::vector<std::string>& args);
    void ubicar_elementos();
    void en_cuadrante(std::vector<std::string>& args);
    void crear_mapa(std::vector<std::string>& args);
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