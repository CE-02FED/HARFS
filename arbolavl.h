#ifndef ARBOLAVL
#define ARBOLAVL

#include "nodoavl.h"

template <class k>
class ArbolAVL {

private:
    NodoAVL<k> *_root;

    NodoAVL<k>* rotarIzquierda(NodoAVL<k> *pNodo);
    NodoAVL<k>* rotarDerecha(NodoAVL<k> *pNodo);
    NodoAVL<k>* rotarIzqDer(NodoAVL<k> *pNodo);
    NodoAVL<k>* rotarDerIzq(NodoAVL<k> *pNodo);

public:
    ArbolAVL();
    ~ArbolAVL();
    bool insertarEnArbol(k pDato);
    void eliminarEnArbol(k pDato);
    void imprimirBalance();
    void rebalancear(NodoAVL<k> *pNodo);
    void setBalance(NodoAVL<k> *pNodo);
    void imprimeBalance(NodoAVL<k> *pNodo);
    void vaciarNodo(NodoAVL<k> *pNodo);
    int heightArbol(NodoAVL<k> *pNodo);

};

// #################################################################

template <class k>
void ArbolAVL<k>::rebalancear(NodoAVL<k> *pNodo)
{
    setBalance(pNodo);

    if (pNodo->_balance == -2)
    {
        if (heightArbol(pNodo->_nodoIzquierdo->_nodoIzquierdo) >= heightArbol(pNodo->_nodoIzquierdo->_nodoDerecho))
            pNodo = rotarDerecha(pNodo);
        else
            pNodo = rotarIzqDer(pNodo);
    }
    else if (pNodo->_balance == 2)
    {
        if (heightArbol(pNodo->_nodoDerecho->_nodoDerecho) >= heightArbol(pNodo->_nodoDerecho->_nodoIzquierdo))
            pNodo = rotarIzquierda(pNodo);
        else
            pNodo = rotarDerIzq(pNodo);
    }

    if (pNodo->_nodoParental != NULL)
        rebalancear(pNodo->_nodoParental);
    else
        _root = pNodo;

}

// #################################################################

template <class k>
NodoAVL<k>* ArbolAVL<k>::rotarIzquierda(NodoAVL<k> *pNodo)
{
    NodoAVL<k> *nodoTmp = pNodo->_nodoDerecho;
    nodoTmp->_nodoParental = pNodo->_nodoParental;
    pNodo->_nodoDerecho = nodoTmp->_nodoIzquierdo;

    if (pNodo->_nodoDerecho != NULL)
        pNodo->_nodoDerecho->_nodoParental = pNodo;

    nodoTmp->_nodoIzquierdo = pNodo;
    pNodo->_nodoParental = nodoTmp;

    if (nodoTmp->_nodoParental != NULL)
    {
        if (nodoTmp->_nodoParental->_nodoDerecho == pNodo)
            nodoTmp->_nodoParental->_nodoDerecho = nodoTmp;
        else
            nodoTmp->_nodoParental->_nodoIzquierdo = nodoTmp;

    }

    setBalance(pNodo);
    setBalance(nodoTmp);
    return nodoTmp;
}

// #################################################################

template <class k>
NodoAVL<k>* ArbolAVL<k>::rotarDerecha(NodoAVL<k>* pNodo)
{
    NodoAVL<k> *nodoTmp = pNodo->_nodoIzquierdo;
    nodoTmp->_nodoParental = pNodo->_nodoParental;
    pNodo->_nodoIzquierdo = nodoTmp->_nodoDerecho;

    if (pNodo->_nodoIzquierdo != NULL)
    pNodo->_nodoIzquierdo->_nodoParental = pNodo;

    nodoTmp->_nodoDerecho = pNodo;
    pNodo->_nodoParental = nodoTmp;

    if (nodoTmp->_nodoParental != NULL)
    {
        if (nodoTmp->_nodoParental->_nodoDerecho == pNodo)
            nodoTmp->_nodoParental->_nodoDerecho = nodoTmp;
        else
            nodoTmp->_nodoParental->_nodoIzquierdo = nodoTmp;
    }

    setBalance(pNodo);
    setBalance(nodoTmp);
    return nodoTmp;
}

