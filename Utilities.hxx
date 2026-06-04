#include <iostream>
#include <regex>

using namespace std;

inline string Utilities::comentario(vector<string>& args){
    string temp;
    for(int i = 3; i < args.size(); i ++) {
        temp += args.at(i) + " ";
    }
    return temp;
}

inline float Utilities::calcularDistancia(CMovimiento &c) {
    float devolver = 0;
    if (c.obtenerUnidad() == "cm") {
        devolver = c.obtenerMagnitud()/100;
        return devolver;
    }
    if (c.obtenerUnidad() == "m") {
        devolver = c.obtenerMagnitud()/1;
        return devolver;
    }
    if (c.obtenerUnidad() == "dm") {
        devolver = c.obtenerMagnitud()/10;
        return devolver;
    }
    if (c.obtenerUnidad() == "km") {
        devolver = c.obtenerMagnitud()*1000;
        return devolver;
    }

    return devolver;
}

/*
La siguiente funcion fue generada con IA, ya que no teniamos idea de como tokenizar sin utilizar liberias externas
asi que utilizamos la siguiente promt para generar esta funcion:
Hola, estoy haciendo un proyecto en C++ donde implemento una terminal. Utilizo std::getline para leer la entrada del usuario, que tiene este formato:
comando argumento1 argumento2 ... argumentoN
Necesito una función que tokenice la cadena completa y devuelva cada argumento por separado, usando exclusivamente la biblioteca estándar de C++, sin librerías externas. No puedo usar std::stringstream, ni strtok, ni nada que no sea parte del STL. Solo puedo usar std::string, bucles y contenedores como std::vector.
*/

