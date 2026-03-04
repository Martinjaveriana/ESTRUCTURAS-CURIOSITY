//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_COMANDOS_H
#define INTERFAZ_DE_USUARIO_COMANDOS_H

#include "CAnalisis.h"
#include "CMovimiento.h"
#include <queue>
#include <vector>

using namespace std;

class Comando{

    //PENDIENTE CAMBIAR LOS STRINGS POR LOS TIPOS DE DATO QUE SON :(

private:
    //queue<CAnalisis> comandos_analisis;
    //queue<CMovimiento> comandos_movimiento;

    vector<CAnalisis> comandos_analisis;
    vector<CMovimiento> comandos_movimiento;

public:
    //Contructor
	Comando();

    //Getters

    vector<CAnalisis> get_CAnalisis();
	vector<CMovimiento> get_Movimientos();

    //Setters

	void set_CAnalisis(vector<CAnalisis> comandos_an_n);
	void set_CMovimiento(vector<CMovimiento> comandos_mo_n);


    //void fijComAn(const queue<CAnalisis>& nComAn);
    //void fijComMov(const queue<CMovimiento>& nComMov);
};


#endif //INTERFAZ_DE_USUARIO_COMANDOS_H