//
// Curiosity.cpp
//

#include "Curiosity.h"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

// ============================================================
//  Constructor
// ============================================================

Curiosity::Curiosity() {
    // inicializa estructuras cuando esten listas
}

// ============================================================
//  Metodo principal — el main solo llama este metodo
// ============================================================

void Curiosity::procesar(const string& entrada) {
    vector<string> args = obtenerArgumentos(entrada);
    if (args.empty()) return;

    string cmd = args[0];

    // ayuda sin argumentos
    if (cmd == "ayuda" && args.size() == 1) {
        funcionAyuda();

    // ayuda <comando>
    } else if (cmd == "ayuda" && args.size() > 1) {
        if      (args[1] == "ayuda")              ayudaA();
        else if (args[1] == "cargar_comandos")    cargarComandosA();
        else if (args[1] == "cargar_elementos")   cargarElementosA();
        else if (args[1] == "agregar_movimiento") agregarMovimientoA();
        else if (args[1] == "agregar_analisis")   agregarAnalisisA();
        else if (args[1] == "agregar_elemento")   agregarElementoA();
        else if (args[1] == "guardar")            guardarA();
        else if (args[1] == "simular_comandos")   simularComandosA();
        else if (args[1] == "ubicar_elementos")   ubicarElementoA();
        else if (args[1] == "en_cuadrante")       enCuadranteA();
        else if (args[1] == "crear_mapa")         crearMapaA();
        else if (args[1] == "ruta_mas_larga")     rutaMasLargaA();
        else if (args[1] == "salir")              salirA();
        else cout << "Error: comando no existente" << endl;

    // comandos con parametros incorrectos (solo el nombre, sin args)
    } else if (args.size() == 1) {
        if      (cmd == "cargar_comandos")    { cout << "Error: numero de parametros incorrecto" << endl; cargarComandosA(); }
        else if (cmd == "cargar_elementos")   { cout << "Error: numero de parametros incorrecto" << endl; cargarElementosA(); }
        else if (cmd == "agregar_movimiento") { cout << "Error: numero de parametros incorrecto" << endl; agregarMovimientoA(); }
        else if (cmd == "agregar_analisis")   { cout << "Error: numero de parametros incorrecto" << endl; agregarAnalisisA(); }
        else if (cmd == "agregar_elemento")   { cout << "Error: numero de parametros incorrecto" << endl; agregarElementoA(); }
        else if (cmd == "guardar")            { cout << "Error: numero de parametros incorrecto" << endl; guardarA(); }
        else if (cmd == "simular_comandos")   { cout << "Error: numero de parametros incorrecto" << endl; simularComandosA(); }
        else if (cmd == "en_cuadrante")       { cout << "Error: numero de parametros incorrecto" << endl; enCuadranteA(); }
        else if (cmd == "crear_mapa")         { cout << "Error: numero de parametros incorrecto" << endl; crearMapaA(); }
        else if (cmd == "ubicar_elementos")   ubicar_elementos();
        else if (cmd == "ruta_mas_larga")     ruta_mas_larga();
        else cout << "Error: comando no existente" << endl;

    // comandos normales con argumentos
    } else {
        if      (cmd == "cargar_comandos")    cargar_comandos(args[1]);
        else if (cmd == "cargar_elementos")   cargar_elementos(args[1]);
        else if (cmd == "agregar_movimiento") agregar_movimiento(args[1], args[2], args[3]);
        else if (cmd == "agregar_analisis")   agregar_analisis(args[1], args[2], args[3]);
        else if (cmd == "agregar_elemento")   agregar_elemento(args[1], args[2], args[3], args[4], args[5]);
        else if (cmd == "guardar")            guardar(args[1], args[2]);
        else if (cmd == "simular_comandos")   simular_comandos(args[1], args[2]);
        else if (cmd == "en_cuadrante")       en_cuadrante(args[1], args[2], args[3], args[4]);
        else if (cmd == "crear_mapa")         crear_mapa(args[1]);
        else cout << "Error: comando no existente" << endl;
    }
}

// ============================================================
//  Comandos principales
// ============================================================

void Curiosity::cargar_comandos(const string& nombre_archivo) {
    ifstream ar((nombre_archivo + ".txt"), ios::ate);
    if (!ar.is_open()) {
        cout << nombre_archivo << " no se encuentra o no puede leerse." << endl;
        return;
    }
    if (ar.tellg() == 0) {
        cout << nombre_archivo << " no contiene comandos." << endl;
        return;
    }
    ar.seekg(0, ios::beg);
    int nComandos = 0;
    // TODO: leer lineas y agregar al vector<Comando>
    cout << nComandos << " comandos cargados correctamente desde " << nombre_archivo << endl;
    ar.close();
}