inline vector<string> Utilities::obtenerArgumentos(string &entrada) {
    vector<string> args = vector<string>();
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

inline bool Utilities::verificador(string& cadena, int opcion) {
    switch (opcion) {
    case 1: {
        regex patron("^-?\\d+(\\.\\d+)?$"); //verifica si la cadena es un numero real
        return regex_match(cadena, patron);
    }
    case 2: {      //verifica si la cadena empieza con ' o ’
        regex patron("'.*");
        regex patron1("’.*");
        bool coincidence = false;
        if (regex_match(cadena, patron)) coincidence = true;
        else if (regex_match(cadena, patron1)) coincidence = true;
        return coincidence;
    }
    case 3: {   //verifica si un numero positivo
        regex patron("^\\d+(\\.\\d+)?$");
        return regex_match(cadena, patron);
    }
    case 4: {   //verifica si la cadena termina con ' o ’
        regex patron(".*'");
        regex patron1(".*’");
        bool coincidence = false;
        if (regex_match(cadena, patron)) coincidence = true;
        else if (regex_match(cadena, patron1)) coincidence = true;
        return coincidence;
    }
    case 5: {
        if(cadena == "fotografiar" || cadena == "perforar" || cadena == "composicion") return true; //verifica si es un comando de analisis
    }
    case 6:
        if(cadena == "avanzar" || cadena == "girar")return true;    //verifica si es un comando de movimiento
    }
    return false;
}

//FUNCIONES DE AYUDA
inline void Utilities::funcionAyuda() {
    cout << "\n\t\t\tAYUDA SELECCIONADA\n" << endl;
    cout << "Mostrando los comandos disponibles junto con la sytnaxis de cada uno:\n" << endl;

    cout << "- ayuda " << endl;
    cout << "- cargar_comandos <nombre_archivo> " << endl;
    cout << "- cargar_elementos <nombre_archivo> " << endl;
    cout << "- agregar_movimiento <tipo_mov> <magnitud> <unidad_med>" << endl;
    cout << "- agregar_analisis <tipo_analisis> <objeto> <comentario>" << endl;
    cout << "- agregar_elemento <tipo_comp> <tamano> <unidad_med> <coordX> <coordY>" << endl;
    cout << "- guardar <tipo_archivo> <nombre_archivo> " << endl;
    cout << "- simular_comandos <coordX> <coordY> " << endl;
	cout << "- ubicar_elementos" << endl;
	cout << "- en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << endl;
    cout << "- crear_mapa <coeficiente_conectividad> " << endl;
    cout << "- ruta_mas_larga " << endl;
    cout << "- salir" << endl;
}

inline void Utilities::cargarComandosA() {
    cout << "\nSyntaxis del comando: cargar_comandos <nombre_archivo> " << endl;
    cout << "\n- Decripcion: Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo.\n" << endl;
}

inline void Utilities::cargarElementosA() {
    cout << "\nSyntaxis del comando: cargar_elementos <nombre_archivo> " << endl;
    cout << "\n- Decripcion: Carga en memoria los datos de puntos de interes o elementos contenidos en el archivo identificado por nombre_archivo.\n" << endl;
}

inline void Utilities::agregarMovimientoA() {
    cout << "\nSyntaxis del comando: agregar_movimiento <tipo_mov magnitud> <unidad_med> " << endl;
    cout << "\n- Decripcion: Agrega el comando de movimiento. El movimiento puede ser de dos tipos: avanzar o girar. La magnitud corresponde al valor del movimiento; si es avanzar, el número de unidades que se espera avanzar, si es girar la cantidad de grados que debe girar. La unidad de medida corresponde a la convención con la que se mide la magnitud del movimiento," << endl;
    cout << "- Tipos de unidades aceptadas: avanzar=cm, dm, m, km y girar grd, rad\n" << endl;
}

inline void Utilities::agregarAnalisisA() {
    cout << "\nSyntaxis del comando: agregar_analisis <tipo_analisis> <objeto comentario> " << endl;
    cout << "\n- Decripcion: Agrega el comando de analisis. El analisis puede ser de tres tipos: fotografiar, composicion o perforar. El objeto es el nombre del elemento que se quiere analizar. El comentario es opcional, debe estar encerrado entre comillas simples ''\n" << endl;
}

inline void Utilities::agregarElementoA() {
    cout << "\nSyntaxis del comando: agregar_elemento <tipo_elemento> <tamano> <unidad_medida> <coordX> <coordY> " << endl;
    cout << "\n- Decripcion: Agrega el componente o elemento descrito a la lista de puntos de interes del robot." << endl;
    cout << "- Tipo de componente: Puede ser uno entre roca, crater, monticulo o duna.\n" << endl;
}

inline void Utilities::guardarA() {
    cout << "\nSyntaxis del comando: guardar <tipo_archivo> <nombre_archivo> " << endl;
    cout << "\n- Decripcion: Guarda en el archivo nombre_archivo la informacion solicitada de acuerdo al tipo de archivo: comandos almacena en el archivo la informacion de comandos de movimiento y de analisis que debe ejecutar el robot, elementos almacena en el archivo la informacion de los componentes o punto de interes conocidos en el suelo marciano\n" << endl;
}

inline void Utilities::simularComandosA() {
    cout << "\nSyntaxis del comando: simular_comandos <coordX> <coordY> " << endl;
    cout << "\n- Decripcion: Permite simular el resultado de los comandos de movimiento que se enviaran al robot." << endl;
    cout << "- A partir de la posicion actual, se asume que el “Curiosity” esta orientado mirando hacia la parte derecha del eje x en un sistema cartesiano (hacia la derecha). Los angulos de giro positivos generan movimiento en el sentido contrario de las manecillas del reloj, mientras que los angulos de giro negativos generan movimiento en el sentido de las manecillas del reloj.\n" << endl;
}

inline void Utilities::ubicarElementoA() {
    cout << "\nSyntaxis del comando: ubicar_elemento" << endl;
    cout << "\n- Decripcion: El comando usa la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura de datos jerarquica para luego poder hacer consultas geograficas.\n" << endl;
}

inline void Utilities::enCuadranteA() {
    cout << "\nSyntaxis del comando: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << endl;
    cout << "\n- Decripcion: Permite utilizar la estructura creada con ubicar_elemento para retornar una lista de los componentes o elementos que estan dentro del cuadrante geografico descrito por los limites de coordenadas en x y y.\n" << endl;
}

inline void Utilities::crearMapaA() {
    cout << "\nSyntaxis del comando: crear_mapa <coeficiente_conectividad> " << endl;
    cout << "\n- Decripcion: El comando debe utilizar la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre si teniendo en cuenta el coeficiente de conectividad dado.\n" << endl;
}

inline void Utilities::rutaMasLargaA() {
    cout << "\nSyntaxis del comando: ruta_mas_larga " << endl;
    cout << "\n- Decripcion: Con el mapa ya creado, el comando permite identificar los dos componentes mas alejados entre si de acuerdo a las conexiones generadas.\n" << endl;
}