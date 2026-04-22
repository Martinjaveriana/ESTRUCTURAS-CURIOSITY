//
// Created by ago on 21/04/26.
//

#include <queue>
#include <vector>
#include "KDTree.h"

using namespace std;

inline KDTree::KDTree()
{
    this->raiz = nullptr;
}

inline KDTree::~KDTree()
{
    if (this->raiz != nullptr)
    {
        delete this->raiz;
        this->raiz = nullptr;
    }
}

inline bool KDTree::esVacio()
{
    return this->raiz == nullptr;
}

inline Elemento& KDTree::obDatoRaiz()
{
    return this->raiz->obtenerElemento();
}

inline int KDTree::altura()   //debe ser recurrente
{
    if (this->esVacio())
    {
        return -1;
    }

    return this->altura(this->raiz);
}

inline int KDTree::altura(NodoKD *nodo)
{
    int altura;

    if (nodo->esHoja())
    {
        altura = 0;
    } else
    {
        int altIzq = -1, altDer = -1;

        if (nodo->obtenerHijoIzq() != nullptr)
        {
            altIzq = this->altura(nodo->obtenerHijoIzq());
        }
        if (nodo->obtenerHijoDer() != nullptr)
        {
            altDer = this->altura(nodo->obtenerHijoDer());
        }
        if (altIzq > altDer)
        {
            altura = altIzq + 1;
        } else
        {
            altura = altDer + 1;
        }
    }

    return altura;
}

inline int KDTree::tamano()   //debe ser recurrente
{
    if (!this->esVacio())
    {
        return this->tamano(this->raiz);
    }

    return 0;
}

inline int KDTree::tamano(NodoKD* nodo)
{
    int altIzq = 0, altDer = 0;
    if (nodo->esHoja())
    {
        return 1;
    }

    if (nodo->obtenerHijoIzq() != nullptr)
    {
        altIzq = this->tamano(nodo->obtenerHijoIzq());
    }
    if (nodo->obtenerHijoDer() != nullptr)
    {
        altDer = this->tamano(nodo->obtenerHijoDer());
    }

    return altIzq + altDer + 1;
}

inline bool KDTree::insertarNodo(Elemento &val)  //no es necesario que sea recurrente, puede ser ITERATIVA
{
    bool esX = true;
    cout << "AAAAAAAAAAAA" << endl;
    NodoKD* nuevo;
    cout << "AAAAAAAAAAAA" << endl;

    if (!this->esVacio())
    {
        //Es el que quiero ins
        NodoKD* nodo = this->raiz;
        NodoKD* padre = this->raiz;

        bool insertado = false, duplicado = false, der = false;

        //para llegar a donde lo quiero insertar
        while (nodo != nullptr && !duplicado)
        {
            if (esX) {
                padre = nodo;
                if (val.obtenerCoordX() < nodo->obtenerElemento().obtenerCoordX())
                {
                    der = false;
                    nodo = nodo->obtenerHijoIzq();
                } else if (val.obtenerCoordX() > nodo->obtenerElemento().obtenerCoordX()){
                    der = true;
                    nodo = nodo->obtenerHijoDer();
                } else
                {
                    cout << "Error: el elemento de tipo '" << val.obtenerTipo() << "' no se pudo agregar, pues ya estaba" << endl;
                    duplicado = true;
                }
            } else if (!esX) {
                padre = nodo;
                if (val.obtenerCoordY() < nodo->obtenerElemento().obtenerCoordY())
                {
                    der = false;
                    nodo = nodo->obtenerHijoIzq();
                } else if (val.obtenerCoordY() > nodo->obtenerElemento().obtenerCoordY()){
                    der = true;
                    nodo = nodo->obtenerHijoDer();
                } else
                {
                    cout << "Error: el elemento de tipo '" << val.obtenerTipo() << "' no se pudo agregar, pues ya estaba" << endl;
                    duplicado = true;
                }
            }
            esX = !esX;
        }

        //Insertar
        if (!duplicado)
        {
            nuevo = new NodoKD(val);
            if (nuevo != nullptr)
            {
                if (!der)
                {
                    padre->fijarHijoIzq(nuevo);
                } else
                {
                    padre->fijarHijoDer(nuevo);
                }
            } else cout << "Error: el elemento de tipo '" << val.obtenerTipo() << "' no se pudo agregar, pues es nulo" << endl;

            insertado = true;
        }

        return insertado;
    }
    nuevo = new NodoKD(val);
    if (nuevo != nullptr)
    {
        this->raiz = nuevo;

        return true;
    }

    return false;
}

