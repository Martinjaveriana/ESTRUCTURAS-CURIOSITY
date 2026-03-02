// Created by martin-sanmiguel on 2/12/26.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include "../../Include/Cabeceras/controladorUI.h"

using namespace std;

/*void funcionInicio() {
    cout << "\n\n\t\t\t***Bienvenido el sistema de navegacion del Curiosity***\n\n" << endl;
    cout << "Escribe: 'ayuda', para obtener ayuda sobre los comandos disponibles " << endl;
    cout << "Escribe: 'ayuda <comando>' , para obtener ayuda de un comando en especifico " << endl << endl;
}*/

/*
La siguiente funcion fue generada con IA, ya que no teniamos idea de como tokenizar sin utilizar liberias externas
asi que utilizamos la siguiente promt para generar esta funcion:
Hola, estoy haciendo un proyecto en C++ donde implemento una terminal. Utilizo std::getline para leer la entrada del usuario, que tiene este formato:
comando argumento1 argumento2 ... argumentoN
Necesito una función que tokenice la cadena completa y devuelva cada argumento por separado, usando exclusivamente la biblioteca estándar de C++, sin librerías externas. No puedo usar std::stringstream, ni strtok, ni nada que no sea parte del STL. Solo puedo usar std::string, bucles y contenedores como std::vector.
*/

vector<string> obtenerArgumentos(const string& entrada) {
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

    if (argActual != "") {
        args.push_back(argActual);
    }

    return args;
}

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

bool verificador(string cadena, int opcion) {
    switch (opcion) {
        case 1: {   //verifica si la cadena tiene algun numero flotante, puede ser negativo
            regex patron("^-?\\d+(\\.\\d+)?$");
            return regex_match(cadena, patron);
        }
        case 2: {   //verifica si es un comentario, ''
            regex patron("'.*'");
            return regex_match(cadena, patron);
        }
        case 3: {   //verifica si es un numero positivo
            regex patron("^\\d+(\\.\\d+)?$");
            return regex_match(cadena, patron);
        }
    }

    return false;
}

