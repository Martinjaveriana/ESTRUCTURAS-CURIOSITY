//
// Created by martin-sanmiguel on 3/3/26.
//
#include "Comandos.h"
#include <vector>

using namespace std;

//constructor vacio, se inicializan los vectores solos
Comando::Comando() {
}

//Getters

    vector<CAnalisis> get_CAnalisis(){
		return vector<CAnalisis>();
	}
	vector<CMovimiento> get_Movimientos(){
		return vector<CMovimiento>();
	}

    //Setters

	void set_CAnalisis(vector<CAnalisis> comandos_an_n){
		comandos_analisis = comandos_an_n;
	}

	void set_CMovimiento(vector<CMovimiento> comandos_mo_n){
		comandos_movimiento = comandos_mo_n;
	}