// #################################################################

template <class k>
NodoAVL<k>* ArbolAVL<k>::rotarIzqDer(NodoAVL<k> *pNodo)
{
    pNodo->_nodoIzquierdo = rotarIzquierda(pNodo->_nodoIzquierdo);
    return rotarDerecha(pNodo);
}

// #################################################################

template <class k>
NodoAVL<k>* ArbolAVL<k>::rotarDerIzq(NodoAVL<k> *pNodo)
{
    pNodo->_nodoDerecho = rotarDerecha(pNodo->_nodoDerecho);
    return rotarIzquierda(pNodo);
}

// #################################################################

template <class k>
int ArbolAVL<k>::heightArbol(NodoAVL<k> *pNodo)
{
    if (pNodo == NULL)
    return -1;
    return 1 + std::max(heightArbol(pNodo->_nodoIzquierdo), heightArbol(pNodo->_nodoDerecho));
}

// #################################################################

template <class k>
void ArbolAVL<k>::setBalance(NodoAVL<k> *pNodo)
{
    pNodo->_balance = heightArbol(pNodo->_nodoDerecho) - heightArbol(pNodo->_nodoIzquierdo);
}

// #################################################################

template <class k>
void ArbolAVL<k>::imprimeBalance(NodoAVL<k> *pNodo)
{
    if (pNodo != NULL)
    {
        imprimeBalance(pNodo->_nodoIzquierdo);
        std::cout << pNodo->_balance << " ";
        imprimeBalance(pNodo->_nodoDerecho);
    }
}
// #################################################################

template <class k>
ArbolAVL<k>::ArbolAVL()
{
    _root = NULL;
}

// #################################################################

template <class k>
ArbolAVL<k>::~ArbolAVL()
{
    delete _root;
}

// #################################################################

template <class k>
bool ArbolAVL<k>::insertarEnArbol(k pDato)
{
    if (_root == NULL)
    {
        _root = new NodoAVL<k>(pDato, NULL);
    }
    else
    {
        NodoAVL<k> *nodoTmp = _root, *parentTmp;

        while (true)
        {
            if (nodoTmp->_dato == pDato)
                return false;

            parentTmp = nodoTmp;

            bool irALaIzq = nodoTmp->_dato > pDato;
            nodoTmp = irALaIzq ? nodoTmp->_nodoIzquierdo : nodoTmp->_nodoDerecho;

            if (nodoTmp == NULL)
            {
                if (irALaIzq)
                    parentTmp->_nodoIzquierdo = new NodoAVL<k>(pDato, parentTmp);

                else
                    parentTmp->_nodoDerecho = new NodoAVL<k>(pDato, parentTmp);

                rebalancear(parentTmp);
                break;
            }
        }
    }

    return true;
}
// #################################################################

template <class k>
void ArbolAVL<k>::eliminarEnArbol(k pDato)
{
    if (_root == NULL)
    return;

    NodoAVL<k> *nodoTmp = _root, *parentTmp = _root,
            *borrartmp = NULL, *hijoTmp = _root;

    while (hijoTmp != NULL)
    {
        parentTmp = nodoTmp;
        nodoTmp = hijoTmp;
        hijoTmp = pDato >= nodoTmp->_dato ? nodoTmp->_nodoDerecho : nodoTmp->_nodoIzquierdo;
        if (pDato == nodoTmp->_dato)
        borrartmp = nodoTmp;
    }

    if (borrartmp != NULL)
    {
        borrartmp->_dato = nodoTmp->_dato;

        hijoTmp = nodoTmp->_nodoIzquierdo != NULL ? nodoTmp->_nodoIzquierdo : nodoTmp->_nodoDerecho;

        if (_root->_dato == pDato)
            _root = hijoTmp;

        else
        {
            if (parentTmp->_nodoIzquierdo == nodoTmp)
                parentTmp->_nodoIzquierdo = hijoTmp;

            else
                parentTmp->_nodoDerecho = hijoTmp;

            rebalancear(parentTmp);
        }
    }
}

// #################################################################

template <class k>
void ArbolAVL<k>::imprimirBalance()
{
    imprimeBalance(_root);
    std::cout << std::endl;
}


#endif // ARBOLAVL
