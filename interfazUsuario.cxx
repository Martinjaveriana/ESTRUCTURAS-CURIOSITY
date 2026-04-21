#include <iostream>
#include <vector>
#include "src/Curiosity.h"
#include "src/Utilites/Utilities.h"

using namespace std;

int main() {
    string args;
    bool ejecutando = true;
	Curiosity* curiosity = new Curiosity();

    while (ejecutando) {
        cout << "$ ";
        getline(cin, args);

        if (args.empty()) continue;

        vector<string>* argumentos = Utilities::obtenerArgumentos(args);

        if (argumentos->size() == 1) {
            if (argumentos->at(0) == "ayuda") Utilities::funcionAyuda();
            else if (argumentos->at(0) == "salir") ejecutando = false;
            else if (argumentos->at(0) == "ubicar_elementos") curiosity->ubicar_elementos();
			else if (argumentos->at(0) == "ruta_mas_larga") curiosity->ruta_mas_larga();
			else if (argumentos->at(0) == "cargar_comandos") {
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::cargarComandosA();
			}else if (argumentos->at(0) == "cargar_elementos"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::cargarElementosA();
			}else if (argumentos->at(0) == "agregar_movimiento"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::agregarMovimientoA();
			}else if (argumentos->at(0) == "agregar_analisis"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::agregarAnalisisA();
			}else if (argumentos->at(0) == "agregar_elemento"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::agregarElementoA();
			}else if (argumentos->at(0) == "guardar"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::guardarA();
			}else if (argumentos->at(0) == "simular_comandos"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::simularComandosA();
			}else if (argumentos->at(0) == "en_cuadrante"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::enCuadranteA();
			}else if (argumentos->at(0) == "crear_mapa"){
				cout<<"Error: numero de parametros incorrecto"<<endl;
				Utilities::crearMapaA();
			}else cout << "Error: comando no existente" << endl;
        }

        if (argumentos->size() > 1 && (argumentos->at(0) == "cargar_comandos"))
            curiosity->cargar_comandos(argumentos);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "cargar_elementos"))
            curiosity->cargar_elementos(argumentos);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "agregar_movimiento"))
            curiosity->agregar_movimiento(argumentos, true);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "agregar_analisis"))
            curiosity->agregar_analisis(argumentos, true);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "agregar_elemento"))
            curiosity->agregar_elemento(argumentos, true);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "guardar"))
            curiosity->guardar(argumentos);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "simular_comandos"))
            curiosity->simular_comandos(argumentos);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "en_cuadrante"))
            curiosity->en_cuadrante(argumentos);
        else if (argumentos->size() > 1 && (argumentos->at(0) == "crear_mapa"))
            curiosity->crear_mapa(argumentos);
        else if (argumentos->size() > 1 && argumentos->at(0) == "ayuda") {
	        cout << "Error: numero de argumentos incorrecto" << endl;
        	cout << "\nSyntaxis del comando: ayuda" << endl;
        } else if (argumentos->size() > 1 && argumentos->at(0) == "salir") {
        	cout << "Error: numero de argumentos incorrecto" << endl;
        	cout << "\nSyntaxis del comando: salir" << endl;
        } else if (argumentos->size() > 1) cout << "Error: comando no existente" << endl;
	}
}