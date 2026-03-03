//
// Curiosity.h
//

#ifndef CURIOSITY_H
#define CURIOSITY_H

#include <vector>
#include <string>

// TODO: cuando esten listas, reemplazar por:
// #include "Elemento.h"
// #include "Comando.h"

class Curiosity {

private:
    std::vector<std::string> elementos; // TODO: vector<Elemento>
    std::vector<std::string> comandos;  // TODO: vector<Comando>

public:
    // --- Constructor ---
    Curiosity();

    // --- Metodo principal: recibe el input del main y lo despacha todo ---
    void procesar(const std::string& entrada);

private:
    // --- Comandos principales ---
    void cargar_comandos(const std::string& nombre_archivo);
    void cargar_elementos(const std::string& nombre_archivo);
    void agregar_movimiento(const std::string& tipo, const std::string& magnitud, const std::string& unidad);
    void agregar_analisis(const std::string& tipo, const std::string& objeto, const std::string& comentario);
    void agregar_elemento(const std::string& tipo, const std::string& tamanio, const std::string& unidad, const std::string& coordX, const std::string& coordY);
    void guardar(const std::string& tipo, const std::string& nombre_archivo);
    void simular_comandos(const std::string& coordX, const std::string& coordY);
    void ubicar_elementos();
    void en_cuadrante(const std::string& xMin, const std::string& xMax, const std::string& yMin, const std::string& yMax);
    void crear_mapa(const std::string& coeficiente);
    void ruta_mas_larga();

    // --- Mensajes de ayuda ---
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

    // --- Utilidades internas ---
    std::vector<std::string> obtenerArgumentos(const std::string& entrada);
    bool verificador(const std::string& cadena, int opcion);
};

#endif // CURIOSITY_H