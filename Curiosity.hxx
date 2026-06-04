#include <iostream>
#include <fstream>
#include <cmath>
#include <numbers>
#include "CAnalisis.h"
#include "CMovimiento.h"

using namespace std;

inline Curiosity::Curiosity() {
    this->comandos = new queue<Comando*>();
    this->elementos = new vector<Elemento*>();
    this->arbolElementos = new KDTree();
}

inline Curiosity::~Curiosity() = default;

inline vector<Elemento*>* Curiosity::obtenerElementos() {
    return this->elementos;
}

inline void Curiosity::fijarElementos(vector<Elemento*>* elementos) {
    this->elementos = elementos;
}

inline queue<Comando*>* Curiosity::obtenerComandos() {
    return this->comandos;
}

inline void Curiosity::fijarComandos(queue<Comando*>* comandos) {
    this->comandos = comandos;
}

inline KDTree* Curiosity::obtenerArbolElementos() {
    return this->arbolElementos;
}

inline void Curiosity::fijarArbolElementos(KDTree* tree) {
    this->arbolElementos = tree;
}

// COMANDOS DEL CURIOSITY
inline void Curiosity::agregarMovimiento(vector<string>* args) {
    float nMagnitud = stof(args->at(2));
    CMovimiento* movimiento = new CMovimiento(args->at(1), nMagnitud, args->at(3));
    this->comandos->push(movimiento);
}

inline void Curiosity::agregarAnalisis(vector<string>* args, string comentario) {
    CAnalisis* analisis = new CAnalisis(args->at(1), args->at(2), comentario);
    this->comandos->push(analisis);
}

inline void Curiosity::limpiarComandos() {
    while (!this->comandos->empty()) {
        this->comandos->pop();
    }
}


