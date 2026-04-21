#include <string>

inline CAnalisis::CAnalisis(string &nTipoAnalisis, string &nObjeto, string &nComentario) {
    Comando::tipoAccion = nTipoAnalisis;
    this->objeto = nObjeto;
    this->comentario = nComentario;
}

inline CAnalisis::~CAnalisis() = default;

inline string& CAnalisis::obtenerTipoAnalisis(){
    return Comando::tipoAccion;
}

inline void CAnalisis::fijarTipoAnalisis(string &nTipoAnalisis) {
    Comando::tipoAccion = nTipoAnalisis;
}

inline string& CAnalisis::obtenerObjeto() {
    return this->objeto;
}

inline void CAnalisis::fijarObjeto(string &nObj) {
    this->objeto = nObj;
}

inline string& CAnalisis::obtenerComentario(){
    return this->comentario;
}

inline void CAnalisis::fijarComentario(string &nCom) {
    this->comentario = nCom;
}