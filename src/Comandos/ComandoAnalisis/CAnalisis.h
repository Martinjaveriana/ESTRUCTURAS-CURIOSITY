#ifndef PROYECTOCURIOSITY_CANALISIS_H
#define PROYECTOCURIOSITY_CANALISIS_H

#include "../Comando.h"

class CAnalisis : public Comando {
private:
    string objeto;
    string comentario;
public:
    inline CAnalisis(string &nTipoAnalisis, string &nObjeto, string &nComentario);
    inline ~CAnalisis() override;
    inline string& obtenerTipoAnalisis();
    inline void fijarTipoAnalisis(string &nTipoAnalisis);
    inline string& obtenerObjeto();
    inline void fijarObjeto(string &nObj);
    inline string& obtenerComentario();
    inline void fijarComentario(string &nCom);
};

#include "CAnalisis.hxx"

#endif //PROYECTOCURIOSITY_CANALISIS_H
