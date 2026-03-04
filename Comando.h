//
// Created by martin-sanmiguel on 3/3/26.
//

#ifndef INTERFAZ_DE_USUARIO_COMANDOS_H
#define INTERFAZ_DE_USUARIO_COMANDOS_H
#include <queue>
#include <list>

using namespace std;

class Comandos {

    //PENDIENTE CAMBIAR LOS STRINGS POR LOS TIPOS DE DATO QUE SON :(

private:
    //queue<CAnalisis> comandos_analisis;
    //queue<CMovimiento> comandos_movimiento;

    List<string CAnalisis> comandos_analisis;
    List<string CMovimiento> comandos_movimiento;

public:
    //Contructor

    //Comandos(queue<CAnalisis> nComAn, queue<CMovimiento> nComMov);

    Comandos(String Comandos_A, String Comandos_M);

    //Getters

    //const queue<CMovimiento> obComMov() const;
    //const queue<CAnalisis> obComAn() const;


    //Setters


    //void fijComAn(const queue<CAnalisis>& nComAn);
    //void fijComMov(const queue<CMovimiento>& nComMov);








};


#endif //INTERFAZ_DE_USUARIO_COMANDOS_H