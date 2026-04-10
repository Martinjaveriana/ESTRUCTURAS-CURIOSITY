//
// Created by martin-sanmiguel on 3/3/26.
//
#include "Comando.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

//constructor vacio, se inicializan los vectores solos
Comando::Comando() {
}

//Getters

    const vector<CAnalisis>& Comando::obComAn() const{
		return comandos_analisis;
	}
	const vector<CMovimiento>& Comando::obComMov() const{
		return comandos_movimiento;
	}

    //Setters

	void Comando::set_CAnalisis(const vector<CAnalisis>& comandos_an_n){
		comandos_analisis = comandos_an_n;
	}

	void Comando::set_CMovimiento(const vector<CMovimiento>& comandos_mo_n){
		comandos_movimiento = comandos_mo_n;
	}

	void Comando::agregarAnalisis(const vector<string>& args, string comentario) {
    	comandos_analisis.push_back( CAnalisis( args[1], args[2], comentario ) );
	}

	void Comando::agregarMovimiento(const vector<string>& args) {
		comandos_movimiento.push_back( CMovimiento(args[1], stof(args[2]), args[3]) );
	}

    void Comando::limpiarAnalisis() {
    comandos_analisis.clear();
    }

    void Comando::limpiarMovimiento() {
    comandos_movimiento.clear();
    }