inline bool KDTree::eliminarNodo(Elemento &val)  //pude ser ITERATIVA
{
    bool esX = true;
    if (!this->esVacio())
    {
        NodoKD* aux;
        NodoKD* mayor;
        NodoKD* nodo = this->raiz;
        NodoKD* padre = this->raiz;
        bool encontrado = false, der = false;

        while (nodo != nullptr && !encontrado)
        {
            if (esX) {
                if (val.obtenerCoordX() == nodo->obtenerElemento().obtenerCoordX()) encontrado = true;
                else padre = nodo;

                if (val.obtenerCoordX() < nodo->obtenerElemento().obtenerCoordX())
                {
                    nodo = nodo->obtenerHijoIzq();
                    der = false;
                } else if (val.obtenerCoordX() > nodo->obtenerElemento().obtenerCoordX()){
                    nodo = nodo->obtenerHijoDer();
                    der = true;
                }
            } else if (!esX) {
                if (val.obtenerCoordY() == nodo->obtenerElemento().obtenerCoordY()) encontrado = true;
                else padre = nodo;

                if (val.obtenerCoordY() < nodo->obtenerElemento().obtenerCoordY())
                {
                    nodo = nodo->obtenerHijoIzq();
                    der = false;
                } else if (val.obtenerCoordY() > nodo->obtenerElemento().obtenerCoordY()){
                    nodo = nodo->obtenerHijoDer();
                    der = true;
                }
            }
            esX = !esX;
        }

        if (encontrado)
        {
            if (nodo->esHoja())
            {
                if (nodo == this->raiz)
                {
                    delete nodo;
                    this->raiz = nullptr;

                    return true;
                }
                delete nodo;
                if (der) padre->fijarHijoDer(nullptr);
                else padre->fijarHijoIzq(nullptr);

                return true;
            }

            if (nodo->obtenerHijoIzq() != nullptr && nodo->obtenerHijoDer() == nullptr)
            {
                aux = nodo->obtenerHijoIzq();
                if (nodo == this->raiz)
                {
                    this->raiz = aux;
                } else if (der) padre->fijarHijoDer(aux);
                else padre->fijarHijoIzq(aux);
                delete nodo;

                return true;
            }
            if (nodo->obtenerHijoIzq() == nullptr && nodo->obtenerHijoDer() != nullptr)
            {
                aux = nodo->obtenerHijoDer();
                if (nodo == this->raiz) this->raiz = aux;
                else if (der) padre->fijarHijoDer(aux);
                else padre->fijarHijoIzq(aux);

                delete nodo;

                return true;
            }

            aux = this->encontrarPadreMayor(nodo->obtenerHijoIzq());
            mayor = aux->obtenerHijoDer();
            if (mayor == nullptr)      //es decir, si el hijo izq del nodo a eliminar es el mayor
            {
                if (nodo == this->raiz)
                {
                    aux->fijarHijoDer(nodo->obtenerHijoDer());
                    this->raiz = aux;
                } else
                {
                    aux->fijarHijoDer(nodo->obtenerHijoDer());
                    if (der) padre->fijarHijoDer(aux);
                    else padre->fijarHijoIzq(aux);
                }
            } else
            {
                if (nodo == this->raiz)
                {
                    mayor->fijarHijoDer(nodo->obtenerHijoDer());
                    aux->fijarHijoDer(mayor->obtenerHijoIzq());
                    mayor->fijarHijoIzq(nodo->obtenerHijoIzq());
                    this->raiz = mayor;
                } else
                {
                    mayor->fijarHijoDer(nodo->obtenerHijoDer());
                    aux->fijarHijoDer(mayor->obtenerHijoIzq());
                    mayor->fijarHijoIzq(nodo->obtenerHijoIzq());
                    if (der) padre->fijarHijoDer(mayor);
                    else padre->fijarHijoIzq(mayor);
                }
            }
            delete nodo;

            return true;
        }

        return false;
    }

    return false;
}

