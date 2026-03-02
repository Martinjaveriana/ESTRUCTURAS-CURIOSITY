#include "../../Include/Cabeceras/controladorUI.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    //funcionInicio();

    string args;
    bool ejecutando = true;

    while (ejecutando) {
        cout << "$ ";
        getline(cin, args);     //cout << "AAAAAAAA" << endl;

        if (args.empty()) continue;

        vector<string> argumentos = obtenerArgumentos(args);

        if (argumentos.size() == 1) {
            if (argumentos[0] == "ayuda") funcionAyuda();
            else if (argumentos[0] == "salir") ejecutando = false;
            else if (argumentos[0] == "ubicar_elementos") funcionalidades(8, argumentos);
			else if (argumentos[0] == "ruta_mas_larga") funcionalidades(11, argumentos);
			else if (argumentos[0] == "cargar_comandos") {
				cout<<"Error: numero de parametros incorrecto"<<endl;
				cargarComandosA();
			}else if (argumentos[0] == "cargar_elementos"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				cargarElementosA();
			}else if (argumentos[0] == "agregar_movimiento"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				agregarMovimientoA();
			}else if (argumentos[0] == "agregar_analisis"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				agregarAnalisisA();
			}else if (argumentos[0] == "agregar_elemento"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				agregarElementoA();
			}else if (argumentos[0] == "guardar"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				guardarA();
			}else if (argumentos[0] == "simular_comandos"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				simularComandosA();
			}else if (argumentos[0] == "en_cuadrante"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				enCuadranteA();
			}else if (argumentos[0] == "crear_mapa"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				crearMapaA();
			}else cout << "Error: comando no existente" << endl;
        }

        if (argumentos.size() > 1 && (argumentos[0] == "cargar_comandos")) {
            funcionalidades(1, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "cargar_elementos")) {
            funcionalidades(2, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "agregar_movimiento")) {
            funcionalidades(3, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "agregar_analisis")) {
            funcionalidades(4, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "agregar_elemento")) {
            funcionalidades(5, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "guardar")) {
            funcionalidades(6, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "simular_comandos")) {
            funcionalidades(7, argumentos);
        } else if (argumentos.size() > 1 && (argumentos[0] == "en_cuadrante"))
            funcionalidades(9, argumentos);
        else if (argumentos.size() > 1 && (argumentos[0] == "crear_mapa"))
            funcionalidades(10, argumentos);
        else if (argumentos.size() > 1) cout << "Error: comando no existente" << endl;
	}
}