void Curiosity::cargar_elementos(const string& nombre_archivo) {
    ifstream ar((nombre_archivo + ".txt"), ios::ate);
    if (!ar.is_open()) {
        cout << nombre_archivo << " no se encuentra o no puede leerse." << endl;
        return;
    }
    if (ar.tellg() == 0) {
        cout << nombre_archivo << " no contiene elementos." << endl;
        return;
    }
    ar.seekg(0, ios::beg);
    int nElementos = 0;
    // TODO: leer lineas y agregar al vector<Elemento>
    cout << nElementos << " elementos cargados correctamente desde " << nombre_archivo << endl;
    ar.close();
}

void Curiosity::agregar_movimiento(const string& tipo, const string& magnitud, const string& unidad) {
    bool verTipo = (tipo == "avanzar" || tipo == "girar");
    bool verMag  = verificador(magnitud, 1);
    bool verUni  = (unidad == "cm" || unidad == "dm" || unidad == "m" || unidad == "km");

    if (!verTipo || !verMag || !verUni) {
        cout << "La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)" << endl;
        return;
    }
    // TODO: crear Movimiento y agregarlo al vector<Comando>
    cout << "El comando de movimiento ha sido agregado exitosamente" << endl;
}

void Curiosity::agregar_analisis(const string& tipo, const string& objeto, const string& comentario) {
    bool verTipo = (tipo == "fotografiar" || tipo == "composicion" || tipo == "perforar");
    bool verCom  = verificador(comentario, 2);

    if (!verTipo || !verCom) {
        cout << "La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)" << endl;
        return;
    }
    // TODO: crear Analisis y agregarlo al vector<Comando>
    cout << "El comando de analisis ha sido agregado exitosamente" << endl;
}

void Curiosity::agregar_elemento(const string& tipo, const string& tamanio, const string& unidad, const string& coordX, const string& coordY) {
    bool verTipo = (tipo == "roca" || tipo == "crater" || tipo == "monticulo" || tipo == "duna");
    bool verTam  = verificador(tamanio, 3);
    bool verUni  = (unidad == "cm" || unidad == "dm" || unidad == "m" || unidad == "km");
    bool verCor  = verificador(coordX, 1) && verificador(coordY, 1);

    if (!verTipo || !verTam || !verUni || !verCor) {
        cout << "La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)" << endl;
        return;
    }
    // TODO: crear Elemento y agregarlo al vector<Elemento>
    cout << "El elemento ha sido agregado exitosamente" << endl;
}

void Curiosity::guardar(const string& tipo, const string& nombre_archivo) {
    if (tipo != "comandos" && tipo != "elementos") {
        cout << "tipo de informacion incorrecta" << endl;
        return;
    }
    ofstream ar((nombre_archivo + ".txt"));
    if (!ar.is_open()) {
        cout << "Error guardando en " << nombre_archivo << endl;
        return;
    }
    // TODO: recorrer el vector correspondiente y escribir cada objeto
    cout << "La informacion ha sido guardada en " << nombre_archivo << endl;
    ar.close();
}

void Curiosity::simular_comandos(const string& coordX, const string& coordY) {
    if (!verificador(coordX, 1) || !verificador(coordY, 1)) {
        cout << "coordenadas invalidas" << endl;
        return;
    }
    // TODO: recorrer vector<Comando> y calcular posicion final
    cout << "La simulacion, a partir de (" << coordX << ", " << coordY
         << "), deja al robot en la nueva posicion (nuevoX, nuevoY)." << endl;
}

void Curiosity::ubicar_elementos() {
    // TODO: insertar elementos del vector en estructura jerarquica
    cout << "Los elementos han sido procesados exitosamente" << endl;
}

void Curiosity::en_cuadrante(const string& xMin, const string& xMax, const string& yMin, const string& yMax) {
    if (!verificador(xMin,1) || !verificador(xMax,1) || !verificador(yMin,1) || !verificador(yMax,1)) {
        cout << "coordenadas invalidas" << endl;
        return;
    }
    if (stoi(xMin) > stoi(xMax) || stoi(yMin) > stoi(yMax)) {
        cout << "La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)" << endl;
        return;
    }
    // TODO: consultar estructura jerarquica
    cout << "Los elementos ubicados en el cuadrante son: ..." << endl;
}

void Curiosity::crear_mapa(const string& coeficiente) {
    if (!verificador(coeficiente, 1)) {
        cout << "el coeficiente tiene que ser un numero" << endl;
        return;
    }
    // TODO: construir grafo con vector<Elemento>
    cout << "El mapa se ha generado exitosamente." << endl;
}

void Curiosity::ruta_mas_larga() {
    // TODO: verificar si el mapa fue creado y calcular ruta
    cout << "El mapa no ha sido generado todavia (con el comando crear_mapa)." << endl;
}

