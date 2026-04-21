using namespace std;

inline Comando::Comando() {
    this->tipoAccion = "";
}

inline Comando::~Comando() = default;

inline void Comando::fijarTipoAccion(string& nTipoAccion) {
    this->tipoAccion = nTipoAccion;
}

inline string& Comando::obtenerTipoAccion() {
    return this->tipoAccion;
}