void funcionalidades(int opcion, vector<string> args) {
    switch (opcion) {
        case 1: {
            //cargar_comandos

            if (args.size() == 2) {
                ifstream arComandos ((args[1] + ".txt"), ios::ate);
                int nComandos = 0;

                if (arComandos.is_open()) {
                    if (arComandos.tellg() == 0) {
                        cout << args[1] << " no contiene comandos." << endl;
                        break;
                    }else {
                        arComandos.seekg(0,ios::beg);

                        cout << nComandos <<" comandos cargados correctamente desde " << args[1] << endl;
                        arComandos.close();
                    }
                } else {
                    cout << args[1] << " no se encuentra o no puede leerse." << endl;
                }
            } else {
				cout<<"Error: numero de parametros incorrecto"<<endl;
				cargarComandosA();
			}

            break;
        } case 2:{
            //cargar_elementos

            if (args.size() == 2) {
                ifstream arElementos ((args[1] + ".txt"), ios::ate);
                int nElementos = 0;

                if (arElementos.is_open()) {
                    if (arElementos.tellg() == 0) {
                        cout << args[1] << " no contiene elementos." << endl;
                        break;
                    }else {
                        arElementos.seekg(0,ios::beg);

                        cout << nElementos <<" elementos cargados correctamente desde " << args[1] << endl;
                        arElementos.close();
                    }
                } else {
                    cout << args[1] << " no se encuentra o no puede leerse." << endl;
                }
            } else {
				cout<<"Error: numero de parametros incorrecto"<<endl;
				cargarElementosA();
			}

            break;
        } case 3: {
            //agregar_movimiento
            bool verMov = true;
            bool verMag = true;
            bool verUni = true;

            if (args.size() == 4) {
                //revisa si los parametros son los correctos

                if (args[1] == "avanzar") cout << "";
                else if (args[1] == "girar") cout << "";
                else verMov = false;

                if ( !verificador(args[2],1) ) verMag = false;

                if (args[3] == "cm") cout << "";
                else if (args[3] == "dm") cout << "";
                else if (args[3] == "m") cout << "";
                else if (args[3] == "km") cout << "";
                else verUni = false;

                if (!verMov || !verMag || !verUni) cout << "La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)" << endl;
                else cout << "El comando de movimiento ha sido agregado exitosamente" << endl;
            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				agregarMovimientoA();
			}

            break;
        } case 4:{
            //agregar_analisis

            bool verAna = true;
            bool verCom = true;

            if (args.size() == 4) {
                //revisa si los parametros son los correctos

                if (args[1] == "fotografiar") cout << "";
                else if (args[1] == "composicion") cout << "";
                else if (args[1] == "perforar") cout << "";
                else verAna = false;

                if ( !verificador(args[3],2) ) verCom = false;

                if (!verAna || !verCom) cout << "La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)" << endl;
                else cout << "El comando de analisis ha sido agregado exitosamente" << endl;
            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				agregarAnalisisA();
			}

            break;
        } case 5: {
            //agregar_elemento

            bool verEle = true;
            bool verTam = true;
            bool verUni = true;
            bool verCor = true;

            if (args.size() == 6) {
                //revisa si los parametros son los correctos

                if (args[1] == "roca") cout << "";
                else if (args[1] == "crater") cout << "";
                else if (args[1] == "monticulo") cout << "";
                else if (args[1] == "duna") cout << "";
                else verEle = false;

                if ( !verificador(args[2],3) ) verTam = false;

                if (args[3] == "cm") cout << "";
                else if (args[3] == "dm") cout << "";
                else if (args[3] == "m") cout << "";
                else if (args[3] == "km") cout << "";
                else verUni = false;

                if ( !verificador(args[4],1) ) verCor = false;
                if ( !verificador(args[5],1) ) verCor = false;

                if (!verEle || !verTam || !verUni || !verCor) cout << "La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)" << endl;
                else cout << "El elemento ha sido agregado exitosamente" << endl;
            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				agregarElementoA();
			}

            break;
        } case 6: {
            //guardar
            bool verInfo = true;

            if (args.size() == 3) {
                //revisa si el tipo de informacion es correcta

                if (args[1] == "comandos") cout << "";
                else if (args[1] == "elementos") cout << "";
                else verInfo = false;

                if (verInfo) {
                    ofstream arAGuardar ((args[2] + ".txt"));

                    if (arAGuardar.is_open()) {
                        cout << "La informacion ha sido guardada en " << args[2] << endl;
                        arAGuardar.close();
                    } else cout << "Error guardando en " << args[2] << endl;

                } else cout << "tipo de informacion incorrecta\n\ndeberia haber una verificacion de si existe informacion almacenada en memoria de alguno de los dos tipos, por ahora no\n\n" << endl;
                //La informacion requerida no esta almacenada en memoria
            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				guardarA();
			}

            break;
        } case 7: {
            //simular_comandos

            bool verCor = true;

            if (args.size() == 3) {

                if ( !verificador(args[1],1) ) verCor = false;
                if ( !verificador(args[2],1) ) verCor = false;

                if (!verCor) cout << "coordenadas invalidas\n\ndeberia haber una verificacion de si existe la informacion necesaria almacenada en memoria, por ahora no\n\n" << endl;
                else {
                    cout << "La simulacion de los comandos, a partir de la posicion (" << args[1] << ", " << args[2] << "), deja al robot en la nueva posicion (nuevoX, nuevoY)." << endl;
                }

            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				simularComandosA();
			}

            break;
        } case 8: {
            //ubicar_elementos

            //deberia haber una funcion que busque los nombres de los archivos existentes de elementos y los devuelva uno a uno
            //por ende el resto de codigo del case tendria que ir dentro de un for

            string nombre = "ejemplo";  //ejemplo no existe, p tiene contenido, nose esta vacio

            ifstream arElementos ((nombre + ".txt"), ios::ate);

            if (arElementos.is_open()) {
                if (arElementos.tellg() == 0) {
                    cout << nombre << " no contiene elementos." << endl;
                    break;
                } else {
                    arElementos.seekg(0, ios::beg);
                    bool verElem = true;

                    if (verElem) cout << "Los elementos han sido procesados exitosamente" << endl;
                    else cout << "Los siguientes elementos no pudieron procesarse adecuadamente: ..." << endl;

                    arElementos.close();
                }
            } else cout << "Error: el archivo " << nombre << " no existe" << endl;

            break;
        } case 9: {
            //en_cuadrante

            bool hayInfo = false;      //el valor de verdad deberia ser asignado despues de buscar las estructuras correspondientes

            if (args.size() == 5) {

                if (hayInfo) {
                    cout << "Los elementos no han sido ubicados todavia (con el comando ubicar_elemntos)." << endl;
                    break;
                }
                //xMin  xMax    yMin    yMax
                if ( !verificador(args[1],1) || !verificador(args[2],1) || !verificador(args[3],1) || !verificador(args[4],1) ) cout << "coordenadas invalidas" << endl;
                else {
                    if ( ( stoi(args[1]) > stoi(args[2]) ) || ( stoi(args[3]) > stoi(args[4]) ) ) {
                        cout << "La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)" << endl;
                    } else cout << "Los elementos ubicados en el cuadranto son: ..." << endl;
                }

                /*
                int xMin = stoi(args[1]);
                int xMax = stoi(args[2]);
                int yMin = stoi(args[3]);
                int yMax = stoi(args[4]);
                */

            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				enCuadranteA();
			}

            break;
        } case 10: {
            //crear_mapa

            //deberia haber una funcion que busque los nombres de los archivos existentes de elementos y los devuelva uno a uno
            //por ende el resto de codigo del case tendria que ir dentro de un for

            if (args.size() == 2) {
                string nombre = "ejemplo";  //ejemplo no existe, p tiene contenido, nose esta vacio

                if ( !verificador(args[1], 1) ) cout << "el coeficiente tiene que ser un numero" << endl;
                else {
                    ifstream arElementos ((nombre + ".txt"), ios::ate);

                    if (arElementos.is_open()) {
                        if (arElementos.tellg() == 0) {
                            cout << nombre << " no contiene elementos." << endl;
                            break;
                        } else {
                            arElementos.seekg(0, ios::beg);
                            float coeficienteC = stof(args[1]);

                            cout << "El mapa se ha generado exitosamente. Cada elemento tiene n vecinos" << endl;

                        }
                    } else cout << "La informacion requerida no esta almacenada en memoria" << endl;
                }
            } else {
				cout << "Error: numero de parametros incorrecto" << endl;
				crearMapaA();
			}

            break;
        } case 11: {
            //ruta_mas_larga

            bool hayMapa = false;

            if (!hayMapa) cout << "El mapa no ha sido generado todavia (con el comando crear_mapa)." << endl;
            else {
                cout << "Los puntos de interes mas alejados entre si son ... y ... La ruta que los conecta tiene una longitud total de ... y pasa por los siguientes elementos: ..." << endl;
            }

            break;
        }
    }
}

