//
// interfazUsuario.cxx  —  main del proyecto
//

#include "Curiosity.h"
#include "Elemento.h"
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

        //se hacen los casos para salida y para cuando la entrada esta vacia
        if (entrada.empty()) continue;
        if (entrada == "salir") { ejecutando = false; continue; }

        // Curiosity se encarga de todo lo demas
        curiosity.procesar(entrada); //se le envia todo al curiosity
    }

    return 0;
}