// ============================================================
//  Utilidades internas
// ============================================================

vector<string> Curiosity::obtenerArgumentos(const string& entrada) {
    vector<string> args;
    string actual = "";
    for (char c : entrada) {
        if (c == ' ') {
            if (!actual.empty()) { args.push_back(actual); actual = ""; }
        } else {
            actual += c;
        }
    }
    if (!actual.empty()) args.push_back(actual);
    return args;
}

bool Curiosity::verificador(const string& cadena, int opcion) {
    switch (opcion) {
        case 1: { regex p("^-?\\d+(\\.\\d+)?$");  return regex_match(cadena, p); }
        case 2: { regex p("'.*'");                 return regex_match(cadena, p); }
        case 3: { regex p("^\\d+(\\.\\d+)?$");     return regex_match(cadena, p); }
    }
    return false;
}

// ============================================================
//  Mensajes de ayuda
// ============================================================

void Curiosity::funcionAyuda() {
    cout << "\n\t\t\tAYUDA\n" << endl;
    cout << "- ayuda" << endl;
    cout << "- cargar_comandos <nombre_archivo>" << endl;
    cout << "- cargar_elementos <nombre_archivo>" << endl;
    cout << "- agregar_movimiento <tipo> <magnitud> <unidad>" << endl;
    cout << "- agregar_analisis <tipo> <objeto> <comentario>" << endl;
    cout << "- agregar_elemento <tipo> <tamano> <unidad> <coordX> <coordY>" << endl;
    cout << "- guardar <tipo> <nombre_archivo>" << endl;
    cout << "- simular_comandos <coordX> <coordY>" << endl;
    cout << "- ubicar_elementos" << endl;
    cout << "- en_cuadrante <xMin> <xMax> <yMin> <yMax>" << endl;
    cout << "- crear_mapa <coeficiente>" << endl;
    cout << "- ruta_mas_larga" << endl;
    cout << "- salir\n" << endl;
}

void Curiosity::ayudaA() {
    cout << "\n1. ayuda -> lista de comandos" << endl;
    cout << "2. ayuda <comando> -> detalle de un comando\n" << endl;
}
void Curiosity::cargarComandosA() {
    cout << "\nSintaxis: cargar_comandos <nombre_archivo>" << endl;
    cout << "Carga comandos de desplazamiento desde el archivo indicado.\n" << endl;
}
void Curiosity::cargarElementosA() {
    cout << "\nSintaxis: cargar_elementos <nombre_archivo>" << endl;
    cout << "Carga puntos de interes desde el archivo indicado.\n" << endl;
}
void Curiosity::agregarMovimientoA() {
    cout << "\nSintaxis: agregar_movimiento <tipo> <magnitud> <unidad>" << endl;
    cout << "Tipos: avanzar, girar | Unidades: cm, dm, m, km\n" << endl;
}
void Curiosity::agregarAnalisisA() {
    cout << "\nSintaxis: agregar_analisis <tipo> <objeto> <comentario>" << endl;
    cout << "Tipos: fotografiar, composicion, perforar | Comentario entre ''\n" << endl;
}
void Curiosity::agregarElementoA() {
    cout << "\nSintaxis: agregar_elemento <tipo> <tamano> <unidad> <coordX> <coordY>" << endl;
    cout << "Tipos: roca, crater, monticulo, duna\n" << endl;
}
void Curiosity::guardarA() {
    cout << "\nSintaxis: guardar <tipo> <nombre_archivo>" << endl;
    cout << "Tipos: comandos, elementos\n" << endl;
}
void Curiosity::simularComandosA() {
    cout << "\nSintaxis: simular_comandos <coordX> <coordY>" << endl;
    cout << "Simula el resultado de los comandos desde la posicion dada.\n" << endl;
}
void Curiosity::ubicarElementoA() {
    cout << "\nSintaxis: ubicar_elementos" << endl;
    cout << "Ubica los elementos en una estructura jerarquica.\n" << endl;
}
void Curiosity::enCuadranteA() {
    cout << "\nSintaxis: en_cuadrante <xMin> <xMax> <yMin> <yMax>" << endl;
    cout << "Lista elementos dentro del cuadrante indicado.\n" << endl;
}
void Curiosity::crearMapaA() {
    cout << "\nSintaxis: crear_mapa <coeficiente_conectividad>" << endl;
    cout << "Conecta los elementos en un mapa segun el coeficiente dado.\n" << endl;
}
void Curiosity::rutaMasLargaA() {
    cout << "\nSintaxis: ruta_mas_larga" << endl;
    cout << "Identifica los dos puntos mas alejados en el mapa.\n" << endl;
}
void Curiosity::salirA() {
    cout << "\nSintaxis: salir" << endl;
    cout << "Termina la ejecucion del programa.\n" << endl;
}