void funcionAyuda() {
    cout << "\n\t\t\tAYUDA SELECCIONADA\n" << endl;
    cout << "Mostrando los comandos disponibles junto con la sytnaxis de cada uno:\n" << endl;

    cout << "- ayuda " << endl;
    cout << "- cargar_comandos nombre_archivo " << endl;
    cout << "- cargar_elementos nombre_archivo " << endl;
    cout << "- agregar_movimiento tipo_mov magnitud unidad_med" << endl;
    cout << "- agregar_analisis tipo_analisis objeto comentario" << endl;
    cout << "- agregar_elemento tipo_comp tamano unidad_med coordX coordY" << endl;
    cout << "- guardar tipo_archivo nombre_archivo " << endl;
    cout << "- simular_comandos coordX coordY " << endl;
	cout << "- ubicar_elementos" << endl;
	cout << "- en_cuadrante coordX1 coordX2 coordY1 coordY2" << endl;
    cout << "- crear_mapa coeficiente_conectividad " << endl;
    cout << "- ruta_mas_larga " << endl;
    cout << "- salir" << endl;
}

void cargarComandosA() {
    cout << "\nSyntaxis del comando: cargar_comandos <nombre_archivo> " << endl;
    cout << "\n- Decripcion: Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo.\n" << endl;
}

