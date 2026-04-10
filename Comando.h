//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_COMANDOS_H
#define INTERFAZ_DE_USUARIO_COMANDOS_H

#include "CAnalisis.h"
#include "CMovimiento.h"
#include "CAnalisis.h"
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
    const vector<CAnalisis>& obComAn() const;

	const vector<CMovimiento>& obComMov() const;

    //Setters
	void set_CAnalisis(const vector<CAnalisis>& comandos_an_n);
	void set_CMovimiento(const vector<CMovimiento>& comandos_mo_n);

	//Metodos
	void agregarAnalisis(const vector<string>& args, string comentario);
	void agregarMovimiento(const vector<string>& args);
    void limpiarAnalisis();
    void limpiarMovimiento();

    //void fijComAn(const queue<CAnalisis>& nComAn);
    //void fijComMov(const queue<CMovimiento>& nComMov);
};


#endif //INTERFAZ_DE_USUARIO_COMANDOS_H