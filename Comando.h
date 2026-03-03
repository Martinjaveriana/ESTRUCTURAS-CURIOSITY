//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_COMANDOS_H
#define INTERFAZ_DE_USUARIO_COMANDOS_H
#include <queue>

using namespace std;

class Comandos {
protected:
    queue<CAnalisis> comandos_analisis;
    queue<CMovimiento> comandos_movimiento;
public:
    Comandos(queue<CAnalisis> nComAn, queue<CMovimiento> nComMov);
    queue<CAnalisis> obComAn();
    void fijComAn(queue<CAnalisis> nComAn);
    queue<CMovimiento> obComMov();
    void fijComMov(queue<CMovimiento> nComMov);
};


#endif //INTERFAZ_DE_USUARIO_COMANDOS_H