//
// interfazUsuario.cxx  —  main del proyecto
//

#include "Curiosity.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Curiosity curiosity;
    string entrada;
    bool ejecutando = true;

    while (ejecutando) {
        cout << "$ ";
        getline(cin, entrada);

        if (entrada.empty()) continue;
        if (entrada == "salir") { ejecutando = false; continue; }

        // Curiosity se encarga de todo lo demas
        curiosity.procesar(entrada);
    }

    return 0;
}