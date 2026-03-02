#ifndef ENTREGA_0_1_FUNCIONES_CONSOLA_H
#define ENTREGA_0_1_FUNCIONES_CONSOLA_H

#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

void funcionInicio();
void funcionAyuda();

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

void funcionalidades(int opcion, vector<string> argumentos);

vector<string> obtenerArgumentos(const string& entrada);
bool verificador(string cadena, int opcion);

#endif //ENTREGA_0_1_FUNCIONES_CONSOLA_H

