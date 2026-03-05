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

    vector<CAnalisis> Comando::get_CAnalisis(){
		return vector<CAnalisis>();
	}
	vector<CMovimiento> Comando::get_Movimientos(){
		return vector<CMovimiento>();
	}

    //Setters

	void Comando::set_CAnalisis(vector<CAnalisis> comandos_an_n){
		comandos_analisis = comandos_an_n;
	}

	void Comando::set_CMovimiento(vector<CMovimiento> comandos_mo_n){
		comandos_movimiento = comandos_mo_n;
	}

	//Metodos

	void Comando::agregar_analisis(vector<string>& args) {
    if (args.size() >= 3) {
        bool verAna = true, verCom = true;

        if (args[1] != "fotografiar" && args[1] != "composicion" && args[1] != "perforar") verAna = false;
		if (args.size()>3 && !verificador(args[3], 2) && !verificador(args[args.size()-1],3)) verCom = false;

        if (!verAna || !verCom) {
            cout << "La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)" << endl;
        } else {
			if(args.size() >= 4) {comandos_analisis.push_back(CAnalisis(args[1], args[2], comentario(args)));}
			else {comandos_analisis.push_back(CAnalisis(args[1], args[2], "sin comentario"));}
			cout << "El comando de analisis ha sido agregado exitosamente" << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        cout << "\nSyntaxis del comando: agregar_analisis <tipo_analisis> <objeto> <comentario>" << endl;
    	cout << "\n- Descripcion: Agrega el comando de analisis. Tipos: fotografiar, composicion, perforar." << endl;
    	cout << "- El comentario es opcional y debe estar encerrado entre comillas simples ''\n" << endl;
    		}
	}

	bool Comando::verificador(const string& cadena, int opcion) {
    switch (opcion) {
        case 1: { regex patron("^-?\\d+(\\.\\d+)?$"); return regex_match(cadena, patron); }
        case 2: { regex patron("'.*");                return regex_match(cadena, patron); }
        case 3: { regex patron(".*'");                return regex_match(cadena, patron); }
    }
    return false;
	}

	string Comando::comentario(const vector<string>& args){
		string temp = "";
		for(int i = 3; i < args.size(); i ++) {
			temp = temp + args[i] + " ";
		}
		return temp;
	}
