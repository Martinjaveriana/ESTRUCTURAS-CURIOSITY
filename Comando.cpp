//
// Created by martin-sanmiguel on 3/3/26.
//
#include "Comandos.h"
#include <queue>

using namespace std;

Comandos(queue<CAnalisis> nComAn, queue<CMovimiento> nComMov) {
    comandos_analisis = nComAn;
    comandos_analisis = nComAn;
}

queue<CAnalisis> obComAn() {
    return comandos_analisis;
}

void fijComAn(queue<CAnalisis> nComAn) {
    comandos_analisis = nComAn;
}

queue<CMovimiento> obComMov() {
    return comandos_movimiento;
}

void fijComMov(queue<CMovimiento> nComMov) {
    comandos_analisis = nComAn;
};