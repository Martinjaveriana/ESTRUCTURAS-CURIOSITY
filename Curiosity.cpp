//
// Curiosity.cpp
//

#include "Curiosity.h"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

//  Constructor

Curiosity::Curiosity() {
    // agregar el resto de las clases/atributos que tenga el curiosity
}

//=============================================
//  Metodo principal —> el que llama el main
//=============================================

void Curiosity::procesar(const string& entrada) {

    /*Estrucura de los ifs:
     * 1. solo se envia un argumento
     * 2. ayuda + arumento
     * 3. else CAMBIAR
     */

    vector<string> argumentos = obtenerArgumentos(entrada);
    if (argumentos.empty()) return;

    //ayuda sin argumentos y comandos sin argumentos
    //se entra a este if si solo se envia un argumento
    if (argumentos.size() == 1) {
        if (argumentos[0] == "ayuda") {
            funcionAyuda();
        }
        else if (argumentos[0] == "ubicar_elementos") {
            ubicar_elementos();
        }
        else if (argumentos[0] == "ruta_mas_larga") {
            ruta_mas_larga();
        }
        else if (argumentos[0] == "cargar_comandos") {
            cout << "Error: numero de parametros incorrecto" << endl; cargarComandosA();
        }
        else if (argumentos[0] == "cargar_elementos") {
            cout << "Error: numero de parametros incorrecto" << endl; cargarElementosA();
        }
        else if (argumentos[0] == "agregar_movimiento") {
            cout << "Error: numero de parametros incorrecto" << endl; agregarMovimientoA();
        }
        else if (argumentos[0] == "agregar_analisis") {
            cout << "Error: numero de parametros incorrecto" << endl; agregarAnalisisA();
        }
        else if (argumentos[0] == "agregar_elemento") {
            cout << "Error: numero de parametros incorrecto" << endl; agregarElementoA();
        }
        else if (argumentos[0] == "guardar") {
            cout << "Error: numero de parametros incorrecto" << endl; guardarA();
        }
        else if (argumentos[0] == "simular_comandos") {
            cout << "Error: numero de parametros incorrecto" << endl; simularComandosA();
        }
        else if (argumentos[0] == "ubicar_elementos") {
            cout << "Error: numero de parametros incorrecto" << endl; ubicarElementoA();
        }
        else if (argumentos[0] == "en_cuadrante") {
            cout << "Error: numero de parametros incorrecto" << endl; enCuadranteA();
        }
        else if (argumentos[0] == "crear_mapa") {
            cout << "Error: numero de parametros incorrecto" << endl; crearMapaA();
        }
        else {
            cout << "Error: comando no existente" << endl;
        }
    }


    //comandos ayuda + comando
    //se entra a estos if si el primer argumento es "ayuda"
    //se hace la verificacion si se envian mas argumentos...
    else if (argumentos[0] == "ayuda") {
        if (argumentos.size() == 2) {
            if      (argumentos[1] == "ayuda") {
                ayudaA();
            }
            else if (argumentos[1] == "cargar_comandos") {
                cargarComandosA();
            }
            else if (argumentos[1] == "cargar_elementos") {
                cargarElementosA();
            }
            else if (argumentos[1] == "agregar_movimiento") {
                agregarMovimientoA();
            }
            else if (argumentos[1] == "agregar_analisis") {
                agregarAnalisisA();
            }
            else if (argumentos[1] == "agregar_elemento") {
                agregarElementoA();
            }
            else if (argumentos[1] == "guardar") {
                guardarA();
            }
            else if (argumentos[1] == "simular_comandos") {
                simularComandosA();
            }
            else if (argumentos[1] == "ubicar_elementos") {
                ubicarElementoA();
            }
            else if (argumentos[1] == "en_cuadrante") {
                enCuadranteA();
            }
            else if (argumentos[1] == "crear_mapa") {
                crearMapaA();
            }
            else if (argumentos[1] == "ruta_mas_larga") {
                rutaMasLargaA();
            }
            else if (argumentos[1] == "salir") {
                salirA();
            }
            else { //revisar si lo rompe
                cout <<endl<< "Error: comando no existente" << endl<<endl;
            }
       }
        else {
            cout << endl << "Error: numero de parametros incorrecto" << endl;
            cout << "Syntaxis del comando: ayuda <nombre_comado>" << endl;
            cout << "tambien puede escribir 'ayuda' para ver la lista de comados" << endl<<endl;
        }
    }


	else if(argumentos.size() > 1) {
		if(argumentos[0] == "salir") {
			cout<<endl<<"Error: numero de parametros incorrecto"<<endl;
			cout<<"Enviar la palabra 'salida' para salir"<<endl<<endl;
		}
		else if (argumentos[0] == "ayuda") {
			cout<<endl<<"Error: numero de parametros incorrecto"<<endl;
		    cout << "\nComando para pedir ayuda, se puede ejecutar de dos formas:" << endl;
    		cout << "\n 1. ayuda                - muestra la lista de comandos" << endl;
    		cout << "\n 2. ayuda <comando>      - muestra el comando en detalle\n" << endl;
		}
	    else if (argumentos[0] == "ruta_mas_larga") {
			cout<<endl<<"Error: numero de parametros incorrecto"<<endl;
			rutaMasLargaA();
		}

		else if (argumentos[0] == "ubicar_elementos") { //CORREGIR (REVISAR PARAMETROS/SALIDAS)
			cout<<endl<<"Error: numero de parametros incorrecto"<<endl;
			ubicarElementoA();
		}

		else cout << "Error: comando no existente" << endl;
	}


    //comandos con argumentos
    //si no se envia un comando con un argumento y
	//descomentar al momento de hacerlo
	//agregar verificaciones :(
    else {
        if (argumentos[0] == "cargar_comandos") {
            cargar_comandos(argumentos);
        }
        else if (argumentos[0] == "cargar_elementos") {
            cargar_elementos(argumentos);
        }
        else if (argumentos[0] == "agregar_movimiento") {
            agregar_movimiento(argumentos);
        }
        else if (argumentos[0] == "agregar_analisis") {
            agregar_analisis(argumentos);
        }
        else if (argumentos[0] == "agregar_elemento") {
            agregar_elemento(argumentos);
        }
        else if (argumentos[0] == "guardar") {
            guardar(argumentos);
        }
        else if (argumentos[0] == "simular_comandos") {
            simular_comandos(argumentos);
        }
        else if (argumentos[0] == "en_cuadrante") {
            en_cuadrante(argumentos);
        }
        else if (argumentos[0] == "crear_mapa") {
            crear_mapa(argumentos);
        }
        /*else {
            cout << "Error: comando no existente" << endl;
        }*/
    }
}

