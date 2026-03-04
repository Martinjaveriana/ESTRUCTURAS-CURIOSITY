//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_COMANDOS_H
#define INTERFAZ_DE_USUARIO_COMANDOS_H
#include <queue>

using namespace std;

class Comandos {
private:
    queue<CAnalisis> comandos_analisis;
    queue<CMovimiento> comandos_movimiento;
public:
    //Contructor
    Comandos(queue<CAnalisis> nComAn, queue<CMovimiento> nComMov);

    //Getters

    const queue<CMovimiento> obComMov() const;
    const queue<CAnalisis> obComAn() const;


    //Setters


    void fijComAn(const queue<CAnalisis>& nComAn);
    void fijComMov(const queue<CMovimiento>& nComMov);








};


#endif //INTERFAZ_DE_USUARIO_COMANDOS_H