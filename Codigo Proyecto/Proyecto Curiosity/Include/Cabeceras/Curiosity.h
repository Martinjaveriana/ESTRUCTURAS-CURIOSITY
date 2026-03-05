//
// Curiosity.h
//

#ifndef CURIOSITY_H
#define CURIOSITY_H

#include <vector>
#include <string>

#include "Elemento.h"
#include "Comando.h"
//#include "CAnalisis.h"
//#include "CMovimiento.h"

using namespace std;
class Curiosity {

private:

	Comando comando;
    vector<Elemento> elementos_C;
    //Comando comandos;

        //float PosX;
        //float PosY;
public:
    Curiosity();

    // Metodo principal: el main solo llama este
    void procesar(const string& entrada);

    //utilidades para interpretar comandos
    vector<string> obtenerArgumentos(const string& entrada);
    bool verificador(const string& cadena, int opcion);




//Contructor con parametros pero la verdad nose para que
    //Curiosity(vector<Elemento> n_elementos, vector<Comando> n_comandos, float n_posX, float n_posY);

//Getters
    const vector<Elemento>& obElem() const;
    //const Comando& obComS() const;


// Setters de las listas de elementos y comandos

    void fijElem(const vector<Elemento>& nElem);
    //void fijComS(const Comando comandos& nComS);



    //comandos del doc
    void cargar_comandos(vector<string>& args);
    void cargar_elementos(vector<string>& args);
    void agregar_movimiento(vector<string>& args);
    //void agregar_analisis(vector<string>& args);

	/*

	void Curiosity::agregar_analisis(vector<string>& args) {
    if (args.size() == 4) {
        bool verAna = true, verCom = true;

        if (args[1] != "fotografiar" && args[1] != "composicion" && args[1] != "perforar") verAna = false;
        if (!verificador(args[3], 2)) verCom = false;

        if (!verAna || !verCom) {
            cout << "La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)" << endl;
        } else {
            cout << "El comando de analisis ha sido agregado exitosamente" << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        agregarAnalisisA();
    }
}

	*/

    void agregar_elemento(vector<string>& args);
    void guardar(vector<string>& args);
    void simular_comandos(vector<string>& args);
    void ubicar_elementos();
    void en_cuadrante(vector<string>& args);
    void crear_mapa(vector<string>& args);
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
};

#endif // CURIOSITY_H