inline void Curiosity::cargar_comandos(vector<string>* args) {
    if (args->size() == 2) {
        string ruta = "" + args->at(1);
        ifstream arComandos(ruta, ios::ate);

        if (arComandos.is_open()) {
            if (arComandos.tellg() == 0) {
                cout << "Error: " << args->at(1) << " no contiene comandos." << endl;
            } else {
                arComandos.seekg(0, ios::beg);
                string linea;
                bool limpio = false;

                while (getline(arComandos, linea)) {
                    if (linea.empty()) continue;

                    vector<string>* argsComandos = Utilities::obtenerArgumentos(linea);

                    if (!limpio) {
                        this->limpiarComandos();
                        limpio = true;
                    }

                    if (argsComandos->size() == 3 && Utilities::verificador(argsComandos->at(0), 6)) {
                        argsComandos->insert(argsComandos->begin(), "agregar_movimiento");
                        this->agregar_movimiento(argsComandos, false);
                    } else if ( argsComandos->size() >= 2 && Utilities::verificador(argsComandos->at(0), 5) ) {
                        argsComandos->insert(argsComandos->begin(), "agregar_analisis");
                        this->agregar_analisis(argsComandos, false);
                    } else cout << "Error: Linea " << linea << " invalida, se omitira" << endl;
                }

                cout << "Info: " << comandos->size() << " elementos cargados correctamente desde " << args->at(1) << endl;
                arComandos.close();
            }
        } else {
            cout << "Error: " << args->at(1) << " no se encuentra o no puede leerse." << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::cargarComandosA();
    }
}

inline void Curiosity::cargar_elementos(vector<string>* args) {
    if (args->size() == 2) {
        string ruta = "" + args->at(1);
        ifstream arElementos(ruta, ios::ate);

        if (arElementos.is_open()) {
            if (arElementos.tellg() == 0) {
                cout << "Info: " << args->at(1) << " no contiene elementos." << endl;
            } else {
                arElementos.seekg(0, ios::beg);
                this->elementos->clear();
                string linea;

                while (getline(arElementos, linea)) {
                    if (linea.empty()) continue;
                    vector<string>* argElemento = Utilities::obtenerArgumentos(linea);

                    if (argElemento->size() != 5) {
                        cout << "Info: Linea invalida, se omite: " << linea << endl;
                        continue;
                    }

                    argElemento->insert(argElemento->begin(), "agregar_elemento");
                    agregar_elemento(argElemento, false);
                }

                cout << "Info: " << this->elementos->size() << " elementos cargados correctamente desde " << args->at(1) << endl;
                arElementos.close();
                cout << "Se ubican los elementos agregados";
                this->ubicar_elementos();
            }
        } else {
            cout << "Info: " << args->at(1) << " no se encuentra o no puede leerse." << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::cargarElementosA();
    }
}

inline void Curiosity::agregar_movimiento(vector<string>* args, bool imprimir) {
    if (args->size() == 4) {
        bool verMov = Utilities::verificador(args->at(1), 6);
        bool verMag = Utilities::verificador(args->at(2), 1);
        bool verUni = (args->at(3) == "cm" || args->at(3) == "dm" || args->at(3) == "m" || args->at(3) == "km" || args->at(3) == "grd" || args->at(3) == "rad");

        if (!verMov || !verMag || !verUni) {
            if (imprimir) cout << "Info: La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)" << endl;
        } else {
            this->agregarMovimiento(args);
            if (imprimir) cout << "Info: El comando de movimiento ha sido agregado exitosamente" << endl;
        }
    } else if (imprimir){
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::agregarMovimientoA();
    }
}

inline void Curiosity::agregar_analisis(vector<string>* args, bool imprimir) {
    if (args->size() >= 3) {
        bool verAna = Utilities::verificador(args->at(1), 5);
        bool verCom = true;

        if (args->size() > 3 && ( !Utilities::verificador(args->at(3),2) && !Utilities::verificador(args->at(args->size()-1), 3) ) ) {
            verCom = false;
        }

        if (!verAna || !verCom) {
            if (imprimir) {
                cout << "Info: \nLa informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)\n" << endl;
                Utilities::agregarAnalisisA();
            }
        } else {
            if (args->size() > 3 ) {
                this->agregarAnalisis(args, Utilities::comentario(args));
            } else this->agregarAnalisis(args, "");
            if (imprimir) cout << "Info: \nEl comando de analisis ha sido agregado exitosamente\n" << endl;
        }
    } else if (imprimir) {
        cout << "\nError: numero de parametros incorrecto\n" << endl;
        Utilities::agregarAnalisisA();
    }
}

inline void Curiosity::agregar_elemento(vector<string>* args, bool imprimir) {
    if (args->size() == 6) {
        bool verEle = (args->at(1) == "roca" || args->at(1) == "crater" || args->at(1) == "monticulo" || args->at(1) == "duna");
        bool verTam = Utilities::verificador(args->at(2), 3);
        bool verUni = (args->at(3) == "cm" || args->at(3) == "dm" || args->at(3) == "m" || args->at(3) == "km");
        bool verCor = (Utilities::verificador(args->at(4), 1) && Utilities::verificador(args->at(5), 1));

        if (!verEle || !verTam || !verUni || !verCor) {
            if (imprimir) cout << "Info: La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)" << endl;
        } else {
            if (imprimir) cout << "Info: El elemento ha sido agregado exitosamente" << endl;
            double nTamano = stod(args->at(2));
            float nCoorX = stof(args->at(4)), nCoorY = stof(args->at(5));
            this->elementos->push_back(new Elemento(args->at(1), nTamano, args->at(3), nCoorX, nCoorY));
        }
    } else if (imprimir) {
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::agregarElementoA();
    }
}

inline void Curiosity::guardar(vector<string>* args) {
    if (args->size() == 3) {
        bool verInfo = (args->at(1) == "comandos" || args->at(1) == "elementos");

        if (verInfo) {
            string ruta = "" + args->at(2);
            ofstream arAGuardar(ruta);

            if (arAGuardar.is_open()) {
                vector<Elemento*>::const_iterator Eit;

                if(args->at(1) == "comandos" && !this->comandos->empty()) {
                    queue<Comando*> coms = *this->comandos;
                    while (!coms.empty()) {
                        CMovimiento* mov = dynamic_cast<CMovimiento*>(coms.front());
                        if (mov != nullptr) {
                            coms.pop();
                            arAGuardar << mov->obtenerTipoMovimiento() << " " << mov->obtenerMagnitud() << " " << mov->obtenerUnidad() << endl;
                        } else {
                            CAnalisis* an = dynamic_cast<CAnalisis*>(coms.front());
                            coms.pop();
                            if (an != nullptr) arAGuardar << an->obtenerTipoAnalisis() << " " << an->obtenerObjeto() << " " << an->obtenerComentario() << endl;
                        }
                    }
                } else if(args->at(1) == "comandos") cout << "Info: no hay comandos en el curiosity" << endl;

                if(args->at(1) == "elementos" && !this->elementos->empty()) {
                    for(Eit = this->elementos->begin() ; Eit !=this->elementos->end(); Eit++ ) {
                        arAGuardar << (*Eit)->obtenerTipo() << " " << (*Eit)->obtenerTamano() << " " << (*Eit)->obtenerUnidad() << " " << (*Eit)->obtenerCoordX() << " " << (*Eit)->obtenerCoordY() << endl;
                    }
                } else if(args->at(1) == "elementos") cout << "Info: no hay elementos en el curiosity" << endl;

                if (arAGuardar.tellp() != 0) {
                    cout << "Info: La informacion ha sido guardada en " << args->at(2) << endl;
                }
                arAGuardar.close();
            } else {
                cout << "Info: Error guardando en " << args->at(2) << endl;
            }
        } else {
            cout << "Info: tipo de informacion incorrecta" << endl;
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::guardarA();
    }
}

inline void Curiosity::simular_comandos(vector<string>* args) {
    if (args->size() == 3) {
        bool verCorX = Utilities::verificador(args->at(1), 1);
        bool verCorY = Utilities::verificador(args->at(2), 1);

        if (!verCorX || !verCorY) {
            cout << "Info: coordenadas invalidas" << endl;
        } else {
            float x = stof(args->at(1));
            float y = stof(args->at(2));
            float distancia = 0;
            float angulo = 0;

            if (!this->comandos->empty()) {
                queue<Comando*> coms = *this->comandos;
                while (!coms.empty()) {
                    CMovimiento* mov = dynamic_cast<CMovimiento*>(coms.front());
                    coms.pop();
                    if (mov != nullptr) {
                        if (mov->obtenerTipoMovimiento() == "avanzar") {
                            distancia = Utilities::calcularDistancia(*mov);
                            x+=distancia*cos(angulo);
                            y+=distancia*sin(angulo);
                        } else if (mov->obtenerTipoMovimiento() == "girar") {
                            if (mov->obtenerUnidad() == "grd") angulo += mov->obtenerMagnitud() * numbers::pi / 180;
                            else angulo += mov->obtenerMagnitud();
                        }
                    }
                }
                cout << "Info: La simulacion de los comandos, a partir de la posicion (" << args->at(1) << ", " << args->at(2)
                     << "), deja al robot en la nueva posicion (" << x << ", " << y << ")." << endl;
            } else cout << "Error: La informacion requerida no esta en memoria." << endl;
        }
    } else {
        cout <<endl<< "Error: numero de parametros incorrecto" << endl;
        Utilities::simularComandosA();
    }
}

// COMANDOS DE LA SEGUNDA ENTREGA
inline void Curiosity::ubicar_elementos() {
    this->arbolElementos->clear();
    this->arbolElementos = new KDTree();

    if (!this->elementos->empty()) {
        vector<Elemento*>::const_iterator Eit;
        bool insertado = false;
        vector<Elemento>* noProcesados = new vector<Elemento>();

        for (Eit = this->elementos->begin(); Eit != this->elementos->end(); Eit++) {
            insertado = this->arbolElementos->insertarNodo(*(*Eit));
            if (!insertado) {
                noProcesados->push_back(**Eit);
            }
        }

        if (!noProcesados->empty()) {
            cout << "Error: Los siguientes elementos no pudieron procesarse adecuadamente:" << endl;
            for (Elemento e: *noProcesados) {
                cout << e.obtenerTipo() << " " << e.obtenerTamano() << " " << e.obtenerUnidad() << " " << e.obtenerCoordX() << " " << e.obtenerCoordY() << endl;
            }
        }

        this->arbolElementos->nivelOrden();
        cout << "Info: Los elementos han sido procesados exitosamente" << endl;

    } else {
        cout << "Error: La información requerida no está almacenada en memoria" << endl;
    }
}

inline void Curiosity::en_cuadrante(vector<string>* args) {
    if (args->size() == 5) {
        if (this->arbolElementos->esVacio()) {
            cout << "Error: Los elementos no han sido ubicados todavia (con el comando ubicar_elementos)" << endl;
            return;
        } 

        if (!Utilities::verificador(args->at(1),1) || !Utilities::verificador(args->at(2),1) || !Utilities::verificador(args->at(3),1) || !Utilities::verificador(args->at(4),1)) {
            cout << "Error: coordenadas invalidas" << endl;
        } else {
            float x1 = stof(args->at(1)), x2 = stof(args->at(2)), y1 = stof(args->at(3)), y2 = stof(args->at(4));
            if (x1 > x2 || y1 > y2) {
                cout << "Info: La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)" << endl;
            } else {
                vector<Elemento>* enCuadrante = this->arbolElementos->enCuadrante(x1, y1, x2, y2);

                if (!enCuadrante->empty()) {
                    cout << "Info: Los elementos ubicados en el cuadrante son:" << endl;
                    for (Elemento e: *enCuadrante) {
                        cout << e.obtenerTipo() << " " << e.obtenerTamano() << " " << e.obtenerUnidad() << " " << e.obtenerCoordX() << " " << e.obtenerCoordY() << endl;
                    }
                }
                else {
                    cout<< endl <<"no hay elementos en el cuadrante"<<endl;
                }
            }
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::enCuadranteA();
    }
}

// COMANDOS DE LA TERCERA ENTREGA
inline void Curiosity::crear_mapa(vector<string>* args) {
    if (args->size() == 2) {
        if (!Utilities::verificador(args->at(1), 1)) {
            cout << "Info: el coeficiente tiene que ser un numero" << endl;
        } else {
            string nombre = "ejemplo";
            ifstream arElementos((nombre), ios::ate);

            if (arElementos.is_open()) {
                if (arElementos.tellg() == 0) {
                    cout << "Info: " << nombre << " no contiene elementos." << endl;
                } else {
                    //arComandos.seekg(0, ios::beg);
                    float coeficienteC = stof(args->at(1));
                    cout << "Info: El mapa se ha generado exitosamente. Cada elemento tiene n vecinos" << endl;
                }
            } else {
                cout << "Info: La informacion requerida no esta almacenada en memoria" << endl;
            }
        }
    } else {
        cout << "Error: numero de parametros incorrecto" << endl;
        Utilities::crearMapaA();
    }
}

inline void Curiosity::ruta_mas_larga() {
    bool hayMapa = false;

    if (!hayMapa) {
        cout << endl << "Info: El mapa no ha sido generado todavia (con el comando crear_mapa)." << endl << endl;
    } else {
        cout << "Info: Los puntos de interes mas alejados entre si son ... y ... La ruta que los conecta tiene una longitud total de ... y pasa por los siguientes elementos: ..." << endl;
    }
}