//  Logica de cada comando

void Curiosity::cargar_comandos(vector<string>& args) {
    if (args.size() == 2) {
        ifstream arComandos((args[1] + ".txt"), ios::ate);
        int nComandos = 0;

        if (arComandos.is_open()) {
            if (arComandos.tellg() == 0) {
                cout << args[1] << " no contiene comandos." << endl;
            } else {
                arComandos.seekg(0, ios::beg);
                //leer lineas y agregar al vector<Comando>
                cout << nComandos << " comandos cargados correctamente desde " << args[1] << endl;
                arComandos.close();
            }
        } else {
            cout << args[1] << " no se encuentra o no puede leerse." << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        cargarComandosA();
    }
}

void Curiosity::cargar_elementos(vector<string>& args) {
    if (args.size() == 2) {
        ifstream arElementos((args[1] + ".txt"), ios::ate);
        int nElementos = 0;

        if (arElementos.is_open()) {
            if (arElementos.tellg() == 0) {
                cout << args[1] << " no contiene elementos." << endl;
            } else {
                arElementos.seekg(0, ios::beg);
                cout << nElementos << " elementos cargados correctamente desde " << args[1] << endl;
                arElementos.close();
            }
        } else {
            cout << args[1] << " no se encuentra o no puede leerse." << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        cargarElementosA();
    }
}

void Curiosity::agregar_movimiento(vector<string>& args) {
    if (args.size() == 4) {
        bool verMov = true, verMag = true, verUni = true;

        if (args[1] != "avanzar" && args[1] != "girar") verMov = false;
        if (!verificador(args[2], 1)) verMag = false;
        if (args[3] != "cm" && args[3] != "dm" && args[3] != "m" && args[3] != "km") verUni = false;

        if (!verMov || !verMag || !verUni) {
            cout << "La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)" << endl;
        } else {
            cout << "El comando de movimiento ha sido agregado exitosamente" << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        agregarMovimientoA();
    }
}

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

void Curiosity::agregar_elemento(vector<string>& args) {
    if (args.size() == 6) {
        bool verEle = true, verTam = true, verUni = true, verCor = true;

        if (args[1] != "roca" && args[1] != "crater" && args[1] != "monticulo" && args[1] != "duna") verEle = false;
        if (!verificador(args[2], 3)) verTam = false;
        if (args[3] != "cm" && args[3] != "dm" && args[3] != "m" && args[3] != "km") verUni = false;
        if (!verificador(args[4], 1) || !verificador(args[5], 1)) verCor = false;

        if (!verEle || !verTam || !verUni || !verCor) {
            cout << "La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)" << endl;
        } else {
            cout << "El elemento ha sido agregado exitosamente" << endl;
            elementos_C.push_back(Elemento(args[1], stod(args[2]), args[3], stof(args[4]), stof(args[5])));
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        agregarElementoA();
    }
}

void Curiosity::guardar(vector<string>& args) {
    if (args.size() == 3) {
        bool verInfo = true;

        if (args[1] != "comandos" && args[1] != "elementos") verInfo = false;

        if (verInfo) {
            ofstream arAGuardar((args[2] + ".txt"));
            if (arAGuardar.is_open()) {
                cout << "La informacion ha sido guardada en " << args[2] << endl;
                arAGuardar.close();
            } else {
                cout << "Error guardando en " << args[2] << endl;
            }
        } else {
            cout << "tipo de informacion incorrecta" << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        guardarA();
    }
}

void Curiosity::simular_comandos(vector<string>& args) {
    if (args.size() == 3) {
        bool verCor = true;

        if (!verificador(args[1], 1)) verCor = false;
        if (!verificador(args[2], 1)) verCor = false;

        if (!verCor) {
            cout << "coordenadas invalidas" << endl;
        } else {
            cout << "La simulacion de los comandos, a partir de la posicion (" << args[1] << ", " << args[2]
                 << "), deja al robot en la nueva posicion (nuevoX, nuevoY)." << endl;
        }
    } else {
        cout <<endl<< "Error: numero de parametros incorrecto" << endl;
        simularComandosA();
    }
}

//*********************
//REVISAR
//*********************
void Curiosity::ubicar_elementos() {
    string nombre = "ejemplo";
    ifstream arElementos((nombre + ".txt"), ios::ate);

    if (arElementos.is_open()) {
        if (arElementos.tellg() == 0) {
            cout << nombre << " no contiene elementos." << endl;
        } else {
            arElementos.seekg(0, ios::beg);
            bool verElem = true;
            if (verElem) cout << "Los elementos han sido procesados exitosamente" << endl;
            else cout << "Los siguientes elementos no pudieron procesarse adecuadamente: ..." << endl;
            arElementos.close();
        }
    } else {
        cout << "Error: numero de parametros incorrecto (a implementar)" << endl;
        ubicarElementoA();
    }
}

void Curiosity::en_cuadrante(vector<string>& args) {
    if (args.size() == 5) {
        bool hayInfo = false;

        if (hayInfo) {
            cout << "Los elementos no han sido ubicados todavia (con el comando ubicar_elementos)." << endl;
            return;
        }
        if (!verificador(args[1],1) || !verificador(args[2],1) || !verificador(args[3],1) || !verificador(args[4],1)) {
            cout << "coordenadas invalidas" << endl;
        } else {
            if (stoi(args[1]) > stoi(args[2]) || stoi(args[3]) > stoi(args[4])) {
                cout << "La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)" << endl;
            } else {
                cout << "Los elementos ubicados en el cuadrante son: ..." << endl;
            }
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        enCuadranteA();
    }
}

//pendiente a implementacion
void Curiosity::crear_mapa(vector<string>& args) {
    if (args.size() == 2) {
        if (!verificador(args[1], 1)) {
            cout << "el coeficiente tiene que ser un numero" << endl;
        } else {
            string nombre = "ejemplo";
            ifstream arElementos((nombre + ".txt"), ios::ate);

            if (arElementos.is_open()) {
                if (arElementos.tellg() == 0) {
                    cout << nombre << " no contiene elementos." << endl;
                } else {
                    arElementos.seekg(0, ios::beg);
                    float coeficienteC = stof(args[1]);
                    cout << "El mapa se ha generado exitosamente. Cada elemento tiene n vecinos" << endl;
                }
            } else {
                cout << "La informacion requerida no esta almacenada en memoria" << endl;
            }
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        crearMapaA();
    }
}

void Curiosity::ruta_mas_larga() {
    bool hayMapa = false;

    if (!hayMapa) {
        cout <<endl<< "El mapa no ha sido generado todavia (con el comando crear_mapa)." << endl<<endl;
    } else {
        cout << "Los puntos de interes mas alejados entre si son ... y ... La ruta que los conecta tiene una longitud total de ... y pasa por los siguientes elementos: ..." << endl;
    }
}

//===============================================
//funciones obtener argumentos y verificadores
//=================================================

/*
 * Tokeniza la entrada separando por espacios.
 * Generada con ayuda de IA
 */

/*
La siguiente funcion fue generada con IA, ya que no teniamos idea de como tokenizar sin utilizar liberias externas
asi que utilizamos la siguiente promt para generar esta funcion:
Hola, estoy haciendo un proyecto en C++ donde implemento una terminal. Utilizo std::getline para leer la entrada del usuario, que tiene este formato:
comando argumento1 argumento2 ... argumentoN
Necesito una función que tokenice la cadena completa y devuelva cada argumento por separado, usando exclusivamente la biblioteca estándar de C++, sin librerías externas. No puedo usar std::stringstream, ni strtok, ni nada que no sea parte del STL. Solo puedo usar std::string, bucles y contenedores como std::vector.
*/

//en resumen la funcion parte la entrada por los argumentos (Ejemplo: cargar_comandos, hello.txt )
vector<string> Curiosity::obtenerArgumentos(const string& entrada) {
    vector<string> args;
    string argActual = "";

    for (char c : entrada) {
        if (c == ' ') {
            if (argActual != "") {
                args.push_back(argActual);
                argActual = "";
            }
        } else {
            argActual += c;
        }
    }

    if (argActual != "") args.push_back(argActual);

    return args;
}

/*
 * Verifica el formato de una cadena:
 *   1 -> numero flotante (puede ser negativo)   ^-?\d+(\.\d+)?$
 *   2 -> comentario entre comillas simples ''    '.*'
 *   3 -> numero positivo                         ^\d+(\.\d+)?$
 */

/*
 * La funcion esNumero la dio una Gemini, esto porque se le pidio como verificar que una cadena de caracteres contiene algun digito con caracteres especiales.
 * La IA respondio que eso se llama "expresiones regulares", a la IA se le enviaron dos prompts, uno en el que dio la funcion esNumero:
 * como puedo verificar usando caracteres especiales si una cadena tiene algun digito
 * El segundo prompt fue:
 * dime que regex me dejaria verificar si un numero es flotante, por ejemplo 3.5
 *
bool esNumero(string cadena) {
    regex patron("^-?\\d+(\\.\\d+)?$");     //^-?\\d+(\\.\\d+)?$     o       ^\\d+(\\.\\d+)?$
    return regex_match(cadena, patron);     // \\'
}
 */

//se verifica el formato de un numero
bool Curiosity::verificador(const string& cadena, int opcion) {
    switch (opcion) {
        case 1: { regex patron("^-?\\d+(\\.\\d+)?$"); return regex_match(cadena, patron); }
        case 2: { regex patron("'.*'");                return regex_match(cadena, patron); }
        case 3: { regex patron("^\\d+(\\.\\d+)?$");   return regex_match(cadena, patron); }
    }
    return false;
}

// ============================================================
//  Mensajes de ayuda
// ============================================================

void Curiosity::funcionAyuda() {
    cout << "\n\t\t\tAYUDA SELECCIONADA\n" << endl;
    cout << "Mostrando los comandos disponibles junto con la sintaxis de cada uno:\n" << endl;
    cout << "ayuda" << endl;
    cout << "cargar_comandos <nombre_archivo>" << endl;
    cout << "cargar_elementos <nombre_archivo>" << endl;
    cout << "agregar_movimiento <tipo_mov> <magnitud> <unidad_med>" << endl;
    cout << "agregar_analisis <tipo_analisis> <objeto> <comentario>" << endl;
    cout << "agregar_elemento <tipo_comp> <tamano> <unidad_med> <coordX> <coordY>" << endl;
    cout << "guardar <tipo_archivo> <nombre_archivo>" << endl;
    cout << "simular_comandos <coordX> <coordY>" << endl;
    cout << "ubicar_elementos" << endl;
    cout << "en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << endl;
    cout << "crear_mapa <coeficiente_conectividad>" << endl;
    cout << "ruta_mas_larga" << endl;
    cout << "salir" << endl << endl;
}

void Curiosity::ayudaA() {
    cout << "\nComando para pedir ayuda, se puede ejecutar de dos formas:" << endl;
    cout << "\n 1. ayuda                - muestra la lista de comandos" << endl;
    cout << "\n 2. ayuda <comando>      - muestra el comando en detalle\n" << endl;
}

void Curiosity::cargarComandosA() {
    cout << "\nSyntaxis del comando: cargar_comandos <nombre_archivo>" << endl;
    cout << "\n- Descripcion: Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo.\n" << endl;
}

void Curiosity::cargarElementosA() {
    cout << "\nSyntaxis del comando: cargar_elementos <nombre_archivo>" << endl;
    cout << "\n- Descripcion: Carga en memoria los datos de puntos de interes o elementos contenidos en el archivo identificado por nombre_archivo.\n" << endl;
}

void Curiosity::agregarMovimientoA() {
    cout << "\nSyntaxis del comando: agregar_movimiento <tipo_mov> <magnitud> <unidad_med>" << endl;
    cout << "\n- Descripcion: Agrega el comando de movimiento. El movimiento puede ser de dos tipos: avanzar o girar." << endl;
    cout << "- Tipos de unidades aceptadas: avanzar = cm, dm, m, km  |  girar = grd, rad\n" << endl;
}

void Curiosity::agregarAnalisisA() {
    cout << "\nSyntaxis del comando: agregar_analisis <tipo_analisis> <objeto> <comentario>" << endl;
    cout << "\n- Descripcion: Agrega el comando de analisis. Tipos: fotografiar, composicion, perforar." << endl;
    cout << "- El comentario es opcional y debe estar encerrado entre comillas simples ''\n" << endl;
}

void Curiosity::agregarElementoA() {
    cout << "\nSyntaxis del comando: agregar_elemento <tipo_comp> <tamano> <unidad_med> <coordX> <coordY>" << endl;
    cout << "\n- Descripcion: Agrega el componente o elemento descrito a la lista de puntos de interes del robot." << endl;
    cout << "- Tipo de componente: roca, crater, monticulo o duna.\n" << endl;
}

void Curiosity::guardarA() {
    cout << "\nSyntaxis del comando: guardar <tipo_archivo> <nombre_archivo>" << endl;
    cout << "\n- Descripcion: Guarda en el archivo la informacion solicitada. Tipos: comandos, elementos.\n" << endl;
}

void Curiosity::simularComandosA() {
    cout << "\nSyntaxis del comando: simular_comandos <coordX> <coordY>" << endl;
    cout << "\n- Descripcion: Permite simular el resultado de los comandos de movimiento que se enviaran al robot." << endl;
    cout << "- El Curiosity inicia orientado hacia la derecha del eje x. Angulos positivos = sentido antihorario, negativos = horario.\n" << endl;
}

void Curiosity::ubicarElementoA() {
    cout << "\nSyntaxis del comando: ubicar_elementos" << endl;
    cout << "\n- Descripcion: Usa la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura jerarquica.\n" << endl;
}

void Curiosity::enCuadranteA() {
    cout << "\nSyntaxis del comando: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << endl;
    cout << "\n- Descripcion: Retorna la lista de elementos dentro del cuadrante geografico indicado.\n" << endl;
}

void Curiosity::crearMapaA() {
    cout << "\nSyntaxis del comando: crear_mapa <coeficiente_conectividad>" << endl;
    cout << "\n- Descripcion: Ubica los puntos de interes en una estructura no lineal y los conecta segun el coeficiente dado.\n" << endl;
}

void Curiosity::rutaMasLargaA() {
    cout << "\nSyntaxis del comando: ruta_mas_larga" << endl;
    cout << "\n- Descripcion: Identifica los dos componentes mas alejados entre si segun las conexiones del mapa.\n" << endl;
}

void Curiosity::salirA() {
    cout << "\nComando para salir del programa.\n" << endl;
}