inline NodoKD* KDTree::buscarNodo(Elemento &val) //pude ser ITERATIVA
{
    bool esX = true;
    if (!this->esVacio())
    {
        NodoKD* nodo = this->raiz;
        bool encontrado = false;

        while (nodo != nullptr && !encontrado)
        {
            if (esX) {
                if (val.obtenerCoordX() < nodo->obtenerElemento().obtenerCoordX())
                {
                    nodo = nodo->obtenerHijoIzq();
                } else if (val.obtenerCoordX() > nodo->obtenerElemento().obtenerCoordX()){
                    nodo = nodo->obtenerHijoDer();
                } else
                {
                    encontrado = true;
                }
            } else if (!esX) {
                if (val.obtenerCoordY() < nodo->obtenerElemento().obtenerCoordY())
                {
                    nodo = nodo->obtenerHijoIzq();
                } else if (val.obtenerCoordY() > nodo->obtenerElemento().obtenerCoordY()){
                    nodo = nodo->obtenerHijoDer();
                } else
                {
                    encontrado = true;
                }
            }
            esX = !esX;
        }

        return nodo;
    }

    return nullptr;
}

inline vector<Elemento>* KDTree::preOrden()    //recurrente
{
    vector<Elemento>* valores = new vector<Elemento>();

    if (!this->esVacio())
    {
        this->preOrden(this->raiz, *valores);
    }

    return valores;
}

inline void KDTree::preOrden(NodoKD *nodo, vector<Elemento> &valores)
{
    if (nodo != nullptr)
    {
        valores.push_back(nodo->obtenerElemento());
        this->preOrden(nodo->obtenerHijoIzq(), valores);
        this->preOrden(nodo->obtenerHijoDer(), valores);
    }
}

inline vector<Elemento>* KDTree::inOrden()     //recurrente
{
    vector<Elemento>* valores = new vector<Elemento>();

    if (!this->esVacio())
    {
        this->inOrden(this->raiz, *valores);
    }

    return valores;
}

inline void KDTree::inOrden(NodoKD *nodo, vector<Elemento> &valores)
{
    if (nodo != nullptr)
    {
        this->inOrden(nodo->obtenerHijoIzq(), valores);
        valores.push_back(nodo->obtenerElemento());
        this->inOrden(nodo->obtenerHijoDer(), valores);
    }
}

inline vector<Elemento>* KDTree::posOrden()    //recurrente
{
    vector<Elemento>* valores = new vector<Elemento>();

    if (!this->esVacio())
    {
        this->posOrden(this->raiz, *valores);
    }

    return valores;
}

inline void KDTree::posOrden(NodoKD *nodo, vector<Elemento> &valores)
{
    if (nodo != nullptr)
    {
        this->posOrden(nodo->obtenerHijoIzq(), valores);
        this->posOrden(nodo->obtenerHijoDer(), valores);
        valores.push_back(nodo->obtenerElemento());
    }
}

inline vector<Elemento>* KDTree::nivelOrden()  //iterativo
{
    vector<Elemento>* valores = new vector<Elemento>();

    if (!this->esVacio())
    {
        queue< NodoKD* > cola;
        NodoKD* nodo;
        cola.push(this->raiz);

        cout << endl;
        while (!cola.empty())
        {
            nodo = cola.front();
            cout << "(" <<nodo->obtenerElemento().obtenerCoordX() << ", " << nodo->obtenerElemento().obtenerCoordY() << ")\t";
            cola.pop();
            valores->push_back(nodo->obtenerElemento());

            if (nodo->obtenerHijoIzq() != nullptr)
            {
                cola.push(nodo->obtenerHijoIzq());
            }
            if (nodo->obtenerHijoDer() != nullptr)
            {
                cola.push(nodo->obtenerHijoDer());
            }
        }
        cout << endl;
    }

    return valores;
}

inline NodoKD* KDTree::encontrarPadreMayor(NodoKD *nodo)
{
    if (nodo != nullptr)
    {
        NodoKD* padre = nodo;
        NodoKD* mayor = nodo;

        while (mayor->obtenerHijoDer() != nullptr)
        {
            padre = mayor;
            mayor = mayor->obtenerHijoDer();
        }

        return padre;
    }

    return nullptr;
}