void cargarElementosA() {
    cout << "\nSyntaxis del comando: cargar_elementos <nombre_archivo> " << endl;
    cout << "\n- Decripcion: Carga en memoria los datos de puntos de interes o elementos contenidos en el archivo identificado por nombre_archivo.\n" << endl;
}

void agregarMovimientoA() {
    cout << "\nSyntaxis del comando: agregar_movimiento <tipo_mov magnitud> <unidad_med> " << endl;
    cout << "\n- Decripcion: Agrega el comando de movimiento. El movimiento puede ser de dos tipos: avanzar o girar. La magnitud corresponde al valor del movimiento; si es avanzar, el número de unidades que se espera avanzar, si es girar la cantidad de grados que debe girar. La unidad de medida corresponde a la convención con la que se mide la magnitud del movimiento," << endl;
    cout << "- Tipos de unidades aceptadas: avanzar=cm, dm, m, km y girar grd, rad\n" << endl;
}

void agregarAnalisisA() {
    cout << "\nSyntaxis del comando: agregar_analisis <tipo_analisis> <objeto comentario> " << endl;
    cout << "\n- Decripcion: Agrega el comando de analisis. El analisis puede ser de tres tipos: fotografiar, composicion o perforar. El objeto es el nombre del elemento que se quiere analizar. El comentario es opcional, debe estar encerrado entre comillas simples ''\n" << endl;
}

void agregarElementoA() {
    cout << "\nSyntaxis del comando: agregar_elemento <tipo_elemento> <tamano> <unidad_medida> <coordX> <coordY> " << endl;
    cout << "\n- Decripcion: Agrega el componente o elemento descrito a la lista de puntos de interes del robot." << endl;
    cout << "- Tipo de componente: Puede ser uno entre roca, crater, monticulo o duna.\n" << endl;
}

void guardarA() {
    cout << "\nSyntaxis del comando: guardar <tipo_archivo> <nombre_archivo> " << endl;
    cout << "\n- Decripcion: Guarda en el archivo nombre_archivo la informacion solicitada de acuerdo al tipo de archivo: comandos almacena en el archivo la informacion de comandos de movimiento y de analisis que debe ejecutar el robot, elementos almacena en el archivo la informacion de los componentes o punto de interes conocidos en el suelo marciano\n" << endl;
}

void simularComandosA() {
    cout << "\nSyntaxis del comando: simular_comandos <coordX> <coordY> " << endl;
    cout << "\n- Decripcion: Permite simular el resultado de los comandos de movimiento que se enviaran al robot." << endl;
    cout << "- A partir de la posicion actual, se asume que el “Curiosity” esta orientado mirando hacia la parte derecha del eje x en un sistema cartesiano (hacia la derecha). Los angulos de giro positivos generan movimiento en el sentido contrario de las manecillas del reloj, mientras que los angulos de giro negativos generan movimiento en el sentido de las manecillas del reloj.\n" << endl;
}

void ubicarElementoA() {
    cout << "\nSyntaxis del comando: ubicar_elemento" << endl;
    cout << "\n- Decripcion: El comando usa la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura de datos jerarquica para luego poder hacer consultas geograficas.\n" << endl;
}

void enCuadranteA() {
    cout << "\nSyntaxis del comando: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << endl;
    cout << "\n- Decripcion: Permite utilizar la estructura creada con ubicar_elemento para retornar una lista de los componentes o elementos que estan dentro del cuadrante geografico descrito por los limites de coordenadas en x y y.\n" << endl;
}

void crearMapaA() {
    cout << "\nSyntaxis del comando: crear_mapa <coeficiente_conectividad> " << endl;
    cout << "\n- Decripcion: El comando debe utilizar la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre si teniendo en cuenta el coeficiente de conectividad dado.\n" << endl;
}

void rutaMasLargaA() {
    cout << "\nSyntaxis del comando: ruta_mas_larga " << endl;
    cout << "\n- Decripcion: Con el mapa ya creado, el comando permite identificar los dos componentes mas alejados entre si de acuerdo a las conexiones generadas.\n" << endl;
}